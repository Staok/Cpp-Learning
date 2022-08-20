//https://blog.csdn.net/u011740322/article/details/10081505
#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        mPtr = new int;
    }
    // ~Base()
    virtual ~Base()
    {
        delete mPtr;
        mPtr = nullptr;
        cout << "Base::Destruction" << endl;
    }
private:
    int* mPtr;
    
};

class Derived:public Base
{
public:
    Derived()
    {
        mDerived = new long;
    }
    ~Derived()
    {
        delete mDerived;
        mDerived = nullptr;
        cout << "Derived::Destruction" << endl;
    }
private:
    long* mDerived;
};


int main()
{
    Base* p = new Derived;
    delete p;
    return 0;
}


/*
如果不将析构函数设置为虚函数
输出结果只有：Base::Destruction
以上代码会产生内存泄露，因为new出来的是Derived类资源，采用一个基类的指针来接收，
析构的时候，编译器因为只是知道这个指针是基类的，所以只将基类部分的内存析构了，
而不会析构子类的，就造成了内存泄露，如果将基类的析构函数改成虚函数，就可以避免这种情况，
因为虚函数是后绑定，其实就是在虚函数列表中，析构函数将基类的析构函数用实际对象的一组析构函数替换掉了，
也就是先执行子类的虚函数再执行父类的虚函数，这样子类的内存析构了，父类的内存也释放了，就不会产生内存泄露。
注：
1.析构函数其实是一个函数，不论子类还是父类，虽然可能看起来名字不一样。而且析构函数执行过程都是执行子类再到父类。
2.多态的时候一定要将析构函数写成虚函数，防止内存泄露，各个子类维护自己内部数据释放。

总结：如果析构函数不写成虚函数，则编译器不知道子类中是否重写了析构函数，导致子类的析构函数无法被调用，内存泄露
如果析构函数写成虚函数，编译器就会知道有子类重写了析构函数，于是先通过this指针找到子类的虚函数指针，调用子类
的虚析构函数，然后再调用父类的析构函数，这样就不会造成内存泄漏。
*/