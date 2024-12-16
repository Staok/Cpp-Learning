//https://blog.csdn.net/henrytien/article/details/80064863
//在构造函数中调用
#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        Function();
    }

    virtual void Function()
    {
        cout << "Base::Function" << endl;
    }

};

class A : public Base
{
public:
    A()
    {
        Function();
    }
    virtual void Function()
    {
        cout << "A::Function" << endl;
    }
};

int main()
{
    //因为父类对象会在子类之前进行构造，此时子类部分的数据成员还未初始化，因此调 
    //用子类的虚函数时不安全的，故而 C++不会进行动态联编；   
    A a;
}