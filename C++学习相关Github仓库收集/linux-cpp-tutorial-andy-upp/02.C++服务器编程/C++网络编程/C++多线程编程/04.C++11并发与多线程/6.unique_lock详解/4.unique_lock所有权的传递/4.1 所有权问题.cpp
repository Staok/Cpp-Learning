//
// Created by 李光辉 on 2020/12/30.
//4.1 所有权问题

#include <map>
#include <string>
#include <thread>
#include <list>
#include <mutex>
#include <iostream>
#include <vector>

using namespace  std;
/*
    3. unique_lock的成员函数
        unique_lock绑定mutex,并管理该mutex
        3.1 lock()
           加锁，不需要担心手动解锁问题
        3.2 unlock()
           灵活控制解锁的时间(unique_lock和lock_guard一样在生命期内构造和释放)
        3.3 try_lock()
            尝试给互斥量加锁，如果拿不到锁返回false，拿到了返回true(不阻塞)
        3.4 release()
            返回所管理的mutex对象指针，并释放所有权(即unique_lock和mutex无关系)
            严格区分release和unlock的区别：
            std::unique_lock初始化操作是将unique锁和Mutex互斥量绑定在一起，而lock，unlock只是其中的操作，
            release相当于将两个对象分开，因此release之后一定要自行管理mutex互斥量(解锁)
            std::unique_lock<std::mutex> mytex(my_mutex_a);
            std::mutex *sp = mytex.release();
            sp.unlock();
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
            std::unique_lock<std::mutex>   tmp_guard2(std::move(tmp_guard1));//移动语义，相当于my_mutex1和tmp_guard2绑定到一起
                                                                        //现在tmp_guard1指向空，tmp_guard2指向my_mutex1
            msgRecvQueue.push_back(i);
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