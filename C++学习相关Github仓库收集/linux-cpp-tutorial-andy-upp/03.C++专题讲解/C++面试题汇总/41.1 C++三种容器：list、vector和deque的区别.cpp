//https://blog.csdn.net/gogokongyin/article/details/51178378
//https://blog.csdn.net/weixin_41743247/article/details/90635931
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

namespace vector_test
{
    //vector初始化
    void vector_init()
    {
        //1.定义具有10个整型元素的向量（尖括号为元素类型名，它可以是任何合法的数据类型），
        //不具有初值，其值不确定
        vector<int> a1(10);
        for(auto& a : a1)
            cout << a << " ";
        cout << endl;
        //2.定义具有10个整型元素的向量，且给出的每个元素初值为1
        vector<int> a2(10, 1);
        for(auto& a : a2)
            cout << a << " ";
        cout << endl;

        //3.用向量b给向量a赋值，a的值完全等价于b的值
        vector<int> a3(a2);
        for(auto& a : a3)
            cout << a << " ";
        cout << endl;

        //4.将向量b中从0-2（共三个）的元素赋值给a，a的类型为int型
        vector<int> a4(a2.begin(), a2.begin()+3);
        for(auto& a : a4)
            cout << a << " ";
        cout << endl;

        //5.从数组中获得初值
        int b[7] = {1,2,3,4,5,6,7};
        vector<int> a5(b,b+7);
        for(auto& a : a5)
            cout << a << " ";
        cout << endl;

        //6.C++11提供的直接赋值方式
        //vector<int> a6{1,3,5,7}; 或者
        vector<int> a6 = {1,3,5,7};
        for(auto& a : a6)
            cout << a << " ";
        cout << endl;

    }

    //对向量添加元素的几种方式
    void vector_add ()
    {
        //1.直接追加
        vector<int> a1;
        for(int i = 0; i < 10; ++i)
            a1.push_back(i);
        for(auto& a : a1)
            cout << a << " ";
        cout << endl;


        //2.从数组中选择元素向向量中添加
        int a2[6] = {1,2,3,4,5,6};
        vector<int> a2_;
        for(int i = 0; i < 4; ++i)
            a2_.push_back(a2[i]);
        
        for(auto& a : a2_)
            cout << a << " ";
        cout << endl;

        //3.从现有向量中选择元素向向量中添加
        vector<int> a3;
        for(vector<int>::iterator it = a2_.begin(); it < a2_.end(); ++it)
        {
            a3.push_back(*it);
        }
        for(auto& a : a3)
            cout << a << " ";
        cout << endl;

        //4.从文件中读取元素向向量中添加
        // ifstream in("data.txt");
        // vector<int> a4;
        // for(int i; in>>i)//?
        //     a4.push_back(i);
        // for(auto& a : a4)
        //     cout << a << " ";
        // cout << endl;
    }

    void vector_get()
    {
        //1.通过迭代器的方式
        int a1[6] = {1,2,3,4,5,6};
        vector<int> a1_(a1, a1+4);
        for(int i = 0; i <= a1_.size()-1; ++i)
            cout << a1_[i] << " ";
        cout << endl;

        //2.使用迭代器方式获取
        int a2[6] = {1,2,3,4,5,6};
        vector<int> a2_(a2, a2+4);
        for(vector<int>::iterator it = a2_.begin(); it != a2_.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }

    void vector_algorithm()
    {
        //对a中的从a.begin()（包括它）到a.end()（不包括它）的元素进行从小到大排列
        vector<int> a1{4,2,1,3,0,2};
        sort(a1.begin(), a1.end());
        for(auto& a : a1)
            cout << a << " ";
        cout << endl;

        //对a中的从a.begin()（包括它）到a.end()（不包括它）的元素倒置，
        //但不排列，如a中元素为1,3,2,4,倒置后为4,2,3,1
        vector<int> a2{4,2,1,3,0,2};
        reverse(a2.begin(), a2.end());
        for(auto& a : a2)
            cout << a << " ";
        cout << endl;

        //把a中的从a.begin()（包括它）到a.end()（不包括它）的元素复制到b中，
        //从b.begin()+1的位置（包括它）开始复制，覆盖掉原有元素
        vector<int> a3{4,2,1,3,0,2};
        vector<int> b3{6,6,6};
        copy(a3.begin(),a3.end(), b3.begin()+1);
        for(auto& b : b3)
            cout << b << " ";
        cout << endl;

    }
}

int main()
{
    //vector_test::vector_init();
    //vector_test::vector_add();
    //vector_test::vector_get();
    vector_test::vector_algorithm();

    return 0;
}