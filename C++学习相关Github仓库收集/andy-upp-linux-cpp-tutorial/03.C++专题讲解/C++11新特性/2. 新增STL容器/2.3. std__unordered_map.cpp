#include <iostream>
#include <string>
#include <unordered_map>

//std::unordered_map与std::map用法基本差不多，但STL在内部实现上有很大不同，
//std::map使用的数据结构为二叉树，而std::unordered_map内部是哈希表的实现方式，
//哈希map理论上查找效率为O(1)。但在存储效率上，哈希map需要增加哈希表的内存开销。

int main()
{
    std::unordered_map<std::string, std::string> mymap =
    {
        { "house","maison" },
        { "apple","pomme" },
        { "tree","arbre" },
        { "book","livre" },
        { "door","porte" },
        { "grapefruit","pamplemousse" }
    };
    unsigned n = mymap.bucket_count();
    std::cout << "mymap has " << n << " buckets.\n";
    for (unsigned i = 0; i<n; ++i) 
    {
        std::cout << "bucket #" << i << " contains: ";
        for (auto it = mymap.begin(i); it != mymap.end(i); ++it)
            std::cout << "[" << it->first << ":" << it->second << "] ";
        std::cout << "\n";
    }
    return 0;
}

