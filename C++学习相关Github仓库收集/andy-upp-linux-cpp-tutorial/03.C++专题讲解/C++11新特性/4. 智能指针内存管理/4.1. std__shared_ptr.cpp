/*
在内存管理方面，C++11的std::auto_ptr基础上，移植了boost库中的智能指针的部分实现，如std::shared_ptr、std::weak_ptr等，
当然，想boost::thread一样，C++11也修复了boost::make_shared中构造参数的限制问题。把智能指针添加为标准，个人觉得真的非常方便，
毕竟在C++中，智能指针在编程设计中使用的还是非常广泛。
什么是智能指针？网上已经有很多解释，个人觉得“智能指针”这个名词似乎起得过于“霸气”，很多初学者看到这个名词就觉得似乎很难。
简单地说，智能指针只是用对象去管理一个资源指针，同时用一个计数器计算当前指针引用对象的个数，当管理指针的对象增加或减少时，
计数器也相应加1或减1，当最后一个指针管理对象销毁时，计数器为1，此时在销毁指针管理对象的同时，也把指针管理对象所管理的指针进行delete操作。
*/
#include <iostream>
#include <memory>
using namespace std;

//std::shared_ptr包装了new操作符动态分配的内存，可以自由拷贝复制，基本上是使用最多的一个智能指针类型。

class Test
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }

    ~ Test()
    {
        cout << "~Test()" << endl;
    }

};

int main()
{
    shared_ptr<Test> p1 = make_shared<Test>(); //make_shared封装了new方法
    cout << "1 ref: " << p1.use_count() << endl;
    {
        shared_ptr<Test> p2 = p1;
        cout << "2 ref:" << p1.use_count() << endl;
    }
    //出了作用域，p2 销毁，就只剩下p1指向对象 Test
    cout << "3 ref:" << p1.use_count() << endl;
    return 0;
}

/*
从上面代码的运行结果，需要读者了解的是：
1、std::make_shared封装了new方法，boost::make_shared之前的原则是既然释放资源
delete由智能指针负责，那么应该把new封装起来，否则会让人觉得自己调用了new，但没有调用
delete，似乎与谁申请，谁释放的原则不符。C++也沿用了这一做法。
2、随着引用对象的增加std::shared_ptr<Test> p2 = p1，指针的引用计数有1变为2，
当p2退出作用域后，p1的引用计数变回1，当main函数退出后，p1离开main函数的作用域，
此时p1被销毁，当p1销毁时，检测到引用计数已经为1，就会在p1的析构函数中调用delete之前std::make_shared创建的指针。
*/