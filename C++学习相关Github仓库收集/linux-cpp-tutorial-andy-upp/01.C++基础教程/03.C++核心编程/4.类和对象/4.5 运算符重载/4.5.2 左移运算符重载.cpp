#include<iostream>
using namespace std;

/*
作用：重载左移运算符可以输出自定义数据类型, 如输出对象的成员变量
总结：重载左移运算符配合友元可以实现输出自定义数据类型
*/

class Person {
	friend ostream& operator<<(ostream& out, Person& p);
public:

	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

	//成员函数 实现不了  p << cout 不是我们想要的效果
    //我们通常不会利用成员函数重载 <<  ，因为无法实现cout在左侧
	//void operator<<(Person& p){
	//}

private:
	int m_A;
	int m_B;
};

//只能利用全局函数实现重载左移运算符，
//cout 属于ostream 数据类型，叫做输出流对象，我们一般称cout为标准的输出流对象
//ostream对象全局只能有一个，所以我们需要用引用的方式传递,out 只是cout的一个别名
ostream& operator<<(ostream& out, Person& p) { //本质上是operator(cout,p)，简化成 cout << p
	out << "a:" << p.m_A << " b:" << p.m_B;
	return out;
}

void test() {

	Person p1(10, 20);
	cout << p1 << " hello world" << endl; //链式编程，可以无限的往后追加输入，需要在实现中返回对象的引用
}

int main() {

	test();
	return 0;
}