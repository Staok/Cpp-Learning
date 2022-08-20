/*
std::call_once的特点：即使有多个线程要访问同一个函数，只有一个线程会成功。
std::call_once的用途：当某个数据只有在初始化的时候需要线程安全的时候，
使用std::once是最安全和恰当的做法。
注意：std::once_flag的生命周期一定要长于std::call_once的线程的声明周期，
所以一般把std::once_flag声明为全局变量。
*/


#include <iostream>
#include <thread>
#include <mutex>
 
std::once_flag flag;
 
void do_once()
{
    std::call_once(flag, [](){ std::cout << "Called once" << std::endl; });
}
 
int main()
{
    std::thread t1(do_once);
    std::thread t2(do_once);
    std::thread t3(do_once);
    std::thread t4(do_once);
 
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}