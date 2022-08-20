//
// Created by 李光辉 on 2020/12/29.
//

//线程id概念: id是个数字，每个线程（不管是主线程还是子线程）实际上都对应着一个数字，不同的线程对应的线程id必然不同
//线程id可以用C++标准库里面的函数 std::this_thread::get_id()来获取；

#include <iostream>
#include <thread>
using namespace std;

//自己实现类做求证
class A
{
public:
    int m_i;
    //这个构造函数也是类型转换构造函数，可以把一个整形数字转成类A的对象
    A(int m):m_i(m)
    {
        cout << "构造函数执行！" << this <<"线程id: " << this_thread::get_id() << endl;
    }
    A(const A& a):m_i(a.m_i)
    {
        cout << "拷贝构造函数执行" << this <<"线程id: " << this_thread::get_id() << endl;
    }
    ~A()
    {
        cout << "析构函数执行" << this <<"线程id: " << this_thread::get_id() << endl;
    }
};


void myprint2(const A& pmybuf)
{
    cout <<"子线程myprint2的参数地址是：" << &pmybuf << endl;//打印 pmybuf类对象的地址
    return;
}

int main()
{

    cout << "主线程id是" <<this_thread::get_id() <<  endl;
    int mvar = 1;
    //通过测试线程id，发现A构造函数的线程id与main()函数线程id相同，说明临时对象在main函数结束之前已经构造
    thread mytobj(myprint2, A(mvar));
    mytobj.join();
    return 0;
}
