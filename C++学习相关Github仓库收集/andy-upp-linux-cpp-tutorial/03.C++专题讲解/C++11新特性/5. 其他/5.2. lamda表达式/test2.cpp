#include<iostream>
#include "Test.h"
//我使用lamda表达式修改5.1中的例子看看：



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

    // TestAdd testAdd;
    // test.Add(std::bind(&TestAdd::Add, testAdd, std::placeholders::_1, std::placeholders::_2), 1, 2);

    test.Add([](int a, int b)->int {
        std::cout << "lamda add fun" << std::endl;
        return a + b;
    },1,2);
    return 0;
}