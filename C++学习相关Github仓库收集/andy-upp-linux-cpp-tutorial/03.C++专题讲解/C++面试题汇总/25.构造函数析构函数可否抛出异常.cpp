//https://www.cnblogs.com/fly1988happy/archive/2012/04/11/2442765.html
//https://blog.csdn.net/isunbin/article/details/99590165
/*

不建议在构造函数中抛出异常。当构造函数中抛出异常时，析构函数将不会被执行，需要手动释放内存。析构函数不应该抛出异常。

more effective c++提出两点理由（析构函数不能抛出异常的理由）：

1）如果析构函数抛出异常，则异常点之后的程序不会执行，如果析构函数在异常点之后执行了某些必要的动作比如释放某些资源，
则这些动作不会执行，会造成诸如资源泄漏的问题。
2）通常异常发生时，c++的机制会调用已经构造对象的析构函数来释放资源，此时若析构函数本身也抛出异常，
则前一个异常尚未处理，又有新的异常，会造成程序崩溃的问题。

因此，当析构函数中有一些可能发生的异常时，这时候要把可能发生的异常完全封装在析构函数内部，决不能让它抛出到函数之外。
*/

#include<iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "construction fun" << endl;
        throw 1;
    }

    ~A()
    {
        cout << "destruction fun" << endl;
        throw 2;
    }
};

int main()
{
    try
    {
        A a;
    }
    catch(...) //catch all
    {
        cout << "caught!" << endl;
    }
    return 0;
}