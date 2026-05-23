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
    Uninitialized,    ///< Not initialized (initial state)
    Initializing,     ///< Initializing (prevents concurrent re-entry)
    Initialized,      ///< Initialized and ready to work
    Deinitializing    ///< Deinitializing (prevents concurrent re-entry)
};

class TestClass
  : public std::enable_shared_from_this<TestClass> {
public:
    TestClass()
    {
        DEBUG_LOGI("Started to construct");
        DEBUG_LOGI("Finished constructing");
    };

    ~TestClass()
    {
        DEBUG_LOGI("Started to destruct");
        deinit();
        DEBUG_LOGI("Finished destructing");
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

        std::lock_guard<std::recursive_mutex> lock(mMutex);
        mExThreadPool = threadPool;
        return 0;
    }

    int32_t init()
    {
        DEBUG_LOGI("initialization started");

        ModuleState expected = ModuleState::Uninitialized;
        if (!mInitState.compare_exchange_strong(expected, ModuleState::Initializing)) {
            if (expected == ModuleState::Initialized) {
                DEBUG_LOGW("already initialized, skipping init");
                return 0;
            }
            DEBUG_LOGW("init in progress or deinitializing, skipping init");
            return -1;
        }

        {
            std::lock_guard<std::recursive_mutex> lock(mMutex);

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

                    // if initA fails, set state back to Uninitialized to allow future init attempts
                    mInitState.store(ModuleState::Uninitialized);
                    return ret;
                }
                if ((ret = initB()) != 0) {
                    DEBUG_LOGE("initB failed with code %d", ret);
                    deinitA(); // cleanup initA if initB fails

                    mInitState.store(ModuleState::Uninitialized);
                    return ret;
                }
            }
        }

        mInitState.store(ModuleState::Initialized);

        DEBUG_LOGI("initialization finished");

        return 0;
    }

    bool getIsInited() const
    {
        return (mInitState.load() == ModuleState::Initialized);
    }

    int32_t deinit()
    {
        DEBUG_LOGI("deinitialization started");

        ModuleState expected = ModuleState::Initialized;
        if (!mInitState.compare_exchange_strong(expected, ModuleState::Deinitializing)) {
            if (expected == ModuleState::Uninitialized) {
                DEBUG_LOGW("already deinitialized, skipping deinit");
                return 0;
            }
            DEBUG_LOGW("deinit in progress or initializing, skipping deinit");
            return -1;
        }

        {
            std::lock_guard<std::recursive_mutex> lock(mMutex);

            deinitB();
            deinitA();

            mExThreadPool = nullptr;
        }

        mInitState.store(ModuleState::Uninitialized);

        DEBUG_LOGI("deinitialization finished");

        return 0;
    }

    void process()
    {
        // DEBUG_LOGI("process started"); for debug, can omit

        if (!getIsInited()) {
            DEBUG_LOGW("not initialized, skipping process");
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
        // The lambda captures a weak pointer to the TestClass instance to prevent accessing it after it has been deinitialized or destructed.
        THREAD_POOL_FUNC_DETACH((*imExThreadPool),
            [selfWeakPtr]() {

            // DEBUG_LOGI("Into thread function"); for debug, can omit

            auto self = selfWeakPtr.lock();
            if (!self || !self->getIsInited()) {
                DEBUG_LOGI("TestClass instance is not valid or not initialized, exiting thread function");
                return;
            }

            // the "self" is shared_ptr so its alive all alone here

            self->setData(84);

            // Simulate some work...
            std::this_thread::sleep_for(std::chrono::seconds(5));

            // After the work is done, check again if the instance is still valid and initialized before accessing its members
            if (!self->getIsInited()) {
                DEBUG_LOGI("TestClass instance is not valid or not initialized after work, exiting thread function");
                return;
            }

            self->setData(42);
        });

        // DEBUG_LOGI("process finished"); for debug, can omit
    }

    void setData(int32_t data)
    {
        if (!getIsInited()) {
            DEBUG_LOGW("not initialized, skipping setData");
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
    std::atomic<ModuleState> mInitState{ModuleState::Uninitialized};
    std::recursive_mutex mMutex;

    std::shared_ptr<ThreadPoolEnh> mExThreadPool{nullptr};

    int32_t mData{0};

    // Simulated init/deinit functions for different components
    // Only internal use, in mutex lock scope, no need to check mIsInited
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
        // Shared pointer approach for TestClass
        // auto testObj = std::make_shared<TestClass>();
        // testObj->setThreadPoolInst(threadPool);
        // testObj->init();
        // testObj->process();

        // Using singleton pattern for TestClass
        TestClass::getInstPtr()->setThreadPoolInst(threadPool);
        TestClass::getInstPtr()->init();
        TestClass::getInstPtr()->process();

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    DEBUG_LOGI("Waiting for user any input to exit...");
    std::cin.get();

    DEBUG_LOGI(" --- main() end");

    return 0;
}
