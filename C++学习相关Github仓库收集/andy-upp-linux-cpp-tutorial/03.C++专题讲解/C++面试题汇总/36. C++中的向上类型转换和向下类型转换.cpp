//https://blog.csdn.net/wangweitingaabbcc/article/details/7720979#

#include <iostream>
using namespace std;

class Base
{
public:
    int b;
    virtual void Test()
    {
        cout << "base" << endl;
    }
};

class Derived:public Base
{
public:
    int d;
    virtual void Test()
    {
        cout << "derived" << endl;
    }
};

int main()
{
    //向上类型转换 子类向基类的类型转换
    //切割：覆盖方法和子类数据丢失的现象生成切割(slice)
    //在向上强制转换过程中，使用指针和引用不会造成切割，而使用直接赋值会造成切割。
    Derived d;
    Base b = d; //直接赋值，产生切割
    b.Test();  //base 切割后子类和父类不再产生关联，所以调用父类自己的方法

    Base& b2 = d; //使用引用赋值（不产生切割）
    b2.Test(); //derived

    Base* b3 = &d; //使用指针赋值（不产生切割）
    b3->Test();//derived

    cout << "======================" << endl;

    /*
    向下强制类型转换
    使用dynamic_cast进行向下强制类型转换。
    使用此关键字有一下几个条件
    1.必须有虚函数
    2.必须打开编译器的RTTI开关
(vc6: progect-> settings -> c/c++ tab ->category[c++ language]-> Enable RTTI)
    3.必须有继承关系
    */

    Base* b1 = new Derived;
    Derived* d1 = dynamic_cast<Derived*>(b1);
    if(!d1)
    {
        cout << "dynamic cast err!" << endl;
    }else
    {
        d1->Test();
    }
    

    return 0;
}