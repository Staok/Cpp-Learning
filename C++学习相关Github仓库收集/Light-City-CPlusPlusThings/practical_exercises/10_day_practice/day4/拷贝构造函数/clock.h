#ifndef CLOCK
# define CLOCK
class Clock
{
    public:
        Clock(int NewH,int NewM,int NewS);
        Clock(Clock &c);//�������캯��,������ӣ����������Զ�����һ���������캯������˼Ӳ��Ӷ�����ֱ��ʹ�á�
        void SetTime(int NewH,int NewM,int NewS);
        void ShowTime();
        ~Clock();//�������������������Զ�����һ��Ĭ�ϵ�����������
    private:
        int Hour,Minute,Second;
};

#endif


/*
#ifndef   ��ʶ��
       �����1
#else
       �����2
#endif
�������ʶ����δ������������������1�������������2��

*/