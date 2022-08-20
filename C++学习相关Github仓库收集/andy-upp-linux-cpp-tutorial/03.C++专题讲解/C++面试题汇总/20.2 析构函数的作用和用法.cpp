#include<iostream>
using namespace std;


class Test
{
    int id;
public:
    Test(int i)
    {
        id = i;
    }
    ~Test()
    {
        cout << "ID: " << id <<" destruction function is invoked!" << endl;
    }

};


Test t0(0);

void Func()
{
    static Test t1(1);
    Test t2(2);
    cout << "-----Func-----" << endl;
}

int main()
{
    Test t3(3);
    t3 = 10;
    cout<<"------Begin of Main-------"<<endl;
    {
        Test t4(4);
    }
    Func();  
    cout<<"------End of Main-------"<<endl;
    return 0;
}