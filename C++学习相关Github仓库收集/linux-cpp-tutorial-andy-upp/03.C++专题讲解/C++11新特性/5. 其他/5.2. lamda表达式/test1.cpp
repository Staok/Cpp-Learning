#include <iostream>

int main()
{
     auto add = [](int a, int b)->int{
         return a + b;
     };
    int ret = add(1,2);
    std::cout << "ret:" << ret << std::endl;
    return 0;
 }


/*
第3至5行为lamda表达式的定义部分

[]：中括号用于控制main函数以内，lamda表达式之前的变量在lamda表达式中的访问形式；
(int a,int b）：为函数的形参
->int：lamda表达式函数的返回值定义
{}:大括号内为lamda表达式的函数体。

*/