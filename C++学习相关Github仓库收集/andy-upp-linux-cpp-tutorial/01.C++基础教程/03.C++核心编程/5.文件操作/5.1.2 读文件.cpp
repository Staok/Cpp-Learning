#include <fstream>
#include <string>
#include<iostream>
#include<string>
using namespace std;

/*
读文件与写文件步骤相似，但是读取方式相对于比较多
读文件步骤如下：

1. 包含头文件   
    #include <fstream>
2. 创建流对象  
   ifstream ifs;
3. 打开文件并判断文件是否打开成功
   ifs.open("文件路径",打开方式);
4. 读数据
   四种方式读取
5. 关闭文件
   ifs.close();

总结：
- 读文件可以利用 ifstream  ，或者fstream类
- 利用is_open函数可以判断文件是否打开成功
- close 关闭文件 
*/



void test01()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//第一种方式 把文件中的数据全都放到字符数组中
	// char buf[1024] = { 0 };
	// while (ifs >> buf) //当读到头 没有读到数据的时候，会返回一个假的标志，退出循环
	// {
	// 	cout << buf << endl;
	// }

	//第二种 按行读取
	// char buf[1024] = { 0 };
	// while (ifs.getline(buf,sizeof(buf)))
	// {
	// 	cout << buf << endl;
	// }

	//第三种 将数据读取到C++的字符串中
	// string buf;
	// while (getline(ifs, buf)) //这里的getline是一个全局函数
	// {
	// 	cout << buf << endl;
	// }

    //第四种 按字符读取 不推荐
	char c;
	while ((c = ifs.get()) != EOF) //每次只读一个字符，EOF是文件尾部的标志
	{
		cout << c;
	}

	ifs.close();


}

int main() {

	test01();
	return 0;
}