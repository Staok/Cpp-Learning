#include<iostream>
using namespace std;

/*
问题：当子类与父类出现同名的成员，如何通过子类对象，访问到的是子类还是父类中同名的数据呢？
  访问子类同名成员   直接访问即可
  访问父类同名成员   需要加作用域

总结：
1. 子类对象可以直接访问到子类中同名成员
2. 子类对象加作用域可以访问到父类同名成员
3. 当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数
*/


//继承中同名成员处理
class Base {
public:
	Base()
	{
		m_A = 100;
	}

	void func()
	{
		cout << "Base - func()调用" << endl;
	}

	void func(int a)
	{
		cout << "Base - func(int a)调用" << endl;
	}

public:
	int m_A;
};


class Son : public Base {
public:
	Son()
	{
		m_A = 200;
	}

	//如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
	void func()
	{
		cout << "Son - func()调用" << endl;
	}
public:
	int m_A;
};

void test01()
{
	Son s;

	cout << "Son下的m_A = " << s.m_A << endl;
	cout << "Base下的m_A = " << s.Base::m_A << endl;

	s.func(); // 直接调用，调用的是子类中的成员函数
	s.Base::func(); //如果想调用父类的成员函数，可以加作用域实现
	s.Base::func(10); //当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数


}
int main() {

	test01();
	return EXIT_SUCCESS;
}