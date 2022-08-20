//
// Created by 李光辉 on 2020/12/29.
//
#include <iostream>
#include <thread>
using namespace std;

//void myprint(const int& i, char* pmybuf)
//传字符串解决方法，将char* 改为 const string,这种改法存在main函数执行完，mybuf被回收，系统才用mybuf转string的可能性，所以不稳定
//最好的方法是构造临时string对象
void myprint(const int i, const string& pmybuf)
{
    cout << i << endl; //分析认为，i并不是mvar的引用，实际是值传递，所以值传递也是安全的,但是也不推荐
    cout << pmybuf << endl;//传指针绝对会有问题，所以也不推荐
    return;
}

int main()
{
    //传递临时对象作为线程参数
    int mvar = 1;
    int& mvary = mvar;
    char mybuf[] = "this is test!";
    //创建线程
    //    thread mytobj(myprint, mvar, mybuf);
    thread mytobj(myprint, mvar, string(mybuf));//如果要传字符串，构造临时string对象是稳定的
    //mytobj.join();
    //陷阱一 将join换成 detach，反对传引用，也反对传指针
    mytobj.detach();
    cout << "I Love China!" << endl;

    return 0;
}