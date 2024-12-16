#include<iostream>
using namespace std;

/*
2.7 布尔类型 bool
作用：布尔数据类型代表真或假的值 

bool类型只有两个值：

true  --- 真（本质是1）
false --- 假（本质是0）
bool类型占==1个字节==大小
*/

int main() {

	bool flag = true;
	cout << flag << endl; // 1

	flag = false;
	cout << flag << endl; // 0

	cout << "size of bool = " << sizeof(bool) << endl; //1
	
	return 0;
}