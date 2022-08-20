#include <vector>
#include <iostream>
using namespace std;

/*
功能描述：

* 创建vector容器

**函数原型：**

*  vector<T> v;             		   //采用模板实现类实现，默认构造函数
*  vector(v.begin(), v.end());         //将v[begin(), end())区间中的元素拷贝给本身。
*  vector(n, elem);                    //构造函数将n个elem拷贝给本身。
*  vector(const vector &vec);          //拷贝构造函数。

总结：vector的多种构造方式没有可比性，灵活使用即可
*/


void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int> v1; //无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	
	printVector(v1);
	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

    int arr[]={0,1,2,36};
    vector<int> vec(begin(arr),end(arr));

	vector<int> v3(10, 100);
	printVector(v3);
	
	vector<int> v4(v3);
	printVector(v4);
}

int main() {

	test01();
	return 0;
}