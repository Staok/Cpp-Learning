#include <iostream>
#include <thread>
#include <string>
#include <unistd.h>
using namespace std;

class Test
{
public:
    void func(int& i)
    {
        cout << i << endl;
    }
};

int main()
{
    Test da;
    int i = 10;
    //&Test::func为对象的方法的指针，
    //&da为对象的指针，ref(i)是方法func的参数
    thread t(&Test::func, &da, ref(i));
    pthread_exit(NULL);
}