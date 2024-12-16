/*
在用 dynamic_cast 进行从多态基类对象（或引用）到派生类的引用的强制类型转换时，
如果转换是不安全的，则会拋出此异常。
*/

#include<iostream>
#include<stdexcept>
using namespace std;

class Base
{
    virtual void func(){}
};

class Derived:public Base 
{
public:
    void Print(){}
};

//在 PrintObj 函数中，通过 dynamic_cast 检测 b 是否引用的是一个 
//Derived 对象，如果是，就调用其 Print 成员函数；如果不是，
//就拋出异常，不会调用 Derived::Print。

void PrintObj(Base& b)
{
    try{
        Derived& rd = dynamic_cast<Derived& >(b);
        //此转换若不安全，会拋出 bad_cast 异常
        rd.Print();
    }catch(bad_cast& e){
        cerr << e.what() << endl;
    }
}

int main()
{
    Base b;
    PrintObj(b);
    return 0;
}