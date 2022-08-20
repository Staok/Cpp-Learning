//
// Created by 李光辉 on 2021/1/10.
//

#include <iostream>
using namespace std;

void f()
{
    //在栈内存中存放了一个指向一块堆内存的指针p
    int* p = new int[5];
    delete []p;
}

int main()
{
    f();
}