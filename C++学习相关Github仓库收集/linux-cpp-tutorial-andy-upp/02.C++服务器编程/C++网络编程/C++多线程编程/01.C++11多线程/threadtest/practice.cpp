#include <iostream>
#include <thread>
using namespace std;

void foo()
{
    cout << "ddd" << endl;
}

void bar(int x)
{   
    cout << "ccc" << endl;
}


int main()
{
    thread first(foo);
    thread second(bar,0);

    first.join();
    second.join();

    return 0;
}