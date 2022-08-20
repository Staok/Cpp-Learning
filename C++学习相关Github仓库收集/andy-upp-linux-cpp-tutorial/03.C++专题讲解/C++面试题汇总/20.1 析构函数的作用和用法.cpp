//https://www.cnblogs.com/puyangsky/p/5319470.html
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

int main()
{
    Test t0(0);
    Test t1[3]{1,1,1};
    
    Test* t2 = new Test(2);
    delete t2;

    Test* t3 = new Test[3]{3,3,3};
    delete[] t3;
    cout << "------End of Main--------" << endl;
    return 0;
}