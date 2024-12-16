#include<iostream>
using namespace std;

/*
在程序编译后，生成了exe可执行程序，未执行该程序前 分为两个区域
​	代码区：
​		存放 CPU 执行的机器指令
​		代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
​		代码区是只读的，使其只读的原因是防止程序意外地修改了它的指令

​	全局区：
​		全局变量和静态变量存放在此.
​		全局区还包含了常量区, 字符串常量和其他常量也存放在此.
​		该区域的数据在程序结束后由操作系统释放.

总结：
* C++中在程序运行前分为全局区和代码区
* 代码区特点是共享和只读
* 全局区中存放全局变量、静态变量、常量
* 常量区中存放 const修饰的全局常量  和 字符串常量
*/

//全局变量
int g_a = 10;
int g_b = 10;

//全局常量
const int c_g_a = 10;
const int c_g_b = 10;

int main() {

	//局部变量
	int a = 10;
	int b = 10;

	//打印地址
	cout << "局部变量a地址为： " << (long)&a << endl;
	cout << "局部变量b地址为： " << (long)&b << endl;

	cout << "全局变量g_a地址为： " <<  (long)&g_a << endl;
	cout << "全局变量g_b地址为： " <<  (long)&g_b << endl;

	//静态变量
	static int s_a = 10;
	static int s_b = 10;

	cout << "静态变量s_a地址为： " << (long)&s_a << endl;
	cout << "静态变量s_b地址为： " << (long)&s_b << endl;

	cout << "字符串常量地址为： " << (long)&"hello world" << endl;
	cout << "字符串常量地址为： " << (long)&"hello world1" << endl;

	cout << "全局常量c_g_a地址为： " << (long)&c_g_a << endl;
	cout << "全局常量c_g_b地址为： " << (long)&c_g_b << endl;

	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "局部常量c_l_a地址为： " << (long)&c_l_a << endl;
	cout << "局部常量c_l_b地址为： " << (long)&c_l_b << endl;

	return 0;
}