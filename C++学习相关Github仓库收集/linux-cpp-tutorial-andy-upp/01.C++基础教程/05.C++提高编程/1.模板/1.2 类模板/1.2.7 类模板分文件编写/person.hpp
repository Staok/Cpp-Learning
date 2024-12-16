#pragma once  //防止头文件重复包含
#include <iostream>
using namespace std;
#include <string>


/*
* 问题：
* 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
* 解决：
* 解决方式1：直接包含.cpp源文件
* 解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制 约定俗成
* 总结：主流的解决方式是第二种，将类模板成员函数写到一起，并将后缀名改为.hpp
*/



template<class T1, class T2>
class Person {
public:
	Person(T1 name, T2 age);
	void showPerson();
public:
	T1 m_Name;
	T2 m_Age;
};

//构造函数 类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}

//成员函数 类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson() {
	cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
}