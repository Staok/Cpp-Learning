#include<iostream>   
#include<cmath>   
using namespace std;   
  
/*  
 *  ʱ����  
 */  
class Clock    
{   
private:    
    int Hour, Minute, Second;   
public:    
    Clock(int h=0, int m=0, int s=0);   
    void ShowTime();   
    Clock& operator ++();    
    Clock operator ++(int);   
};   
  
/*  
 *  ʱ���๹�캯��  
 */  
Clock::Clock(int h,int m, int s)   
{   
    if(h>=0 && h<24 && m>=0 && m<60 && s>=0 && s<60)   
    {   
        Hour = h;   
        Minute =m;    
        Second= s;   
    }   
    else  
        cout<<"�����ʱ���ʽ����!"<<endl;   
}   
  
/*  
 *  ��ʾʱ��  
 */  
void Clock::ShowTime()   
{   
    cout<<Hour<<":"<<Minute<<":"<<Second<<endl;   
}   
  
/*  
 *  ʱ�����һ�루����ǰ׺++�������  
 */  
Clock& Clock::operator ++()    
{    
    Second++;   
    if (Second >= 60)   
    {   
        Second = Second - 60;   
        Minute++;   
        if (Minute >= 60)   
        {   
            Minute = Minute - 60;   
            Hour++;   
            Hour = Hour % 24;   
        }   
    }   
    return *this;   
}   
  
/*  
 *  ʱ�����һ�루���غ�׺++�������  
 */  
Clock Clock::operator ++(int)   
{   
    Clock old = *this;   
    ++(*this);   
    return old;   
}   
  
/*  
 *  ������  
 */  
int main()   
{   
    Clock myClock(23,59,59);   
    cout<<"��ʼ����ʾʱ��Ϊ:\t\t";   
    myClock.ShowTime();   
  
    cout<<"ִ��myClock++���ʱ��Ϊ:\t";   
  
    //��ִ��ShowTime()�����myClock=23:59:59��   
    //��ִ��myClock++����ʱmyClock=00:00:00   
    (myClock++).ShowTime();   
  
    cout<<"ִ��++myClock���ʱ��Ϊ:\t";   
  
    //��ִ��++myClock����ʱmyClock=00:00:01   
    //��ִ��ShowTime()�����myClock=00:00:01   
    (++myClock).ShowTime();   
    system("pause");
}  