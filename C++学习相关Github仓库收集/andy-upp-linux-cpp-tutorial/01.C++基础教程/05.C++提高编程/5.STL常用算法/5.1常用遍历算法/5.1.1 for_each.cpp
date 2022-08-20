#include <algorithm>
#include <vector>
#include <iostream>
#include <unistd.h>
/*
功能描述：实现遍历容器
函数原型：for_each(iterator beg, iterator end, _func);
参数说明：
        beg 开始迭代器
        end 结束迭代器
        _func 函数或者函数对象

总结：for_each在实际开发中是最常用遍历算法，需要熟练掌握
*/

//普通函数
void print01(int val) 
{
	std::cout << val << " ";
}
//函数对象(仿函数)
class print02 
{
 public:
    //重载括号
	void operator()(int val) 
	{
		std::cout << val << " ";
	}
};

//for_each算法基本用法
void test01() {

	std::vector<int> v;
	for (int i = 0; i < 10; i++) 
	{
		v.push_back(i);
	}

	//遍历算法
	//普通函数传入函数名称
	for_each(v.begin(), v.end(), print01);
	std::cout << std::endl;
    
    //仿函数传入函数对象，需要加括号
	for_each(v.begin(), v.end(), print02());
	std::cout << std::endl;
}

int main() {

	test01();
    pause();
	return 0;
}