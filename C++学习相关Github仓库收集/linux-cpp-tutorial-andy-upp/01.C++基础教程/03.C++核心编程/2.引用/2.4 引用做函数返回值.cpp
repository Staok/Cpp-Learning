#include<iostream>
using namespace std;

/*
作用：引用是可以作为函数的返回值存在的
注意：不要返回局部变量引用
用法：函数调用作为左值
*/

//返回局部变量引用
int& test01() {
	int a = 10; //局部变量
	return a;
}

//返回静态变量引用
int& test02() {
	static int a = 20;
	return a;
}

int main() {

	//不能返回局部变量的引用
	int& ref = test01();
	cout << "ref = " << ref << endl;


	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
    
   //如果函数做左值，那么必须返回引用
	test02() = 1000;

	cout << "ref3 = " << ref2 << endl;
	return 0;
}