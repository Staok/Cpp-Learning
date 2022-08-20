//https://blog.csdn.net/weixin_42437114/article/details/108929891

//如果我们想将某个类用作基类，则该类必须已经定义而非仅仅声明
//这一规定的原因显而易见：派生类中包含并且可以使用它从基类继承
//而来的成员， 为了使用这些成员， 派生类当然要知道它们是什么。
//因此该规定还有一层隐含的意思， 即一个类不能派生它本身
#include <iostream>
using namespace std;


class Queue; 

class Bulk_quote : public Queue
{
    Bulk_quote()
    {
        cout << "contruction" << endl;
    }
};

int main()
{
    Bulk_quote bq; //报错
    return 0;
}
