//https://blog.csdn.net/zyl_1102179268/article/details/60370626
//https://zhuanlan.zhihu.com/p/67762401
/*
这种情况有四种：
（1）如果一个类没有任何构造函数，但是有一个成员对象，它有默认构造函数。但是编译器产生默认构造函数只有在构造真正需要的时候才发生。
（2）有一个含有默认构造函数的基类。那么编译器将会生成一个默认构造函数，调用上层基类的构造函数。
（3）含有虚函数。
（4）有一个虚基类。

需要注意的是，编译器在这四种情况下合成的构造函数只满足编译器的需要！！！而不是程序的需要。
至于没有这四种情况而且没有默认构造函数时，它所拥有的只是默认的trivial（无用的）构造函数，实际上并不被合成出来。
具体可以参考《深度探索C++对象模型》一书chapter2.1 Default Constructor的建构操作
*/
#include<iostream>
using namespace std;

//情况1 如果某个类含有类对象数据成员，该类对象类型有默认构造函数
class A1
{
public:
    A1()
    {
        cout << "A1()" << endl;
    }
};

class B1
{
public:
   //B1类含有类对象数据成员a1，则B1类有默认构造函数
    A1 a1;
    int num;
};

void Test1()
{
    B1 b1;
    cout << b1.num << endl;
}

//情形2 其基类带有默认构造函数的派生类，派生类会生成默认构造函数
class Base
{
public:
   //这里不算是默认构造函数吧？
    Base()
    {
        cout << "Base()" << endl;
    }
};

class Derived : public Base
{
public:
    int d;
};

void Test2()
{
    Derived d;
}

//3.带有虚函数的类

class Foo
{
public:
    virtual void func(){}
};


void Test3()
{
    Foo f;
}


//4.带有虚基类的类
class X{};
class A4 : public virtual X{};

void Test4()
{
    A4 a4;
}

/*
总结一下： 不符合以上4种情形的而且没有声明任何构造函数的，编译器并不会合成默认的构造函数；
并且合成的默认构造函数并不会初始化类的内置类型复合类型的数据成员。
*/

int main()
{
    //Test1();
    //Test2();
    //Test3();
    Test4();
    return 0;
}