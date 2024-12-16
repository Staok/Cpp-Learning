//
// Created by 李光辉 on 2021/1/10.
//

#include <iostream>
using namespace std;

//这段代码可以代替默认的操作符来满足内存分配的请求。出于解释C++的目的，我们也可以直接调用malloc() 和free()。
void* operator new(size_t size)
{
    cout << "调用重载的new"  << endl;
    void *p = malloc(size);
    return (p);
}

void operator delete(void *p)
{
    cout << "调用重载的delete" << endl;
    free(p);
}

//-------------------------------------------
//所有TestClass对象的内存分配都采用这段代码。更进一步，
//任何从TestClass继承的类也都采用这一方式，除非它自己也重载了new和delete操作符。
class TestClass {
public:
    void* operator new(size_t size);
    void operator delete(void *p);
// .. other members here ...
};

void* TestClass::operator new(size_t size)
{
    cout << "调用类的内存分配" << endl;
    void *p = malloc(size); // Replace this with alternative allocator
    return (p);
}

void TestClass::operator delete(void *p)
{
    cout << "调用类的析构" << endl;
    free(p); // Replace this with alternative de-allocator
}


int main()
{
    int* p = new int(5);
    delete p;

    //---------------------
    TestClass* tc = new TestClass();
    delete tc;
    return 0;
}


