#include <iostream>
#include <thread>
#include <string>
#include <unistd.h>

using namespace std;

void f2(int& i)
{
    cout << "f2:" << i << endl;
}

void f1(int& i)
{
    cout << "f1: " << i << endl;
    int j = 11;
    thread t(f2, ref(j));
    t.detach();
    sleep(2); //不加的话 会发生段错误，因为j的内存已经释放
}

int main()
{
    int i = 10;
    thread t(f1,ref(i));
    t.detach();
    pthread_exit(NULL);
}


/*
执行结果分析：
打印出【f1：10】的原因可能是，①处分离线程后，main函数所在的线程还没有结束，
所以i还没有被释放掉，所以能打印出10；还有可能是main函数所在的线程虽然已经结束了，
但是巧合的是值还是10。
打印出【f2：0】的原因是，②处分离线程后，线程f1已经结束了，所以函数f1里的j已经
被释放了，这时线程f2再访问j的时候就是0了。
*/