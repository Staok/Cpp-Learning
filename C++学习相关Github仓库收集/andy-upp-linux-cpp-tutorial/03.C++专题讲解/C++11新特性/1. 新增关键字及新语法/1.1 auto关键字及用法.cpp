#include <iostream>
#pragma once


//auto 可以做什么
//auto并没有让C++成为弱类型语言，也没有弱化变量什么，只是使用auto的时候，编译器根据上下文情况，确定auto变量的真正类型。
auto AddTest(int a, int b) 
{
    return a + b;
}
//是的，你没看错auto在C++14中可以作为函数的返回值，因此auto AddTest(int a, int b)的定义是没问题的。


//auto不能做什么？
//auto作为函数返回值时，只能用于定义函数，不能用于声明函数。

// class Test
// {
// public:
//     auto TestWork(int a ,int b);
// };
//如下函数中，在引用头文件的调用TestWork函数是，编译无法通过。
//但如果把实现写在头文件中，可以编译通过，因为编译器可以根据函数实现的返回值确定auto的真实类型。
//如果读者用过inline类成员函数，这个应该很容易明白，此特性与inline类成员函数类似。



int main()
{   
    auto index = 10;
    auto str = "abc";
    auto ret = AddTest(1,2);
    std::cout << "index:" << index << std::endl;
    std::cout << "str:" << str << std::endl;
    std::cout << "res:" << ret << std::endl;
}

