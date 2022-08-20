#include <atomic>
#include <stdio.h>

/*

std::atomic为C++11封装的原子数据类型。
什么是原子数据类型？
从功能上看，简单地说，原子数据类型不会发生数据竞争，能直接用在多线程中
而不必我们用户对其进行添加互斥资源锁的类型。
从实现上，大家可以理解为这些原子类型内部自己加了锁。
我们下面通过一个测试例子说明原子类型std::atomic_int的特点。
下面例子中，我们使用10个线程，把std::atomic_int类型的变量iCount从100减到1。
*/

std::atomic_bool bIsReady = false;
std::atomic_int iCount = 100;
void threadfun1()
{
    if (!bIsReady) {
        std::this_thread::yield();
    }
    while (iCount > 0)
    {
        printf("iCount:%d\r\n", iCount--);
    }
}

int main()
{
    std::atomic_bool b;
    std::list<std::thread> lstThread;
    for (int i = 0; i < 10; ++i)
    {
        lstThread.push_back(std::thread(threadfun1));
    }
    for (auto& th : lstThread)
    {
        th.join();
    }
}

//　　从上面的结果可以看到，iCount的最小结果都是1，
//单可能不是最后一次打印，没有小于等于0的情况，大家可以代码复制下来多运行几遍对比看看。
