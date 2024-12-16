//
// Created by 李光辉 on 2021/1/2.
//2.call_once


#include <iostream>
#include <thread>
#include <mutex>
#include <list>
#include <algorithm>
#include <cstring>


using namespace std;


/*

    4. std::call_once()
        功能: 能够保证函数a只会被调用一次。具备解决单例模式下的1次调用
        需要和std::once_flag配合使用(函数调用成功后，会标记std::once_flag为已调用)
*/
std::mutex resource_mutex;
std::once_flag flag;
class MyCAS{   //单例类
private:
    MyCAS(){}
    MyCAS(const MyCAS&){}

private:
    volatile static MyCAS* m_instance;

public:
    volatile static MyCAS* getInstance1() {
        if(m_instance == nullptr) {   //双重锁定
            std::unique_lock<std::mutex> myunlock(resource_mutex);  //自动加锁
            if(m_instance == nullptr) {
                m_instance = new MyCAS();
                static GC  gc;   //利用静态成员变量生命周期来析构内存
            }
        }
        return m_instance;
    }

    volatile static MyCAS* getInstance2() {

        std::call_once(flag, CreatOnce);   //只允许调用一次函数。具备互斥量的作用
        std::chrono::milliseconds dura(20000);
        std::this_thread::sleep_for(dura);


        return m_instance;
    }

    void func() {
        cout << "Test:" << endl;
    }

    static void CreatOnce() {
        m_instance = new MyCAS();
        cout << "getMyCAS Over" << endl;
        static GC gc;
    }

public:
    class GC{
    public:
        ~GC() {
            if(!MyCAS::m_instance) {
                delete MyCAS::m_instance;
                MyCAS::m_instance = nullptr;
            }
        }
    };
};
volatile MyCAS* MyCAS::m_instance = nullptr;  //对静态成员赋初值

static void test_singleton1(void)
{
    volatile MyCAS* pa = MyCAS::getInstance1();
    volatile MyCAS* pb = MyCAS::getInstance1();
    printf("Address of pa is %p\n", pa);
    printf("Address of pb is %p\n", pb);

}



//线程安全的单例模式
void mythread() {
    cout << "Thread Start: " << endl;
    volatile MyCAS* pa = MyCAS::getInstance2();

}


int test_singleton2(void)
{

    std::thread tobj1(mythread);
    std::thread tobj2(mythread);
    tobj1.join();
    tobj2.join();

    cout << "Main Thread End!" << endl;
    return 0;
}


int main(void)
{
    test_singleton1();

    test_singleton2();
    return 0;
}