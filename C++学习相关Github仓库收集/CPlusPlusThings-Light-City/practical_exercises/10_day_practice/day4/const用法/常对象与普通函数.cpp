#include<iostream>
using namespace std;
class R
{    public:
         R(int r1, int r2){R1=r1;R2=r2;}
         //const���ֳ�Ա���غ���
         void print();
         void print() const;
      private:
         int R1,R2;
};
/*
����Ա����˵����ʽ������˵����  ��������������const;
���const�Ǻ������͵�һ����ɲ��֣������ʵ�ֲ���ҲҪ��const�ؼ��֡�
const�ؼ��ֿ��Ա����ڲ�������غ���������
ͨ��������ֻ�ܵ������ĳ���Ա����
*/

void R::print()
{     
    cout<<"��ͨ����"<<endl;
    cout<<R1<<":"<<R2<<endl;
}
//ʵ����Ҳ��Ҫ����
void R::print() const
{     
    cout<<"���������"<<endl;
    cout<<R1<<";"<<R2<<endl;
}
int main()
{   
    R a(5,4);
    a.print();  //����void print()
    //ͨ��������ֻ�ܵ������ĳ���Ա����
    const R b(20,52);  
    b.print();  //����void print() const
    system("pause");
    return 0;
}


