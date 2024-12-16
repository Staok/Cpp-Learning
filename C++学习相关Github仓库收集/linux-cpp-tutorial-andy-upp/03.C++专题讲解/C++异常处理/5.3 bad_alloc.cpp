//在用 new 运算符进行动态内存分配时，如果没有足够的内存，则会引发此异常。

#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    try {
        char * p = new char[0x7fffffff];  //无法分配这么多空间，会抛出异常
    }
    catch (bad_alloc & e)  {
        //此处没有打印异常，猜测是64位操作系统里面虚拟内存的原因，new内存无上限
        cerr << e.what() << endl;
    }
    return 0;
}