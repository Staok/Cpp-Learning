//https://www.jianshu.com/p/d19fc8447eaa
#include <iostream>
using namespace std;

//左值和右值
namespace Test1 
{
    //区分左值和右值的便捷方法：看能不能对表达式取地址，
    //如果能，则为左值，否则为右值。
    int i = 0; //i是左值，0是右值
    class A
    {
    public:
        int a;    
    };

    A getTemp()
    {
        return A(); //返回的是一个临时对象
    }

    A a = getTemp(); //a是左值  getTemp()的返回值是右值（临时变量）
}

//左值引用，使用符号&
namespace Test2
{
    int a = 10;
    int& refA = a; //refA是a的别名，修改refA就是修改a,a是左值，a左移是左值引用

    //int& b = 1; 编译错误! 1是右值，不能够使用左值引用    
}

//右值引用,使用符号&&
namespace Test3
{
    int&& a = 1;  //实质上就是将不具名(匿名)变量取了个别名
    int b = 1;
    //int&& c = b;//编译错误！ 不能将一个左值复制给一个右值引用

    class A 
    {
    public:
        int a;
    };

    A getTemp()
    {
        return A(); 
    }

    A&& a_ = getTemp(); //getTemp()的返回值是右值（临时变量）

    /*
    常量左值引用却是个奇葩，它可以算是一个“万能”的引用类型，它可以
    绑定非常量左值、常量左值、右值，而且在绑定右值的时候，常量左值
    引用还可以像右值引用一样将右值的生命期延长，缺点是，只能读不能改。
    */
    const A& a__ = getTemp();
}


//常量左值引用的例子,常量左值引用能够绑定一个右值，可以减少一次拷贝
namespace Test4
{
    class Copyable
    {
    public:
        Copyable(){}
        Copyable(const Copyable& o)
        {
            cout << "Copied" << endl;
        }
    };
    
    Copyable returnRvalue()
    {
        return Copyable();//返回一个临时对象
    }

    void AcceptVal(Copyable a)
    {}

    void AcceptRef(const Copyable& a)
    {}

} // namespace name
 
 
//移动构造和移动赋值
namespace Test5
{

}







int main()
{   
    Test1::A a1 = Test1::getTemp();
    Test3::A&& a3 = Test3::getTemp();
    
    /*
    以下不管哪种方式，一次拷贝构造函数都没有调用！

    这是由于编译器默认开启了返回值优化(RVO/NRVO, RVO, Return Value Optimization 
    返回值优化，或者NRVO， Named Return Value Optimization)。编译器很聪明，
    发现在ReturnRvalue内部生成了一个对象，返回之后还需要生成一个临时对象调用拷贝构造函数，
    很麻烦，所以直接优化成了1个对象对象，避免拷贝，而这个临时变量又被赋值给了函数的形参，
    还是没必要，所以最后这三个变量都用一个变量替代了，不需要调用拷贝构造函数。
    
    可以在编译的时候加上-fno-elide-constructors选项(关闭返回值优化)来调用拷贝构造函数。
    */

    cout << "pass by value: " << endl;
    Test4::AcceptVal(Test4::returnRvalue());//应该调用两次拷贝构造函数，但是一次没调用
    cout << "pass by reference" << endl;
    Test4::AcceptRef(Test4::returnRvalue()); //应该只调用一次拷贝构造函数，但是一次没调用

    return 0;
}