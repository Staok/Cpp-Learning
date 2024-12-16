//C++将对象数组的内存分配作为一个单独的操作，而不同于单个对象的内存分配。
//为了改变这种方式，你同样需要重载new[ ] 和 delete[ ]操作符。
#include<iostream>
using namespace std;

class TestClass
{
public:
    TestClass()
    {
        cout << "构造函数" << endl;
    }
    ~TestClass()
    {
        cout << "析构函数" << endl;
    }

    void* operator new[](size_t size);
    void operator delete[](void* p);
};

void* TestClass::operator new[](size_t size)
{
    //new[]操作符中的个数参数是数组的大小加上额外的存储对象数目的一些字节
    //关于size_t https://blog.csdn.net/qq_41598072/article/details/84924997?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.control
    cout << "重载new class,size = " << size << endl;
    void* p = malloc(size);
    return p;
}

void TestClass::operator delete[](void* p)
{
    cout << "重载 delete class" << endl;
    free(p);
}

int main(void)
{
    TestClass* p = new TestClass[3];
    delete[] p;
    return 0;
}

/*
重载new class,size = 11
构造函数
构造函数
构造函数
析构函数
析构函数
析构函数
重载 delete class
*/

