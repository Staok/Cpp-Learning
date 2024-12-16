//https://blog.csdn.net/qq_40056908/article/details/83538290?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.control
#include<iostream>
#include<map>
using namespace std;


//1.下标访问
void test_map_get1()
{
    map<int,int> m;
    m[1] = 111;
    m[2] = 222;
    m[3] = 333;
    cout << m[4] << endl; //自行初始化为0
}

//at(i)访问
void test_map_get2()
{
    map<int,int> m;
    m[1] = 111;
    m[2] = 222;
    m[3] = 333;
    //抛出异常 out_of_range: map::at:  key not found
    //这是一种安全的访问方式
    //cout << m.at(4) << endl; 
}


//find访问
void test_map_get3()
{
    /*
    multimap容器的元素添加方式不同于map，不能直接用
    m[key]=value的方式直接添加元素，必须用insert或者emplace
    */
    multimap<int,int> m; 
    m.insert({1,11});
    m.insert({1,12});
    m.insert({1,13});
    m.insert({1,14});
    m.insert({2,21});
    m.insert({3,31});
    //无法用前两种方式获取元素
    auto Find = m.find(1);
    auto Count = m.count(1);

    while (Count)
    {
        cout << Find->second << endl;
        Find++;
        Count--;
    }
}

//4.使用迭代器的解决方式 lower_bound\upper_bound
void test_map_get4()
{
    multimap<int,int> m; 
    m.insert({1,11});
    m.insert({1,12});
    m.insert({1,13});
    m.insert({1,14});
    m.insert({2,21});
    m.insert({3,31});
    //输出key为1和2的所有value
    for(auto lo = m.lower_bound(1), hi = m.upper_bound(2); lo != hi; lo++)
        cout << lo->second << endl;
}

//5.equal_range
//equal_range会返回一个pair，first是一个迭代器，
//指向匹配的第一个元素，second指向后一个。
void test_map_get5()
{
    multimap<int,int> m; 
    m.insert({1,11});
    m.insert({1,12});
    m.insert({1,13});
    m.insert({1,14});
    m.insert({2,21});
    m.insert({3,31});
    for(auto pos = m.equal_range(1); pos.first != pos.second; pos.first++)
        cout << pos.first->second << endl;
}




int main()
{
    //test_map_get();
    //test_map_get2();
    //test_map_get3();
    //test_map_get4();
    test_map_get5();
    return 0;
}