
//����12-2��  �ú���get��getline��ȡ���ݡ�
#include <iostream>
using namespace std;
//cin.get(arrayname,size)  ���ַ����뵽arrayname�У����Ȳ�����size
int main()
{
    //get()��������

    //1.���봮��<size�����봮��>arraylength�����Զ�����arrayname��С��ʹ�ܱ�����������
	// char a[10];
	// cin.get(a,20);
	// cout<<a<<endl;
    // cout<<sizeof(a)<<endl;
    //2.���봮��<size�����봮��<arraylength���Ѵ�ȫ�����룬���油��\0��
    // char b[10];
	// cin.get(b,20);
	// cout<<b<<endl;//12345����ʱ����������Ϊ��12345'\0��
    // cout<<sizeof(b)<<endl;
    //3.���봮��>size���Ƚ�ȡsize���ַ��������Ǵ���arraylength��������ǰarraylength-1���ַ�����󲹳䡮\0��
    // char c[5];
	// cin.get(c,10);
	// cout<<c<<endl;
    // cout<<sizeof(c)<<endl;
    //4.���봮��>size���Ƚ�ȡsize���ַ�����С��arraylength����ѽ�ȡ�����������У���󲹳䡮\0��
    // char d[10];
	// cin.get(d,5);
	// cout<<d<<endl;
    // cout<<sizeof(d)<<endl;
    
    //get()��������
    /*
        �÷���cin.get(arrayname,size,s) ?���������뵽arrayname�ַ������У������ﳤ��sizeʱ�������������ַ�sʱ����
        ע�ͣ�a�������ַ����飬��char a[]l���ͣ�����Ϊstring���ͣ�sizeΪ�������볤�ȣ�sΪ���ƣ�����s��ǰ����������������s��������

    */
    int i;
    char e[10];
    cin.get(e,8,',');
    cout<<e;
    system("pause");
    return 0;
}

