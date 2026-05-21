#pragma once

#include <atomic>
#include <cstdint>
#include <cassert>

// `DEBUG_LOGx` is a function for logging.

/**
 * @brief The AppState enum defines the lifecycle states of the application context.
 *
 */
enum class AppState : int {
    Stopped,       ///< Not initialized, not running (initial state)
    Starting,      ///< Initializing (prevents concurrent re-entry)
    Started,       ///< Initialized and running
    Stopping       ///< Stopping and deinitializing (prevents concurrent re-entry)
};

/* Usage example:

    #include "AppContext.h"
    #include "ToolBox/Log.h"

    int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv)
    {
        (void)argc;
        (void)argv;

        DEBUG_LOGI_SYS("main() begin");

        AppContext::inst().setArgcArgv(argc, argv);
        int32_t ret = AppContext::inst().run(); // blocking
        if(ret < 0) {
            DEBUG_LOGE_SYS("AppContext run() failed: %d", ret);
            return -1;
        }

        DEBUG_LOGI_SYS("main() end");

        return 0;
    }

*/

/**
 * @brief The AppContext class manages the overall application context,
 * including initialization, running, and stopping of core components.
 *
 * This handle all signals and exceptions.
 * This is a singleton class, use "AppContext::inst()" to get the instance.
 */
class AppContext {
public:

    AppContext();
    ~AppContext();

    // Deleted copy/move constructors and assignment operators
    AppContext(const AppContext&) = delete;
    AppContext& operator=(const AppContext&) = delete;
    AppContext(AppContext&&) = delete;
    AppContext& operator=(AppContext&&) = delete;

    /**
     * @brief Get the singleton instance of AppContext
     * @return AppContext& Reference to the singleton instance
     */
    static AppContext& inst();

    /**
     * @brief Set the argc and argv for initialization
     * @param argc Argument count
     * @param argv Argument vector
     */
    void setArgcArgv(int argc, char** argv);

    /**
     * @brief Run the application context. Blocks until stopped.
     * @return int32_t Return code, negative on error
     */
    int32_t run();

    /**
     * @brief Check if the application context is running
     * @return true if in Started state, false otherwise
     */
    bool getIsRunning() const;

    /**
     * @brief Stop the application context
     */
    void stop();

private:

    // app vals

private:
    // std::recursive_mutex mMutex; no need
    std::atomic<AppState> mInitRunState{AppState::Stopped};
    std::atomic<bool> mIsStopFromSignal{false};

    int mArgc = 0;
    char** mArgv = nullptr;

    int32_t init(); // shall do not blocking things
    void deinit(); // shall do not blocking things

    friend void signalHandler(int signo);
    void setupSignalHandler();

    void setupTerminateHandle();
};
