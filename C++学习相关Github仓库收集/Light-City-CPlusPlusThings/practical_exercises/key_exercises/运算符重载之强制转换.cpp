/*
��һ����Circle����Ƹ��������ת������������Circle����ת����int��ʱ������Բ�İ뾶��������ת����double��ʱ���ͷ���Բ���ܳ���������ת����float��ʱ���ͷ���Բ�������
*/

/*

����ת������û�в�����
����ת������û�з������͡�
����ת���������뷵�ؽ�Ҫת���ɵ�type�������ݡ�

*/

#include <iostream>
using namespace std;
class Circle{
private:
    double x,y,r;
public:
    Circle(double x1,double y1,double r1){x=x1;y=y1;r=r1;	}
    operator int(){return int(r);}
    operator double(){return 2*3.14*r;}
    operator float(){return (float)3.14*r*r;}
};
int main(){
    Circle c(2.3,3.4,2.5);
    int r=c;        //����operator int()����Circle����ת����int
    double length=c;   //����operator double()��ת����double
    float area=c;   //����operator float()����Circle����ת����float
    double len=(double) c;	//��Cirlce���Ͷ���ǿ��ת����double
    cout<<r<<endl;
    cout<<length<<endl;
    cout<<len<<endl;
    cout<<area<<endl;
    system("pause");
}
