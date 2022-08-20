//https://blog.csdn.net/bryant_zhang/article/details/111600209
//http://m.biancheng.net/view/7251.html
/*
unordered_set在C++11的时候被引入标准库了，而hash_set并没有，
所以建议还是使用unordered_set比较好，这就好比一个是官方认证的，
一个是民间流传的。在编译器中，Visual Studio（当然需要支持C++11的版本）
库中两个数据结构都有定义，而在gcc/g++中并不支持hash_set。总之，
如果想使用这种基于哈希表的关联容器，那么就使用unordered_set就好了
所以此处讲解 unordered_set
*/

#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

//set
void set_test()
{
    vector<int> vec = { 5,14,34,22,39,5 };
    set<int> set1;
    for(int i = vec.size()-1; i >= 0; --i)
        set1.insert(vec[i]);

    //自动排序且去重
    for(auto i = set1.begin(); i != set1.end(); ++i)
        cout << *i << " ";
    cout << endl;

    cout <<"find 5: " << *set1.find(5) << endl;
	cout <<"count 5: " << set1.count(5) << endl;
}


//unordered_set unordered_set的内部实现了一个 哈希表，因此， 其元素的排列顺序是无序的
void unordered_set_test()
{
    vector<int> vec = { 5,14,34,22,39,5 };
	unordered_set<int> set;
	for (int i = vec.size() - 1; i >= 0; i--) {
		set.insert(vec[i]);  //倒序插入
	}

    //无序且去重
	for (unordered_set<int>::iterator i = set.begin(); i != set.end(); i++) {
		cout << *i << endl;  //输出的数是无序的且只有一个5
	}
	cout << " find 39: " << *set.find(39) << endl;
	cout << "count 14:" << set.count(14) << endl;
}

/*
和 unordered_set 容器不同的是，unordered_multiset 容器可以同时存储
多个值相同的元素，且这些元素会存储到哈希表中同一个桶（本质就是链表）上。
*/
void unordered_multiset_test()
{
    //创建一个空的unordered_multiset容器
    std::unordered_multiset<std::string> umset;
    //给 uset 容器添加数据
    //通过使用成员函数 emplace()，可以在 vector 序列中插入新的元素。
    //对象会在容器中直接生成，而不是先单独生成对象，然后再把它作为参数传入。
    umset.emplace("http://c.biancheng.net/java/");
    umset.emplace("http://c.biancheng.net/c/");
    umset.emplace("http://c.biancheng.net/python/");
    umset.emplace("http://c.biancheng.net/c/");
    //查看当前 umset 容器存储元素的个数
    cout << "umset size = " << umset.size() << endl;
    //遍历输出 umset 容器存储的所有元素
    for (auto iter = umset.begin(); iter != umset.end(); ++iter) {
        cout << *iter << endl;
    }
}


int main()
{
    //set_test();
    //unordered_set_test();
    unordered_multiset_test();
    return 0;
}