//https://www.cnblogs.com/yocichen/p/10561615.html

/*
1） 任意时刻unique_ptr只能指向某一个对象，指针销毁时，指向的对象也会被删除
    （通过内置删除器，通过调用析构函数实现删除对象）
2）禁止拷贝和赋值（底层实现拷贝构造函数和复制构造函数 = delete），
    可以使用std::move()、unique_ptr.reset(...) 转移对象指针控制权。

（由1决定，指针发生了拷贝就违反了第一条）
*/

#include <iostream>
#include <memory>
using namespace std;

// unique_ptr::get vs unique_ptr::release
int main()
{
    std::unique_ptr<int> foo; //foo - null
    std::unique_ptr<int> bar; //bar - null
    int* p = nullptr;
    foo = std::unique_ptr<int>(new int(100));// foo - 100
    bar = std::move(foo); // foo转移给bar bar - 100 foo - null
    p = bar.get(); // p - 100 smart pointer.get（）返回一个指向该对象的内置指针
    foo.reset(bar.release()); // bar 放弃指针控制权，返回指针给foo foo - 100, bar已经不存在

    cout << "foo : " << *foo << endl;
    cout << "p   : " << *p << endl;
    delete p; //记得删除，这也是使用智能指针的初衷之一---防止内存泄漏！！！

    if (bar)
        cout << "bar : " << *bar << endl;
    else
        cout << "bar已经被释放" << endl; //这里bar已经销毁了，可能会报错。

    return 0;
}