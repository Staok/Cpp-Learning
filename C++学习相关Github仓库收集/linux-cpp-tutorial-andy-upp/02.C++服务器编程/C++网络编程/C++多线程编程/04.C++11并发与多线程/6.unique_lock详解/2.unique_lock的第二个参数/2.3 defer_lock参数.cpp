//
// Created by 李光辉 on 2020/12/30.
//2.3 defer_lock参数

#include <map>
#include <string>
#include <thread>
#include <list>
#include <mutex>
#include <iostream>
#include <vector>

/*
         2.3 std::defer_lock(不能提前lock)
            std::unique_lock<std::mutex> ulock(my_mutex_a, std::defer_lock);
            初始化了一个没有加锁的mutex，可以配合unique_lock的成员函数
*/


class A
{
public:
    //把收到的消息(玩家命令)入到一个队列的线程
    void inMsgRecvQueue()
    {
        for(int i = 0; i < 100000; ++i)
        {
            std::cout << "inMsgReceiveQueue 执行，插入一个元素" << i << std::endl;
            std::unique_lock<std::mutex>   tmp_guard1(my_mutex1,std::defer_lock);//没有加锁的my_mutex1
            tmp_guard1.lock();//不用自己解锁
            tmp_guard1.unlock();//临时解锁，处理一些非共享代码
            tmp_guard1.lock();//再次加锁
            msgRecvQueue.push_back(i);
        }
        return;
    }

    bool outMsgLULProc(int& command)
    {
        std::unique_lock<std::mutex>   tmp_guard1(my_mutex1);
//        std::chrono::milliseconds dura(2000); //休息2秒
//        std::this_thread::sleep_for(dura);//休息一定的时长

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
    A myobja;
    std::thread myOutMsgObj(&A::outMsgRecvQueue,&myobja); //取对象的地址传参（可以理解为引用）
    std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);

    myInMsgObj.join();
    myOutMsgObj.join();


    std::cout << "I Love China" << std::endl;//最后执行这句，整个进程退出
}