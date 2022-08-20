

//普通的函数一般是不能用来为constexpr常量赋值的，但是C++11允许定义一种constexpr的函数，
//这种函数在编译期间就可以计算出结果，这样的函数是可以用来为constexpr赋值的。
constexpr int size(int s)
{
    return s*4;
}
 
int a = 20;
const int b = 30;
constexpr int c = 40;
constexpr int si = size(a);  //error a是一个变量所以函数返回的是一个可变的值
constexpr int si1 = size(20); //ok 函数返回的实际上是一个常量
constexpr int si2 = size(b);  //ok
constexpr int si3 = size(c);  //ok