//https://www.jianshu.com/p/ddd1970633ee

/*
函数中的静态变量
当变量声明为static时，空间将在程序的生命周期内分配。
即使多次调用该函数，静态变量的空间也只分配一次，
前一次调用中的变量值通过下一次函数调用传递。
这对于在C/C ++或需要存储先前函数状态的任何其他应用程序非常有用。
*/

#include<iostream>
#include<string>
using namespace std;

void demo()
{
    static int count = 0; //静态变量
    cout << count << " ";
    ++count;
}

int main()
{
    for(int i = 0; i < 5; ++i)
        demo();
    return 0;
}