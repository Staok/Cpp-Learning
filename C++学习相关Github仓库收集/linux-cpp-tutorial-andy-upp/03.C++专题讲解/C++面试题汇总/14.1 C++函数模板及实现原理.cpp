//https://blog.csdn.net/baidu_28312631/article/details/47975385

#include<iostream>
using namespace std;




template <typename T>

void myswap(T& a, T& b)
{
    T t;
    t = a;
    a = b;
    b = t;
}


int main()
{
    int  x = 1;
	int	 y = 2;
	myswap(x, y); //自动数据类型 推导的方式 
	
	float a = 2.0;
	float b = 3.0;
	myswap(a, b); //自动数据类型 推导的方式 

    myswap<float> (a,b);

	cout<<"hello..."<<endl;
    return 0;
}


















/*
c++编译器模板机制实现
通过观察反汇编代码，我们可以得出这样的结论：编译器并不是把函数模板处理成能够处理
任意类的函数；编译器从函数模板通过具体类型产生不同的函数；编译器会对函数模板进行
两次编译：在声明的地方对模板代码本身进行编译，在调用的地方对参数替换后的代码进行
编译。
*/