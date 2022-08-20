//https://blog.csdn.net/u011857683/article/details/79720782
#include <iostream>
using namespace std;

//情况1
class Test1
{
public:
    Test1(int, int, int)
    {
        cout << "Test" << endl;
    }

private:
    int x;
    int y;
    int z;
};

class Mytest1
{
public:
    Mytest1():test(1,2,3)
    {
        cout << "Mytest" << endl;
    }

private:
    Test1 test;
};

//情况2
class Test2
{
public:
    Test2(int b):a(10),b(b)
    {
        cout << "Test2" << endl;
    }


private:
    const int a;
    int& b;
};

//情况3
class Test3
{
public:
    Test3()
    {
        cout << "33333333" << endl;
    }

    Test3(int x)
    {
        int_x = x;
    }

    void show()
    {
        cout << int_x << endl;
    }

private:
    int int_x;
};

class Mytest3 :public Test3
{
public:
    Mytest3():Test3(110)
    {
		// 构造函数只能在初始化列表中被显示调用(如果不显示初始化，默认调用默认构造函数)，
        //不能在构造函数内部被显示调用
     
		// 内部调用的是临时变量
        //Test(110); 
        cout << "mytest3" << endl;
    }
};


int main()
{
    // 情况一的说明：数据成员是对象，并且这个对象只有含参数的
    // 构造函数，没有无参数的构造函数；
    //也就是 当调用一个成员类的构造函数，而它拥有一组参数时；
    Mytest1 test;

    //情况二的说明：对象 引用或者cosnt修饰的数据成员
    //也就是 ① 当初始化一个引用成员时； ② 当初始化一个常量成员时；
    Test2 test2(10);

    //情况三的说明：子类初始化父类的私有成员，需要在(并且也只能在)
    //参数初始化列表中显示调用父类的构造函数
    //也就是 当子类调用一个基类的构造函数，而它拥有一组参数时
    cout << "======test3========" << endl;
    Test3* test3 = new Mytest3();
    test3->show();

    return 0;
}