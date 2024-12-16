/*
1，当在一个函数里启动一个线程后，并detach了
2，detach的线程里使用了这个函数里new出来的一个对象
3，detach后，delete了这个对象
4，为什么detach在线程里，使用了在3处delete的内存还不报错误？

回答4的问题：

线程还没来得及执行，main函数就执行完了，直接杀死还没有执行完的线程，所以线程里
使用了已经delete的内存，也没有出错。如果在main函数里调用sleep(2)，就会出错误。
如果当main函数结束后，还不想结束其他由main函数创建的子线程，就必须调用下
pthread_exit(NULL)。
*/

#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;


class bad
{
public:
    bad(int* i):data(i)
    {
        cout << "addr2" << data << endl;
    }

    void operator()()
    {
        for(unsigned j = 0; j < 10000000000; ++j)
        {
            something(data);
        }
    }

private:
    void something(int* i)
    {
        *i = 100;
        cout << *i << endl;
    }
    int* data;

};

void func()
{
    int* local = new int(10);
    cout << "addr: " << local << endl;
    bad b(local);
    delete local;
    //b为仿函数 
    thread t(b);
    cout << "end delete" << endl;
    t.detach();

    cout << "after join " << *local << endl;
    cout << "func end" << endl;  
}

int main()
{
    func();
    //sleep(1);
    pthread_exit(NULL);
    cout << "end" << endl;
}


