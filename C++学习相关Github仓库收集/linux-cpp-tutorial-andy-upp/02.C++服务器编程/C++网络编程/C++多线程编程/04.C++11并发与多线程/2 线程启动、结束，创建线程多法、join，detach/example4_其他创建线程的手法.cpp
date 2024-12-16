//
// Created by 李光辉 on 2020/12/29.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <thread>

using namespace  std;


//用类作为可调用对象，
class TA
{


public:
//    int& m_i;
    int m_i;
    TA(int i):m_i(i)
    {
        cout << "TA()构造函数被执行" << endl;
    }

    TA(const TA& ta):m_i(ta.m_i)
    {
        cout << "TA()拷贝构造函数被执行" << endl;
    }

    ~TA()
    {
        cout << "TA()析构构造函数被执行" << endl;
    }
    //operator函数就是入口点
    void operator ()() //重载括号运算符，不能带参数
    {
//      cout << "我的operator()函数开始执行了" <<  endl;
//      //...
//      cout << "我的operator()函数结束执行了" <<  endl;

        cout << "mi_1的值为：" << m_i << endl;
        cout << "mi_2的值为：" << m_i << endl;
        cout << "mi_3的值为：" << m_i << endl;
        cout << "mi_4的值为：" << m_i << endl;
        cout << "mi_5的值为：" << m_i << endl;
        cout << "mi_6的值为：" << m_i << endl;
    }
};


int main()
{
    /*
   //用类创建线程
   int my_i = 6;
    //这里的问题是，如果如果是引用传参，主线程结束，my_i被销毁，那么在子线程当中的my_i 引用就会产生不可预料的后果
    TA ta(my_i);
   //主线程结束了，主线程中的ta会被销毁，子线程中的ta对象不会被销毁，因为ta是被复制到子线程当中去的
   thread myobj(ta); //ta:可调用对象
   myobj.join();
   //myobj.detach();
   */


   //用lambda表达式创建线程,没有参数和返回值小括号可以省略
   auto mylamthread = []{
       cout << "我的线程3开始执行了" << endl;
       //...
       cout << "我的线程3结束了" << endl;
   };

   thread myobj(mylamthread);
   //myobj.join();
   myobj.detach();

    cout << "I Love China1" << endl;
    return 0;
}
