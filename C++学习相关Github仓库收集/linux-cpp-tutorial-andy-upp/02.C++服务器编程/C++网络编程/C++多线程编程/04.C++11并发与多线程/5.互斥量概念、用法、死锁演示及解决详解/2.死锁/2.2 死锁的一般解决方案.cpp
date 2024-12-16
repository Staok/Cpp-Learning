//
// Created by 李光辉 on 2021/1/1.
//2.2 死锁的一般解决方案

//只要保证两个互斥量上锁的顺序一致，就不会死锁
//同理 lock_guard 只要两个顺序一致也不会死锁

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
            //两个lock可能需要保护不同的共享块
            my_mutex1.lock();
            //其他代码....
            my_mutex2.lock();
            msgRecvQueue.push_back(i);
            my_mutex2.unlock();
            my_mutex1.unlock();
        }
        return;
    }

    bool outMsgLULProc(int& command)
    {
        my_mutex1.lock();
        my_mutex2.lock();
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

    //死锁
    //C++中，死锁的产生至少有两个互斥量锁，假如有两个锁 金锁和银锁，JinLock 和 YinLock，要求必须都锁定才能执行业务
    //两个线程A，B
    //线程A执行的时候，这个线程先锁金锁，把金锁lock()成功了，然后去lock银锁。。，此时出现了上下文切换
    //线程B执行了，线程B先锁银锁，成功后又去锁金锁，死锁产生了



    cout << "I Love China" << endl;//最后执行这句，整个进程退出
}