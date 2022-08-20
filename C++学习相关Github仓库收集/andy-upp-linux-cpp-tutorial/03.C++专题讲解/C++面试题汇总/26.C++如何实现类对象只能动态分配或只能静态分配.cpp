//https://blog.csdn.net/u012411498/article/details/80816613
#include <iostream>
using namespace std;

//1.只能动态分配(只能在堆上分配)
/*
编译器在为类对象分配栈空间时，会先检查类的析构函数的访问性
（其实不光是析构函数，只要是非静态的函数，编译器都会进行检查）。
如果类的析构函数在类外部无法访问，则编译器拒绝在栈空间上为类对象分配内存。
*/

class A_1
{
public:
    A_1(){}
    void destory()
    {
        cout << "提供一个destory函数来实现内存空间的释放" << endl;
        delete this;
    }
private:
    ~A_1(){}
};

/*
上面的方法虽然能实现只能动态建立对象，但是有一个缺点：无法实现
继承。因为如果A作为基类的话，则析构函数通常要设为virtual，然后在
子类中被重写，以实现多态。因此析构函数不能设为private。为了解决
这个问题该怎么办呢？别忘了，C++还提供了第三种访问控制，就是
protected。将析构函数设为protected，类外无法访问protected成员，
但是子类可以访问。完美解决问题。
*/

class A_2
{
protected:
    A_2(){}
    virtual ~A_2(){}

public:
    /*
增加create函数是为了让代码看起来更统一，调用create函数在堆上创建类
A对象，调用destory函数来释放内存。
    */
    static A_2* create()
    {
        cout << "静态函数，用类直接调用" << endl;
        return new A_2();
    }

    void destroy()
    {
        delete this;
    }
};


class A_3 : protected A_2
{
public:
    A_3()
    {
        cout << "A_3" << endl;
    }

    virtual ~A_3()
    {
        cout << "子类重写～A_2()" << endl;
    }
};





int main()
{   
/*
这样在使用A a; 来建立对象时会编译错误，提示析构函数无法访问。
这样就只能用new运算符来建立对象了，并且构造函数可以调用，
因为是public。但是必须提供一个destory函数来实现内存空间的释放。
*/
    //A_1 a_1;
    A_1* a_1 = new A_1;
    a_1->destory();
    a_1 = nullptr;


   //A_2 
    A_2* a_2 = A_2::create();
    a_2->destroy();

    A_2* a_3 = new A_3;
    delete a_3;



    return 0;
}