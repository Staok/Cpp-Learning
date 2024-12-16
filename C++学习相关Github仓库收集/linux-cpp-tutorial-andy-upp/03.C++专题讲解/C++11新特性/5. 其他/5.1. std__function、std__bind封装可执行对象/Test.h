
//修改前
/*
Test
{
public:
    void Add()
    {
        
    }
};
*/



//假如我们的需求是让Test里面的Add由外部实现，如main.cpp里面的add函数，有什么方法呢？
//没错，我们可以用函数指针。
/*
class Test
{
public:
    typedef int(*FunType)(int, int);
    void Add(FunType fun,int a,int b)
    {
        int sum = fun(a, b);
        std::cout << "sum:" << sum << std::endl;
    }
};
*/

//假如add方法在TestAdd类内部

class Test
{
public:
    void Add(std::function<int(int, int)> fun, int a, int b)
    {
        int sum = fun(a, b);
        std::cout << "sum:" << sum << std::endl;
    }
};
