#include <iostream>
using namespace std;

/*
作用：利用sizeof关键字可以 统计数据类型所占内存大小
语法： sizeof( 数据类型 / 变量)
*/

int main() {

	cout << "short 类型所占内存空间为： " << sizeof(short) << endl;
	cout << "int 类型所占内存空间为： " << sizeof(int) << endl;
	cout << "long 类型所占内存空间为： " << sizeof(long) << endl;
	cout << "long long 类型所占内存空间为： " << sizeof(long long) << endl;
	return 0;
}
