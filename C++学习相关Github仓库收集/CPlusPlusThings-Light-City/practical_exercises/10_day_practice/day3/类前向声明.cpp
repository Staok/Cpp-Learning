/*
ʹ��ǰ������������Ȼ���Խ��һЩ���⣬�������������ܵġ���Ҫע����ǣ�
����ʹ����ǰ�������������������ṩһ��������������֮ǰ��������������Ķ���
Ҳ������������Ա������ʹ�ø���Ķ����뿴����ĳ���Σ�
*/

//��һ��
#include<iostream>
class Fred;	//ǰ����������
class Barney {
   Fred x;	//������Fred�������в�����
};
class Fred {
   Barney y;
};


//�ڶ���
class Fred;	//ǰ����������
 
class Barney {
 public:
   void method()
   {
     x->yabbaDabbaDo();	//����Fred��Ķ����ڶ���֮ǰ��ʹ��
   }
 private:
   Fred* x;   //��ȷ������ǰ��������������������Fred��Ķ���ָ��
 };
 
class Fred {
 public:
   void yabbaDabbaDo();
 private:
   Barney* y;
}; 

/*
�ܽ᣺��ʹ��ǰ����������ʱ��ֻ��ʹ�ñ������ķ��ţ��������漰����κ�ϸ�ڡ�
*/