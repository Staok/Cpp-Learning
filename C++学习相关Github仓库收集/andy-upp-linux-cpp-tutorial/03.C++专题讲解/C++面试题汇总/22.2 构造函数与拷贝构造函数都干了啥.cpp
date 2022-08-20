//https://blog.csdn.net/wufeifan_learner/article/details/88986949

//而隐式调用拷贝构造函数的时候，我们称之为“浅拷贝”。
//但是，请注意一点，并不是说显示调用就是“深拷贝”，而是如果要深拷贝一定要显示调用。


#include<iostream>
using namespace std;

class A
{
public:
    A(int b):a(b)
    {
        cout << "构造函数" << endl;
    }
    A(const A& c)
    {
        a = c.a;
        cout << "拷贝构造函数" << endl;
    }

    ~A()
    {
        cout << "析构函数" << endl;
    }
    void newA(A b)
    {
        cout << "bbbbb" << endl;
    }

private:
    int a;
};

int main()
{
    A a(1000); //调用构造函数
    A b = a; //调用拷贝构造函数
    a.newA(a); //调用拷贝构造函数
    return 0;
}