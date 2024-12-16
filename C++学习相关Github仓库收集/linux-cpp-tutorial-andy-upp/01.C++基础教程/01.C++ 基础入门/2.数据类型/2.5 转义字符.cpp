#include<iostream>
using namespace std;

/*
作用：用于表示一些==不能显示出来的ASCII字符==
现阶段我们常用的转义字符有：\n  \\  \t
*/



int main() {

	cout << "\\" << endl;
	cout << "\tHello" << endl;
	cout << "\n" << endl;

	return 0;
}