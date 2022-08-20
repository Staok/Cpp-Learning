//https://blog.csdn.net/bryant_zhang/article/details/111600209
//http://m.biancheng.net/view/7248.html
/*
unordered_map在C++11的时候被引入标准库了，而hash_map并没有，
所以建议还是使用unordered_map比较好，这就好比一个是官方认证的，
一个是民间流传的。在编译器中，Visual Studio（当然需要支持C++11的版本）
库中两个数据结构都有定义，而在gcc/g++中并不支持hash_map。总之，
如果想使用这种基于哈希表的关联容器，那么就使用unordered_map就好了
所以此处讲解 unordered_map
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

//map和multimap底层都是红黑树
void map_test()
{
    vector<int> vec = {5, 14, 34, 22, 39, 5};
    map<int, int> map;
    for(int i = vec.size()-1; i >= 0; --i)
        map[i] = vec[i];

    //输出的数是有序的且有两个5
    //map是基于RBT的，因此元素是有序存储的(默认按 键 的升序排列)
    for(auto i = map.begin(); i != map.end(); ++i)
        cout << i->first << " " << i->second << endl;

    if(map.find(3) != map.end())
        cout << "find key=" << map.find(3)->first << ", value=" << map.find(3)->second << endl;
    
    //m.count(n)计算下标为n的位置有无数据，有返回1，无返回0
    if(map.count(5) > 0)
        cout << "count 5: " << map.count(5) << endl;
}

//unordered_map 是基于hash表的，因此元素是无序存储的（ 不按键 升序排列）。
void unordered_map_test()
{
    vector<int> vec = {5, 14, 34, 22, 39, 5};
    unordered_map<int, int> map;
    for(int i = vec.size()-1; i >= 0; --i)
        map[i] = vec[i];
    
    // cout << map[0] << endl;
    for (unordered_map<int, int>::iterator i = map.begin(); i != map.end(); i++) {
		cout << i->first << ' ' << i->second << endl;  //输出的数是有序的且有两个5
	}
	if (map.find(3) != map.end()) {
		cout << "find key=" << map.find(3)->first << ", value=" << map.find(3)->second << endl;
	}
	if (map.count(5) > 0) {  //m.count(n)计算下标为n的位置有无数据，有返回1，无返回0
		cout << "find 5: " << map.count(5) << endl;  //find()和count()的输入都是key值
	}

}

/*
和 unordered_map 容器一样，unordered_multimap 容器也以键值对的形式存储数据，
且底层也采用哈希表结构存储各个键值对。两者唯一的不同之处在于，unordered_multimap 
容器可以存储多个键相等的键值对，而 unordered_map 容器不行。
*/
void unorderedmulti_map_test()
{
    //创建空容器
    std::unordered_multimap<std::string, std::string> myummap;
    //向空容器中连续添加 5 个键值对
    //通过使用成员函数 emplace()，可以在 vector 序列中插入新的元素。
    //对象会在容器中直接生成，而不是先单独生成对象，然后再把它作为参数传入。
    myummap.emplace("Python教程", "http://c.biancheng.net/python/");
    myummap.emplace("STL教程", "http://c.biancheng.net/stl/");
    myummap.emplace("Java教程", "http://c.biancheng.net/java/");
    myummap.emplace("C教程", "http://c.biancheng.net");
    myummap.emplace("C教程", "http://c.biancheng.net/c/");
    //输出 muummap 容器存储键值对的个数
    cout << "myummmap size = " << myummap.size() << endl;
    //利用迭代器输出容器中存储的所有键值对
    for (auto iter = myummap.begin(); iter != myummap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
}


int main()
{   
    //map_test();
    //unordered_map_test();
    unorderedmulti_map_test();
    return 0;
}