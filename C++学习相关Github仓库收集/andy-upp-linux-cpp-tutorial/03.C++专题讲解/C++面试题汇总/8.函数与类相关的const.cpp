//https://blog.csdn.net/Eric_Jo/article/details/4138548?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-2.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-2.control

#include <iostream>
using namespace std;


void function1(const int var);
void function2(const char* var);
void function3(char* const var);
void function4(const class& var);
void function5(const TYPE& var);

const int fun1();
const int* func2();
int* const func3();


class TestClass
{
    TestClass(int x):value(v){};

    void function() const;

private:
    const int value;
    
    
};

int main()
{

    const TestClass* aa = new TestClass(6);
    return 0;
}