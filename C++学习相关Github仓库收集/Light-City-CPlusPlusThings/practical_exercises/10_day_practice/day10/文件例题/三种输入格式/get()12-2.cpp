//����12-2��  �ú���get��getline��ȡ���ݡ�
#include <iostream>
using namespace std;
int main()
{
	char a,b,c,d;
	cin.get(a);
	cin.get(b);
	c = cin.get();
	d = cin.get();
	cout<<int(a)<<','<<int(b)<<','<<int(c)<<','<<int(d)<<endl;
    system("pause");
    return 0;
}

/*
�÷���a = cin.get() ?���� ?cin.get(a)
���������������ַ��㹻��س�
˵��������ǵ��ַ������룬��;������һ���ַ���������ASCALL����뵽a��
����������cin��ͬ��cin.get()�ڻ���������[enter]��[space]��[tab]������Ϊ���������Ǽ������ڻ�������
*/