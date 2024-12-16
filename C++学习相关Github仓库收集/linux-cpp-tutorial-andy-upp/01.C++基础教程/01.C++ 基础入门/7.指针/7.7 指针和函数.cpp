#include<iostream>
using namespace std;

/*
作用：利用指针作函数参数，可以修改实参的值
总结：如果不想修改实参，就用值传递，如果想修改实参，就用地址传递
*/


//值传递
void swap1(int a ,int b)
{
	int temp = a;
	a = b; 
	b = temp;
}

//地址传递
void swap2(int * p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main() {

	int a = 10;
	int b = 20;
	swap1(a, b); // 值传递不会改变实参
	swap2(&a, &b); //地址传递会改变实参

	cout << "a = " << a << endl;

	cout << "b = " << b << endl;

	return 0;
}