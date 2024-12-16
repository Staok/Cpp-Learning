#include<iostream>
using namespace std;

//2.如果对象有多个构造函数，那么new的语句也可以有多种形式
class Obj
{
public:
    Obj(void)//无参数的构造函数
    {
        cout << "调用无参构造" << endl;
    } 
    Obj(int x) //带一个参数的构造函数
    {
        cout << "调用有参构造" << endl;
        a = x;
    }
private:
    int a;
};


void Test(void)
{
    Obj* a = new Obj;
    Obj* b = new Obj(1); //初值为1

    delete a;
    delete b;

    //用new创建对象数组
    Obj* objects = new Obj[100]; //创建100个动态对象,调用无参构造
    
    delete[] objects;
}



int main()
{
//1.malloc 要注意返回指针的类型
int* p1 = (int*)malloc(sizeof(int)*3);
int* p2 = new int[3];

//2
Test();
return 0;
}