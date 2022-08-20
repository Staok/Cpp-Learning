//
// Created by 李光辉 on 2020/12/29.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <thread>

using namespace  std;


//自己创建的线程也要从一个函数(初始函数)开始执行
void myprint()
{
    cout << "我的线程开始执行了" << endl;
    //...
    //...
    cout << "我的线程执行完毕了1" << endl;
    cout << "我的线程执行完毕了2" << endl;
    cout << "我的线程执行完毕了3" << endl;
    cout << "我的线程执行完毕了4" << endl;
    cout << "我的线程执行完毕了5" << endl;
    cout << "我的线程执行完毕了6" << endl;
    cout << "我的线程执行完毕了7" << endl;

}

int main()
{

    thread myobj(myprint); // 1、创建线程，入口函数是myprint函数 2.myprint线程开始执行

    //joinable(): 判断是否可以成功使用join()或者detach(),返回true或者false
    if(myobj.joinable())
    {
        cout << "1: jponabel == true" << endl;
    } else{
        cout << "1: jponabel == false" << endl;

    }

    myobj.detach();
    //线程对象不能两次join或者detach
    if(myobj.joinable())
    {
        cout << "2: jponabel == true" << endl;
    } else{
        cout << "2: jponabel == false" << endl;

    }

    cout << "I Love China1" << endl;
    return 0;
}