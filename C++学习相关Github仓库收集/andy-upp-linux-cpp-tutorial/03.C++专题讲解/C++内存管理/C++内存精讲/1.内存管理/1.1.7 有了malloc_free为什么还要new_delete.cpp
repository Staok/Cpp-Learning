#include<iostream>
using namespace std;

class Obj
{
public:
    Obj(void)
    {
        cout << "Initialization" << endl;
    }
    ~Obj(void)
    {
        cout << "Destroy" << endl;
    }
    void Initialize(void)
    {
        cout << "Initialization_" << endl;
    }
    void Destroy(void)
    {
        cout << "Destroy_" << endl;
    }
};

void UseMallocFree(void)
{
    Obj* a = (Obj*)malloc(sizeof(Obj));//申请动态内存
    a->Initialize(); //初始化
    a->Destroy(); //清除工作
    free(a);//释放内存
}

void UseNewDelete(void)
{
    Obj* a = new Obj; //申请动态内存并且初始化
    delete a;//清除并且释放内存
}

int main()
{
    UseMallocFree();
    UseNewDelete();
    return 0;
}