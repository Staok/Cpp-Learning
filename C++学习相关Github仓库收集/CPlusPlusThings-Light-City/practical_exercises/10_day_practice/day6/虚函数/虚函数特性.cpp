#include <iostream>
#include<string>
using namespace std;
class A { 
public: 
    void f(int i){cout<<"A::f()"<<endl;};
};
class B: public A { 
public:
    virtual void f(int i){cout<<"B::f()"<<endl;}
};
class C: public B {
public: 
    void f(int i){cout<<"C::f()"<<endl;}
};
//һ����ĳ����Ա��������Ϊ�麯�������ڼ̳���ϵ�о���ԶΪ�麯���� 
class D: public C{
public:
    void f (int){cout<<"D::f()"<<endl;}
};
int main(){
    A *pA,a;
    B *pB, b;    C c;    D d;
    pA=&a;    pA->f(1);		//����A::f
    pB=&b;    pB->f(1);		//����B::f
    pB=&c;    pB->f(1);		//����C::f
    pB=&d;    pB->f(1);		//����D::f
    system("pause");
    return 0;
}
