//修改前
#include <iostream>
#include "Test.h"
//假如我们的需求是让Test里面的Add由外部实现，如main.cpp里面的add函数，有什么方法呢？
//没错，我们可以用函数指针。

int add(int a,int b)
{
    return a + b;
}

//假如add实现是在另外一个类内部,这个时候std::function和std::bind就帮上忙了。


class TestAdd
{
public:
    void Add(std::function<int(int, int)> fun, int a, int b)
    {
        int sum = fun(a, b);
        std::cout << "sum:" << sum << std::endl;
    }
};


int main()
{

    Test test;
    test.Add(add, 1, 2);


    TestAdd testAdd;
    test.Add(std::bind(&TestAdd::Add, testAdd, std::placeholders::_1, std::placeholders::_2), 1, 2);

    return 0;
}


