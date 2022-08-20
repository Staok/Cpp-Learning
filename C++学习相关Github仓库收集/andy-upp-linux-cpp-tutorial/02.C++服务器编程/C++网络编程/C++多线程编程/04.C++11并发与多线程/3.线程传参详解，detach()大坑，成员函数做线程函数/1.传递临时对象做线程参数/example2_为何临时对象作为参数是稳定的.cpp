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
    int m_i;
    //这个构造函数也是类型转换构造函数，可以把一个整形数字转成类A的对象
    A(int m):m_i(m)
    {
        cout << "构造函数执行！" << this << endl;
    }

    A(const A& a):m_i(a.m_i)
    {
        cout << "拷贝构造函数执行" << this << endl;
    }

    ~A()
    {
        cout << "析构函数执行" << this << endl;
    }
};



void myprint(const int i, const A& pmybuf)
{
    cout << &pmybuf << endl;//打印 pmybuf类对象的地址
    return;
}

int main()
{
    int mvar = 1;
    int mysecondpar = 12;

    //thread mytobj(myprint, mvar, mysecondpar); //我们是希望mysecondpar转成A类型对象，传递给myprint的第二个参数
    thread mytobj(myprint, mvar, A(mysecondpar)); //用A的临时对象转化，可以解决问题1，因为在main函数执行结束之前，已经先构造类A对象，传递到线程去了


    //mytobj.join(); 这种写法没问题
    mytobj.detach();//问题1：改成detach会有问题，主线程与子线程分离，主线程退出，则mysecondpar会被销毁，导致失效
                    //在创建线程同时，构造临时对象的方法传递参数是可行的
    //cout << "I Love China!" << endl;

    return 0;
}

/*
1.3总结 使用detach()时

如果传递int这种简单类型，推荐使用值传递，不要用引用
如果传递类对象，避免使用隐式类型转换，全部都是创建线程这一行就创建出临时对象，然后在函数参数里，用引用来接，否则还会创建出一个对象
终极结论：建议不使用detach

 */



