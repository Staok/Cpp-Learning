#include<iostream>
using namespace std;
class Figure{
    protected:
        double x,y;
    public:
        void set(double i, double j){
            x=i;y=j;
        }
        virtual void area()=0;
};

class Trianle:public Figure{
    public:
        void area(){
            cout<<"�����������"<<x*y*0.5<<endl;
        }
};
class Rectangle:public Figure{
    public:
        void area(){
            cout<<"���Ǿ��Σ���������ǣ�"<<x*y<<endl;
        }
};

int main(int argc, char const *argv[])
{
    //���������ָ��
    Figure *pF=NULL;
    // Figure f1; �����಻�ܱ�ʵ����
    Rectangle r;
    Trianle t;
    t.set(10,20);
    pF=&t;
    pF->area();
    r.set(10,20);
    pF=&r;
    pF->area();
    //�������������
    Figure &rF=t;
    rF.set(20,20);
    rF.area();
    system("pause");
    return 0;
}

