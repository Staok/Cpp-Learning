# C++学习总结

本文非基础教学文，而是在有 C 语言的基础上对 C++ 学习的总结记录。教程可参考下文 “有迹可循” 一节。本文主体为参考 《C++ Primer Plus（第六版 ）》书，再旁引补充网络教程如 菜鸟教程 和 C语言中文网 等的内容。

------

## 有迹可循

下面的教程会列举很多，选择去看即可。

**C 语言入门**

- 菜鸟教程 [C 语言教程 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cprogramming/c-tutorial.html)。
- C语言中文网 [网站地图 (biancheng.net)](http://c.biancheng.net/sitemap/)，个别小节需要 RMB。
- B站搜“C语言学习” [C语言学习 _ 搜索结果_ 哔哩哔哩 _Bilibili](https://search.bilibili.com/all?keyword=C语言学习)，随便一搜一大把，其它语言同理。

**C 语言提高**

- C 语言三剑客：《C和指针》、《C陷阱与缺陷》和《C专家编程》，经典永流传。
- [《嵌入式C语言的自我修养》](https://book.douban.com/subject/35446929/) 从沙子讲到CPU，从编辑器讲到编译器，从高阶C语言讲到内存管理，从GNU讲到多任务编程。[《嵌入式C语言自我修养》勘误 - 公众号文章汇总 | 宅学部落 (zhaixue.cc)](https://www.zhaixue.cc/weixin/weixin-correction.html)。
- 列一些提高的书：（有的书可以网上找到电子版（只提醒一下））
  - [让你不再害怕指针——C指针详解(经典,非常详细) - 简书 (jianshu.com)](https://www.jianshu.com/p/9b8aeaba8ca8)，[让你不再害怕指针——C指针详解(经典,非常详细)_程序老兵的博客-CSDN博客_指针](https://blog.csdn.net/soonfly/article/details/51131141)。
  - [你必须知道的495个C语言问题 (豆瓣) (douban.com)](https://book.douban.com/subject/26868092/)，[你必须知道的495个C语言问题_benpaobagzb的博客-CSDN博客_你必须知道的495个c语言问题](https://blog.csdn.net/benpaobagzb/article/details/48442099)，[《你必须知道的495个C语言问题》知识笔记及补充 - Alexia(minmin) - 博客园 (cnblogs.com)](https://www.cnblogs.com/lanxuezaipiao/p/3539262.html)。
  - [C语言深度解剖 (豆瓣) (douban.com)](https://book.douban.com/subject/4924419/)。
  - [C语言的底层操作_zhongjie的专栏-CSDN博客_c语言底层架构](https://blog.csdn.net/zhongjiekangping/article/details/4953044)。
  - [深入理解C指针 (豆瓣) (douban.com)](https://book.douban.com/subject/25827246/)。
  - [[嵌入式学习网\]嵌入式C精华.pdf 免费在线阅读 (book118.com)](https://max.book118.com/html/2019/0416/6201034040002023.shtm)，[嵌入式C语言精华文章集锦.pdf_嵌入式c-C文档类资源-CSDN文库](https://download.csdn.net/download/flyinchina1991/10256853)。
- 本文作者的 “C 规范”，Gitee：[C & MCU编写规范和其他.md · 瞰百/coding-style-and-more - Gitee.com](https://gitee.com/staok/coding-style-and-more/blob/main/C & MCU编写规范和其他.md)、Github：[coding-style-and-more/C & MCU编写规范和其他.md at main · Staok/coding-style-and-more (github.com)](https://github.com/Staok/coding-style-and-more/blob/main/C %26 MCU编写规范和其他.md)。
- 学完一门语言要赶紧去看该语言的 **数据结构与算法**。C 语言的数据结构与算法，网搜教程。本文作者的 [【万字总结】数据结构与算法简述和CS综合，保姆级一文打包_空有精品无人问，倒也自然-CSDN博客](https://blog.csdn.net/Staokgo/article/details/122085252)。

**C++ 教程**

- 《C++ Primer Plus（第六版 ）》中文版，大厚书，适合用于复习和课余补充。
- 菜鸟教程 [C++ 教程 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-tutorial.html)。
- C语言中文网 [C++入门教程，C++基础教程（更新完毕） (biancheng.net)](http://c.biancheng.net/cplus/)，[STL教程：C++ STL快速入门（非常详细） (biancheng.net)](http://c.biancheng.net/stl/)。
- [干货推荐 ：五万字长文总结 C/C++ 知识 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/516819910)。

快速教程

- [这可能是史上最快学习C++的课程，期末考前复习冲刺的宝典_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV15Y411j7JW)。
- [复习100分钟拿下100分，你能做得到吗？【C++】(面向对象程序设计)（总复习）_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1ta411k7Yn)。

下面这些 C++ 笔记仓库可牛了（这些仓库均已离线到 `C++学习相关Github仓库收集` 文件夹下！）

- [linux-cpp-tutorial: 基于Linux的C++ 教程合集， 包括C++基础， C++服务器， C++专题 - Gitee.com](https://gitee.com/andy-upp/linux-cpp-tutorial/tree/master)。下文会多出引用这里的内容。
- [czs108/Cpp-Primer-5th-Notes-CN: 📚 《C++ Primer中文版（第5版）》笔记 (github.com)](https://github.com/czs108/Cpp-Primer-5th-Notes-CN)。
- [demon90s/CppStudy: My study notes for c/cpp language (github.com)](https://github.com/demon90s/CppStudy)。
- [Light-City/CPlusPlusThings: C++那些事 (github.com)](https://github.com/Light-City/CPlusPlusThings)。

C++ 杂文

- [C++_路过的小熊~的博客-CSDN博客](https://blog.csdn.net/qq_32348883/category_11547008.html)。
- [C++ 实例 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-examples.html)。
- .etc

**C++ 参考**

- [C++ 有用的资源 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-useful-resources.html)。

  > 以下资源包含了 C++ 有关的网站、书籍和文章。请使用它们来进一步学习 C++ 的知识。
  >
  > C++ 有用的网站：
  >
  > - [C++ Standard Library headers](https://en.cppreference.com/w/cpp/header) − C++ 标准库。
  > - [C++ Programming](http://en.wikibooks.org/wiki/C++_Programming) − 这本书涵盖了 C++ 语言编程、软件交互设计、C++ 语言的现实生活应用。
  > - [C++ FAQ](http://www.sunistudio.com/cppfaq/) − C++ 常见问题
  > - [Free Country](http://www.thefreecountry.com/sourcecode/cpp.shtml) − Free Country 提供了免费的 C++ 源代码和 C++ 库，这些源代码和库涵盖了压缩、存档、游戏编程、标准模板库和 GUI 编程等 C++ 编程领域。
  > - [C and C++ Users Group](http://www.hal9k.com/cug/) − C 和 C++ 的用户团体提供了免费的涵盖各种编程领域 C++ 项目的源代码，包括 AI、动画、编译器、数据库、调试、加密、游戏、图形、GUI、语言工具、系统编程等。
  >
  > C++ 有用的书籍：
  >
  > - 《Essential C++ 中文版》
  > - 《C++ Primer Plus 第6版中文版》
  > - 《C++ Primer中文版（第5版）》

- .etc

**C/C++标准原文**

高阶的 直接拿 C/C++语言标准原文 做备查：

- ISO IEC 9899 1999 (C99)。
- ISO IEC 14882 2003 (C++03)。
- ISO IEC 14882 2011 (C++11)。

## C++ 基础



《C++ Primer Plus（第六版 ）》书 已经看完 4、5、6、7（7章最后还差一点）章节，开始弄c++总结时候，先将前面这些 书上 画线、笔记 总结到这里；

当Linux应用完之后，接着看完C加加书的第7章，然后将4 5 6 7章的所有划线部分都零散的总结进去，然后再接着看后面的计划的章节：10、13章，还有 16.1、16.3、16.7。



### 基础

*p.s 与 C 大同小异的部分不做展开。*

#### 变量与作用域

补充&参考 [C++ 数据类型 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-data-types.html)、[C++ 变量类型 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-variable-types.html)、[C++ 变量作用域 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-variable-scope.html)；[C++ 常量 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-constants-literals.html)、[C++ 修饰符类型 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-modifier-types.html)。[C++变量的定义位置 (biancheng.net)](http://c.biancheng.net/view/2195.html)，[C++布尔类型（bool） (biancheng.net)](http://c.biancheng.net/view/2197.html)。

```
void
bool（true/false）
char、wchar_t、short、int、long、long long
float、double
auto
/*  auto：声明变量时根据初始化表达式自动推断该变量的类型、声明函数时函数返回值的占位符。
    C++98 标准中 auto 关键字用于自动变量的声明，但由于使用极少且多余，在 C++17 中已删除这一用法。*/

signed、unsigned

struct 结构体  结构体里面可以写函数，通过 “结构体.函数名(..)” 来调用
enum   枚举    c++ enum的新特性之enum class enum struct：https://blog.csdn.net/qq_32348883/article/details/122866241
union  联合

const、static、volatile
typedef 类型定义
extern  对其他文件可见
```

#### 预处理

补充参考 [C++ 预处理器 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-preprocessor.html)。

```
#include
#if、#ifdef、#ifndef、#elif、#else、#endif
#define

#  后文转字符串
## 左右文拼接

__LINE__、__FILE__、__DATE__、__TIME__
```

#### 循环和分支结构

```
循环：for、while、do{ }while + continue、break
分支：if、if-else、if-else if-...-else、switch
```



**下面开始介绍 c++ 标准库里构造的 常用数据结构，不过主要会用 string、vector、stack、hash。**



#### string

参考：[C++ string类型理解_xuewu0zhijing的博客-CSDN博客](https://blog.csdn.net/xuewu0zhijing/article/details/105375414)。[c++ string常见用法汇总_路过的小熊~的博客-CSDN博客_c++ string 使用](https://blog.csdn.net/qq_32348883/article/details/124551731)。

```c++
#include <string>

string str1 = "runoob";
string str2 = "google";
string str3;

/* 运算符重载
    “+”、“+=”：连接多个字符串； 
    “=”：给字符串赋值；如
    	str3 = str1;        // 复制 str1 到 str3 
    	str3 = “aaa”;
    	str3 = str1 + str2; // 连接 str1 和 str2
    
    “<”、“<=”、“>”、“>=”：字符串的比较；
    “==”、“！=”：判断字符串是否相等；
*/

/* string 类的方法，每个方法 都是 “string对象.方法;” 来用
    size();    // 返回字符串长度，int len = str3.size(); // str3 的总长度
    length();  // 返回字符串长度
    empty();   // 检查 str 是否为空，为空返回 1，否则返回 0
    at(n);     // 同 str[n]; 作用，存取 str 第 n + 1 个字符（如果溢出会抛出异常）
	
	append(“abc”);            // 作用同 + 运算符重载，在字符串末尾添加字符串"abc"，并返回形成的新字符串
	insert(x, “hello”);       // 从 [x] 位置开始添加字符串 “hello”，并返回形成的新字符串
    insert(x, “hello”, y);    // 从 [x] 位置开始添加字符串 “hello” 的前 y个字符，并返回形成的新字符串
    insert(x, “hello”, y, z); // 从 [x] 位置开始添加字符串 “hijklmn” 的 [y]位置开始的 z 个连续字符 （包括 [y] 在内），并返回形成的新字符串
	
	erase(x);    // 删除 [x] 及其以后的字符，并返回形成的新字符串
	erase(x, y); // 删除从 [x] 开始的 y 个字符，并返回形成的新字符串
	
	查找
	find(" ");     // 返回字符串 " " 在 str 的位置；
    find(" ", x);  // 在 str[x] ~ str[n - 1] **(x<n，下同)**范围内查找并返回字符串 " " 在 str 的位置；
    rfind(" ", x); // 在 str[0] ~ str[x] 范围内查找并返回字符串 " " 在 str 的位置；
    
    string 与 char* 相互拷贝
        char *  转成 string，直接赋值
            string s1 = "aaa";
        
        string 转成 char *，调用类方法
            法一：只需调用 c_str() 方法
                printf("%s\n", s1.c_str());
            法二：调用 copy() 方法
                char buf[128];
                s1.copy(buf, 3 ,0);  // 把string中的内容copy到char *类型的buf中，从位置0开始拷贝3个到buf中
    
    
    first 类方法
    find_first_of(" ");       // 返回 " " 中任何一个字符首次在 str 中出现的位置；
    find_first_of(" ", x);    // 返回 " " 中任何一个字符首次在 str[x]~str[n-1] 范围中出现的位置；
    find_first_not_of(" ");   // 返回除 " " 以外的任何一个字符在 str 中首次出现的位置；
    find_first_not_of(" ", x);// 返回除 " " 以外的任何一个字符在 str[x]~str[n-1] 范围中首次出现的位置；
    
    last 类方法
    find_last_of(" ");          // 返回 " " 中任何一个字符最后一次在 str 中出现的位置；
    find_last_of(" ", x);       // 返回 " " 中任何一个字符最后一次在 str[0]~str[x] 范围中出现的位置；
    find_last_not_of(" ");      // 返回除 " " 以外的任何一个字符在 str 中最后一次出现的位置；
    find_last_not_of(" ", x);   // 返回除 " " 以外的任何一个字符在 str[0]~str[x] 范围中最后一次出现的位置；
	以上如果没有找到相对应的字符，均返回string::npos
	
	替换
	replace(x,y,“hello”)；     // 返回把 [x]~[x+(y-1)] 的内容替换为 “hello” 后的新字符串
    replace(x, y, “abcd”, z); // 返回把 [x]~[x+(y-1)] 的内容替换为 “abcd” 的前z个字符后的新字符串
    
    子串
    substr(x)；  // 返回[x]及以后的子字符串
    substr(x,y)；// 返回[x]~[x+(y-1)]的子字符串（即从[x]开始的y个连续字符组成的字符串）
*/
```

理解：
- [C++初阶：String类_AKA你的闺蜜的博客-CSDN博客](https://blog.csdn.net/yourfriendyo/article/details/123267922)。
- [C++ String类的理解_一只名叫二毛的猫的博客-CSDN博客](https://blog.csdn.net/cherry_ermao/article/details/51051640)。
- [ String类的理解_mm1296939448的博客-CSDN博客](https://blog.csdn.net/mm1296939448/article/details/114982153)。

#### 容器

补充参考：

- [c++容器--vector deque list set map stack queue特性及其选取准则_路过的小熊~的博客-CSDN博客](https://blog.csdn.net/qq_32348883/article/details/123223993)。
- .etc

##### vector

- [C++Vector使用方法 - mengfanrong - 博客园 (cnblogs.com)](https://www.cnblogs.com/mengfanrong/p/3770971.html)。

```c++
#include <vector>

vector< typeName > v4(n);   // v4含有n个值为0的元素
vector< typeName > v3(n,i); // v3包括n个值为i的typeName类型元素

vector< typeName > v1;      // 默认v1为空，故以下的赋值是错误的v1[0]=5;
vector< typeName > v2(v1);  // v2是v1的一个副本，若v1.size（）>v2.size()则赋值后v2.size()被扩充为v1.size()
// 或 v2 = v1;
// 或 vector<typeName> v2(v1.begin(), v1.end());
// 或 int a[4]={0,1,2,3,3}; vector<int> v5(a,a+5); // v5的size为5，v5被初始化为a的5个值。后一个指针要指向将被拷贝的末元素的下一位置

/* vector对象最重要的几种操作
	v.push_back(t)     在容器的最后加入一个值为t的数据，容器的size变大
	v.pop_back()       删除容器的末元素，并不返回该元素
	v.insert(pointer,number, content)    向v中pointer指向的位置插入number个content的内容
    v.insert(pointer, content) 或 v.insert(pointer,a[2],a[4]) 将a[2]到a[4]三个元素插入
    
	v.size()           返回容器中数据的个数，size返回对应vector类定义的size_type的值。
	v.resize(2*v.size) 或 v.resize(2*v.size, 99) 将v的容量翻倍(并把新元素的值初始化为99)
	
	v.empty()         判断vector是否为空
	
	v.clear()         删除容器中的全部元素
	
	v[n]              读写v中位置为n的元素，下标仅仅能用于读写已存在的元素
	
	v1 == v2          判断v1与v2是否相等
	!=、<、<=、>、>=    保持这些操作符惯有含义
*/
```

vector 迭代器用法：

[C++ STL vector容器迭代器用法详解 (biancheng.net)](http://c.biancheng.net/view/6803.html)。

##### list



##### array

参考：[C++ array_星空那么亮的博客-CSDN博客_c++array](https://blog.csdn.net/qq_26646107/article/details/106967633)。[C++基础之容器——array详解_helpburn的博客-CSDN博客_array c++](https://blog.csdn.net/itlilyer/article/details/107561110)。

array 是序列式容器，类似于 C 语言的数组，是固定大小的，一旦定义完成后就无法进行扩容或收缩。

```c++
#include <array>

std::array<int, 4> arr = { 1, 3, 2, 4 };

for (auto it = arr.begin(); it != arr.end(); it++) 
{
		std::cout << *it << " ";
}
```

有方法：begin（返回一个指向array容器第一个元素的迭代器，迭代器可以随机移动和访问元素），end，size，max_size，empty，at，front（返回第一个元素的引用），back，data，fill，swap 等。

##### stack

参考：[c++ stack用法详解_斯文～的博客-CSDN博客_c++ stack](https://blog.csdn.net/weixin_52341477/article/details/119250698)。[C++中stack使用详细说明_想去的远方的博客-CSDN博客_c++stack用法](https://blog.csdn.net/qq_42185999/article/details/115346850)。

后进先出（LIFO）数据结构的实现。

```c++
#include <stack>

/*
    stack<int> q;	// 以int型为例
    q.push(x);		// 将 int 类型的 x 压入栈顶（栈顶，即当前栈指针所指向的位置，随着入栈会移动）
    q.top();		// 返回栈顶的元素，即返回当前栈指针所指向的元素，只返回元素但不弹出
    q.pop();		// 删除栈顶的元素，但不返回，应该先用 q.top(); 取出数据再弹出！
    	即 cout << ss.top(); ss.pop(); 执行这两句才是一次 取数据和弹出
    
    q.size();		// 返回栈中元素的个数
    q.empty();		// 检查栈是否为空,若为空返回true,否则返回false
*/
```



##### set

参考：[c++ set用法详解_斯文～的博客-CSDN博客_c++ set](https://blog.csdn.net/weixin_52341477/article/details/119248919)。

set就是集合，STL的set用二叉树实现，集合中的每个元素只出现一次(参照数学中集合的互斥性)，并且是排好序的(默认按键值升序排列，可以改为降序)，访问元素的时间复杂度是O(log_⁡2 n)。

以乱序 insert 数据之后，用其 迭代器 `set<int>::iterator i;` 来从头到尾取数据 `for( i=q.begin();i!=q.end();i++)   cout<<i<<" ";` 输出 `1 2 3 4`，可见自动按键值排序。

使用看上面链接里的教程即可。

##### map

参考：[c++中map详解_嗯嗯好的呢！的博客-CSDN博客_c++ map](https://blog.csdn.net/m0_67403076/article/details/124503868)。[【c++】map用法详解_LeeMooq的博客-CSDN博客_c++ map](https://blog.csdn.net/yyhyyhy/article/details/124531264)。

以键值对存储的数据，其类型可以自己定义，每个关键字在map中只能出现一次，关键字不能修改，值可以修改；map同set、multiset、multimap（与map的差别仅在于multimap允许一个键对应多个值）内部数据结构都是红黑树，而java中的hashmap是以hash table实现的。所以map内部有序（自动排序，单词时按照字母序排序），查找时间复杂度为O(logn)。

使用看上面链接里的教程即可。

##### hash

即 unordered_map（hash 键值对） 和 unordered_set（hash 集合）。

使用：

- [C++ vector和unordered_map浅析_weixin_30678821的博客-CSDN博客](https://blog.csdn.net/weixin_30678821/article/details/99304348)。
- [unordered_map 简介_菠萝开方的博客-CSDN博客_unordered_map](https://blog.csdn.net/qq_40838478/article/details/114664223)。
- [C++: unordered_map常见用法_道纪书生的博客-CSDN博客_c++ unordered_map用法](https://blog.csdn.net/qq_40682833/article/details/119933215)。

这里只针对 unordered_map，使用 hash 数据结构，一是其为键值对结构，二是其搜索时间复杂度可达 O(1)，搜索问题都可以上 unordered_map 来减小时间复杂度。无论从查找、插入上来说，unordered_map 的效率都优于 hash_map（java里面的），更优于map；而空间复杂度方面，hash_map最低，unordered_map次之，map最大。对于那些有顺序要求的问题，用`map`会更高效一些。对于查找问题，`unordered_map`会更加高效一些。

无序映射（Unordered maps）是用于存储键值和映射值组合成的元素的关联容器，并允许基于其键快速检索各个元素。在unordered_map中，键值通常用于唯一地标识元素，而映射值是具有与该键关联的内容的对象。键的类型和映射的值可能会有所不同。

```c++
#include <unordered_map>

unordered_map<char, int> map;
unordered_map<int, string> myMap={{ 5, "张大" },{ 6, "李五" }}; // 使用{}赋值


// 插入元素
map['a'] = 1;      // 数组形式，若存在则是修改
map.insert( { {'b',2} , {'c',3} } ); // 直接插入，这里是花括号

myMap[2] = "李四";  // 数组形式，进行单个插入，若已存在键值2，则赋值修改，若无则插入
myMap.insert(pair<int, string>(3, "陈二")); // 使用insert和pair插入，这里是括号

// 修改元素
// 使用 map[键] = 值; 通过 键 来 读写 值
map['a'] = 0;

// 删除元素
map.erase('a');          // 删除key为'a'的元素
map.erase(map.begin());  // 删除第一个元素

// 判断元素是否存在
if(map.find('a') != map.end()) // find() 返回一个指向 键 'a' 的迭代器
if(map.count('a'))

// 清空所有元素
map.clear();

// 遍历并取出键和值

// 方法一
for (auto it = map.begin(); it != map.end(); it++) 
{
		char key = it->first;
        int  value = it->second;
}

// 方法二
for( auto& a : map)
{
    char key= a.first;
    int  value= a.second;
}

// 判断是否为空
if( map.empty() )

// 求元素个数
map.size();
```



### 异常处理

参考 [C++ 异常处理 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-exceptions-handling.html)。[C++异常处理（try catch）从入门到精通 (biancheng.net)](http://c.biancheng.net/cplus/exception/)。



### 命名空间

补充参考 [C++ 命名空间 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-namespaces.html)、[C++命名空间（名字空间）详解 (biancheng.net)](http://c.biancheng.net/view/2192.html)。

本意即 区分不同库中**相同名称**的函数、类、变量等。本质上，命名空间就是定义了一个范围。

下面简单例子说明 命名空间的定义（新定义或多次定义增加内容）、引用（使用 `using` 或 `::` 直接引用）和 保证元素名称的唯一性。

```c++
#include <iostream>
using namespace std; /* 使用 iostream 库中 std 命名空间 的内容 */
/* using 指令也可以用来指定命名空间中的特定项目。例如，如果您只打算使用 std 命名空间中的 cout 部分，您可以使用如下的语句：
    using std::cout; */

// 定义第一个命名空间
// 一个命名空间的各个组成部分可以分散在多个文件中，下面的命名空间定义可以是定义一个新的命名空间，也可以是为已有的命名空间增加新的元素
namespace first_space // 该 命名空间 的 名字 first_space
{
    // 这里是代码声明
    
    void func()
    {
        cout << "Inside first_space" << endl;
    }
}

// 定义第二个命名空间
namespace second_space
{
    void func()
    {
        cout << "Inside second_space" << endl;
    }
}

using namespace first_space;

int main ()
{
 
   // 上面 using 表明 其后面的程序使用 first_space 命名空间的内容，这里直接调用第一个命名空间中的函数
   func();
   
   // 使用 :: 调用第二个命名空间中的函数
   second_space::func(); 
 
   return 0;
}

/* 命名空间可以嵌套 */
namespace namespace_name1 {
   // 代码声明
    int a = 100;
   namespace namespace_name2 {
      // 代码声明
       int a =20;
   }
}

using namespace namespace_name1::namespace_name2; // 访问 namespace_name2 中的成员
// using namespace namespace_name1; // 访问 namespace_name1 中的成员

/* 使用 :: 运算符来访问嵌套的命名空间中的成员：
		using namespace namespace_name1::namespace_name2::a;
		或者直接引用
		namespace_name1::namespace_name2::a 

	   要保证同名的函数、变量等的唯一性，不能同时：
		using namespace namespace_name1::namespace_name2; 和 using namespace namespace_name1;
*/
```



### 动态内存

补充参考和引用 [C++ 动态内存 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-dynamic-memory.html)、[C++ new和delete运算符简介 (biancheng.net)](http://c.biancheng.net/view/2199.html)。[new、new()和new 三者的区别_西雅图_Seattle的博客-CSDN博客_new()](https://blog.csdn.net/Seattle_panchaoyi/article/details/51703015)。

```c++
/* 获取数组的成员个数 */
#define ARR_SIZE(arr) sizeof(arr)/sizeof(arr[0])

/* 打印数组 */
#define PRINT_ARR(arr)                 \
    for(i = 0;i < ARR_SIZE(arr);i++)   \
            cout << arr[i] << ' ';     \
    cout << endl;

/* ———————— 申请 变量 和 数组 ———————— */

double* pvalue  = new double;
	if(NULL == pvalue) exit(-1);

/* new 后跟 类型名，也可以是类 */

int* arr_ptr = new int(10);      // 开辟 1 个 int 空间，并赋初值为 10
	if(NULL == arr_ptr) exit(-1);
cout << *arr_ptr << endl;

cin >> n;
int* arr = new int[n];           // 开辟 n 个 int 空间 的数组，地址连续
	if(NULL == arr) exit(-1);

for(i = 0;i < ARR_SIZE(arr);i++) // 挨个填充值，可以空格隔开，如输入 -1 2 6
    cin >> arr[i];

PRINT_ARR(arr);

delete[] arr;                   // 释放 new 申请的数组空间
delete arr_ptr;                 // 释放 new 申请的变量空间
delete pvalue;

/* ———————— 申请 m 行 n 列 的 二维数组 ———————— */
cin >> m >> n;

int** array = new int* [m]; // 分配 m 个指针空间（指针数组）

for(unsigned int i = 0; i < m; i++)
{
    array[i] = new int [n]; // 对指针数组每一个指针所指地址再申请 n 个 int 空间
}

// 释放
for(unsigned int i = 0; i < m; i++)
{
    delete [] array[i];
}

delete [] array;
```



### 引用

补充参考 [C++引用精讲，C++ &用法全面剖析 (biancheng.net)](http://c.biancheng.net/cplus/25/)。[c++引用_路过的小熊~的博客-CSDN博客](https://blog.csdn.net/qq_32348883/article/details/123316063)。

作用： 给变量起别名。 语法： `数据类型& 别名 = 原名`。本质：引用的本质在c++内部实现是一个指针常量

特点：

- 引用必须初始化。
- 引用在初始化后，不可以改变。
- 函数传参时，可以利用 “引用” 让修饰形参（等效于传入指针可以变量修改），也可以修饰 返回值（函数内不要返回局部变量的引用）。通过引用参数产生的效果同按 地址/指针 传递是一样的，引用的语法更清楚简单。
- 在函数形参列表中，可以加 const 修饰形参 ，防止形参改变实参，增加引用的安全性。
- 不能建立数组的引用。

```c++
// 引用修饰 形参 和 返回值。传入 a b 进行交换，再返回 静态变量 c。
int& test02(int& a, int& b, const int& v)
{
    /* v 只能读，不能改 */
    // v += 10;
    
    int temp = a;
	a = b;
	b = temp;
    
	static int c = 30;
	return c;
}

int& test01() {
	static int a = 20;
	return a; // 函数内返回引用变量必须为 static 修饰 或 全局变量
}

int main()
{
    int a1;
    const int &ra=a1;
    // ra = 1; // 错误
    a1 = 1;    // 正确
    
    int temp_a = 10, temp_b = 20;
	int& ref2 = test02(temp_a, temp_b, temp_a + temp_b);
    /* int& ref2 = xxx; 编译器认为为 int* const ref = &xxx */
    cout << "temp_a = " << temp_a << " " << "temp_b = " << temp_b << endl;
    cout << "ref2 = " << ref2 << endl;
    
    int& ref1 = test01();
    cout << "ref1 = " << ref1 << endl;
    test01() = 1000; /* 这样等效于修改 变量 ref1 */
    /* 内部发现 ref1 是引用，自动帮我们转换为: *ref1 = 1000; */
    cout << "ref1 = " << ref1 << endl;
    
    system("pause");
    return 0;
}

/* 打印信息
    temp_a = 20 temp_b = 10
    ref2 = 30
    ref1 = 20
    ref1 = 1000
*/
```



### 函数默认值

函数的形参列表中的形参是可以有默认值的。

注意点：

- 从带有默认参数的形参开始，右面所有的形参都要带默认参数。
- 如果函数声明有默认值，函数实现的时候就不能有默认参数。

```c++
// 从带有默认参数的形参开始，右面所有的形参都要带默认参数
int func(int a, int b = 10, int c = 10)
{
	return a + b + c;
}

// 如果函数声明有默认值，函数实现的时候就不能有默认参数
int func2(int a = 10, int b = 10);
int func2(int a, int b)
{
	return a + b;
}

int main()
{

	cout << "ret = " << func(20, 20) << endl;
	cout << "ret = " << func(100) << endl;

	system("pause");

	return 0;
}

/* 打印信息
    ret = 50
    ret = 120
*/
```



### 函数占位参数

函数的形参列表里可以有占位参数（但只写变量类型不用写变量名），用来做占位，调用函数时必须填补该位置。在个别高级编程场景里面会用到。

```c++
// 函数占位参数 ，占位参数也可以有默认参数
void func(int a, int)
{
	cout << "this is func" << endl;
}

int main() {

	func(10,10); // 占位参数必须填补

	system("pause");
	return 0;
}
```



### 函数重载

函数名相同但参数列表不同的多个函数共存，调用时通过传入不同参数形式来区分调用哪一个。

函数重载满足条件 和 例子：

* 同一个作用域下。

* 函数名称相同。

* 函数参数**类型不同**  或者 **个数不同** 或者 **顺序不同**。函数的返回值不作为函数重载的条件。

  引用也算，带不带 const 修饰的形参 也算不同（传入参数也根据是不是常量来区分调用哪一个函数）。

  函数默认参数 也算不同，但要注意调用时候不要产生歧义。

```c++
void func() {}                    // 调用例子：func();
void func(int a) {}               // 调用例子：func(10);
void func(double a) {}            // 调用例子：func(3.14);
void func(int a ,double b) {}     // 调用例子：func(10, 3.14);
void func(double a ,int b) {}     // 调用例子：func(3.14, 10);

void func(int &a) {}              // 调用例子：int a = 10; func(a);  即 调用无 const 的
void func(const int &a) {}        // 调用例子：            func(10); 即 调用有 const 的

void func2(int a, int b = 10)     // 这样调用会产生歧义：func2(10);  碰到默认参数产生歧义，需要避免
void func2(int a)
```

## 类封装

补充参考 [C++ 类 & 对象 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-classes-objects.html)、[C++类和对象（class和object） (biancheng.net)](http://c.biancheng.net/cplus/class/)。[复习100分钟拿下100分，你能做得到吗？【C++】(面向对象程序设计)（总复习）_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1ta411k7Yn)。[C++ 数据抽象 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-data-abstraction.html) 介绍将数据封装为类的一些概念。

### 封装

变量成员/类属性 和 函数成员/类方法 定义在 类 里面（直接定义）；变量成员 和 函数成员 定义在 类 外面（使用双冒号 ::）。



在类外 访问类内的 变量成员 和 函数成员。



三种访问权限（public/private/protected 关键字，如不定义则默认为 private）。

- 公共权限 public 类内可以访问  类外可以访问。
- 私有权限 private 类内可以访问  类外不可以访问，包括 子类/孩子类 也不能访问；但可以通过 在 public 下定义 set/get 操作 的 函数 来专门访问到 这些 private 变量 而间接对外开放，函数内可以做一些 检查/合法化 等操作，如果是设置 set 或 get 操作 的 函数 就让这些 私有变量 变成 只写 或 只读。
- 保护权限 protected 类内可以访问  类外不可以访问，但是继承的 子类/孩子类 可以访问。



类内 静态的（static 修饰的）变量成员  和 静态或非静态的  函数成员  这三者 均不占 对象空间，即 只有一份/一个实例，所有成员都用这一份/一个实例；而 非静态的 成员变量 占用 对象空间，即每次例化 新的 对象，都会对 这些 变量 新申请空间。



静态函数成员（函数成员 左边 用 static 修饰）只能访问 类内的静态成员；常函数成员（函数成员 的 函数名 后加 const），即 类内的 常函数，该类型函数内不允许修改 变量成员，只能读。



常对象（在最前面 用 const 修饰 来 创建新对象），常对象只能访问 常函数成员。



this 指针，指向 所在的类，即所在类的类指针。若 函数 的形参 和 类内的 变量成员 名字一致，则用 `this->变量成员` 来专门表示 类内的那个成员 而不是 形参，用于区分，这只是一种情况，可灵活运行。



### 构造 & 析构函数

构造函数 和 析构函数 的 作用 分别为 对 对象 的 初始化 和 清理，定义好之后 分别 由 对象创造 和 销毁 的时候自动调用。

构造函数 三种：无参数、有参数（新对象的某些参数的初始化） 和 拷贝构造函数（用于对新对象的成员变量用老对象的成员变量赋值）。



每一个点 都用一两句话 的例子 做说明，最最后 再来一个 用到所有 feature 的 综合例子



关于 拷贝构造函数 的 深拷贝与浅拷贝：个人理解，如果在 无参数、有参数 构造函数 里面 有 使用 new 等的 进行内存申请，那么在 拷贝构造函数 也应该对应的进行 new 等的 内存申请，这样在 创建新对象 时候 使用 拷贝构造函数 的时候 会 重新申请空间（执行深拷贝）而不是 简单的赋值拷贝操作（浅拷贝）。并对应的在 析构函数 里面 对申请的内存进行释放。

### 友元

使用 friend 关键字 在左边 修饰 在类内 声明的 函数成员，则 该 函数 定义在 类外面（而左边不用加 "类名::"） 也可以访问到 类内的成员，即在 类内 修饰 该 函数成员 为 该类 的朋友，可以访问自己。

### 运算符重载

或叫 重载运算。补充参考 [C++ 重载运算符和重载函数 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-overloading.html)、[C++函数重载详解 (biancheng.net)](http://c.biancheng.net/view/2206.html)、[C++运算符重载基础教程 (biancheng.net)](http://c.biancheng.net/view/2306.html)。



## 类继承

补充参考 [C++ 继承 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-inheritance.html)、[C++继承和派生简明教程 (biancheng.net)](http://c.biancheng.net/view/2264.html)。

- 父类/基类。
- 子类/派生类。

派生类中的成员，包含两大部分：

- 一类是从基类继承过来的，一类是自己增加的成员。

- 从基类继承过过来的表现共性，而新增的成员体现个性。

三种继承/派生（继承和派生这里一个意思）：公共继承、保护继承、私有继承。基类 中 a 权限的成员 被以 b 权限 继承到子类，那么子类中该成员的权限取 a 和 b 中较低的那一个。

公共继承中，父类中私有成员也是被子类继承下去了，只是由编译器给隐藏后访问不到。

子类继承父类后，当创建子类对象，先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反。

子类的构造函数中对类变量成员进行初始化，要先用 初始化列表 来初始化 基类 的 变量成员，再去在函数内初始化 子类的 变量成员，比较规范。看 https://www.bilibili.com/video/BV1ta411k7Yn?p=2&spm_id_from=pageDriver&vd_source=c633af9518bed5572b1614612e2be3df 的 4分半的地方



继承/派生 的时候 如果 是修饰为 类指针 或者 引用 类型（而且不使用 new 创建空间），则不为其分配内存。

```c++

```



### 公共继承





### 保护继承





### 私有继承





### 虚继承 / 菱形继承

一个类（孙）继承多个类（子），而这多个类中至少有两个类（子） 又 继承自 同一个类（父），从而导致 孙辈的类 会包含 多个来自 父辈类的副本成员，因此要使用 虚继承。继承时候使用 virtual 修饰。





## 类多态



## Cpp 标准库

参考 菜鸟教程、C 语言中文网等。这里只是罗列库函数，解决“都有什么”的问题，每一个 API 的具体用法需要用时现查。

- <iostream>

  该文件定义了 **cin、cout、cerr** 和 **clog** 对象（**iostream** 类的实例），分别对应于标准输入流、标准输出流、非缓冲标准错误流 和 缓冲标准日志流。

  使用 cerr 流来显示错误消息，而其他的日志消息则使用 clog 流来输出。

  

  一些设置输出模式的 API（比如 设置/清除 左/右对齐、保留几位小数、科学计数法、16禁止输出，还有 iostream 中定义的操作符 等）：

  参考 [C++ 基本的输入输出 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-basic-input-output.html)，[C++ cout格式化输出（超级详细） (biancheng.net)](http://c.biancheng.net/view/7578.html)。

  

  也可以用 c 的标准输入输出 API 如 scanf()、printf()、getchar()、putchar() 等等。

- <cmath>：常用数学函数。

  |      | cmath 库函数                                                 |
  | ---- | ------------------------------------------------------------ |
  | 1    | **double cos(double);** 该函数返回弧度角（double 型）的余弦。 |
  | 2    | **double sin(double);** 该函数返回弧度角（double 型）的正弦。 |
  | 3    | **double tan(double);** 该函数返回弧度角（double 型）的正切。 |
  | 4    | **double log(double);** 该函数返回参数的自然对数。           |
  | 5    | **double pow(double, double);** 假设第一个参数为 x，第二个参数为 y，则该函数返回 x 的 y 次方。 |
  | 6    | **double hypot(double, double);** 该函数返回两个参数的平方总和的平方根，也就是说，参数为一个直角三角形的两个直角边，函数会返回斜边的长度。 |
  | 7    | **double sqrt(double);** 该函数返回参数的平方根。            |
  | 8    | **int abs(int);** 该函数返回整数的绝对值。                   |
  | 9    | **double fabs(double);** 该函数返回任意一个浮点数的绝对值。  |
  | 10   | **double floor(double);** 该函数返回一个小于或等于传入参数的最大整数。 |

- <ctime>：时间和日期。

  有四个与时间相关的类型：**clock_t、time_t、size_t**（这三个能够把系统时间和日期表示为某种整数） 和 **tm**。

  结构类型 **tm** 把日期和时间以 C 结构的形式保存，tm 结构的定义如下：

  ```c++
  struct tm {
    int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
    int tm_min;   // 分，范围从 0 到 59
    int tm_hour;  // 小时，范围从 0 到 23
    int tm_mday;  // 一月中的第几天，范围从 1 到 31
    int tm_mon;   // 月，范围从 0 到 11
    int tm_year;  // 自 1900 年起的年数
    int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
    int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
    int tm_isdst; // 夏令时
  };
  ```

  

  |      | ctime 库函数                                                 |
  | ---- | ------------------------------------------------------------ |
  | 1    | [**time_t time(time_t \*time);**](https://www.runoob.com/cplusplus/c-function-time.html) 该函数返回系统的当前日历时间，自 1970 年 1 月 1 日以来经过的秒数。如果系统没有时间，则返回 -1。 |
  | 2    | [**char \*ctime(const time_t \*time);**](https://www.runoob.com/cplusplus/c-function-ctime.html) 该返回一个表示当地时间的字符串指针，字符串形式 *day month year hours:minutes:seconds year\n\0*。 |
  | 3    | [**struct tm \*localtime(const time_t \*time);**](https://www.runoob.com/cplusplus/c-function-localtime.html) 该函数返回一个指向表示本地时间的 **tm** 结构的指针。 |
  | 4    | [**clock_t clock(void);**](https://www.runoob.com/cplusplus/c-function-clock.html) 该函数返回程序执行起（一般为程序的开头），处理器时钟所使用的时间。如果时间不可用，则返回 -1。 |
  | 5    | [**char \* asctime ( const struct tm \* time );**](https://www.runoob.com/cplusplus/c-function-asctime.html) 该函数返回一个指向字符串的指针，字符串包含了 time 所指向结构中存储的信息，返回形式为：day month date hours:minutes:seconds year\n\0。 |
  | 6    | [**struct tm \*gmtime(const time_t \*time);**](https://www.runoob.com/cplusplus/c-function-gmtime.html) 该函数返回一个指向 time 的指针，time 为 tm 结构，用协调世界时（UTC）也被称为格林尼治标准时间（GMT）表示。 |
  | 7    | [**time_t mktime(struct tm \*time);**](https://www.runoob.com/cplusplus/c-function-mktime.html) 该函数返回日历时间，相当于 time 所指向结构中存储的时间。 |
  | 8    | [**double difftime ( time_t time2, time_t time1 );**](https://www.runoob.com/cplusplus/c-function-difftime.html) 该函数返回 time1 和 time2 之间相差的秒数。 |
  | 9    | [**size_t strftime();**](https://www.runoob.com/cplusplus/c-function-strftime.html) 该函数可用于格式化日期和时间为指定的格式。 |

  使用例子参考 [C++ 日期 & 时间 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-date-time.html)。

- <cstdlib>：

  rand()

- <cstring>：与 c 的 string.h 大同小异。

  |      | cstring 库函数                                               |
  | ---- | ------------------------------------------------------------ |
  | 1    | **strcpy(s1, s2);** 复制字符串 s2 到字符串 s1。              |
  | 2    | **strcat(s1, s2);** 连接字符串 s2 到字符串 s1 的末尾。连接字符串（string 类型的）也可以用 **+** 号，例如: `string str1 = "runoob"; string str2 = "google"; string str = str1 + str2;` |
  | 3    | **strlen(s1);** 返回字符串 s1 的长度。                       |
  | 4    | **strcmp(s1, s2);** 如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；如果 s1>s2 则返回值大于 0。 |
  | 5    | **strchr(s1, ch);** 返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。 |
  | 6    | **strstr(s1, s2);** 返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。 |

- <algorithm>：泛函算法
  搜索算法：find() 、search() 、count() 、find_if() 、search_if() 、count_if()
  分类排序：sort() 、merge()
  删除算法：unique() 、remove()
  生成和变异：generate() 、fill() 、transformation() 、copy()
  关系算法：equal() 、min() 、max()

- <fstream>：文件操作库，用时现查即可。

  可参考 [C++ 文件和流 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-files-streams.html)。[C++文件操作 (biancheng.net)](http://c.biancheng.net/cplus/60/)。

## 模板

模板是泛型编程的基础。C++ 模板 来支持 泛型编程，对数据类型不敏感 [大话C++模板编程的来龙去脉 (biancheng.net)](http://c.biancheng.net/view/2319.html)，STL（Standard Template Library，标准模板库）就是 C++ 对数据结构进行封装后的称呼。

补充参考：

- [C++ 模板 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-templates.html)。
- [C++模板和泛型程序设计 (biancheng.net)](http://c.biancheng.net/cplus/70/)。
- [c++高效编程之模板函数、模板结构体、模板类的使用_路过的小熊~的博客-CSDN博客_c++ 结构体模板](https://blog.csdn.net/qq_32348883/article/details/122044301)。

### 函数模板

参考：[C++函数模板5分钟入门教程 (biancheng.net)](http://c.biancheng.net/view/2317.html)。中文语境下 也叫 “模板函数”。



### 类模板

参考：[C++类模板5分钟入门教程 (biancheng.net)](http://c.biancheng.net/view/2318.html)。中文语境下 也叫 “模板类”。



## STL

补充参考 [C++ STL 教程 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-stl-tutorial.html)、[STL教程：C++ STL快速入门（非常详细） (biancheng.net)](http://c.biancheng.net/stl/)。

