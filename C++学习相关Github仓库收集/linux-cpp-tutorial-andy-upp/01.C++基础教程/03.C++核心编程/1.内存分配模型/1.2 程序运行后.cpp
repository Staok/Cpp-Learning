#include<iostream>
using namespace std;

/*
​栈区：
由编译器自动分配释放, 存放函数的参数值,局部变量等
注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放

堆区：
由程序员分配释放,若程序员不释放,程序结束时由操作系统回收
在C++中主要利用new在堆区开辟内存
总结：
堆区数据由程序员管理开辟和释放
堆区数据利用new关键字进行开辟内存

*/

int * func()
{
	int a = 10;
	return &a;
}

int* func_()
{
	int* a = new int(10);
	return a;
}

int main() {

	int *p = func();

 	cout << *p << endl;
    cout << "------------" << endl;

	int *p_ = func_();
	cout << *p_ << endl;
	return 0;
}

