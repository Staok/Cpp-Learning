#include<iostream>
using namespace std;

/*
* 作用：通过指针访问结构体中的成员
* 利用操作符 `-> `可以通过结构体指针访问结构体属性
* 总结：结构体指针可以通过 -> 操作符 来访问结构体中的成员
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
	
	struct student stu = { "张三",18,100, };
	
	struct student* p = &stu;
	
	p->score = 80; //指针通过 -> 操作符可以访问成员
	cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;
	
	return 0;
}