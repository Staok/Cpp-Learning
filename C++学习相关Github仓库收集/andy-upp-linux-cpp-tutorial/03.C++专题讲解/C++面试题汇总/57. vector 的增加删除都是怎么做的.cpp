//https://www.cnblogs.com/sylar5/p/6549482.html

#include <iostream>
#include <vector>
using namespace std;

//添加元素
void test_vector_add()
{
    //1.insert()插入元素到Vector中
    vector<int> vec1{1,2,3};
    vector<int>::iterator it1;
    //在指定位置loc前插入值为val的元素,返回指向这个元素的迭代器
    it1 = vec1.insert(vec1.begin()+1,0);
    for(it1 = vec1.begin(); it1 != vec1.end(); ++it1)
        cout << *it1 << " ";
    cout << endl;

    vector<int> vec2{1,2,3};
    //在指定位置loc前插入num个值为val的元素 
    vector<int>::iterator it2;

    it2 =  vec2.insert(vec2.begin(),3,0);
    for(it2 = vec2.begin(); it2 != vec2.end(); ++it2)
        cout << *it2 << " ";
    cout << endl;


    vector<int> vec3{1,2,3};
    vector<int> vec33{0,0,0};
    //在指定位置loc前插入区间[start, end)的所有元素
    vector<int>::iterator it3;

    it3 =  vec3.insert(vec3.begin()+1,vec33.begin(),vec33.end());
    for(it3 = vec3.begin(); it3 != vec3.end(); ++it3)
         cout << *it3 << " ";
    cout << endl;
}


//删除元素
void test_vector_delete()
{
    //方法1
    //clear() 清空所有元素
    //empty() 判断Vector是否为空（返回true时为空）
    vector<int> vec1{1,2,3};
    vec1.clear();
    vector<int>::iterator it1;
    for(it1 = vec1.begin(); it1 != vec1.end(); ++it1)
        cout << *it1 << " ";
    cout << endl;

    //方法2
    //erase() 删除指定元素 (可以用指针来代替迭代器)
    vector<int> vec2{1,2,3,4,5};
    vector<int>::iterator it2;

    it2 =  vec2.erase(vec2.begin());   //要删除元素的迭代器
    for(it2 = vec2.begin(); it2 != vec2.end(); ++it2)
        cout << *it2 << " ";
    cout << endl;

    vector<int> vec22{1,2,3,4,5};
    vector<int>::iterator it22;
    //要删除的第一个元素的迭代器，要删除的第二个元素的迭代器
    it22 =  vec22.erase(vec22.begin()+1,vec22.begin()+3);
    for(it22 = vec22.begin(); it22 != vec22.end(); ++it22)
        cout << *it22 << " ";
    cout << endl;

    //方法3 移除最后一个元素
    vector<int> vec3{1,2,3,4,5};
    vec3.pop_back();
    for(auto& v: vec3)
        cout << v << " ";
    cout << endl;

    //方法四：
    /*
    可以采用通用算法remove()来删除vector容器中的元素， 不同的是，采用remove 
    一般情况下不会改变容器的大小，而pop_back()与erase()等成员函数会改变容器的大小。
    但这个函数只是把val移到vec的末尾，并把最后一个元素赋值给它，并不真正删除
    真正删除还是要调用一次erase函数
    */
    vector<int> vec4{1,2,3,4,5};
    vector<int>::iterator it4;

    it4 = remove(vec4.begin(), vec4.end(),4); //删除所有值为3的元素
    for(it4 = vec4.begin(); it4 != vec4.end(); ++it4)
        cout << *it4 << " "; 
    cout << endl;





}


int main()
{
    //test_vector_add();
    test_vector_delete();
    return 0;

}