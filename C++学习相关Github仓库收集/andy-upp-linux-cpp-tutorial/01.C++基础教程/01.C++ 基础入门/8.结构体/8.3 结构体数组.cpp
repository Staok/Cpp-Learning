#include<iostream>
using namespace std;

/*
作用：将自定义的结构体放入到数组中方便维护
语法：struct  结构体名 数组名[元素个数] = {  {} , {} , ... {} }
*/


//结构体定义
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

int main() {
	//结构体数组
	struct student arr[3]=
	{
		{"张三",18,80 },
		{"李四",19,60 },
		{"王五",20,70 }
	};

	for (int i = 0; i < 3; i++)
	{
		cout << "姓名：" << arr[i].name << " 年龄：" << arr[i].age << " 分数：" << arr[i].score << endl;
	}

	return 0;
}