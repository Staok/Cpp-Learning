/*
������protected�ĳ�Ա
���ڲ������Է���
���ʹ���ߣ����ܷ���
����������Ա�����Է���
*/
#include<iostream>
class B
{	
    private: 
        int i;
	protected: 
        int j;
	public: 
        int k;
};
class D: public B
{
public:
	void f() 
	{	
        i=1;//cannot access �����಻�ɷ��ʻ���˽�г�Ա
		j=2;//��������Է��ʻ��ౣ����Ա	
        k=3;	
    }
};
int main()
{	
    B b; 
	b.i=1;//cannot access ˽�г�Ա�����ʹ���߲��ܷ���
	b.j=2; //cannot access ������Ա�����ʹ���߲��ܷ���
	b.k=3;
    system("pause");
    return 0;
}

