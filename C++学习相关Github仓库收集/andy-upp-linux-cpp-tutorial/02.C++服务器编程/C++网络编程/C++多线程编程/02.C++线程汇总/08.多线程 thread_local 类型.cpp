/*
thread_local变量是C++ 11新引入的一种存储类型。
thread_local关键字修饰的变量具有线程周期(thread duration)，
这些变量(或者说对象）在线程开始的时候被生成(allocated)，
在线程结束的时候被销毁(deallocated)。
并且每 一个线程都拥有一个独立的变量实例(Each thread has its own instance of the object)。
thread_local 可以和static 与 extern关键字联合使用，这将影响变量的链接属性(to adjust linkage)。
*/

#include <iostream>
#include <thread>

struct S
{
    S() {
      printf("S() called i=%d\n", i);
    }
    int i = 0;
};

//thread_local S gs;
S gs;

void foo()
{
  gs.i += 1;
  printf("foo  %p, %d\n", &gs, gs.i);
}

void bar()
{   
  gs.i += 2;
  printf("bar  %p, %d\n", &gs, gs.i);
}

int main()
{
  std::thread a(foo), b(bar);
  a.join();
  b.join();
}