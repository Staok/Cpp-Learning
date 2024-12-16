//https://www.cnblogs.com/LearningTheLoad/p/7309817.html
//https://blog.csdn.net/qq_39551987/article/details/80730664

#include<iostream>
using namespace std;

/*
1.继承
继承指的是一个类继承另外的一个类，继承的类叫做子类，被继承的类叫做父类。
*/

class A1
{
public:
    A1()
    {
        cout << "A1 ctr" << endl;
    }
};

class B1:public A1
{
public:
    B1()
    {
        cout << "B1 ctr" << endl;
    }
};

void Test1()
{
    B1 b1;
}
/*
2.实现
实现讲的是c++中面向对象的“接口”，“接口”是java中的重点，
在c++中的接口主要通过纯虚函数实现。
*/

class A2
{
public:
    // virtual void func2()
    // {
    //     cout << "func2" << endl;
    // }
    //类A中的函数func22（）为纯虚函数，没有函数体，在继承它的函数中写出func22（）的具体实现。
    //抽象类无法生成对象
    virtual void func22() = 0;
};

class B2 : public A2
{
public:
    // virtual void func2()
    // {
    //     cout << "func2_" << endl;
    // }

    virtual void func22()
    {
        cout << "func22" << endl;
    }
};

void Test2()
{
    // A2 a2;
    // a2.func2();
    B2 b2;
    // b2.func2();
    b2.func22();
}

/*
3.依赖
C++语法中，通过将一个类作为另一类方法的参数的形式实现两个类之间的依赖关系。
*/


class A3{
public:
    void display()
    {
        cout << "display" << endl;
    }
};

class B3{
public:
   //A类型的对象作为B类中函数的参数,B依赖A
   void func(A3& a)
   {
       a.display();
   };
};

void Test3()
{
    B3 b3;
    A3 a3;
    b3.func(a3);
}

/*
4.聚合
在C++语法中，通过类的指针来实现聚合
*/

class A4{
public:
    void display()
    {
        cout << "display" << endl;
    }
private:
    int a[10];
};

class B4{
public:
    void display()
    {
        for(int i = 0; i < 5; ++i)
            a4[i].display();
    }

private:
   A4 a4[5];
};

void Test4()
{
    B4 b4;
    b4.display();
    cout << "sizeof(b4): " << sizeof(b4) << endl;
}


/*
5.关联（也可以称为委托）
C++中，通过定义其他类指针类型的成员来实现关联。
*/


class A5{
public:
    void display()
    {
        cout << "display" << endl;
    }
private:
    int a[100];
};

class B5{
public:
    void display()
    {
        a5->display();
    }

private:
   A5* a5;
};


void Test5()
{
    B5 b5;
    b5.display();
    cout << "sizeof(b5): " << sizeof(b5) << endl;

}

/*
6.组合

    组合是将一个对象（部分）放到另一个对象里（组合）。相比"聚合"，组合是一种强所属关系，
    组合关系的两个对象往往具有相同的生命周期，被组合的对象是在组合对象创建的同时或者创建
    之后创建，在组合对象销毁之前销毁。一般来说被组合对象不能脱离组合对象独立存在，而且也
    只能属于一个组合对象。在C++语法中，使用在一个类中包含另外一个类类型的成员来实现组合。
*/

class A6{
public:
    void display()
    {
        cout << "display" << endl;
    }
private:
    int a[10];
};

class B6{
public:
    void display()
    {
            a6.display();
    }
private:
   A6 a6;
};

void Test6()
{
    B6 b6;
    b6.display();
    cout << "sizeof(b6):" << sizeof(b6) << endl;
    cout << "sizeof(int):" << sizeof(int) << endl;
}




int main()
{
    //Test1();
    //Test2();
    //Test3();
    //Test4();
    Test5();
    //Test6();
    return 0;
}