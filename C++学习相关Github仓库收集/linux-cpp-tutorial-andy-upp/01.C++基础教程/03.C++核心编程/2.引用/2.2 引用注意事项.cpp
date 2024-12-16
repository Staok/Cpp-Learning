#include<iostream>
using namespace std;

/*
* 引用必须初始化
* 引用在初始化后，不可以改变
*/

int main() {

	int a = 10;
	int b = 20;
	//int &c; //错误，引用必须初始化
	int& c = a; //一旦初始化后，就不可以更改
	c = b; //这是赋值操作，不是更改引用，此处可以理解为利用引用c来改变它所指向的a的值
    //&c = b; //这种是对引用c，改变了它的指定对象，一开始是a的引用，之后，又重新说明是b的引用，这种引用的重新赋值是不允许的。

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	return 0;
}