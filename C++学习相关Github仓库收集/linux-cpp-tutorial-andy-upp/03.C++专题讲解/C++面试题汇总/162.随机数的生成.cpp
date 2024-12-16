#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
using namespace std;

//https://www.cnblogs.com/isky0824/p/12096575.html

/*
(1)  如果你只要产生随机数而不需要设定范围的话，你只要用rand()就可以了：
rand()会返回一随机数值, 范围在0至RAND_MAX 间。RAND_MAX定义在stdlib.h, 
其值为0x7fff。
*/
void Test1()
{
    for(int i=0; i<10; ++i)
        cout << rand() << endl;
}

/*
(2)  如果你要随机生成一个在一定范围的数，你可以在宏定义中定义一个
random(int number)函数，然后在main()里面直接调用random()函数
*/
#define random(x) (rand()%x)
void Test2()
{
    for(int i = 0; i < 10; ++i)
        cout << random(100) << endl;
}

/*
(3)但是上面两个例子所生成的随机数都只能是一次性的，如果你第二次运行的时候输出
结果仍和第一次一样。这与srand()函数有关。srand()用来设置rand()产生随机数时
的随机数种子。在调用rand()函数产生随机数前，必须先利用srand()设好随机数种子
（seed）, 如果未设随机数种子, rand()在调用时会自动设随机数种子为1。上面的两个
例子就是因为没有设置随机数种子，每次随机数种子都自动设成相同值1 ，进而导致rand()
所产生的随机数值都一样。

srand()函数定义 ： void srand (unsigned int seed);
通常可以利用geypid()或time(0)的返回值来当做seed
如果你用time(0)的话，要加入头文件#include<time.h>
*/

void Test3()
{
    srand((int)time(0));
    for(int i = 0; i < 10; ++i)
        cout << random(100) << endl;
}


int main()
{
    //Test1();
    //Test2();
    Test3();

    return 0;
}
