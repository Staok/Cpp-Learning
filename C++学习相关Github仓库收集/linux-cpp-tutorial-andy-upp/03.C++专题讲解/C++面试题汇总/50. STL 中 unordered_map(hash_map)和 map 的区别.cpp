//https://www.freesion.com/article/66231039919/
//此处以set和unordered_set(hash_set)为例子进行说明，map同理,代码有问题 没调试通过

#include<unordered_set> // hash_set则是#iunclude<hash_set>
using namespace std;

int main()
{
    unordered_set<int> set_fir; // 默认构造对象
    unordered_set<int> set_sed = { 2, 3, 10, 5, 9 }; //初始化构造

    set_sed.insert(7); // 插入7，放置在set中位置跟hash构建有关，并不是在尾部

    unordered_set<int>::iterator iter1 = set_sed.lower_bound(2); //返回set中>=2的索引(迭代器)，切记非小于2
    unordered_set<int>::iterator iter2 = set_sed.upper_bound(2); //返回set中>2的索引

    set_sed.erase(2); //删除set中元素2
    set_sed.erase(set_sed.begin(), set_sed.end()); //清空整个set

    if (set_sed.find(5) != set_sed.end()) // 查找键值为5的元素
        cout << "exsit" << endl;

    // 正向访问
    unordered_set<int>::iterator iter4;
    for (iter4 = set_sed.begin(); iter4 != set_sed.end(); iter4++)
        cout << *iter4 << endl;

    unordered_set<int>::reverse_iterator iter5; //对应反向迭代器对象
    // 反向访问
    for (iter5 = set_sed.rbegin(); iter5 != set_sed.rend(); iter5++)
        cout << *iter5 << endl;

    set_sed.count(12);     // 返回set中元素的个数，由于set的特殊性，所以结果只有0或者1
    set_sed.swap(set_fir); // 交换所有数据，需要确保set中元素类型相同
    set_sed.clear();       // 清空集合set_sed
    set_sed.size();        // 统计set_sed中元素个数
    set_sed.empty();       // 判断set中是否为空，空则返回1

    return 0;
}