#include<iostream>
using namespace std;

/*
注意事项：

  自动类型推导，必须推导出一致的数据类型T,才可以使用
  模板必须要确定出T的数据类型，才可以使用

总结：
  使用模板时必须确定出通用数据类型T，并且能够推导出一致的类型
*/

//利用模板提供通用的交换函数
template<class T> //这里用template和class没有区别
void mySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}


// 1、自动类型推导，必须推导出一致的数据类型T,才可以使用
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	mySwap(a, b); // 正确，可以推导出一致的T
	//mySwap(a, c); // 错误，推导不出一致的T类型
}


// 2、模板必须要确定出T的数据类型，才可以使用
//因为func()函数中没有用到T，所以直接调用无法确定T的类型
template<class T>
void func()
{
	cout << "func 调用" << endl;
}

void test02()
{
	//func(); //错误，模板不能独立使用，必须确定出T的类型
	func<int>(); //利用显示指定类型的方式，给T一个类型，才可以使用该模板
}

int main() {

	test01();
	test02();
	return 0;
}