#include<iostream>
using namespace std;

/*
  普通函数与函数模板区别： 普通函数可以发生隐式类型转换 函数模板分情况
  普通函数调用时可以发生自动类型转换（隐式类型转换）
  函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
  如果利用显示指定类型的方式，可以发生隐式类型转换

总结：建议使用显示指定类型的方式，调用函数模板，因为可以自己确定通用类型T
*/

//普通函数
int myAdd01(int a, int b)
{
	return a + b;
}

//函数模板
template<class T>
T myAdd02(T a, T b)  
{
	return a + b;
}

//使用函数模板时，如果用自动类型推导，不会发生自动类型转换,即隐式类型转换
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	
	cout << myAdd01(a, c) << endl; //正确，将char类型的'c'隐式转换为int类型  'c' 对应 ASCII码 99

	//myAdd02(a, c); // 报错，使用自动类型推导时，不会发生隐式类型转换
	myAdd02<int>(a, c); //正确，如果用显示指定类型，可以发生隐式类型转换
}

int main() {

	test01();
	return 0;
}