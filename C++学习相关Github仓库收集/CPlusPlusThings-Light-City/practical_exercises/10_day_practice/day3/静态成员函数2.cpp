#include<iostream>
using namespace std;
class A
{
    public:
        static void f(A a);
    private:
        int x;
};
void A::f(A a)
{
   
    //��̬��Ա����ֻ���������ڸ���ľ�̬���ݳ�Ա��̬��Ա������
    // cout<<x; //��x�������Ǵ����
    cout<<a.x;  //��ȷ
}

int main(int argc, char const *argv[])
{
    A a;
    a.f(A());
    system("pause");
    return 0;
}
