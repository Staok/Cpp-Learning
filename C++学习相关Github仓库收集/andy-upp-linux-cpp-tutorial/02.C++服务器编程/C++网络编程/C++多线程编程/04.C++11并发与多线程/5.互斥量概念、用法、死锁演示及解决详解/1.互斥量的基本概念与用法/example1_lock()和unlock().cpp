//
// Created by 李光辉 on 2020/12/30. 
// example1_lock()和unlock()
//


#include <map>
#include <string>
#include <thread>
#include <list>
#include <mutex>
#include <iostream>
#include <vector>
using namespace  std;

class A
{
public:
    //把收到的消息(玩家命令)入到一个队列的线程
    void inMsgRecvQueue()
    {
        for(int i = 0; i < 100000; ++i)
        {
            cout << "inMsgReceiveQueue 执行，插入一个元素" << i << endl;
            //数字i即为服务器收到的命令，插入到list中,即收到十万个玩家不断向消息队列中发玩家命令
            //写数据加锁只保护共享数据
            my_mutex.lock();
            msgRecvQueue.push_back(i);
            my_mutex.unlock();
        }
        return;
    }

    bool outMsgLULProc(int& command)
    {
        //取数据也加锁
        my_mutex.lock();
        if(!msgRecvQueue.empty())
        {
            //消息不为空,则取出数据
            int command = msgRecvQueue.front();//返回第一个元素，但不检查元素是否存在
            msgRecvQueue.pop_front(); //移除第一个元素，但不返回
            my_mutex.unlock();//两个出口，需要两个unlock()
            return true;
        }
        my_mutex.unlock();
        return false;
    }


    //把数据从消息队列中取出的线程
    void outMsgRecvQueue()
    {
        int command = 0;
        for(int i = 0; i < 100000; ++i)
        {
            bool result = outMsgLULProc(command);
            if(result == true)
            {
                cout << "outMsgRecvQueue()执行，取出一个元素" << endl;
            }
            else
            {
                //消息队列为空
                cout << "目前消息队列为空" << i << endl;
            }
        }
        cout << "end" << endl;
    }
private:
    list<int> msgRecvQueue; //list容器，用于代表玩家发送给服务器的命令
    mutex my_mutex; //创建一个互斥量
};


int main()
{
    //开发一个网络服务器，假设有两个线程，一个线程收集玩家命令（用一个数字代表玩家发的命令），并把命令数据写到一个队列中，
    // 另一个线程从队列中取出玩家的命令,解析然后执行玩家需要的动作
    //用成员函数作为线程的方法来写线程
    A myobja;
    thread myOutMsgObj(&A::outMsgRecvQueue,&myobja); //取对象的地址传参（可以理解为引用）
    thread myInMsgObj(&A::inMsgRecvQueue, &myobja);

    myInMsgObj.join();
    myOutMsgObj.join();

    //保护共享数据 操作数据之前 锁住共享数据
    //1.互斥量（mutex）的基本概念
    //互斥量是一个类对象，多个线程尝试用他的lock()成员函数加锁，只有一个成员函数锁定成功，成功的标志是lock返回
    //如果没有成功，那么流程卡在lock()这里不断尝试


    //互斥量怎么用
    //lock(),unlock()，先lock(),操作共享数据，然后unlock(),二者要成对使用

    cout << "I Love China" << endl;//最后执行这句，整个进程退出
}