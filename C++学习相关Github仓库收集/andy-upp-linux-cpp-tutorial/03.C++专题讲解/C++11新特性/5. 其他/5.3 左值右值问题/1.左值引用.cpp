

int main()
{
    int a = 10; 
    int& refA = a; // refA是a的别名， 修改refA就是修改a, a是左值，左移是左值引用

    int& b = 1; //编译错误! 1是右值，不能够使用左值引用

    return 0;
}