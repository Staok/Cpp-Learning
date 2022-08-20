//https://blog.csdn.net/ghosc/article/details/7008521?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.control

#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

/*
1、vector
vector在遍历中进行 erase(pos) ，这个时候iter++的时候
会出现bug，会跳过一个字段或者coredump。
当你用erase以迭代器方式删除vector中的元素时，
vector会自动将被删除元素后边的元素往上挪一位，
所以此时指向删除元素的迭代器指向了被删除元素后面的元素，
所以在循环中，此时迭代器就不应该加1了
解决方法：（要删除的时候直接赋值返回值，但是不能++）
*/
//测试vector
void test_vector()
{
    vector<int> vec = {1,2,3,4};
    vector<int>::iterator it;
    for(it = vec.begin(); it != vec.end();)
    {
        if(*it == 3)
        {
            it = vec.erase(it);
            //it++;
        }else{
            it++;
        }
        cout << "*it:" << *it << endl;

    }
}

/*
list在遍历中进行 erase(pos) ，
这个时候iter++的时候会出现bug，会直接coredump。
*/
//测试list
void test_list()
{
    list<int> li = {1,2,3,4,5};
    list<int>::iterator it;
    for(it = li.begin(); it != li.end(); ++it)
    {
        if(*it == 3)
        {
            //li.erase(*it);
            li.remove(*it++); //注意list不会自动指向下一个迭代器
        }
        cout << *it <<" ";
    }
    cout << endl;
}

/*
list在遍历中进行 erase(pos) ，
这个时候iter++的时候会出现bug，会出现未知问题。
*/
//测试map
void test_map()
{
    map<int,string> m;
    m[0] = "value1";
    m.insert(pair<int,string>(1, "value2"));
    m.insert(pair<int,string>(2, "value3"));

    map<int,string>::iterator it;
    for(it = m.begin(); it != m.end(); ++it)
    {
        if(it->second == "value2")
        {   
            // cout << "get value2" << endl;
            // cout << "key" << it->first << endl;
            //m.erase(it->first); //这样写会导致迭代器失效
            m.erase((it++)->first);
        }
        cout << it->first << " " << it->second << endl;
    }
}

int main()
{
    //test_vector();
    //test_list();
    test_map();
    return 0;
}