//https://www.cnblogs.com/yinwei-space/p/12708871.html

/*
类模版std::function是一种通用、多态的函数封装。std::function的实例可以对任何可以
调用的目标实体进行存储、复制、和调用操作，这些目标实体包括普通函数、Lambda表达式、函数指针、
以及其它函数对象等。std::function对象是对C++中现有的可调用实体的一种类型安全的
包裹（我们知道像函数指针这类可调用实体，是类型不安全的）。

通常std::function是一个函数对象类，它包装其它任意的函数对象，被包装的函数对象具有类型
为T1, …,TN的N个参数，并且返回一个可转换到R类型的值。std::function使用 模板转换构造函
数接收被包装的函数对象；特别是，闭包类型可以隐式地转换为std::function。

最简单的理解就是：
　　　通过std::function对C++中各种可调用实体（普通函数、Lambda表达式、函数指针、以及其它
函数对象等）的封装，形成一个新的可调用的std::function对象；让我们不再纠结那么多的可调用实体。
一切变的简单粗暴。
std::function 最大的用处是函数回调；

*/

#include <functional>
#include <iostream>
using namespace std;
 
std::function< int(int)> Functional;
 
// 普通函数
int TestFunc(int a)
{
    return a;
}
 
// Lambda表达式
auto lambda = [](int a)->int{ return a; };
 
// 仿函数(functor)
class Functor
{
public:
    int operator()(int a)
    {
        return a;
    }
};
 
// 1.类成员函数
// 2.类静态函数
class TestClass
{
public:
    int ClassMember(int a) { return a; }
    static int StaticMember(int a) { return a; }
};
 
int main()
{
    // 普通函数
    Functional = TestFunc;
    int result = Functional(10);
    cout << "普通函数："<< result << endl;
 
    // Lambda表达式
    Functional = lambda;
    result = Functional(20);
    cout << "Lambda表达式："<< result << endl;
 
    // 仿函数
    Functor testFunctor;
    Functional = testFunctor;
    result = Functional(30);
    cout << "仿函数："<< result << endl;
 
    // 类成员函数
    TestClass testObj;
    Functional = std::bind(&TestClass::ClassMember, testObj, std::placeholders::_1);
    result = Functional(40);
    cout << "类成员函数："<< result << endl;
 
    // 类静态函数
    Functional = TestClass::StaticMember;
    result = Functional(50);
    cout << "类静态函数："<< result << endl;
 
    return 0;
}