#include<iostream>
#include<string>
using namespace std;

/*
2.6 字符串型
作用：用于表示一串字符
两种风格
*/
   int main() {
      //1.C风格字符串: char 变量名[] = "字符串值",C风格的字符串要用双引号括起来

   	char str1[] = "hello world";
   	cout << str1 << endl;
       

      //2.C++风格字符串： string  变量名 = "字符串值"
      string str = "hello world1";
   	cout << str << endl;

   	return 0;
   }




