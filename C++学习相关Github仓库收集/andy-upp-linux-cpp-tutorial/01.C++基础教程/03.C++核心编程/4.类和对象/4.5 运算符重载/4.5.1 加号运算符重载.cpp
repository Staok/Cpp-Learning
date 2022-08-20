#include<string.h>
#include<iostream>
using namespace std;

/*
作用：实现两个自定义数据类型相加的运算

> 总结1：对于内置的数据类型的表达式的的运算符是不可能改变的
> 总结2：不要滥用运算符重载

*/
class Person {
public:
	Person() {};
	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
	//成员函数实现 + 号运算符重载，本质上是一个成员函数，只不过编译器统一提供了一个函数名为 operator+ 
	//返回值是一个新的对象
	Person operator+(const Person& p) {
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		cout << "----" << endl;
		return temp;
	}


public:
	int m_A;
	int m_B;
};

//通过全局函数实现 + 号运算符重载
Person operator+(const Person& p1, const Person& p2) {
	Person temp(0, 0);
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	cout << "=====" << endl;
	return temp;
}

//运算符重载 可以发生函数重载 
Person operator+(const Person& p2, int val)  
{
	Person temp;
	temp.m_A = p2.m_A + val;
	temp.m_B = p2.m_B + val;
	cout << "+__+_++_+__+" << endl;
	return temp;
}

void test() {

	Person p1(10, 10);
	Person p2(20, 20);

	//成员函数方式 或者 全局函数方式都可以,默认使用成员函数方式的重载
	Person p3 = p2 + p1;  //成员函数重载相当于 p2.operaor+(p1),全局函数重载相当于 operator(p1,p2)
	cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;


	Person p4 = p3 + 10; //相当于 operator+(p3,10),此处注意，运算符重载也可以发生函数重载
	cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;
}

int main() {

	test();
	return 0;
}