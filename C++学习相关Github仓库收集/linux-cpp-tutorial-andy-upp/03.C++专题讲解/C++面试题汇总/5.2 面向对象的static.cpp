#include<iostream>
#include<string>
using namespace std;


class Apple
{
public:
    Apple()
    {
        cout << "构造函数" << endl;
    }
    int getValue_i()
    {
        ++i;
        return i;
    }
    int getValue_j()
    {
        return j;
    }

    static int getValue()
    {
        //return l;错误，  静态成员函数仅能访问静态数据成员或其他静态成员函数，它们无法访问类的非静态数据成员或成员函数。
        return j;
    }

    static const int k = 20;
private:
    // 被const修饰的static变量在c++11中可以在类内被直接初始化。
    static const int j = 10;
    static int i; //类内声明
    int l = 30;
};
// 声明为static的变量只被初始化一次，因为它们在单独的静态存储中分配了空间，
//因此类中的静态变量由对象共享。对于不同的对象，不能有相同静态变量的多个副本。
//也是因为这个原因，静态变量不能使用构造函数初始化。
int Apple::i = 1; //类外初始化


int main()
{
    Apple a;
    cout << a.getValue_i() << endl;
    cout << a.getValue_j() << endl;
    Apple b;
    cout << b.getValue_i() << endl;
    cout << b.getValue_j() << endl;
    cout << Apple::k << endl;//直接通过类作用域调用静态成员
    cout <<Apple::getValue() << endl;

    return 0;
}