#include<iostream>
using namespace std;

/*
string中单个字符存取方式有两种

*  char& operator[](int n);     //通过[]方式取字符
*  char& at(int n);             //通过at方法获取字符
总结：string字符串中单个字符存取有两种方式，利用 [ ] 或 at
*/


void test01()
{
	string str = "hello world";

	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;


	//字符修改
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;
	
}

int main() {

	test01();
	return 0;
}