#include <iostream>
/*
为什么需要nullptr? NULL有什么毛病？
NULL在c++里表示空指针，看到问题了吧，我们调用test.TestWork(NULL)，其实期望是调用的是
void TestWork(int* index)，但结果调用了void TestWork(int index)。但使用nullptr的时候，
我们能调用到正确的函数。
*/


class Test
{
public:
    void TestWork(int index)
    {
        std::cout << "TestWork 1" << std::endl;
    }
    void TestWork(int* index)
    {
        std::cout << "TestWork 2" << std::endl;
    }
};

int main()
{
    Test test;
    // test.TestWork(NULL);
    test.TestWork(nullptr);
}