/*
֪ʶ�㣺
��̬��Ա����
����������ʹ������������������������þ�̬��Ա������
��̬��Ա����ֻ���������ڸ���ľ�̬���ݳ�Ա��̬��Ա������
*/
#include<iostream>
using namespace std;
class Application
{ 
public:
    static void f(); 
    static void g();
private:
    static int global;
};
int Application::global=0;
void Application::f()
{  global=5;}
void Application::g()
{  cout<<global<<endl;}

int main()
{
    Application::f();
    Application::g();
    system("pause");
    return 0;
}

