#include "AppContext.h"
#include <cstdlib>

#include "ToolBox/Log.h"

#ifdef __linux__
#include <unistd.h>
#endif

#define _POSIX
#include "signal.h"

#include <future>
#include <thread>
#include <chrono>
#include <cerrno>

AppContext::AppContext()
  : mInitRunState(AppState::Stopped),
    mIsStopFromSignal(false),

    mArgc(0), mArgv(nullptr)
{
    DEBUG_LOGI_SYS("AppContext constructor");

    // Setup signal handlers for graceful shutdown
    setupSignalHandler();

    // Setup terminate handler for catching unhandled exceptions
    setupTerminateHandle();

    DEBUG_LOGI_SYS("AppContext constructor finished");
}

AppContext& AppContext::inst()
{
    static AppContext instance;
    return instance;
}

AppContext::~AppContext()
{
    DEBUG_LOGI_SYS("AppContext destructor called, call stop() and wait for deinit to finish...");
    stop();
    while (mInitRunState.load() != AppState::Stopped) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    DEBUG_LOGI_SYS("AppContext destructor finished");
}

void AppContext::setArgcArgv(int argc, char** argv)
{
    // std::lock_guard<std::recursive_mutex> lock(mMutex);
    mArgc = argc;
    mArgv = argv;
}

int32_t AppContext::run()
{
    DEBUG_LOGI_SYS("AppContext run() called");

    if((mArgc <= 0) || (mArgv == nullptr)) {
        DEBUG_LOGE_SYS("AppContext run() need setArgcArgv() first");
        return -EIO;
    }

    AppState expected = AppState::Stopped;
    if (!mInitRunState.compare_exchange_strong(expected, AppState::Starting)) {
        if (expected == AppState::Started) {
            DEBUG_LOGW("AppContext already running, no re-call run()");
            return 0;
        }
        DEBUG_LOGW("AppContext run in progress or stopping, skipping run");
        return -1;
    }

    int32_t result = init();
    if(result < 0) {
        DEBUG_LOGE_SYS("Failed to init AppContext");

        // if init failed, set state back to Stopped, to allow next time call run() to try again
        mInitRunState.store(AppState::Stopped);
        return result;
    }

    mInitRunState.store(AppState::Started);

    DEBUG_LOGI_SYS(" --->>>>>> All init done. Enter main blocking loop...");

    do {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // or not sleep and just do some periodic non-blocking tasks here if needed

    } while(mInitRunState.load() == AppState::Started);

    // this "mIsStopFromSignal" only be set true in signal handler
    if(!(mIsStopFromSignal.load())) {
        DEBUG_LOGI_SYS("exiting blocking loop and start deinit...");
        deinit();
    }

    DEBUG_LOGI_SYS("AppContext run() exit");

    return result;
}

bool AppContext::getIsRunning() const
{
    return (mInitRunState.load() == AppState::Started);
}

void AppContext::stop()
{
    DEBUG_LOGI_SYS("AppContext stop() called");

    AppState expected = AppState::Started;
    if (!mInitRunState.compare_exchange_strong(expected, AppState::Stopping)) {
        if (expected == AppState::Stopped) {
            DEBUG_LOGW("AppContext already stopped, skipping stop");
        } else {
            DEBUG_LOGW("AppContext stop in progress or starting, skipping stop");
        }
        return;
    }
    // state is now Stopping, blocking loop will exit
}

// internal functions

int32_t AppContext::init()
{
    DEBUG_LOGI_SYS("AppContext init begin");

    // state is already Starting (set by run()), no need to check again

    // app init tasks
    {
        // init things in order
    }

    DEBUG_LOGI_SYS("AppContext init() finished");

    return 0;
}

void AppContext::deinit()
{
    DEBUG_LOGI_SYS("AppContext deinit() begin");

    // state should be Stopping at this point
    if (mInitRunState.load() != AppState::Stopping) {
        DEBUG_LOGE_SYS("AppContext deinit() called in unexpected state, just return");
        return;
    }

    // app deinit tasks
    {
        // deinit things in reverse order of init
    }

    mInitRunState.store(AppState::Stopped);

    DEBUG_LOGI_SYS("AppContext deinit() finished");
}

void signalHandler(int signo)
{
    // prevent re-entry
    static std::atomic<bool> handlingSignal{false};
    if(handlingSignal.exchange(true)) {
        // "exchange()": set handlingSignal to true and return the old value atomically
        // so here is already handling signal
        // DEBUG_LOGE_SYS("signalHandler: already handling signal, signo: %d", signo);
        return;
    }

    DEBUG_LOGE_SYS(" <<<<<<<<<<<<------ signalHandler: signo: %d", signo);

    auto fut = std::async(std::launch::async, []{

        // restore signal default handler
        {
            DEBUG_LOGI_SYS("signalHandler: signal_restore: set signal default handler");

            #ifdef _WIN32
                signal(SIGHUP, SIG_DFL);
                signal(SIGINT, SIG_DFL);
                signal(SIGQUIT, SIG_DFL);
                signal(SIGILL, SIG_DFL);
                signal(SIGABRT, SIG_DFL);
                // signal(SIGKILL, SIG_DFL); SIGKILL cannot be caught or ignored, so no need to set handler for it
                signal(SIGSEGV, SIG_DFL);
                signal(SIGFPE, SIG_DFL);
                signal(SIGTERM, SIG_DFL);
                signal(SIGPIPE, SIG_DFL);
                signal(SIGABRT_COMPAT, SIG_DFL);
                signal(SIGBREAK, SIG_DFL);
                signal(SIGABRT2, SIG_DFL);
                // signal(SIGTRAP, SIG_DFL);
                // signal(SIGIOT, SIG_DFL);
                // signal(SIGEMT, SIG_DFL);
                // signal(SIGBUS, SIG_DFL);
                // signal(SIGSYS, SIG_DFL);
                // signal(SIGALRM, SIG_DFL);

            #elif __linux__
                struct sigaction saDefault;
                memset(&saDefault, 0, sizeof(saDefault));
                saDefault.sa_handler = SIG_DFL;

                sigaction(SIGHUP, &saDefault, nullptr);
                sigaction(SIGINT, &saDefault, nullptr);
                sigaction(SIGQUIT, &saDefault, nullptr);
                sigaction(SIGILL, &saDefault, nullptr);
                sigaction(SIGTRAP, &saDefault, nullptr);
                sigaction(SIGABRT, &saDefault, nullptr);
                sigaction(SIGBUS, &saDefault, nullptr);
                // sigaction(SIGKILL, &saDefault, nullptr); SIGKILL cannot be caught or ignored, so no need to set handler for it
                sigaction(SIGUSR1, &saDefault, nullptr);
                sigaction(SIGUSR2, &saDefault, nullptr);
                sigaction(SIGSEGV, &saDefault, nullptr);
                sigaction(SIGFPE, &saDefault, nullptr);
                sigaction(SIGALRM, &saDefault, nullptr);
                sigaction(SIGTERM, &saDefault, nullptr);
                sigaction(SIGPIPE, &saDefault, nullptr);
                sigaction(SIGPROF, &saDefault, nullptr);
                sigaction(SIGPOLL, &saDefault, nullptr);
                sigaction(SIGSYS, &saDefault, nullptr);
                sigaction(SIGVTALRM, &saDefault, nullptr);

            #endif
        }

        // deinit things
        {
            if(AppContext::inst().getIsRunning()) {
                DEBUG_LOGI_SYS("signalHandler: start stop and deinit AppContext");
                AppContext::inst().mIsStopFromSignal.store(true);
                AppContext::inst().stop();
                AppContext::inst().deinit();
            }
        }
    });

    auto wait_ret = fut.wait_for(std::chrono::seconds(10));

    DEBUG_LOGI_SYS("signalHandler: wait_for(10s) returned: %d", static_cast<int>(wait_ret));

    if ( wait_ret == std::future_status::timeout ) {
        // system("reboot");
        DEBUG_LOGE_SYS("signalHandler: wait_for timeout, raise signo: SIGTERM", SIGTERM);
        std::abort(); // to generate core dump for post-mortem analysis, can also use std::terminate() or std::exit()
    } else {
        DEBUG_LOGI_SYS("signalHandler: wait_for completed, raise signo: %d", signo);
        raise(signo);
        // to enter default handler to let process exit
    }
}

void AppContext::setupSignalHandler()
{
    DEBUG_LOGI_SYS("setup signal handler");

#ifdef _WIN32

    signal(SIGHUP, signalHandler);
    signal(SIGINT, signalHandler);
    signal(SIGQUIT, signalHandler);
    signal(SIGILL, signalHandler);
    signal(SIGABRT, signalHandler);
    // signal(SIGKILL, signalHandler); SIGKILL cannot be caught or ignored, so no need to set handler for it
    signal(SIGSEGV, signalHandler);
    signal(SIGFPE, signalHandler);
    signal(SIGTERM, signalHandler);

    signal(SIGABRT_COMPAT, signalHandler);
    signal(SIGBREAK, signalHandler);
    signal(SIGABRT2, signalHandler);
    // signal(SIGTRAP, signalHandler);
    // signal(SIGIOT, signalHandler);
    // signal(SIGEMT, signalHandler);
    // signal(SIGBUS, signalHandler);
    // signal(SIGSYS, signalHandler);
    // signal(SIGALRM, signalHandler);

    // Ignore SIGPIPE to avoid process exit when writing to a closed socket
    signal(SIGPIPE, SIG_IGN);

#elif __linux__

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));

    sigset_t mask;
    sigemptyset(&mask);

    sa.sa_handler = signalHandler;
    sa.sa_mask = mask;
    sa.sa_flags = 0;

    sigaction(SIGHUP, &sa, nullptr);
    sigaction(SIGINT, &sa, nullptr);
    sigaction(SIGQUIT, &sa, nullptr);
    sigaction(SIGILL, &sa, nullptr);
    sigaction(SIGTRAP, &sa, nullptr);
    sigaction(SIGABRT, &sa, nullptr); // 6
    sigaction(SIGBUS, &sa, nullptr);
    // sigaction(SIGKILL, &sa, nullptr); 9 SIGKILL cannot be caught or ignored, so no need to set handler for it
    sigaction(SIGUSR1, &sa, nullptr);
    sigaction(SIGUSR2, &sa, nullptr);
    sigaction(SIGSEGV, &sa, nullptr); // 11
    sigaction(SIGFPE, &sa, nullptr);
    sigaction(SIGALRM, &sa, nullptr);
    sigaction(SIGTERM, &sa, nullptr); // 15
    sigaction(SIGPROF, &sa, nullptr);
    sigaction(SIGPOLL, &sa, nullptr);
    sigaction(SIGSYS, &sa, nullptr);
    sigaction(SIGVTALRM, &sa, nullptr);

    // Ignore SIGPIPE to avoid process exit when writing to a closed socket
    struct sigaction saIgnore;
    memset(&saIgnore, 0, sizeof(saIgnore));
    saIgnore.sa_handler = SIG_IGN;
    sigaction(SIGPIPE, &saIgnore, nullptr);

#endif

}

void AppContext::setupTerminateHandle()
{
    DEBUG_LOGI_SYS("setup terminate handler");

    // Set terminate handler to catch unhandled exceptions
    std::set_terminate([]() {
        try {
            if (std::current_exception()) {
                // Rethrow the current exception to capture its message
                std::rethrow_exception(std::current_exception());
            }
        } catch (const std::exception &e) {
            DEBUG_LOGE_SYS(" <<<<<<<<<<<<------ exception: %s", e.what());
        } catch (...) {
            DEBUG_LOGE_SYS(" <<<<<<<<<<<<------ exception: unknown");
        }
    });
}
