#include <iostream>
using namespace std;

/*
  函数调用运算符 ()  也可以重载
  由于重载后使用的方式非常像函数的调用，因此称为仿函数
  仿函数没有固定写法，非常灵活
*/

class MyPrint
{
public:
	void operator()(string text)
	{
		cout << text << endl;
	}

};
void test01()
{
	//重载的（）操作符 也称为仿函数,因为它使用起来非常像函数调用
	MyPrint myFunc;
	myFunc("hello world");
}


//仿函数非常灵活，没有固定的写法
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test02()
{
	MyAdd add;
	int ret = add(10, 10);
	cout << "ret = " << ret << endl;

	//匿名函数对象调用，不需要先创建对象，就可以直接调用仿函数，其中MyAdd()创建了一个匿名对象，用完了直接释放
	cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
}

int main() {

	test01();
	test02();
	return 0;
}