//Eg9-6.cpp
#include <iostream>
#include<cstring>
using namespace std;
template <class T>
T Max(T a,T b) {
    return (a>b)?a:b;
}
//�ػ�
//template <> �������� ������<�ػ�����������>(������) {}
template<>char * Max<char *>(char *a,char *b) {
    return (strcmp(a,b)>=0)?a:b;
}
int main(){
    float  c=5.1,d=3.2;
    cout<<"2,3�����ֵ�ǣ�"<<Max(3,2)<<endl;   
    cout<<"c,d�����ֵ�ǣ�"<<Max(c,d)<<endl;   
    cout<<Max("xbv","xyce")<<endl;         
    system("pause");
}
/*
�� ��������ͬʱ����ģ��������ػ�ʱ���ػ��������ȵ��ã�
�� ��ͬһ�������У����˺���ģ��������ػ��⣬��������ͬ������ͨ����������������C++�����ͨ�����ĵ���ʵ�ν�����ʽ������ת����
�������ģ�庯�����ػ������Ĳ��������κ���ʽ������ת����

*/