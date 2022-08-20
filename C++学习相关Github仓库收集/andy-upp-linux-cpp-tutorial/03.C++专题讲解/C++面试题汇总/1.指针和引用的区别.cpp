//https://blog.csdn.net/qeqjkqjklq/article/details/109321439
#include<iostream>
using namespace std;

int test(int* s)
{
    *s = *s + 2;
    return *s;
}

int test1(int& s)
{
    cout << &c << endl; //&s = q,变量q的地址
    cout<<s<<endl;//这里相当于s为q别名
    s = s + 2;
    return s;
}


void test2(int*& r)
{
    *r = 30;
}


int main()
{
    long double a = 20;
    long double* b = &a;
    long double& c = a;

    //1、指针不需要初始化，引用需要初始化
    long double *e;
    //long double &q = NULL;//error:不能给引用赋值NULL(不能对临时变量加引用)
    //long double &d; // error :Declaration of reference variable 'd' requires an initializer


    //2.直接输出指针和引用
    //5、引用访问一个变量c是直接访问，而指针是间接访问(先访问变量的地址，再访问值)
    cout<<b<<endl;//指针这里是输出的变量b的【地址】:0x70fe30
    cout<<c<<endl;//引用这里是输出的变量b的【值】    


    //3、通过sizeof来获取指针和引用的【大小】
    cout<<sizeof(b)<<endl;//指针的大小为8个字节，因为是64位系统
    cout<<sizeof(c)<<endl;//引用的大小就是其所指向变量a的大小，long double类型16个字节

    //4、 对指针和引用分别进行加1操作，指针的加1操作就是指向下一个地址空间(指针的值+16,,因为这里是long double)
    b++;//0x70fe40-0x70fe30=10(这是16进制的10)，也就是16正好是一个long double类型所占的字节
    c++;//11,就是变量的值加1
    cout<<b<<endl;
    cout<<c<<endl;



    //6、传引用就相当于给原有变量起了一个别名s(见test1函数),对s的操作就是对q的操作
    //传引用,传递的【值】是【变量的地址】(&s = q),&是取地址运算符,&s为变量q的地址。
    //传引用，传递的【实质】是变量的地址
    //传递的值看的是函数里面的变量比如s
    //传递的实质是看&s
    cout<<"下面是指针和引用的参数传递测试,(为啥传引用和传参数，变量的地址都没有改变)"<<endl;
    int q = 10;
    int& w = q;//w相当于是q的别名
    cout<<w<<endl;
    cout<<&q<<endl;

    cout<<"传引用之前，q的地址："<<&q<<endl;
    cout<<test1(q)<<endl;
    cout<<q<<endl;
    cout<<"传引用之后，q的地址："<<&q<<endl;


    //传指针,传递的【值】是【指针的地址】(*s = m),
    //传指针，传递的【实质】是值，传递的值看的是函数里面的变量比如s
    //传递的实质是看*s
    //int *m = &q;
    cout<<"传指针之前，q的地址："<<&q<<endl;
    cout<<test(&q)<<endl;
    cout<<"主调函数实参变量的值："<<q<<endl;
    cout<<"传指针之后，q的地址："<<&q<<endl;
    //cout<<test(m)<<endl;


    cout<<"下面为多级指针测试"<<endl;
    //    https://www.cnblogs.com/johnnyzen/p/7575929.html
    //7、有多级指针但是没有多级引用
    int value = 10;
    int *pointer1 = &value;
    int **pointer2 = &pointer1;

    cout<<&value<<endl;//0x70fe18为value值的地址
    cout<<&pointer1<<endl;//0x70fe10为pointer1值的地址
    cout<<&pointer2<<endl;//0x70fe08为pointer2值的地址

    cout<<pointer1<<endl;//0x70fe18,pointer1=&value      =value的地址
    cout<<pointer2<<endl;//0x70fe10,pointer2=&pointer1   =pointer1的地址

    cout<<*pointer1<<endl;//*pointer1=value=10
    cout<<*pointer2<<endl;//*pointer2=pointer1=&value=0x70fe18
    cout<<*(&pointer1)<<endl;//解释同上

    cout<<**pointer2<<endl;//**pointer2=*(*pointer2)=*pointer1=value=10

    //引用变量没有地址（【系统为引用变量自身分配了地址】，只不过引用变量自身的地址我们连读的权限都没有，
    //所以我们默认引用自身没有地址，即引用类似常量），
    //所【不能声明引用的引用,int &&p = 】，【也不能声明指向引用的指针】
    int i = 10;
    int* p1 = &i;
    int* &r = p1;//相当于int* (&r) = p1
    cout<<p1<<endl;
    cout<<*(&p1)<<endl;//值与上一行一样，由此可得*(&p1)==p1
    cout<<&p1<<endl;
    cout<<&r<<endl;


    cout<<&i<<endl;
    cout<<p1<<endl;
//    https://blog.csdn.net/boy_of_god/article/details/81022316
    cout<<r<<endl;//见82行,或者上诉博客的第二张图
//    上面这一行代码解释：r表示 以引用变量中存储的内容【p1的地址】为地址的变量【指针p1】的值【i的地址】

    *r = 30;
    cout<<r<<endl;
    cout<<i<<endl;
    cout<<&i<<endl;
    r = (int *)malloc(sizeof(int));
    cout<<r<<endl;
    cout<<&r<<endl;//不变
    cout<<&p1<<endl;//不变
    cout<<p1<<endl;
    cout<<&i<<endl;

    test2(p1);
    cout<<i<<endl;

    return 0;



}