//http://c.biancheng.net/view/491.html
//https://www.cnblogs.com/hailexuexi/archive/2012/04/10/2440209.html

#include <iostream>
#include <map>
#include <string>
using namespace std;

void test_map()
{
    map<int,string> m;
    /*
    在map中插入元素,map对[]进行了重载
    插入2时,先在m中查找主键为2的项，没发现，然后将一个新的对象
    插入m，键是2，值是一个空字符串，插入完成后，将字符串赋为
    "Two"; 该方法会将每个值都赋为缺省值，然后再赋为显示的值，
    如果元素是类对象，则开销比较大
    */
    m[1] = "One";
    m[2] = "Two";
    //用insert插入来避免开销
    m.insert(map<int,string>::value_type(3,"Three"));

    //查找并获取map中的元素
    //只有当map中有这个键的实例时才对，否则会自动插入一个实例，值为初始化值。
    //我们可以使用Find()和Count()方法来发现一个键是否存在。
    string s = m[2];
    string s1 = m[4];
    cout << "s: " << s << endl;
    cout << "s1: " << s1 << endl; //s1 的值被初始化为空

    //从map中删除元素
    //可以通过迭代器删除，也可以通过关键字删除
    m.erase(1);


    //遍历
    map<int,string>::iterator it;
    for(it = m.begin(); it != m.end(); ++it)
        cout << it->first << " " << it->second << endl;
    
}

int main()
{
    test_map();
    return 0;
}