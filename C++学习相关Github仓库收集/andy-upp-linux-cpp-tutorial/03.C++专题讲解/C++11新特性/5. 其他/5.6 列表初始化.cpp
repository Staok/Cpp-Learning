//数组列表初始化
int xx[5]={1,2,3,4,5};
int yy[]={6,7,8,9,0};
 
//值类型进行初始化
int a{10};
int b={10};
int c={10.123}; // 编译器报错，g++ 5.3.1当列表初始化用于值类型的时候，如果有精度损失，编译器会报错。
 
//列表初始化还可以用结构体
typedef struct Str{
   int x;
   int y;
}Str;
Str s = {10,20};
 
//列表初始化类,必须是public成员,如果含有私有成员会失败
class Cls{
public:
   int x;
   int y;
};
Cls c  = {10,20};
 
//vector不仅可以使用列表初始化，还可以使用列表进行赋值，数组不能用列表赋值
vector<int>v1={1,2,3,4,5,6,7,8,9}; // 初始化
vector<int>v2;
v2={3,4,5,6,7}; //赋值
 
//map列表初始化
map<string ,int> m = {
      {"x",1},
      {"y",2},
      {"z",3}
};
 
//用函数返回初始化列表只展示关键代码，相关头文件自行添加
//同理结构体，类，map的返回也可以使用初始化列表返回
vector<int> getVector()
{
  return {1,2,3,4,5};
}
 
int main()
{
  vector<int> v = getVector();
  cout<<v[0]<<v[1]<<v.size()<<endl;
  return 0 ;
}