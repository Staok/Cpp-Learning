#include <functional>
#include <list>
//function
//lambda

int funA(int a, int b)
{
	printf("funA\n");
	return 0;
}

int main()
{
	//std::list< int > a;
	//std::function< int(int, int) > call = funA;
	//int n = call(0,2);

	std::function< int(int,int) > call;

	int n = 5;
	//��������
	call = [n/*�ⲿ���������б�*/](/*�����б�*/int a,int b) -> int/*����ֵ����*/
	{
		//������
		printf("%d\n",n+a+b);
		return 2;
	};

	int f = call(3,1);
	return 0;
}

/* lambda���ʽ  ��������ʽ ��������
[ caputrue ] ( params ) opt -> ret { body; };

[ �ⲿ���������б� ] ( ������ ) ��������� -> ����ֵ���� { ������; };

�����б�lambda���ʽ�Ĳ����б�ϸ������lambda���ʽ�ܹ����ʵ��ⲿ�������Լ���η�����Щ������

1) []�������κα�����

2) [&]�����ⲿ�����������б���������Ϊ�����ں�������ʹ�ã������ò��񣩡�

3) [=]�����ⲿ�����������б���������Ϊ�����ں�������ʹ��(��ֵ����)��

4) [=, &foo]��ֵ�����ⲿ�����������б������������ò���foo������

5) [bar]��ֵ����bar������ͬʱ����������������

6) [this]����ǰ���е�thisָ�룬��lambda���ʽӵ�к͵�ǰ���Ա����ͬ���ķ���Ȩ�ޡ�
����Ѿ�ʹ����&���� = ����Ĭ�Ϻ��д�ѡ�
����this��Ŀ���ǿ�����lamda��ʹ�õ�ǰ��ĳ�Ա�����ͳ�Ա������

////////
1).capture�ǲ����б�

2).params�ǲ�����(ѡ��)

3).opt�Ǻ���ѡ�������mutable,exception,attribute��ѡ�

mutable˵��lambda���ʽ���ڵĴ�������޸ı�����ı��������ҿ��Է��ʱ�����Ķ����non-const������

exception˵��lambda���ʽ�Ƿ��׳��쳣�Լ������쳣��

attribute�����������ԡ�

4).ret�Ƿ���ֵ���͡�(ѡ��)

5).body�Ǻ����塣
*/