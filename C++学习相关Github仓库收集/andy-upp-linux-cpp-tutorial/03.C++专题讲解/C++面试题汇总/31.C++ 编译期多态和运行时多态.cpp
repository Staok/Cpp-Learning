//https://zhuanlan.zhihu.com/p/147563035
#include<iostream>
/*
编译时期的多态
对模板参数而言，多态是通过模板特例化和函数重载解析实现的。
以不同的模板参数特例化导致调用不同的函数，这就是所谓的编译期多态。
*/

class A1
{
public:
    void Print()
    {
        std::cout << "A1 Print\n" << std::endl;
    }
};

template <typename T>
void TempalteInstance(T& t)
{
    t.Print();
}

void Test1()
{
    A1 a1;
    TempalteInstance(a1);
}

/*
运行时多态
例如多态的使用，函数的调用在运行的时候确定。
*/

class A2
{
public:
    virtual void vFunc()
    {
        std::cout << "A2 vFunc\n" << std::endl;
    }
};


class B2 : public A2
{
public:
    virtual void vFunc()
    {
        std::cout << "B2 vFunc\n" << std::endl;
    }
};

void Test2()
{
    A2* a2 = new B2;
// 在运行期确定指针（或引用）所指对象的真正类型，调用该类型对应的接口b
    a2->vFunc();
}


int main()
{
    //Test1();
    Test2();
    return 0;
}