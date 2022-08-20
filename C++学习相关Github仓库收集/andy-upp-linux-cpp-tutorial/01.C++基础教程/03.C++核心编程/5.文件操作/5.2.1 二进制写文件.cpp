#include<iostream>
#include<fstream>
using namespace std;


/*
以二进制的方式对文件进行读写操作

打开方式要指定为 ios::binary

二进制方式写文件主要利用流对象调用成员函数write

函数原型 ：ostream& write(const char * buffer,int len);

参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
文件输出流对象 可以通过write函数，以二进制方式写数据

*/

//二进制文件支持自定义数据类型 这里是将Person数据类型写入二进制文件中
class Person
{
public:
	char m_Name[64]; //对文件进行操作，最好还是用C语言的字符串，而不是C++的字符数组，因为底层是用C写的
	int m_Age;
};

//二进制文件  写文件
void test01()
{
	//1、包含头文件

	//2、创建输出流对象 这里是把第三步合到第二步了
	ofstream ofs("person.txt", ios::out | ios::binary);
	
	//3、打开文件
	//ofs.open("person.txt", ios::out | ios::binary);

	Person p = {"张三"  , 18};

	//4、写文件 把数据的地址转为const char *
	ofs.write((const char *)&p, sizeof(p));

	//5、关闭文件
	ofs.close();
}

int main() {

	test01();
	return 0;
}