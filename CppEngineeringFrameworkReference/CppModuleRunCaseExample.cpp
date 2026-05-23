#include <atomic>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

// p.s `ThreadPoolEnh` is a thread pool implementation, similar to https://github.com/progschj/ThreadPool.
// `DEBUG_LOGx` is a function for logging.
#include "ToolBox/ThreadPool/ThreadPoolEnh.h"
#include "ToolBox/Log.h"

/**
 * @brief Module initialization example with proper handling of init/deinit and other APIs and thread safety.
 */
enum class ModuleState : int {
    Stopped,    ///< Not running (initial state)
    Starting,   ///< Starting (prevents concurrent re-entry)
    Started,    ///< Running and ready to work
    Stopping    ///< Stopping (prevents concurrent re-entry)
};

class TestClass
  : public std::enable_shared_from_this<TestClass> {
public:
    TestClass()
    {
        DEBUG_LOGI("constructed");
    };

    ~TestClass()
    {
        DEBUG_LOGI("started to destruct");
        stop();
        DEBUG_LOGI("finished destructing");
    };

    // Deleted copy/move constructors and assignment operators
    // Used for singleton pattern
    // Optional if needed, can be deleted if not using singleton pattern
    TestClass(const TestClass&) = delete;
    TestClass& operator=(const TestClass&) = delete;
    TestClass(TestClass&&) = delete;
    TestClass& operator=(TestClass&&) = delete;

    // Singleton pattern for TestClass
    // Because this class used "shared_from_this()", it must be managed by a shared_ptr
    // Optional if needed
    static std::shared_ptr<TestClass> getInstPtr() {
        static std::shared_ptr<TestClass> instance = std::make_shared<TestClass>();
        return instance;
    }

    int32_t setThreadPoolInst(std::shared_ptr<ThreadPoolEnh> threadPool)
    {
        if (!threadPool) {
            DEBUG_LOGE("ThreadPoolEnh instance is required");
            return -1;
        }

        if(mRunState.load() != ModuleState::Stopped) {
            DEBUG_LOGE("Module is running, cannot set thread pool instance");
            return -ENOENT;
        }

        std::lock_guard<std::recursive_mutex> lock(mMutex);
        mExThreadPool = threadPool;
        return 0;
    }

    int32_t run(const bool isBlock)
    {
        DEBUG_LOGI("run() called, starting");

        ModuleState expected = ModuleState::Stopped;
        if (!mRunState.compare_exchange_strong(expected, ModuleState::Starting)) {
            if (expected == ModuleState::Started) {
                DEBUG_LOGW("already running, skipping run");
                return 0;
            }
            DEBUG_LOGW("run in progress or stopping, skipping run");
            return -1;
        }

        std::unique_lock<std::recursive_mutex> lock(mMutex);

        {
            assert(mExThreadPool);

            // reset class vals to default
            {
                mData = 0;
            }

            // perform actual initialization
            {
                int32_t ret = -1;

                // inside these component init fun,
                // can start some working therad or add timers, but make sure to clean them up in deinit funs

                if ((ret = initA()) != 0) {
                    DEBUG_LOGE("initA failed with code %d", ret);

                    // if initA fails, set state back to Stopped to allow future run attempts
                    mRunState.store(ModuleState::Stopped);
                    return ret;
                }
                if ((ret = initB()) != 0) {
                    DEBUG_LOGE("initB failed with code %d", ret);
                    deinitA(); // cleanup initA if initB fails

                    mRunState.store(ModuleState::Stopped);
                    return ret;
                }
            }
        }

        mRunState.store(ModuleState::Started);

        DEBUG_LOGI_SYS("Started");

        // enter blocking loop if isBlock is true
        if(isBlock) {
            // unlock before entering blocking loop to allow "stop()" .etc funs to acquire the lock
            lock.unlock();

            DEBUG_LOGI_SYS("Enter blocking loop...");

            do {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));

                // or not sleep and just do some periodic non-blocking tasks here if needed

            } while(mRunState.load() == ModuleState::Started);

            DEBUG_LOGI_SYS("Exiting blocking loop");
        }

        DEBUG_LOGI("run() exit");

        return 0;
    }

    bool getIsRunning() const
    {
        return (mRunState.load() == ModuleState::Started);
    }

    void stop()
    {
        DEBUG_LOGI("stop() called");

        ModuleState expected = ModuleState::Started;
        if (!mRunState.compare_exchange_strong(expected, ModuleState::Stopping)) {
            if (expected == ModuleState::Stopped) {
                DEBUG_LOGW("already stopped, skipping stop");
                return;
            }
            DEBUG_LOGW("stop in progress or starting, skipping stop");
            return;
        }

        {
            std::lock_guard<std::recursive_mutex> lock(mMutex);

            deinitB();
            deinitA();

            mExThreadPool = nullptr;
        }

        mRunState.store(ModuleState::Stopped);

        DEBUG_LOGI("stop() finished");
    }

    void process()
    {
        // DEBUG_LOGI("process started"); for debug, can omit

        if (!getIsRunning()) {
            DEBUG_LOGW("not running, skipping process");
            return;
        }

        std::shared_ptr<ThreadPoolEnh> imExThreadPool;
        {
            std::lock_guard<std::recursive_mutex> lock(mMutex);

            // get a copy of the shared_ptr under lock to ensure it's valid during the process function execution
            imExThreadPool = mExThreadPool;
        }
        if (!imExThreadPool) {
            DEBUG_LOGI("ThreadPool is not initialized, exiting process");
            return;
        }

        // do work...

        std::weak_ptr<TestClass> selfWeakPtr = shared_from_this();

        // Using THREAD_POOL_FUNC_DETACH to run a task in the thread pool without blocking the current thread
        // The lambda captures a weak pointer to the TestClass instance to prevent accessing it after it
        THREAD_POOL_FUNC_DETACH((*imExThreadPool),
            [selfWeakPtr]() {

            // DEBUG_LOGI("Into thread function"); for debug, can omit

            auto self = selfWeakPtr.lock();
            if (!self || !self->getIsRunning()) {
                DEBUG_LOGI("TestClass instance is not valid or not running, exiting thread function");
                return;
            }

            // the "self" is shared_ptr so its alive all alone here

            self->setData(84);

            // Simulate some work...
            std::this_thread::sleep_for(std::chrono::seconds(5));

            // After the work is done, check again if the instance is still valid and running before accessing its members
            if (!self->getIsRunning()) {
                DEBUG_LOGI("TestClass instance is not valid or not running after work, exiting thread function");
                return;
            }

            self->setData(42);
        });

        // DEBUG_LOGI("process finished"); for debug, can omit
    }

    void setData(int32_t data)
    {
        if (!getIsRunning()) {
            DEBUG_LOGW("not running, skipping setData");
            return;
        }

        DEBUG_LOGI("Setting data to %d", data);

        std::lock_guard<std::recursive_mutex> lock(mMutex);
        mData = data;
    }

    int32_t getData()
    {
        std::lock_guard<std::recursive_mutex> lock(mMutex);
        return mData;
    }

private:
    std::atomic<ModuleState> mRunState{ModuleState::Stopped};
    std::recursive_mutex mMutex;

    std::shared_ptr<ThreadPoolEnh> mExThreadPool{nullptr};

    int32_t mData{0};

    // Simulated init/deinit functions for different components
    // Only internal use, in mutex lock scope, no need to check mIsRunning
    // Every init and deinit fun inside shall log start and finish of its execution
    int32_t initA() { return 0; }
    int32_t initB() { return 0; }

    void deinitA() {  }
    void deinitB() {  }
};

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    auto threadPool = std::make_shared<ThreadPoolEnh>(1);

    {
        // Using singleton approach for TestClass
        std::thread([]() {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            TestClass::getInstPtr()->process();

            std::this_thread::sleep_for(std::chrono::seconds(1));
            TestClass::getInstPtr()->stop();
        }).detach();

        TestClass::getInstPtr()->setThreadPoolInst(threadPool);
        TestClass::getInstPtr()->run(true); // block

        // Also TestClass can be used as shared pointer approach
    }

    DEBUG_LOGI("Waiting for user any input to exit...");
    std::cin.get();

    DEBUG_LOGI(" --- main() end");

    return 0;
}
