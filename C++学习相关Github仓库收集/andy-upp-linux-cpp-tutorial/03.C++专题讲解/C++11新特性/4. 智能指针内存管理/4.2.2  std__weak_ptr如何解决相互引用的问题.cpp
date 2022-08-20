//　　我们在上面的代码基础上使用std::weak_ptr进行修改：

class TestB;
class TestA
{
public:
    TestA()
    {
        std::cout << "TestA()" << std::endl;
    }
    void ReferTestB(std::shared_ptr<TestB> test_ptr)
    {
        m_TestB_Ptr = test_ptr;
    }
    void TestWork()
    {
        std::cout << "~TestA::TestWork()" << std::endl;
    }
    ~TestA()
    {
        std::cout << "~TestA()" << std::endl;
    }
private:
    std::weak_ptr<TestB> m_TestB_Ptr;
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
    void TestWork()
    {
        std::cout << "~TestB::TestWork()" << std::endl;
    }
    ~TestB()
    {
        std::shared_ptr<TestA> tmp = m_TestA_Ptr.lock();
        tmp->TestWork();
        std::cout << "2 ref a:" << tmp.use_count() << std::endl;
        std::cout << "~TestB()" << std::endl;
    }
    std::weak_ptr<TestA> m_TestA_Ptr;
};


int main()
{
    std::shared_ptr<TestA> ptr_a = std::make_shared<TestA>();
    std::shared_ptr<TestB> ptr_b = std::make_shared<TestB>();
    ptr_a->ReferTestB(ptr_b);
    ptr_b->ReferTestB(ptr_a);
    std::cout << "1 ref a:" << ptr_a.use_count() << std::endl;
    std::cout << "1 ref b:" << ptr_a.use_count() << std::endl;
    return 0;
}

/*
由以上代码运行结果我们可以看到：

　　1、所有的对象最后都能正常释放，不会存在上一个例子中的内存没有释放的问题。
　　2、ptr_a 和ptr_b在main函数中退出前，引用计数均为1，也就是说，在TestA和
      TestB中对std::weak_ptr的相互引用，不会导致计数的增加。在TestB析构函数中，
      调用std::shared_ptr<TestA> tmp = m_TestA_Ptr.lock()，把std::weak_ptr
      类型转换成std::shared_ptr类型，然后对TestA对象进行调用。　
*/

