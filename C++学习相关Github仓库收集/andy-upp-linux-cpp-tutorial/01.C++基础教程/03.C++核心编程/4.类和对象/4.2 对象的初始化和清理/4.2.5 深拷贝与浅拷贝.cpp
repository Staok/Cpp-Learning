#include<iostream>
using namespace std;

/*
深浅拷贝是面试经典问题，也是常见的一个坑
浅拷贝：简单的赋值拷贝操作（在栈区）,内存自动释放 
深拷贝：在堆区重新申请空间，进行拷贝操作，内存需要手动释放
总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
*/

class Person {
public:
	//无参（默认）构造函数
	Person() {
		cout << "无参构造函数!" << endl;
	}
	//有参构造函数
	Person(int age ,int height) {		
		cout << "有参构造函数!" << endl;
		m_age = age;
		m_height = new int(height); //身高数据的数据创建在堆区，所以需要int* 的指针接收
	}
	//拷贝构造函数  
	Person(const Person& p) {
		cout << "拷贝构造函数!" << endl;
        //m_height = p.m_height  编译器默认实现就是这行代码
		//如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区内存问题
        //如果是浅拷贝的话，不重新在堆区申请内存，相当于两个对象的指针指向同一块内存，如果一个对象释放，会导致另一个对象重复释放内存
		m_age = p.m_age;
		m_height = new int(*p.m_height);
		
	}

	//析构函数 将堆区开辟的代码做释放操作
	~Person() {
		cout << "析构函数!" << endl;
		if (m_height != NULL)
		{
			delete m_height;
            m_height = NULL;
		}
	}
public:
	int m_age;
	int* m_height;
};

void test01()
{
	Person p1(18, 180);
	Person p2(p1);

	cout << "p1的年龄： " << p1.m_age << " 身高： " << *p1.m_height << endl;
	cout << "p2的年龄： " << p2.m_age << " 身高： " << *p2.m_height << endl;
}

int main() {

	test01();
	return 0;
}