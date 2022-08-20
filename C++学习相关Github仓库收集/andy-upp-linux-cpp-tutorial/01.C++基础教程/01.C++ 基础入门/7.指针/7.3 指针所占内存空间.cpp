#include<iostream>
using namespace std;

/*
总结：所有指针类型在32位操作系统下是4个字节,在64位操作系统下是8字节
*/

int main() {

	int a = 10;

	int * p;
	p = &a; //指针指向数据a的地址

	cout << *p << endl; //* 解引用
	cout << sizeof(p) << endl; //8
	cout << sizeof(char *) << endl; //8
	cout << sizeof(float *) << endl; //8
	cout << sizeof(double *) << endl; //8
	return 0;
}