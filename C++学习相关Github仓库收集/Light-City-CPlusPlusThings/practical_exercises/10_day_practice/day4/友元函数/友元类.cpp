#include<iostream>
using namespace std;
/*
��һ����Ϊ��һ�������Ԫ�����������г�Ա���ܷ��ʶԷ����˽�г�Ա��
�����﷨������Ԫ��������һ������ʹ��friend����˵����
*/

/*
�������B����A�����Ԫ��B��ĳ�Ա�����Ϳ��Է���A���˽�кͱ������ݣ�
��A��ĳ�Ա����ȴ���ܷ���B���˽�С��������ݡ�
*/
class A{
  friend class B;
  public:
    void Display(){
      cout<<x<<endl;
    }
    private:
      int x;
};
class B
{   public:
      void Set(int i);
      void Display();
    private:
      A a;
};
void B::Set(int i)
{
   a.x=i;
}
void B::Display()
{
   a.Display();
}

int main(int argc, char const *argv[])
{
    B b;
    b.Set(10);
    b.Display();

    system("pause");
    return 0;
}

/*
�������B����A�����Ԫ��B��ĳ�Ա�����Ϳ��Է���A���˽�кͱ������ݣ���A��ĳ�Ա����ȴ���ܷ���B���˽�С���������
*/