//
// Created by 李光辉 on 2020/12/29.
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
    cout << "我的线程执行完毕了1" << endl;
    cout << "我的线程执行完毕了2" << endl;
    cout << "我的线程执行完毕了3" << endl;
    cout << "我的线程执行完毕了4" << endl;
    cout << "我的线程执行完毕了5" << endl;
    cout << "我的线程执行完毕了6" << endl;
    cout << "我的线程执行完毕了7" << endl;

}

int main()
{

    thread myobj(myprint); // 1、创建线程，入口函数是myprint函数 2.myprint线程开始执行


    //detach 分离，主线程和子线程分离，主线程不等待子线程执行结束，不影响子线程执行
    //更好的方式还是使用join让主线程等子线程逐个结束，更稳定
    //detach之后，主线程与子线程失去联系，子线程运行结束后，由运行时库负责清理该线程相关的资源（守护线程）
    myobj.detach();//detach会导致myprint线程失去控制，所以更推荐用join

    //注意主线程退出后，会导致进程退出，所以子线程没有输出结束也会被中断，子线程在后台执行，无法看到打印信息

    cout << "I Love China1" << endl;
    cout << "I Love China2" << endl;
    cout << "I Love China3" << endl;
    cout << "I Love China4" << endl;
    cout << "I Love China5" << endl;
    cout << "I Love China6" << endl;

    return 0;
}