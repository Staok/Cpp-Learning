#include<vector>
#include<algorithm>
#include<iostream>
#include<unistd.h>

using namespace std;
/*
功能描述：搬运容器到另一个容器中

函数原型：transform(iterator beg1, iterator end1, iterator beg2, _func);

参数说明：
        beg1 源容器开始迭代器
        end1 源容器结束迭代器
        beg2 目标容器开始迭代器
        _func 函数或者函数对象
总结： 搬运的目标容器必须要提前开辟空间，否则无法正常搬运
*/
class TransForm
{
public:
    //将源容器每一个元素放到模板容器中，然后做一些逻辑运算后返回，存到目标容器
	int operator()(int val)
	{
        val = val+100;
		return val;
	}

};

class MyPrint
{
public:
	void operator()(int val)
	{
		std::cout << val << " " << std::endl;
	}
};

void test01()
{   
    
	vector<int>v;//源容器
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
    
	vector<int>vTarget; //目标容器

	vTarget.resize(v.size()); // 目标容器需要提前开辟空间

	transform(v.begin(), v.end(), vTarget.begin(), TransForm());

	for_each(vTarget.begin(), vTarget.end(), MyPrint());
}

int main() {

	test01();
	return 0;
}