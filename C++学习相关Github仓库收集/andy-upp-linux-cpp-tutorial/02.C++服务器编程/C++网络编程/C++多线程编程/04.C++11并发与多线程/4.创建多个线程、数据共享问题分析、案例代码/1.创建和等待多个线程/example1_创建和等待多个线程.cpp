//
// Created by 李光辉 on 2020/12/30.
//

#include <map>
#include <string>
#include <thread>
#include <list>
#include <mutex>
#include <iostream>
#include <vector>
using namespace  std;

//线程入口函数
void myprint(int inum)
{
    cout << "myprint线程开始执行了，线程编号：" << inum << endl;
    //....
    cout << "myprint线程结束执行了，线程编号：" << inum << endl;
    return;
}


int main()
{
    //1.创建和等待多个线程
    vector<thread> mythreads;
    //创建10个线程，线程入口函数统一用myprint
    //a）多个线程执行顺序是乱的，跟操作系统内部对线程的调度机制有关
    //b）推荐使用join，主线程等待所有子线程结束后再结束，更容易写出稳定的程序
    //c）把thread放到容器中进行管理，这对我们一次创建多个线程并进行管理来说很方便
    for(int i = 0; i < 10; i++)
    {
        mythreads.push_back(thread(myprint,i));//创建10个线程，并开始执行线程
    }

    for(auto iter = mythreads.begin(); iter != mythreads.end(); ++iter)
    {
        iter->join(); //等待10个线程都返回
    }
    cout << "I Love China" << endl;//最后执行这句，整个进程退出
}