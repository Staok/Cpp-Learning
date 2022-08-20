/*

 容器分为顺序容器和关联容器，其中Unordered container 是C++11新出的容器，本质上也是关联容器 ，底部是哈希表


    顺序容器：
    array : C++11新增 ，将C++语言的数组包装成class，连续空间，无法扩充，
	vector：元素可扩充的数组，由分配器自动分配内存
	deque： 双向队列 前后都可以扩充 (deque)
	list：双向链表
	forward-list：C++11新增，单向链表，内存占用比list小
	
	关联容器：
	set/multiset： 底层是红黑树实现，set的key就是value，value就是key，muitiset表示key可以重复
	map/multimap：底层是红黑树实现，每个节点包括key和value，multimap表示key可以重复
	unordered container :无序容器，底层是哈希表，用拉链法解决hash碰撞问题
	
	没讲的：
	string
	stack

总共10种容器，顺序7种，关联3种
*/

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int main()
{
    int ia[6] = {27,210,12,47,109,83};
    //vector为容器  vector为分配器（默认可以不写）
    vector<int,vector<int> > vi(ia,ia+6);
    //count_if为算法 begin和end会传回迭代器 notl和bind2nd为适配器 less为仿函数
    //计算小于40的数有几个
    cout << count_if(vi.begin(), vi.end(),
                not1(bind2nd(less<int>(), 40)));


    return 0;
}