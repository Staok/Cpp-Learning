#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
功能描述：求两个集合的并集



函数原型：

set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest); 

  求两个集合的并集
  注意:两个集合必须是有序序列

  beg1 容器1开始迭代器
  end1 容器1结束迭代器
  beg2 容器2开始迭代器
  end2 容器2结束迭代器
  dest 目标容器开始迭代器

总结：
求并集的两个集合必须的有序序列
目标容器开辟空间需要**两个容器相加
set_union返回值既是并集中最后一个元素的位置
*/



class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}

	vector<int> vTarget;
	//取两个容器的和给目标容器开辟空间
	vTarget.resize(v1.size() + v2.size());

	//返回目标容器的最后一个元素的迭代器地址
	vector<int>::iterator itEnd = 
        set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
}

int main() {

	test01();

	return 0;
}