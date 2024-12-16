//https://www.cnblogs.com/linuxAndMcu/p/10260124.html
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

//定义及初始化
namespace deque_test1
{
    void test_deque_init()
    {
        deque<int> a;
        deque<int> a1(10);
        deque<int> a2(10, 1);
        deque<int> b(a);
        // 将双端队列a中从第0个到第2个(共3个)作为双端队列b的初始值
        deque<int> b1(a1.begin(), a1.begin()+3); 
        //用数组初始化向量
        int n[] = {1,2,3,4,5};
        //将数组n的前5个元素作为双端队列的初始值
        deque<int> a3(n, n+5);
        // 将n[1]、n[2]、n[3]作为双端队列a的初值
        deque<int> b2(&n[1], &n[4]);
    }
}

//容量函数
namespace deque_test2 
{
    void test_deque_capacity()
    {
        deque<int> deq;
        for(int i = 0; i < 6; ++i)
            deq.push_back(i);

        cout << deq.size() << endl;
        cout << deq.max_size() << endl;
        deq.resize(0);  //更改元素大小
        if(deq.empty())
            cout << "元素为空" << endl;
    }
}

//添加函数
namespace deque_test3
{
    void test_deque_insert()
    {
        deque<int> deq;
        //头部添加元素
        deq.push_front(4);//    4 <-
        //尾部添加元素
        deq.push_back(5);   // ->5 4
        //任意位置插入一个元素
        deque<int>::iterator it = deq.begin();
        deq.insert(it, 2);  // 5 4 2 <-
        //任意位置插入n个相同的元素
        it = deq.begin();
        deq.insert(it,3,9); //5 4 2 9 9 9 <-
        //插入另一个向量的[first, last]间的数据
        deque<int> deq2(5,8);
        it = deq.begin();
        deq.insert(it, deq2.end()-1, deq2.end()); //5 4 2 9 9 9 8<-

        deque<int> deq3;
        deq3.push_back(1); // ->1
        deq3.push_back(2);//  ->21 
        deq3.push_back(3);//  ->321
        deq3.push_front(4); //3214<-
        //遍历显示
        for(it = deq.begin(); it != deq.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
}

//删除函数
namespace deque_test4
{

    void test_deque_erase()
    {
        deque<int> deq;
        for(int i = 0; i < 8; ++i)
            deq.push_back(i);
        
        //头部删除元素
        deq.pop_front();
        //末尾删除元素
        deq.pop_back();
        //任意位置删除一个元素
        deque<int>::iterator it = deq.begin();
        deq.erase(it);
        //删除[first, last]之间的元素
        deq.erase(deq.begin(), deq.begin()+1);

        //遍历显示
        for(it = deq.begin(); it != deq.end(); ++it)
            cout << *it << " ";
        cout << endl;

        //清空所有元素
        deq.clear();
        //遍历显示
        for(it = deq.begin(); it != deq.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
}

//访问函数
namespace deque_test5
{
    void test_deque_get()
    {
        deque<int> deq;
        for(int i = 0; i < 6; ++i)
            deq.push_back(i);
        
        //下标访问
        cout << deq[0] << endl;
        //at方法访问
        cout << deq.at(0) << endl;
        //访问第一个元素
        cout << deq.front() << endl;
        //访问最后一个元素
        cout << deq.back() << endl;
    }
}

//其他函数
namespace deque_test6
{

    void test_deque_others()
    {
        //多个元素赋值
        deque<int> deq;
        deq.assign(3,1);
        deque<int> deq2;
        deq2.assign(3,2);

        //交换两个容器的元素
        deq.swap(deq2);

        //遍历显示
        cout << "deq: ";
        for(int i = 0; i <deq.size(); ++i)
            cout << deq[i] << " "; 
        cout << endl;

        //遍历显示
        cout << "deq2: ";
        for(int i = 0; i <deq2.size(); ++i)
            cout << deq2[i] << " ";
        cout << endl;
    }
}

//迭代器与算法
namespace deque_test7
{   
    void test_deque_iterator()
    {
        deque<int> deq;
        deq.push_back(1);
        deq.push_back(2);
        deq.push_back(3);

        cout << *(deq.begin()) << endl; // 输出：1
        cout << *(--deq.end()) << endl; // 输出：3
        cout << *(deq.cbegin()) << endl; // 输出：1
        cout << *(--deq.cend()) << endl; // 输出：3
        cout << *(deq.rbegin()) << endl; // 输出：3
        cout << *(--deq.rend()) << endl; // 输出：1
        cout << endl;
    }

    void test_deque_algorithm()
    {
        deque<int> deq{1,2,3,4};
        //遍历
        deque<int>::iterator it;
        for (it = deq.begin(); it != deq.end(); it++)
            cout << *it << endl;
        // 或者
        for (int i = 0; i < deq.size(); i++) {
            cout << deq.at(i) << endl;
        }


        //元素翻转
        reverse(deq.begin(), deq.end());

        //元素排序
        sort(deq.begin(), deq.end()); // 采用的是从小到大的排序

        // // 如果想从大到小排序，可以采用先排序后反转的方式，也可以采用下面方法:
        // // 自定义从大到小的比较器，用来改变排序方式
        // bool Comp(const int& a, const int& b) {
        //     return a > b;
        // }

        // sort(deq.begin(), deq.end(), Comp);
    }
}


int main()
{
    //deque_test1::test_deque_init();
    //deque_test2::test_deque_capacity();
    //deque_test3::test_deque_insert();
    //deque_test4::test_deque_erase();
    //deque_test5::test_deque_get();
    //deque_test6::test_deque_others();
    deque_test7::test_deque_iterator();
    deque_test7::test_deque_algorithm();
    return 0;
}