#include <iostream>
#include <thread>
#include <string>
#include <unistd.h>
using namespace std;


void f1(unique_ptr<int> upt)
{
    cout << *upt << endl;
}

int main()
{
    unique_ptr<int> upt(new int(10));
    //必须使用move函数，否则编译不过
    thread t(f1,move(upt));
    t.detach();
    pthread_exit(NULL);
}