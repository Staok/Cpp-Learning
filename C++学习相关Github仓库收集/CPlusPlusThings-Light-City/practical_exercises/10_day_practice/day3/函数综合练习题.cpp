/*
һԲ����Ӿ����ͼ��ʾ��������������Χ��һԲ�͹���������������Χ��դ����դ���۸�Ϊ35Ԫ/�ף��������Ϊ20Ԫ/ƽ���ס�
�������Ϊ3�ף���Ӿ�ذ뾶�ɼ������롣Ҫ���̼��㲢���������դ������ۡ�

ͼ����������ԲǶ��СԲ��
СԲ�ڴ�Բ�м䣬СԲΪ��Ӿ�أ���Բ��СԲ���Ϊ������
*/
#include<iostream>
using namespace std;
const float PI=3.14159;
const float FencePrice=35;
const float ConcretePrice=20;

class Circle
{
    private:
        float radius;
    public:
        Circle(float r);
        float Circumference() const;
        float Area() const;
};
Circle::Circle(float r)
{
    radius=r;
}

// ����Բ���ܳ�
float Circle::Circumference() const
{
    return 2 * PI * radius;
}
        
// ����Բ����� 
float Circle::Area() const
{
    return PI * radius * radius;
}

int main(int argc, char const *argv[])
{
    float radius;
    float FenceCost, ConcreteCost; 
    
    // ��ʾ�û�����뾶
    cout<<"Enter the radius of the pool: ";
    cin>>radius;

    // ���� Circle ����
    Circle Pool(radius);
    Circle PoolRim(radius + 3);       
    // ����դ����۲����
    FenceCost = PoolRim.Circumference() * FencePrice;
    cout << "Fencing Cost is ��" << FenceCost << endl;
    
    //  ���������۲����
    ConcreteCost = (PoolRim.Area() - Pool.Area())*ConcretePrice;
    cout << "Concrete Cost is ��" << ConcreteCost << endl;
    system("pause");
    return 0;
}
