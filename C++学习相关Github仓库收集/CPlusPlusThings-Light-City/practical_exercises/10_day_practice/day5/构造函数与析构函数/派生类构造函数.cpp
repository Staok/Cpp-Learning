#include <iostream>
using namespace std;
class Base{
private:
    int x;
public:
    Base(int a){
        x=a;
        cout<<"Base constructor x="<<x<<endl;
    }
    ~Base(){ cout<<"Base destructor..."<<endl; }
};
class Derived:public  Base{
private:
    int y;
public:
    Derived(int a,int b):Base(a){       //�����๹�캯���ĳ�ʼ���б�
        y=b;
        cout<<"Derived constructor y="<<y<<endl;
    }
    ~Derived(){ cout<<"Derived destructor..."<<endl; }
};
int main(){
    Derived d(1,2);
    system("pause");
    return 0;
} 