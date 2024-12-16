//
// Created by 李光辉 on 2020/12/29.
//

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


    void thread_work(int num)
    {
        cout << "子线程thread_work执行" << this <<"线程id: " << this_thread::get_id() << endl;
    }

    void operator()(int num)
    {
        cout << "子线程 （） 执行" << endl;
    }
};


void myprint2(unique_ptr<int> pzn)
{
    //我们修改该值，不会影响到main函数，虽然是引用传参，但是为来数据安全，此处会用拷贝构造
    //子线程中的参数传递，不管是引用还是值，默认会拷贝一份数据传参数
//    pmybuf.m_i = 199;
//    cout <<"子线程myprint2的参数地址是：" << &pmybuf << endl;//打印 pmybuf类对象的地址
    return;
}

int main()
{

     A myobj(10); //生成一个类A的对象
     //thread mytobj(&A::thread_work,myobj,15);//成员函数指针作为线程参数
     thread mytobj(myobj,15); //重载的（）作为线程参数
     mytobj.join();

    return 0;
}
