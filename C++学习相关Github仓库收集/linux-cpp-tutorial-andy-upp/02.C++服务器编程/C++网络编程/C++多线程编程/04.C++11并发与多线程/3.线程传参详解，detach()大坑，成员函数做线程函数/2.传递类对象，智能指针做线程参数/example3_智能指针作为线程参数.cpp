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
};


void myprint2(unique_ptr<int> pzn)
{
    //我们修改该值，不会影响到main函数，虽然是引用传参，但是为了数据安全，此处会用拷贝构造
    //子线程中的参数传递，不管是引用还是值，默认会拷贝一份数据传参数
//    pmybuf.m_i = 199;
//    cout <<"子线程myprint2的参数地址是：" << &pmybuf << endl;//打印 pmybuf类对象的地址
    return;
}

int main()
{
    unique_ptr<int> myp(new int(100)); //创建一个整形独占式指针
    thread mytobj(myprint2, move(myp)); //move将myp指针转到线程pzn中去，转完之后，myp为空，由pzn指向 new int(100)

    mytobj.join(); // 注意此处不能用detach()

    return 0;
}
