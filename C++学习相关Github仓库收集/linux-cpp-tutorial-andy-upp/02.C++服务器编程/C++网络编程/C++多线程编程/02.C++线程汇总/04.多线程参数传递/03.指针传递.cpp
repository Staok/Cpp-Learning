#include <iostream>
#include <thread>
#include <string>
#include <unistd.h>
using namespace std;


void f2(int* i)
{
    cout << "f2: " << *i << endl;
}


void f1(int& i)
{
    cout << "f1: " << i << endl;
    int j = 11;
    thread t(f2, &j);
    sleep(1);
    t.detach();
}

int main()
{
    int i = 10;
    thread t(f1, ref(i));
    t.detach();
    pthread_exit(NULL);
}