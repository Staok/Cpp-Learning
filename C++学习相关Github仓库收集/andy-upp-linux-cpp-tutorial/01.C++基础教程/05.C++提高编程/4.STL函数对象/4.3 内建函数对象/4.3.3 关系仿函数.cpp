#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;

/*
功能描述：- 实现逻辑运算
函数原型：
* `template<class T> bool logical_and<T>`        //逻辑与
* `template<class T> bool logical_or<T>`         //逻辑或
* `template<class T> bool logical_not<T>`        //逻辑非

总结：关系仿函数中最常用的就是greater<>大于
*/

void test01()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);


	for(vector<bool>::iterator it = v.begin(); it!= v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//逻辑非  将v容器搬运到v2中，并执行逻辑非运算
	vector<bool> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(),  v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	test01();
	return 0;
}