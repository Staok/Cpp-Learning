//
// Created by 李光辉 on 2021/1/1.
//2.3 lock()函数模板



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
            lock(my_mutex1,my_mutex2);//相当于每个互斥量都调用了lock()
            msgRecvQueue.push_back(i);
            my_mutex2.unlock();
            my_mutex1.unlock();
        }
        return;
    }

    bool outMsgLULProc(int& command)
    {
        lock(my_mutex1,my_mutex2);//相当于每个互斥量都调用了lock()
        if(!msgRecvQueue.empty())
        {
            //消息不为空,则取出数据
            int command = msgRecvQueue.front();//返回第一个元素，但不检查元素是否存在
            msgRecvQueue.pop_front(); //移除第一个元素，但不返回
            my_mutex1.unlock();//
            my_mutex2.unlock();
            return true;
        }
        my_mutex1.unlock();
        my_mutex2.unlock();
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
    mutex my_mutex1; //创建一个互斥量
    mutex my_mutex2; //创建另一个互斥量

};


int main()
{

    A myobja;
    thread myOutMsgObj(&A::outMsgRecvQueue,&myobja); //取对象的地址传参（可以理解为引用）
    thread myInMsgObj(&A::inMsgRecvQueue, &myobja);

    myInMsgObj.join();
    myOutMsgObj.join();

    //std::lock()函数模板，一次锁住两个或两个以上的互斥量，用来处理多个互斥量的时候才出场
    //不存在因锁住多个互斥量而导致的风险问题，互斥量中有一个没锁住，它就在那里等着，等所有互斥量都锁住，它才能往下走
    //要么两个互斥量都锁住，要么两个互斥量都没锁住，如果只锁住一个，另一个没锁住，则它立即把已经锁住的解锁，所以不会导致死锁
    //


    cout << "I Love China" << endl;//最后执行这句，整个进程退出
}