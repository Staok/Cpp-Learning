#include <iostream>
using namespace std;
class A {
    int a;
public: 
    A(int x) {
        a=x;
        cout<<"Virtual Bass A..."<<endl; 
    }
}; 
class B:virtual public A {
public: 
    B(int i):A(i){ cout<<"Virtual Bass B..."<<endl; }
};
class C:virtual public A{
    int x;
public:
    C(int i):A(i){
        cout<<"Constructing C..."<<endl;
        x=i; 
    }
};
class ABC:public C, public B {
public: 
    //������������������ʼ�� 
    ABC(int i,int j,int k):C(i),B(j),A(i) //L1����������A���г�ʼ��
        { cout<<"Constructing ABC..."<<endl; }
}; 
int main(){
    ABC obj(1,2,3);
    system("pause");
    return 0;
}
