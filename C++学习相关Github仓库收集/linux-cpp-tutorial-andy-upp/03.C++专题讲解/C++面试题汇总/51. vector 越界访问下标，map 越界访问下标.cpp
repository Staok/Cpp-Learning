//https://blog.csdn.net/zhu2695/article/details/9466125?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-2&spm=1001.2101.3001.4242


/*
对于Vector容器，用aVector[i]访问第i个元素时，如果元素不存在，容器不会增加元素， 
而对于map,用aMap[key] 
访问键key对应的对象时，如果该键对应的对象存在，则返回该对象（这和Vector一样），
但是，当键值为key的元素不存在时，容器会自动的增加一个pair，键为key,而值则为一个容
器定义时指定的类型并默认初始化（即，如果该类型为基本类型，则初始化为0，比如本例中，
aMap[1]的使用会产生一个pair,<1,NULL>，若该类型为类类型，则调用默认构造函数初始化之） 
*/
#include <iostream> 
#include <map> 

using namespace std; 

struct A 
{ 
    A(int i) 
    { 
        x=i; 
    } 
    int x; 
}; 

int main() 
{ 
    /*
    显然，本例中，aMap[1]为NULL，后面的erase()不会执行，使得后面的 
    插入语句aMap.insert(1,new A())键值冲突  ??
    */
    map<int,A*> amap; 
    if ( amap[1] != NULL ) 
        amap.erase(1); 
    amap.insert(make_pair(1,new A(1))); 
    amap.insert(make_pair(2,new A(2))); 
    amap.insert(make_pair(3,new A(3))); 
    return 0; 
} 