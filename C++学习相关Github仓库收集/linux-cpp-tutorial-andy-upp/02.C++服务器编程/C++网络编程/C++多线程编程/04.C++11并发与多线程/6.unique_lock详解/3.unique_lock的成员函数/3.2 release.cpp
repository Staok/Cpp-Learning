//
// Created by 李光辉 on 2020/12/30.
//3.2 release

#include <map>
#include <string>
#include <thread>
#include <list>
#include <mutex>
#include <iostream>
#include <vector>

using namespace  std;
/*
    4. unique_lock所有权的传递
            std::unique_lock<std::mutex> sg(my_mutex);
            sg拥有my_mutex的所有权
            sg对象可以将my_mutex的所有权可以转移给sgg，但是不能复制
            std::unique_lock<std::mutex>  ssg(std::move(sg));  //所有权转移，和unique_ptr独占类型智能指针类似
            在函数中return一个局部unique_lock变量，发生移动构造函数(和unique_ptr类似)
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
            std::unique_lock<std::mutex>   tmp_guard1(my_mutex1);
            mutex* ptx = tmp_guard1.release(); //解除绑定后，需要自己解锁my_mutex1
            msgRecvQueue.push_back(i);
            ptx->unlock();//自己负责my_mutex1的unlock
        }
        return;
    }

    bool outMsgLULProc(int& command)
    {
        std::unique_lock<std::mutex>   tmp_guard1(my_mutex1);
        std::chrono::milliseconds dura(200); //休息200毫秒
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
    A myobja;
    std::thread myOutMsgObj(&A::outMsgRecvQueue,&myobja); //取对象的地址传参（可以理解为引用）
    std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);

    myInMsgObj.join();
    myOutMsgObj.join();


    std::cout << "I Love China" << std::endl;//最后执行这句，整个进程退出
}