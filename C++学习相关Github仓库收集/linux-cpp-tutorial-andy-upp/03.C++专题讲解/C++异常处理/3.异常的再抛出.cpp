//如果一个函数在执行过程中拋出的异常在本函数内就被 catch 块捕获并处理，
//那么该异常就不会拋给这个函数的调用者（也称为“上一层的函数”）；
//如果异常在本函数中没有被处理，则它就会被拋给上一层的函数。


#include<iostream>
#include<string>
using namespace std;

class CException
{
public:
    string msg;
    CException(string s):msg(s){}
};

double Devide(double x, double y)
{
    if(y == 0)
        throw CException("devided by zero");
    cout << "in Devide" << endl;
    return x/y;
}

int CountTax(int salary)
{
    try{
        if(salary < 0)
            throw -1;
        cout << "counting tax" << endl;
    }catch(int){
        cout << "salary < 0" << endl;
    }
    cout << "tax counted" << endl;
    return salary*0.15;
}

int main()
{
    double f = 1.2;
    try{
        CountTax(-1);
        f = Devide(3,0);
        cout << "end of try block" << endl;
    }catch(CException e){
        cout << "打印抛出的异常语句" << endl;
        cout << e.msg << endl;
    }
    cout << "f = " << f <<endl;
    cout << "finishedd" << endl;
    return 0;
}