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

vector<int> g_v = {1,2,3};//共享数据

//线程入口函数
void myprint(int inum)
{
    cout << "id为" << this_thread::get_id() << "的线程，打印g_v值" << g_v[0] << g_v[1] << g_v[2] << endl;
//    cout << "g_v: " << g_v[0] << endl;
    return;
}


int main()
{
    //1. 只读的数据,是安全稳定的，不需要什么安全手段，直接读就可以
    //2. 有读有写的数据：2个线程写，8个线程读，如果没有特别的处理，那程序肯定崩溃
    //   最简单的崩溃处理，读的时候不能写，写的时候不能读，2个线程不能同时写，8个线程不能同时读，否则很有可能因为任务切换导致程序崩溃
    //3. 数据共享
    vector <thread> mythreads;
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