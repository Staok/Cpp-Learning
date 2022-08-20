#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

/*
功能描述：
两个容器元素合并，并存储到另一容器中

函数原型：

merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  

  容器元素合并，并存储到另一容器中
  注意: 两个容器必须是 有序的

  beg1   容器1开始迭代器
  end1   容器1结束迭代器
  beg2   容器2开始迭代器
  end2   容器2结束迭代器
  dest    目标容器开始迭代器

 总结：merge合并的两个容器必须的有序序列
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
	for (int i = 0; i < 10 ; i++) 
    {
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	vector<int> vtarget;
	//目标容器需要提前开辟空间
	vtarget.resize(v1.size() + v2.size());
	//合并  需要两个有序序列
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), vtarget.end(), myPrint());
	cout << endl;
}

int main() {

	test01();

	return 0;
}