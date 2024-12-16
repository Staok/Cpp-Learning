//https://www.cnblogs.com/xiaoshiwang/p/9752001.html
#include <iostream>
#include <thread>

using namespace std;


class my_thread
{
public:
    explicit my_thread(thread& t_):t(t_){}

    ~my_thread()
    {
        //调用join前，必须要先判断是不是joinable。这很重要，因为只能join一次，多次join就会出错误。
        if(t.joinable())
        {
            t.join();
        }
    }
    //拷贝构造函数和赋值运算符被标记成delete了，确保它们不会被编译器自动提供。
    //复制或赋值一个thread对象是很危险的，因为它可能比它要结合的线程的作用域存在更久。
    my_thread(my_thread const& ) = delete; 
    my_thread operator= (const my_thread&) = delete;
private:
    thread& t;
};

class func
{
public:
    func(int& d):data(d)
    {
        cout << "func" << endl;
    }

    void operator()()
    {
        cout << "thread started!" << endl;
        for(unsigned j = 0; j < 100; ++j)
        {
            cout << j << endl;
        }
    }
private:
    int& data;
};

int main(){
    int state = 0;
    func f(state);

    thread t(f);//子线开始执行

    //join：主线程等待join线程结束后，主线程才结束。
    //detach：主线程不等待detach线程。使用detach的话，直接在std::thread t(fun);后面加上t.detach()即可
    
    //若发生异常，则此处不会被执行
    //t.join();

    my_thread mt(t);
    //若在此处发生异常，则mt的析构函数会被调用，join函数被调用
}//此处局部对象会被销毁，所以mt的析构函数就会被调用，join函数被调用