//https://blog.csdn.net/z685455/article/details/101583437
#include <iostream>
#include <map>
#include <string>
using namespace std;

void testInsert(map<int,string>& m)
{   /*
    四种方法异同：前三种方法当出现重复键时，编译器会报错，
    而第四种方法，当键重复时，会覆盖掉之前的键值对。
    */

    //第一种方式
    m.insert(pair<int,string>(1, "teacher1"));
    //第二种方式
    m.insert(make_pair<int,string>(2,"teacher2"));
    //第三种方式
    m.insert(map<int, string>::value_type(3, "teacher3"));
    //第四种方式
    m[4] = "teacher4";


    /*
    使用前三种方法可以的到一个返回值pair，该pair的类型是 
    pair<map<int, string>::iterator, bool>
    */
    pair<map<int, string>::iterator, bool> pair5 = m.insert(pair<int,string>(5,"teacher5"));
    if(pair5.second)
    {
        cout << "插入成功" << endl;
    }else{
        cout << "插入失败" << endl;
    }
    for(map<int,string>::iterator it = m.begin(); it != m.end(); ++it)
        cout << it->first << " " << it->second << endl;

}

int main()
{
    map<int, string> m;
    testInsert(m);
    return 0;
}