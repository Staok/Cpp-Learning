#include<iostream>
using namespace std;

/*
功能描述：

*从字符串中获取想要的子串

函数原型：
*  string substr(int pos = 0, int n = npos) const;   //返回由pos开始的n个字符组成的字符串

总结： 灵活的运用求子串功能，可以在实际开发中获取有效的信息

*/

//子串
void test01()
{
	string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;

	string email = "hello@sina.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username: " << username << endl;

    string a;
    string s("123456789");
      
    a = s.substr(0,5);//拷贝字符串s中从第0位开始的长度为5的字符串
    cout << a << endl;//输出12345
      
    a=s.substr(); //不加参数即默认拷贝整个字符串s
    cout<<a<<endl;//输出123456789
     
    a=s.substr(4);//输出56789
    cout<<a<<endl;//单个参数则默认拷贝从第4位开始至末尾的字符串

}

int main() {

	test01();
	return 0;
}