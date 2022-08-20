/*
std::weak_ptr网上很多人说其实是为了解决std::shared_ptr在相互引用的情况下出现的问题而存在的，
C++官网对这个只能指针的解释也不多，那就先甭管那么多了，让我们暂时完全接受这个观点。
std::weak_ptr有什么特点呢？与std::shared_ptr最大的差别是在赋值时，不会引起智能指针计数增加。

我们下面将继续如下两点：
　　1、std::shared_ptr相互引用会有什么后果；
　　2、std::weak_ptr如何解决第一点的问题。
*/

#include <memory>
#include <iostream>
using namespace std;

class TestB;
class TestA
{
public:
    TestA()
    {
        std::cout << "TestA()" << std::endl;
    }

    void ReferTestB(shared_ptr<TestB> test_ptr)
    {
        m_TestB_Ptr = test_ptr;
    }

    ~TestA()
    {
        std::cout << "~TestA()" << std::endl;
    }
private:
    shared_ptr<TestB> m_TestB_Ptr; //testB 的智能指针

}; 


class TestB
{
public:
    TestB()
    {
        std::cout << "TestB()" << std::endl;
    }

    void ReferTestB(std::shared_ptr<TestA> test_ptr)
    {
        m_TestA_Ptr = test_ptr;
    }
    ~TestB()
    {
        std::cout << "~TestB()" << std::endl;
    }
    std::shared_ptr<TestA> m_TestA_Ptr; //TestA的智能指针
};


int main()
{
    std::shared_ptr<TestA> ptr_a = std::make_shared<TestA>();
    std::shared_ptr<TestB> ptr_b = std::make_shared<TestB>();
    ptr_a->ReferTestB(ptr_b);
    ptr_b->ReferTestB(ptr_a);
    return 0;
}

/*
大家可以看到，上面代码中，我们创建了一个TestA和一个TestB的对象，但在整个main函数都运行完后，
都没看到两个对象被析构，这是什么问题呢？
原来，智能指针ptr_a中引用了ptr_b，同样ptr_b中也引用了ptr_a，在main函数退出前，
ptr_a和ptr_b的引用计数均为2，退出main函数后，引用计数均变为1，也就是相互引用。
这等效于说：
ptr_a对ptr_b说，哎，我说ptr_b，我现在的条件是，你先释放我，我才能释放你，这是天生的，造物者决定的，改不了。
ptr_b也对ptr_a说，我的条件也是一样，你先释放我，我才能释放你，怎么办？
是吧，大家都没错，相互引用导致的问题就是释放条件的冲突，最终也可能导致内存泄漏。
*/

