//
// Created by 李光辉 on 2020/12/28.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <thread>

using namespace  std;


//自己创建的线程也要从一个函数(初始函数)开始执行
void myprint()
{
    cout << "我的线程开始执行了" << endl;
    //...
    //...
    cout << "我的线程执行完毕了" << endl;
}

int main()
{
    //1.范例演示线程开始和结束
    //程序运行起来，生成一个进程，该进程所属的主线程开始自动运行
    //cout << "I Love China" << endl;//实际上是主线程在执行，主线程结束，则整个进程结束

    //我们自己创建的线程，也需要从一个函数开始执行，函数运行完毕，则线程结束
    //整个进程是否执行完毕的标志是：一般情况下，主线程是否执行完，如果主线程执行完毕了，就代表整个进程执行完毕了，
    //此时如果其他子线程还没有执行完，也会被强行终止
    // 如果想让子线程保持运行，那么就要让主线程（main）保持运行【此条有例外，以后会解释】
    //如果主线程执行完了，子线程没有执行完毕，这种程序是不稳定的，因为子线程会被系统杀掉
    //一个书写良好的程序，英国主线程等待子线程执行完毕后，自己再退出

    //必须要明白：有两个线程在跑，相当于整个程序中有两条线在同时走，即使一条被阻塞，另一条也能运行
    //生成一个属于thread类的对象,myprint是一个可调用对象
    thread myobj(myprint); // 1、创建线程，入口函数是myprint函数 2.myprint线程开始执行

    //阻塞主线程，让主线程等待子线程执行完毕，然后子线程和主线程汇合，主线程再往下走
    myobj.join();

    cout << "主线程收尾，最终主线程安全退出！" << endl;
    return 0;
}