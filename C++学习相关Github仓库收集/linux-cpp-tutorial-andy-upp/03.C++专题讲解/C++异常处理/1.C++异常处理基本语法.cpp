/*
  异常处理机制。其基本思想是：函数 A 在执行过程中发现异常时可以不加处理，
而只是“拋出一个异常”给 A 的调用者，假定为函数 B。
  拋出异常而不加处理会导致函数 A 立即中止，在这种情况下，函数 B 可以选择捕获
A 拋出的异常进行处理，也可以选择置之不理。如果置之不理，这个异常就会被拋给 B 的调用者，以此类推。
  如果一层层的函数都不处理异常，异常最终会被拋给最外层的 main 函数。main 函数应该处理异常。
如果main函数也不处理异常，那么程序就会立即异常地中止。
*/

#include <iostream>
using namespace std;
int main()
{
    double m, n;
    cin >> m >> n;

    try{
        cout << "before dividing." << endl;
        if( n == 0)
            throw -1; //抛出int类型异常
        else
            cout << m/n << endl;
    }catch(double d){
        cout << "catch(double)" << d << endl;
    }catch(int e){
        cout << "catch(int)" << e << endl;
    }
    cout << "finished" << endl;
    return 0;
}