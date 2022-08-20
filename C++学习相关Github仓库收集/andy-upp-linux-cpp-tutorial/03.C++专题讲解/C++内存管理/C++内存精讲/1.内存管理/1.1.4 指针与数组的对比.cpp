#include<iostream>
using namespace std;

void Func(char a[12])
{
    cout << "Func函数中：" << sizeof(a) << " " << *a << endl; //8字节而不是100字节

}

void GetMemory(char* p, int num)
{
    p = (char*)malloc(sizeof(char)*num);
}

void Test(void)
{
    char* str = NULL;
    GetMemory(str, 100); //str仍然是NULL因为指针传递是值传递，函数中对指针的修改并不会改变str
    //strcpy(str,"hello"); //发生断错误
}


//用指向指针的指针，把一级指针当成值，可以改变一级指针的值
void GetMemory2(char** p, int num)
{
    *p = (char*)malloc(sizeof(char)*num);
}

void Test2(void)
{
    char* str = NULL;
    GetMemory2(&str, 100);//注意参数是&str, 而不是str
    strcpy(str, "hello");
    cout << str << endl;
    free(str);
}


//用函数返回值传递动态内存(堆内存)
char* GetMemory3(int num)
{
    char* p = (char*)malloc(sizeof(char*)*num);
    return p;
}

void Test3(void)
{
    char* str = NULL;
    str = GetMemory3(100);
    strcpy(str, "hello");
    cout << str << endl;
    free(str);
}

//不要用return语句返回“栈内存”的指针
char* GetString(void)
{
    // char p[] = "hello world";
    // return p; //编译器将提出警告

    //虽然不会运行出错，但是p指向静态存储区，返回的是只读的内存块
    char* p  = "hello world";
    return p;
}

void Test4(void)
{
    char* str = NULL;
    str = GetString(); //str的内容是垃圾
    cout << str << endl;
    //*str = "s"; // 编译出错
}


int main()
{
   cout << "========1========" << endl;

//1.修改内容
    char a_1[] = "hello";
    a_1[0] = 'X';
    //cout << a << endl;

    //char* p = "world"; //p指向字符串常量
    //p[0] = 'X';//该语句企图修改常量字符串的内容而导致运行错误，编译器不能发现该错误
    //cout << p << endl;

   cout << "========2========" << endl;

//2.内容的复制与比较
   //数组与数组
   char a_2[] = "hello";
   char b_2[10];
   strcpy(b_2,a_2); //不能用b = a
   if(strcmp(b_2,a_2) == 0) //不能用if(b_2 == a_2)
   {
       cout << "比较成功" << endl;
   }
   
   //指针与数组
   int len = strlen(a_2);
   char* p_2 = (char*)malloc(sizeof(char)*(len+1));
   strcpy(p_2,a_2); //不要用p=a;
   if(strcmp(p_2,a_2) == 0) //不要用p_2 == a_2
   {
       cout << "比较成功" << endl;
   }

   cout << "========3========" << endl;

//3.计算内存容量
    char a_3[] = "hello world";
    char* p_3 = a_3;

    cout << sizeof(a_3) << endl; //12字节
    cout << sizeof(p_3) << endl; //8字节  注意64位操作系统中，指针统一为8字节

    //注意当数组作为函数的参数进行传递时，该数组自动退化为同类型的指针
    Func(a_3);
   cout << "========4========" << endl;

//4.指针参数如何传递内存
    //Test();
    //Test2();
    //Test3();
    Test4();
    return 0;
}