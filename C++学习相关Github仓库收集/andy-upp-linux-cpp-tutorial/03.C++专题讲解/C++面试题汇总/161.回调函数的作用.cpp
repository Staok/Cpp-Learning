//回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一个函数，
//当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该函数的实现方直接调用，
//而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应。

#include <stdio.h>

typedef void (*fp)(int);
//定义函数指针
fp back_up;

void callback1(int a)
{
    printf("callback1 %d\n",a);
}

void callback2(int a){
    printf("callback2 %d\n",a);
}

//这个函数中触发了回调函数的执行条件
void run(int param)
{
    back_up(param);
}

//这个函数的作用就是将回调函数与特定条件联系在一起，
//此处当别的函数调用back_up时，满足执行条件，触发
//回调函数
void reg(fp callback)
{
    back_up = callback;
}

int main(){
    //这个函数中注册了回调函数callback1，
    //只有当满足条件时才执行
    reg(callback1);
    //满足条件，执行回调函数
    run(1);
    run(2);
}