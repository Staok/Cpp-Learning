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
//    mutable int m_i; //mutable说明即使在const限定中，也可以修改m_i的值
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


void myprint2(A& pmybuf)
{
    //我们修改该值，不会影响到main函数，虽然是引用传参，但是为了数据安全，此处会用拷贝构造
    //子线程中的参数传递，不管是引用还是值，默认会拷贝一份数据传参数
    pmybuf.m_i = 199;
    cout <<"子线程myprint2的参数地址是：" << &pmybuf << endl;//打印 pmybuf类对象的地址
    return;
}

int main()
{

    A myobj(10);
    //thread mytobj(myprint2, myobj); //将类对象作为线程的参数,调用拷贝构造函数

    //如果强制引用传参数，需要使用ref
    thread mytobj(myprint2, ref(myobj)); //将类对象作为线程的参数，不会调用拷贝构造函数

    mytobj.join();
    cout <<"修改后的m_i: " <<  myobj.m_i << endl;

    return 0;
}
