#include<iostream>
using namespace std;
/*
��1��cin.getline(arrayname,size)��cin.get(arrayname,size)������
cin.get(arrayname,size)������[enter]ʱ�����Ŀǰ���룬������ɾ���������е�[enter]
cin.getline(arrayname,size)������[enter]ʱ�������ǰ���룬���ǻ�ɾ���������е�[enter]
*/
int main()
{
    /*
	char a[10];
    char b;
    cin.get(a,10);
	cin.get(b);
    cout<<a<<endl<<int(b);//���룺12345[enter] �����12345 �����С� 10*/
    /*char c[10];
    char d;
    cin.getline(c,10);
    cin.get(d);
	cout<<c<<endl<<int(d);//���룺12345[enter]a[enter] �����12345�����С�97*/
    //cin.getline(arrayname,size,s)��cin.gei(arrayname,size,s)������
    /*
    cin.getline(arrayname,size,s)������sʱ��������룬����s�ӻ�������ɾ��
    cin.get��arrayname,size,s��������sʱ��������룬������ɾ���������е�s
    */
   /*
    char e[10];
    char f;
    cin.get(e,10,',');
	cin.get(f);
	cout<<e<<endl<<f;//���룺12345,[enter] �����12345�����С���˵����cin,get����ɾ���������ģ�*/
    char e1[10];
    char f1;
    cin.getline(e1,10,',');
	cin.get(f1);
	cout<<e1<<endl<<f1;//���룺asd,wqe �����asd�����С�w
    system("pause");
}
