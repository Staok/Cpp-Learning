//
// Created by 李光辉 on 2020/12/30.
//2.1 unique_lock的第二个参数

#include <map>
#include <string>
#include <thread>
#include <list>
#include <mutex>
#include <iostream>
#include <vector>

class A
{
public:
    //把收到的消息(玩家命令)入到一个队列的线程
    void inMsgRecvQueue()
    {
        for(int i = 0; i < 100000; ++i)
        {
            std::cout << "inMsgReceiveQueue 执行，插入一个元素" << i << std::endl;
            my_mutex1.lock();//要先加锁
            std::unique_lock<std::mutex>   tmp_guard1(my_mutex1,std::adopt_lock);
            msgRecvQueue.push_back(i);
        }
        return;
    }


    bool outMsgLULProc(int& command)
    {
        std::unique_lock<std::mutex>   tmp_guard1(my_mutex1);
        std::chrono::milliseconds dura(20000); //休息20秒
        std::this_thread::sleep_for(dura);//休息一定的时长



        if(!msgRecvQueue.empty())
        {
            //消息不为空,则取出数据
            command = msgRecvQueue.front();//返回第一个元素，但不检查元素是否存在
            msgRecvQueue.pop_front(); //移除第一个元素，但不返回
            return true;
        }
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
                std::cout << "outMsgRecvQueue()执行，取出一个元素" << std::endl;
            }
            else
            {
                //消息队列为空
                std::cout << "目前消息队列为空" << i << std::endl;
            }
        }
        std::cout << "end" << std::endl;
    }
private:
    std::list<int> msgRecvQueue; //list容器，用于代表玩家发送给服务器的命令
    std::mutex my_mutex1; //创建一个互斥量
};


int main()
{
    //开发一个网络服务器，假设有两个线程，一个线程收集玩家命令（用一个数字代表玩家发的命令），并把命令数据写到一个队列中，
    // 另一个线程从队列中取出玩家的命令,解析然后执行玩家需要的动作
    //用成员函数作为线程的方法来写线程
    A myobja;
    std::thread myOutMsgObj(&A::outMsgRecvQueue,&myobja); //取对象的地址传参（可以理解为引用）
    std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);

    myInMsgObj.join();
    myOutMsgObj.join();


    //unique_lock的第二个参数
    //1.std::adopt_lock,表示这个互斥量已经被lock了(你必须要把互斥量提前lock)，所以lock_guard不会在构造函数中lock互斥量
    //这种用法与在lock_guard中的用法相同

    std::cout << "I Love China" << std::endl;//最后执行这句，整个进程退出
}