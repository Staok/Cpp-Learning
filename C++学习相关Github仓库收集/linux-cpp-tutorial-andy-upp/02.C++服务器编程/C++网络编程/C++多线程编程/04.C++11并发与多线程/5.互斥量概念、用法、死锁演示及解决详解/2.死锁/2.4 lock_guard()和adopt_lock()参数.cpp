//
// Created by 李光辉 on 2021/1/1.
//2.4 lock_guard()和adopt_lock()参数



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
            //adopt_lock参数可以自动解锁，不需要调用my_mutex1.unlock();
            lock_guard<mutex> tmp_guard1(my_mutex1,adopt_lock);
            lock_guard<mutex> tmp_guard2(my_mutex2,adopt_lock);

            msgRecvQueue.push_back(i);
//            my_mutex2.unlock();
//            my_mutex1.unlock();
        }
        return;
    }

    bool outMsgLULProc(int& command)
    {

        lock(my_mutex1,my_mutex2);//相当于每个互斥量都调用了lock()
        //adopt_lock参数可以自动解锁，不需要调用my_mutex1.unlock();
        lock_guard<mutex> tmp_guard1(my_mutex1,adopt_lock);
        lock_guard<mutex> tmp_guard2(my_mutex2,adopt_lock);
        if(!msgRecvQueue.empty())
        {
            //消息不为空,则取出数据
            int command = msgRecvQueue.front();//返回第一个元素，但不检查元素是否存在
            msgRecvQueue.pop_front(); //移除第一个元素，但不返回
//            my_mutex1.unlock();//
//            my_mutex2.unlock();
            return true;
        }
//        my_mutex1.unlock();
//        my_mutex2.unlock();
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

    //adopt_lock()是一个结构体对象，表示这个互斥量已经lock过了，不需要lock_guard<mutex>在构造函数中重复lock()

    //lock()一次锁住多个互斥量建议大家谨慎使用（建议一个一个锁）

    cout << "I Love China" << endl;//最后执行这句，整个进程退出
}