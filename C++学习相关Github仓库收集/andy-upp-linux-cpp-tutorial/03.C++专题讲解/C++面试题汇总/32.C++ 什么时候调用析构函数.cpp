//https://www.cnblogs.com/AntonioSu/p/12269474.html
#include <iostream>
using namespace std;
/*
析构函数是在对象消亡时，自动被调用，用来释放对象占用的空间。

有四种方式会调用析构函数：
1.生命周期：对象生命周期结束，会调用析构函数。
2.delete：调用delete，会删除指针类对象。
3.包含关系：对象Dog是对象Person的成员，Person的析构函数被调用时，
  对象Dog的析构函数也被调用。
4.继承关系：当Person是Student的父类，调用Student的析构函数，
  会调用Person的析构函数。
*/

//第一种 生命周期结束

class Person1{
public:
    Person1(){
        cout << "Person1的构造函数" << endl;
    }
    ~Person1()    {
        cout << "删除Person1对象 " << endl;
    }
private:
    int name;
};

void Test1()
{
    Person1 person1;
}

/*
第二种 delete
对于new的对象，是指针，其分配空间是在堆上，故而需要用户删除申请空间，
否则就是在程序结束时执行析构函数
*/

class Person2{
public:
    Person2(){
        cout << "Person2的构造函数" << endl;
    }
    ~Person2()    {
        cout << "删除Person2对象 " << endl;
    }
private:
    int name;
};


void Test2()
{
    Person2* p2 = new Person2();
    delete p2; 
}


/*
第三种 包含关系
*/

class Dog{
public:
    Dog(){
        cout << "Dog的构造函数" << endl;
    }
    ~Dog()    {
        cout << "删除Dog对象 " << endl;
    }
private:
    int name;
};

class Person3{
public:
    Person3(){
        cout << "Person3的构造函数" << endl;
    }
    ~Person3()    {
        cout << "删除Person3对象 " << endl;
    }
private:
    int name;
    Dog dog;
};

void Test3()
{
    Person3 p3;
}


/*
第四种 继承关系
*/
class Person4{
public:
    Person4(){
        cout << "Person4的构造函数" << endl;
    }
    ~Person4()    {
        cout << "删除Person4对象 " << endl;
    }
private:
    int name;

};
class Student4 : public Person4{
public:
    Student4(){
        cout << "Student的构造函数" << endl;
    }
    ~Student4()    {
        cout << "删除Student对象 " << endl;
    }
private:
    int name;
    string no;
};

void Test4()
{
    Student4 s4;
}

int main() {
    //Test1();
    //Test2();
    //Test3();
    Test4();
    return 0;
}

