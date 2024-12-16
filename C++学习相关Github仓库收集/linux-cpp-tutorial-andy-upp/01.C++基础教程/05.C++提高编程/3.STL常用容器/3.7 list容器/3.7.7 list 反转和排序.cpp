#include <list>
#include<iostream>
using namespace std;

/*
**功能描述：**

* 将容器中的元素反转，以及将容器中的数据进行排序



**函数原型：**

* `reverse();`   //反转链表
* `sort();`        //链表排序
总结：

* 反转   --- reverse
* 排序   --- sort （成员函数）
*/

void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

bool myCompare(int val1 , int val2)
{
	return val1 > val2;
}

//反转和排序
void test01()
{
	list<int> L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	printList(L);

	//反转容器的元素
	L.reverse();
	printList(L);

	//排序
	L.sort(); //默认的排序规则 从小到大
	printList(L);

	L.sort(myCompare); //指定规则，从大到小
	printList(L);
}

int main() {

	test01();


	return 0;
}