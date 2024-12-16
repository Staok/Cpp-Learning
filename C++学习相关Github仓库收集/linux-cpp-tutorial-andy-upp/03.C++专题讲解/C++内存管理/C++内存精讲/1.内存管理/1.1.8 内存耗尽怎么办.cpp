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


//1.判断指针是否为NULL，如果是则马上用return语句终止本函数
void Func_1(void)
{
    A* a = new A;
    if(a == nullptr)
    {
        cout << "1.指针为null，退出" << endl;
        return;
    }
}

//2.判断指针是否是NULL，如果是则马上用exit(1)终止整个程序的运行
void Func_2(void)
{
    A* a = new A;
    if(a == NULL)
    {
        cout << "Memory Exhausted" << endl;
        exit(1);
    }
}




int main()
{
//通常有3种方式处理“内存耗尽”
    //Func_1();
    //Func_2();
    //3.32位以上的操作系统，因为虚拟内存的原因，几乎不可能内存耗尽
    //但是不加错误处理将导致程序的质量很差，千万不可因小失大。
    float* p = NULL;
    while (true)
    {
        p = new float[1000000];
        cout << "eat memory" << endl;
        if(p == NULL)
        {
            exit(1);
        }
    }
    return 0;
}