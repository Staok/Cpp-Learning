//
// Created by 李光辉 on 2020/12/30.
//example2_lock_guard模板
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
//            my_mutex.lock();
            lock_guard<mutex> tmp_guard(my_mutex);//lock_guard保护范围是最小的作用域，此处是for循环
            msgRecvQueue.push_back(i);//
//            my_mutex.unlock();
        }
        return;
    }

    bool outMsgLULProc(int& command)
    {
        //取数据也加锁
//        my_mutex.lock();
        lock_guard<mutex> tmp_guard(my_mutex); //lock_guard构造函数里执行mutex::lock(),析构的时候执行mutex::unlock()
        if(!msgRecvQueue.empty())
        {
            //消息不为空,则取出数据
            int command = msgRecvQueue.front();//返回第一个元素，但不检查元素是否存在
            msgRecvQueue.pop_front(); //移除第一个元素，但不返回
            //my_mutex.unlock();//两个出口，需要两个unlock()
            return true;
        }
       //my_mutex.unlock();
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

    A myobja;
    thread myOutMsgObj(&A::outMsgRecvQueue,&myobja); //取对象的地址传参（可以理解为引用）
    thread myInMsgObj(&A::inMsgRecvQueue, &myobja);

    myInMsgObj.join();
    myOutMsgObj.join();


    //有lock(),忘记unlock(),非常难排查，为了防止大家忘记unlock(),C++11引入 std::lock_guard的类模板，自动unlock
     //lock_guard类模板，同时取代lock()和unlock(),用了lock_guard后，就不能再用lock()和unlock()了



    cout << "I Love China" << endl;//最后执行这句，整个进程退出
}