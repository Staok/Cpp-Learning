//Eg9-2.cpp
#include <iostream>
using namespace std;
template <class T>
T Max(T a,T b) {
		return (a>b)?a:b;
}
/*
C++��ʵ��������ģ��Ĺ����У�ֻ�Ǽ򵥵ؽ�ģ������滻�ɵ���ʵ�ε����ͣ����Դ�����ģ�庯����������в������͵��κ�ת����
*/
int main(){
    double a=2,b=3.4;
    float  c=5.1,d=3.2;
    //��ģ�����ʱ���в������͵�ǿ��ת��
    cout<<"2, 3.2    �����ֵ�ǣ�"<<Max(double(2),3.2)<<endl;
    cout<<"a, c    �����ֵ�ǣ�"<<Max(float(a),c)<<endl;
    //��ʾָ������ģ��ʵ�����Ĳ�������
    cout<<"'a', 3    �����ֵ�ǣ�"<<Max<int>('a',3)<<endl;
    system("pause");
}

