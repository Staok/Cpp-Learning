#include <iostream>
using namespace std;

class A
{
public:
    int a;
    int b;

    A()
    {
        memset(this, 0, sizeof(*this));
        cout << "A cons" << endl;
    }
    ~A()
    {
        cout << "A des" << endl;
    }
};


int main()
{
    A a;
    cout << a.a << " " << a.b << endl;
    return 0;
}