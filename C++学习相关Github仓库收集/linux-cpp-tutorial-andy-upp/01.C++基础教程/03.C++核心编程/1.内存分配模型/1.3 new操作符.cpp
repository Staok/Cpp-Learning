#include<iostream>
using namespace std;

/*
C++中利用 new 操作符在堆区开辟数据
堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 delete

语法：new 数据类型
利用new创建的数据，会返回该数据对应的类型的指针
*/

int* func()
{
	int* a = new int(10);
	return a;
}

int main() {

	int *p = func();
	cout << *p << endl;

	//利用delete释放堆区数据
	delete p;
	//cout << *p << endl; //报错，释放的空间不可访问

//开辟数组

	int* arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	//释放数组 delete 后加 []
	delete[] arr;

	return 0;
}