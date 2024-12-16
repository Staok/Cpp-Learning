https://blog.csdn.net/sevenjoin/article/details/88314531


/*
在C++的类中，如果我们没有定义构造函数，编译器会为我们合成默认的无参构造函数，
如果我们定义了构造函数，则编译器就不生成默认构造函数了，但是如果我们定义构造函数同时
也希望编译器生成默认构造函数呢? C++11中可以通过在构造函数的声明中直接  =default的方式要求
编译器生成构造函数。
*/

class ClassName{
    public:
        ClassName(int x);
        ClassName()=default; // 显式要求编译器生成构造函数
};

/*
C++11中，当类中含有不能默认初始化的成员变量时，可以禁止默认构造函数的生成，
myClass()=delete;//表示删除默认构造函数
myClass()=default;//表示默认存在构造函数
当类中含有不能默认拷贝成员变量时，可以禁止默认构造函数的生成，
myClass(const myClass&)=delete;//表示删除默认拷贝构造函数，即不能进行默认拷贝
myClass & operatir=(const myClass&)=delete;//表示删除默认拷贝构造函数，即不能进行默认拷贝
*/