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
            msgReceiveQueue.push_back(i);
        }
    }

    //把数据从消息队列中取出的线程
    void outMsgRecvQueue()
    {
        for(int i = 0; i < 100000; ++i)
        {
            if(!msgReceiveQueue.empty())
            {
                //消息不为空,则取出数据
                int command = msgReceiveQueue.front();//返回第一个元素，但不检查元素是否存在
                msgReceiveQueue.pop_front(); //移除第一个元素，但不返回
                //处理数据。。。
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
    list<int> msgReceiveQueue; //list容器，用于代表玩家发送给服务器的命令
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
    //程序运行会引发异常，因为没有锁住共享数据，解决这个问题，需要引入互斥量
    cout << "I Love China" << endl;//最后执行这句，整个进程退出
}