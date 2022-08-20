#include<iostream>
using namespace std;

/*
多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
解决方式：将父类中的析构函数改为 虚析构  或者 纯虚析构 


虚析构和纯虚析构共性：
  可以解决父类指针释放子类对象
  都需要有具体的函数实现

虚析构和纯虚析构区别：
 如果是纯虚析构，该类属于抽象类，无法实例化对象

虚析构语法：
virtual ~类名(){}

纯虚析构语法：
virtual ~类名() = 0;

类名::~类名(){}


总结：

​	1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
​	2. 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
​	3. 拥有纯虚析构函数的类也属于抽象类
*/


class Animal {
public:

	Animal()
	{
		cout << "Animal 构造函数调用！" << endl;
	}
	virtual void Speak() = 0;

	//析构函数加上virtual关键字，变成虚析构函数
	//virtual ~Animal()
	//{
	//	cout << "Animal虚析构函数调用！" << endl;
	//}

    //纯虚析构需要代码的实现，因为有可能父类的一些属性开辟到堆区
    //需要声明，也需要实现，有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
	virtual ~Animal() = 0;
};
Animal::~Animal()
{
	cout << "Animal 纯虚析构函数调用！" << endl;
}

//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。

class Cat : public Animal {
public:
	Cat(string name)
	{
		cout << "Cat构造函数调用！" << endl;
		m_Name = new string(name);
	}
	virtual void Speak()
	{
		cout << *m_Name <<  "小猫在说话!" << endl;
	}
	~Cat()
	{
		cout << "Cat析构函数调用!" << endl;
		if (this->m_Name != NULL) {
			delete m_Name;
			m_Name = NULL;
		}
	}

public:
	string *m_Name;
};

void test01()
{
	Animal *animal = new Cat("Tom");
	animal->Speak();

	//通过父类指针去释放，不会调用子类的析构函数，会导致子类对象可能清理不干净，造成内存泄漏
	//怎么解决？给基类增加一个虚析构函数
	//虚析构函数就是用来解决通过父类指针释放子类对象
	delete animal;
}

int main() {

	test01();
	return 0;
}