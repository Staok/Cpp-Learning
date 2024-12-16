#include<iostream>
using namespace std;

/*
继承的语法：class 子类 : 继承方式  父类
  继承方式一共有三种：
  父类也叫基类,子类也叫派生类，父类中私有内容，子类无论用哪种方式，都不可以访问 （父类私有内容不可访问）
  公共继承：父类中公共的属性，在子类中依然是公共的属性，父类中是保护的属性，在子类中依然是保护的的属性（公共继承属性不变）
  保护继承：父类中公共的属性和保护的属性，在子类中都变为了保护的属性（保护继承属性变保护）
  私有继承：父类中公共的属性和保护的属性，在子类中都变为了私有的属性（私有继承属性变私有）
*/

class Base1
{
public: 
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

//公共继承
class Son1 :public Base1
{
public:
	void func()
	{
		m_A; //可访问 public权限
		m_B; //可访问 protected权限
		//m_C; //不可访问 
	}
};

void myClass()
{
	Son1 s1;
	s1.m_A; //其他类只能访问到公共权限
    // s1.m_B; 类外保护权限 不可访问
}

//保护继承
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son2:protected Base2
{
public:
	void func()
	{
		m_A; //可访问 protected权限
		m_B; //可访问 protected权限
		//m_C; //不可访问
	}
};
void myClass2()
{
	Son2 s;
	//s.m_A; //不可访问 类外保护权限不可访问
}

//私有继承
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son3:private Base3
{
public:
	void func()
	{
		m_A; //可访问 private权限
		m_B; //可访问 private权限
		//m_C; //不可访问
	}
};
class GrandSon3 :public Son3
{
public:
	void func()
	{
		//Son3是私有继承，所以继承Son3的属性在GrandSon3中都无法访问到
		//m_A;
		//m_B;
		//m_C;
	}
};