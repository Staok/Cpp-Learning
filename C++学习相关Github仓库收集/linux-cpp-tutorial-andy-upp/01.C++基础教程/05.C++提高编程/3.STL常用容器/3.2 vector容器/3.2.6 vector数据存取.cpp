#include <vector>
#include <iostream>
using namespace std;

/*
* 对vector中的数据的存取操作

函数原型：

*  at(int idx);       //返回索引idx所指的数据
*  operator[];        //返回索引idx所指的数据
*  front();             //返回容器中第一个数据元素
*  back();              //返回容器中最后一个数据元素

总结：

* 除了用迭代器获取vector容器中元素，[ ]和at也可以
* front返回容器第一个元素
* back返回容器最后一个元素
*/


void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;

	cout << "v1的第一个元素为： " << v1.front() << endl;
	cout << "v1的最后一个元素为： " << v1.back() << endl;
}

int main() {

	test01();
	return 0;
}