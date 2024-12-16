
#include <iostream>
using namespace std;

int main()
{
    const int e = 4;
    int a = 5;
    
    const int* b = &a;
    int* const c = &a;
    const int*  const d = &a;

    return 0;
}