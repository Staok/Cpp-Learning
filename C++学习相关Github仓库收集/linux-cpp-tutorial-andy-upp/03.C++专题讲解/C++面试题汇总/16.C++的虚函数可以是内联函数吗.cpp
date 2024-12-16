//https://zhuanlan.zhihu.com/p/256202496
/*
当使用类的对象来调用时，则虚函数可以当做是内联的，因为编译器在编译时就确切知道对象是哪个类的；
但当使用基类指针或引用来调用虚函数时，它都不能是内联函数，因为调用发生在运行时，是动态绑定的。
*/

#include <iostream>
using namespace std;

class Base
{
public:
    inline virtual void Display()
    {
        cout << "Base: Display" << endl;
    }
};

class Derived: public Base
{
public:
    inline virtual void Display()
    {
        cout << "Derived: Display" << endl;
    }
};

int main()
{
    // 这里的虚函数是通过具体对象调用的, 可以是内联的
    Base b;
    b.Display();
    Derived d;
    d.Display();

    // 这里的虚函数是通过基类指针调用的, 不能是内联的
    Base* bp = new Derived();
    bp->Display();
    delete bp;
    bp = nullptr;

    return 0;
}