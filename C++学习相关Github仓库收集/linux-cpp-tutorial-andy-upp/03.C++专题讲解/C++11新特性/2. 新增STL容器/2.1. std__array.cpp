#include <array>
#include <iostream>


//个人觉得std::array跟数组并没有太大区别，对于多维数据使用std::array，个人反而有些不是很习惯吧。
//std::array相对于数组，增加了迭代器等函数（接口定义可参考C++官方文档）。

int main(){
    std::array<int, 4> arrayDemo = {1,2,3,4}; //这种赋值方法适合C++11中的大部分容器
    std::cout << "arrayDemo:" << std::endl;
    for(auto itor : arrayDemo)
    {
        std::cout << itor << std::endl;
    }
    int arrayDemoSize = sizeof(arrayDemo);
    std::cout << "arrayDemo size:" << arrayDemoSize << std::endl;
    return 0;
}

