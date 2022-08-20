#include <functional> //内建函数对象的头文件
#include <iostream>
using namespace std;


/*
功能描述：
* 实现四则运算
* 其中negate是一元运算，其他都是二元运算
仿函数原型：

* `template<class T> T plus<T>`            //加法仿函数
* `template<class T> T minus<T>`           //减法仿函数
* `template<class T> T multiplies<T>`      //乘法仿函数
* `template<class T> T divides<T>`         //除法仿函数
* `template<class T> T modulus<T>`         //取模仿函数
* `template<class T> T negate<T>`          //取反仿函数
总结：使用内建函数对象时，需要引入头文件 `#include <functional>`

*/



//negate 一元仿函数 取反仿函数
void test01()
{   
    //通过内建的negate来创建一个函数对象，<int>是模版参数列表，表示参数类型是 int
   	negate<int> n;
	cout << n(50) << endl;
}

//plus 加法仿函数
void test02()
{
	plus<int> p;
	cout << p(10, 20) << endl;
}

int main() {

	test01();
	test02();
	return 0;
}