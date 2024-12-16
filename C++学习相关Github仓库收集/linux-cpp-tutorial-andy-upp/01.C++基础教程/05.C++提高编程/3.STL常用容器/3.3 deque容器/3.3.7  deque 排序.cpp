#include <deque>
#include <algorithm>
#include<iostream>
using namespace std;

/*
**功能描述：**

* 利用算法实现对deque容器进行排序

**算法：**

* `sort(iterator beg, iterator end)`  //对beg和end区间内元素进行排序

总结：sort算法非常实用，使用时包含头文件 algorithm即可

*/



void printDeque(const deque<int>& d) 
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}

void test01()
{

	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);

	printDeque(d);
	sort(d.begin(), d.end());
	printDeque(d);

}

int main() {

	test01();


	return 0;
}