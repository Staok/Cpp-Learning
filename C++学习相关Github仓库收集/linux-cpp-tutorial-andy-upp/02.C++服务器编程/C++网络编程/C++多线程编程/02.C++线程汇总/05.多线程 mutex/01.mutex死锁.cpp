#include <list>
#include <iostream>
#include <mutex>
#include <algorithm>
#include <thread>
#include <unistd.h>
using namespace std;

//https://www.cnblogs.com/xiaoshiwang/p/9880228.html

class data_protect
{
public:
    void add_list(int val)
    {
        m.lock();
        alist.push_back(val);
    }

    bool contains(int val)
    {
        m1.unlock();//m1 无法解开m的锁，导致死锁
        return find(alist.begin(), alist.end(), val) != alist.end();
    }

public:
    list<int>  alist{1,2};
    mutex m;
    mutex m1;
};

void func(data_protect& dp)
{
    dp.add_list(12);
}


int main()
{
    data_protect dp;
    thread t(func, ref(dp));
    t.detach();
    dp.add_list(12);//调用add_list()方法，进去后，发现是上锁的状态，所以就阻塞
    
    if(dp.contains(12))
    {
        cout << "contains 12" << endl;
    }

    for(auto& s : dp.alist)
    {
        cout << s << endl;
    }
    pthread_exit(NULL);
}