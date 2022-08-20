//http://c.biancheng.net/cpp/biancheng/view/3297.html

#include <iostream>
#include <cstdlib>
using namespace std;

class Complex{
public:
    Complex(double real = 0.0, double imag = 0.0): m_real(real), m_imag(imag){ }
public:
    operator double() const { return m_real; }  //类型转换函数
private:
    double m_real;
    double m_imag;
};

int main(){
    //下面是正确的用法
    int m = 100;
    Complex c(12.5, 23.8);
    long n = static_cast<long>(m);  //宽转换，没有信息丢失
    char ch = static_cast<char>(m);  //窄转换，可能会丢失信息
    int *p1 = static_cast<int*>( malloc(10 * sizeof(int)) );  //将void指针转换为具体类型指针
    void *p2 = static_cast<void*>(p1);  //将具体类型指针，转换为void指针
    double real= static_cast<double>(c);  //调用类型转换函数
   
    //下面的用法是错误的
    float *p3 = static_cast<float*>(p1);  //不能在两个具体类型的指针之间进行转换
    p3 = static_cast<float*>(0X2DF9);  //不能将整数转换为指针类型

    return 0;
}