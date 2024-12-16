/*
用 vector 或 string 的 at 成员函数根据下标访问元素时，
如果下标越界，则会拋出此异常
*/

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> v(10);
    try{
        v.at(100) = 100; //拋出 out_of_range 异常
    }catch(out_of_range& e){
        cerr << "vector越界异常:"  << e.what() << endl;
    }

    string s = "hello";
    try{
        char c = s.at(100); //拋出 out_of_range 异常
    }catch(out_of_range& e){
        cerr <<"string越界异常:" << e.what() << endl;
    }
    return 0;
}