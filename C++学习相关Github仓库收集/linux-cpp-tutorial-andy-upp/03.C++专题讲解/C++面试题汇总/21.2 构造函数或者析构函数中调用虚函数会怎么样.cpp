#include <iostream>
using namespace std;

class A
{
public:
    virtual void show()
    {
        cout << "in A" << endl;
    }
    //在调用基类的析构函数时，派生类对象的数据成员已经 
	//销毁，这个时候再调用子类的虚函数没有任何意义。
    virtual ~A()
    {
        show();
    }
};

class B : public A
{
public:
    void show()
    {
        cout << "in B" << endl;
    }
};


int main()
{
    A a;
    B b;
}