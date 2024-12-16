#include<iostream>
using namespace std;
/*
作用： 告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义。
函数的声明可以多次，但是函数的定义只能有一次
*/

//声明可以多次，定义只能一次
//声明
int max(int a, int b);
int max(int a, int b);
//定义
int max(int a, int b)
{
	return a > b ? a : b;
}

int main() {

	int a = 100;
	int b = 200;

	cout << max(a, b) << endl;

	return 0;
}