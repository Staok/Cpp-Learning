#include<iostream>
using namespace std;

class A
{
public:
    void Func(void)
    {
        cout << "Func of class A" << endl;
    }
};

void Test(void)
{
    A* p;
    {
        A a;
        p = &a; 
    }
    p->Func(); //p是 “野指针”，但是这个程序运行没有出错，可能与编译器有关
};

int main()
{
//1.指针变量创建后应当被初始化
char* p = NULL;
char* str = (char*)malloc(100);
//2.指针被free或者delete后，应当设置为NULL
free(str);
str = nullptr;

//3.指针操作超出变量的作用域和范围会造成野指针
Test();

return 0;
}