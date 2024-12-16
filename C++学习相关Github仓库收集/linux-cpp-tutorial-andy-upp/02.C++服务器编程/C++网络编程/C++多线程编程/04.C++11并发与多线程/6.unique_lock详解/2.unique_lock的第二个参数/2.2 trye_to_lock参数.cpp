//
// Created by 李光辉 on 2021/1/2.
// 2.2 trye_to_lock参数

#include <iostream>
#include <algorithm>
#include <mutex>
#include <thread>
#include <vector>
#include <list>

using namespace std;

/*

        2.2 std::try_to_lock(不能提前lock)
            std::unique_lock<std::mutex>  ulock(my_mutex, std::try_to_lock);
            尝试用mutex的lock去锁定mutex，但是如果没有锁定成功，也会立即返回而不会阻塞。(前提是:自己
            不能提前lock,这样就相当于锁两次了，会导致程序卡死)
            if(myulock.owns_lock()) {}   //检查是否拿到锁

*/

class Game_new{

private:
    std::mutex my_mutex_a;
    std::mutex my_mutex_b;
    std::list<int> order;

public:
    void inMsgRecQueue() {
        for(int i =0; i < 10000; i ++) {

            std::unique_lock<std::mutex> myulock(my_mutex_a, std::try_to_lock);
            if(myulock.owns_lock()) {  //尝试拿到锁
                cout << "inMsgRecQueue Start----Insert Msg: " << i << endl;
                order.push_back(i);
            }else {
                cout << "inMsgRecQueue Failed to Lock" << endl;
                cout << "没有拿到锁，尝试干别的事情" << endl;
            }

//
//            if(ulock.try_lock()) {
//
//                cout << "inMsgRecQueue Start----Insert Msg: " << i << endl;
//                order.push_back(i);
//            }else {
//                cout << "inMsgRecQueue Failed to Lock" << endl;
//            }
            //my_mutex_a.unlock();
        }
    }


    bool  _outMsgRecQueue() {

        //my_mutex_a.lock();
        std::unique_lock<std::mutex> myulock(my_mutex_a);
        //std::unique_lock<std::mutex> myulock(my_mutex_a, std::adopt_lock);
        //std::unique_lock<std::mutex> myulock(my_mutex_a, std::try_to_lock);

        std::chrono::milliseconds dura(2000);
        std::this_thread::sleep_for(dura);   //睡眠20秒

        if(!order.empty()) {
            cout << "outMsgRecQueue Start-----Pop Msg: " << order.front() << endl;
            order.pop_front();
            //my_mutex_a.unlock();
            return true;
        }else {
            //my_mutex_a.unlock();
            return false;
        }
    }

    void outMsgRecQueue() {

        for(int i =0 ; i < 10000; i ++) {
            bool result = _outMsgRecQueue();
            if(!result) {
                cout<< "Queue Empty Now!" << endl;
            }
        }
        return;
    }

};



int main(void)
{

    Game_new ga;
    thread out(&Game_new::outMsgRecQueue, &ga);
    thread in(&Game_new::inMsgRecQueue, &ga);

    in.join();
    out.join();

    cout << "MainThread End!" << endl;
    return 0;
}