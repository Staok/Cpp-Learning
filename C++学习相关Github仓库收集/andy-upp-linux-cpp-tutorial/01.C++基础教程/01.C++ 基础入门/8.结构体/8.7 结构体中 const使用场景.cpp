#include<iostream>
using namespace std;



/*
作用： 用const来防止误操作
*/

//学生结构体定义
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

//const使用场景
void printStudent(const student* stu) //加const防止函数体中的误操作
{
	//stu->age = 100; //操作失败，因为加了const修饰 ,常量指针无法修改指针指向的值
	cout << "姓名：" << stu->name << " 年龄：" << stu->age << " 分数：" << stu->score << endl;
}

int main() {

	student stu = { "张三",18,100 };
	printStudent(&stu);


	return 0;
}