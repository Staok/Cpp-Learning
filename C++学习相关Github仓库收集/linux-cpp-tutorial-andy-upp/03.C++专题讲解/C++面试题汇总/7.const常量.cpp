//https://blog.csdn.net/Eric_Jo/article/details/4138548?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-2.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-2.control

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