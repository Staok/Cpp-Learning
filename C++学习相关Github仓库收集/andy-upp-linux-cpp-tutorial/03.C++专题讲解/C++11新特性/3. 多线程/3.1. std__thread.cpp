#include <iostream>
#include <thread>

//　在C++11以前，C++的多线程编程均需依赖系统或第三方接口实现，一定程度上影响了代码的移植性。
//C++11中，引入了boost库中的多线程部分内容，形成C++标准，形成标准后的boost多线程编程部分接口基本没有变化，
//这样方便了以前使用boost接口开发的使用者切换使用C++标准接口，把容易把boost接口升级为C++接口。

//　　std::thread为C++11的线程类，使用方法和boost接口一样，非常方便，同时，C++11的std::thread解决了
//boost::thread中构成参数限制的问题，我想着都是得益于C++11的可变参数的设计风格。

void threadfun1()
{
    std::cout << "threadfun1 - 1\r\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "threadfun1 - 2" << std::endl;
}

void threadfun2(int iParam, std::string sParam)
{
    std::cout << "threadfun2 - 1" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "threadfun2 - 2" << std::endl;
}

int main()
{
    std::thread t1(threadfun1);
    std::thread t2(threadfun2, 10, "abc");
    t1.join();
    std::cout << "join" << std::endl;
    t2.detach();
    std::cout << "detach" << std::endl;
}
/*
有以上输出结果可以得知，t1.join()会等待t1线程退出后才继续往下执行，t2.detach()并不会。
把detach字符输出后，主函数退出，threadfun2还未执行完成，但是在主线程退出后，t2的线程也被已经被强退出。

在声明一个std::thread对象之后，都可以使用detach和join函数来启动被调线程，区别在于两者是否阻塞主调线程。
（1）当使用join()函数时，主调线程阻塞，等待被调线程终止，然后主调线程回收被调线程资源，并继续运行；
（2）当使用detach()函数时，主调线程继续运行，被调线程驻留后台运行，主调线程无法再取得该被调线程的控制权。
    当主调线程结束时，由运行时库负责清理与被调线程相关的资源。
*/