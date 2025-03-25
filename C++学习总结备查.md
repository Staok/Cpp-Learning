# C++ 学习总结

本文非基础教学文，而是在有 C 语言的基础上对 C++ 学习的总结记录，长期积累&更新。

欢迎在原文 [github](https://github.com/Staok/Cpp-Learning) / [gitee](https://gitee.com/staok/Cpp-Learning) 仓库 提 issue 指出错误，和 提 PR 来一同建设内容。 

本文的 Github 仓库地址 内文章会不断更新，而发在其它位置的不会跟进了，本文的 Gitee 仓库地址 访问更流畅。

*p.s 本文为个人对 C++ 学习的总结，本人习惯性把一块领域的内容用一篇大文章（万字为单位计）来汇聚（而非分了很多个小文章），说白了是主要用于个人总结和备查，而非做教程，因而会有个人对内容的挑选，而非照搬该领域的大部分内容（因此本文会遗漏一些过于基础的东西），以及使用的最佳实践，后二点，可以通过多看一些最佳实践的文章和工程来对自己进行提高（下面也会给出很多推荐看的链接）；本文会给出大量的参考链接，绝大多数都是漫长时间里面发现、挑选、整理出来的精品，也就是个人把本文当字典来用；因为非教程，而是面向有一定基础的人，而且一个文章的体量相比于大多数网络文章显得 "过于巨大"，看的人少也是应该的。*



尚有 一些 标记了 TODO 的地方 有待施工。没有三头六臂，很多资料 手头和脑里 都有 只是尚未没有整理出来。



> 虽抱文章，开口谁亲。且陶陶、乐尽天真。几时归去，作个闲人。对一张琴，一壶酒，一溪云。



------

## C/C++ 精品文 汇总

下面的教程会列举很多，选择合适自己的去看即可。

**C 语言入门**

- 菜鸟教程 [C 语言教程 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cprogramming/c-tutorial.html)。
- C语言中文网 [网站地图 (biancheng.net)](http://c.biancheng.net/sitemap/)，个别小节需要 RMB。
- B站搜“C语言学习” [C语言学习 _ 搜索结果_ 哔哩哔哩 _Bilibili](https://search.bilibili.com/all?keyword=C语言学习)，随便一搜一大把，其它语言同理。

**对于 C 语言特性的精品汇总**

- [Knowledge-Notes/2 - C语言笔记 at master · wuxiaolie/Knowledge-Notes (github.com)](https://github.com/wuxiaolie/Knowledge-Notes/tree/master/2 - C语言笔记)。
- [embedded/01_C at master · kuraxii/embedded (github.com)](https://github.com/kuraxii/embedded/tree/master/01_C)。
- [lh233/C-knowledge: 关于C语言的基础知识 (github.com)](https://github.com/lh233/C-knowledge)。

**C 语言提高**

- C 语言三剑客：《C和指针》、《C陷阱与缺陷》和《C专家编程》，经典永流传。

- [《嵌入式C语言的自我修养》](https://book.douban.com/subject/35446929/) 从沙子讲到CPU，从编辑器讲到编译器，从高阶C语言讲到内存管理，从GNU讲到多任务编程。[《嵌入式C语言自我修养》勘误 - 公众号文章汇总 | 宅学部落 (zhaixue.cc)](https://www.zhaixue.cc/weixin/weixin-correction.html)。

- 列一些提高的书：（有的书可以网上找到电子版（只提醒一下））

  - [让你不再害怕指针——C指针详解(经典,非常详细) - 简书 (jianshu.com)](https://www.jianshu.com/p/9b8aeaba8ca8)，[让你不再害怕指针——C指针详解(经典,非常详细)_程序老兵的博客-CSDN博客_指针](https://blog.csdn.net/soonfly/article/details/51131141)。
  - [你必须知道的495个C语言问题 (豆瓣) (douban.com)](https://book.douban.com/subject/26868092/)，[你必须知道的495个C语言问题_benpaobagzb的博客-CSDN博客_你必须知道的495个c语言问题](https://blog.csdn.net/benpaobagzb/article/details/48442099)，[《你必须知道的495个C语言问题》知识笔记及补充 - Alexia(minmin) - 博客园 (cnblogs.com)](https://www.cnblogs.com/lanxuezaipiao/p/3539262.html)。
  - [C语言深度解剖 (豆瓣) (douban.com)](https://book.douban.com/subject/4924419/)。
  - [C语言的底层操作_zhongjie的专栏-CSDN博客_c语言底层架构](https://blog.csdn.net/zhongjiekangping/article/details/4953044)。
  - [深入理解C指针 (豆瓣) (douban.com)](https://book.douban.com/subject/25827246/)。
  - [嵌入式学习网\]嵌入式C精华.pdf 免费在线阅读 (book118.com)](https://max.book118.com/html/2019/0416/6201034040002023.shtm)，[嵌入式C语言精华文章集锦.pdf_嵌入式c-C文档类资源-CSDN文库](https://download.csdn.net/download/flyinchina1991/10256853)。

- 本文作者的 “C 规范”：

  Gitee：[C & MCU编写规范和其他.md · 瞰百/coding-style-and-more - Gitee.com](https://gitee.com/staok/coding-style-and-more/blob/main/C & MCU编写规范和其他.md)。

  Github：[coding-style-and-more/C & MCU编写规范和其他.md at main · Staok/coding-style-and-more (github.com)](https://github.com/Staok/coding-style-and-more/blob/main/C %26 MCU编写规范和其他.md)。

- 学完一门语言要赶紧去看该语言的 **数据结构与算法**。C 语言的数据结构与算法，网搜教程。

  本文作者的 [（大集合）数据结构与算法简述和CS综合 - 欢迎来到 Staok - 瞰百易 (github.io)](https://staok.github.io/15数据结构与算法简述和cs综合/) / [CSDN](https://blog.csdn.net/Staokgo/article/details/122085252)。
  
  这个文章属于早期整理，正式的、内容更丰富的 github 仓库为 [Staok/C-Cpp-data-struct-algo: C-C++-数据结构与算法相关优秀资料集子 (github.com)](https://github.com/Staok/C-Cpp-data-struct-algo)。

**C++ 教程**

- B站大学 [玄马教育 C++40个知识点带你入门_哔哩哔哩_bilibili](https://space.bilibili.com/477729104/channel/seriesdetail?sid=864816)。

- 简明教程（推荐） [C++ Beginner's Guide for Python/Java/... Programmers | hacking C++ (hackingcpp.com)](https://hackingcpp.com/cpp/beginners_guide.html)。

  介绍 [论C++教程就属HackingCpp简洁优雅,C++ Primer,cppreference_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1Ko4y137vG/)。

- 《C++ Primer Plus（第六版 ）》中文版，大厚书，适合用于复习和课余补充。

- 菜鸟教程（推挤） [C++ 教程 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-tutorial.html)。

- C语言中文网 [C++入门教程，C++基础教程（更新完毕） (biancheng.net)](http://c.biancheng.net/cplus/)，[STL教程：C++ STL快速入门（非常详细） (biancheng.net)](http://c.biancheng.net/stl/)。

- [干货推荐 ：五万字长文总结 C/C++ 知识 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/516819910)。

- [C++ 标准库简介 - OI Wiki (oi-wiki.org)](https://oi-wiki.org/lang/csl/)，[类 - OI Wiki (oi-wiki.org)](https://oi-wiki.org/lang/class/)。

- [学习C++这一篇就够了（基础篇）-CSDN博客](https://blog.csdn.net/m0_60259116/article/details/131987585)，[学习C++这一篇就够了（提升篇）_c++提升学习-CSDN博客](https://blog.csdn.net/m0_60259116/article/details/131995639)，[学习C++这一篇就够了（进阶篇）_c++ 进阶csdn-CSDN博客](https://blog.csdn.net/m0_60259116/article/details/132026127)。

~~C++ 快速复习~~ 都是些应试用的~~时代废品~~

- ~~[这可能是史上最快学习C++的课程，期末考前复习冲刺的宝典_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV15Y411j7JW)。~~
- ~~[复习100分钟拿下100分，你能做得到吗？【C++】(面向对象程序设计)（总复习）_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1ta411k7Yn)。~~

**对于 C++ 语言特性的精品汇总**

- [Knowledge-Notes/2 - C++笔记 at master · wuxiaolie/Knowledge-Notes (github.com)](https://github.com/wuxiaolie/Knowledge-Notes/tree/master/2 - C%2B%2B笔记)。
- [embedded/02_CPP at master · kuraxii/embedded (github.com)](https://github.com/kuraxii/embedded/tree/master/02_CPP)。
- [EmbeddedSystem/Language at master · SummerGift/EmbeddedSystem (github.com)](https://github.com/SummerGift/EmbeddedSystem/tree/master/Language)。



- [chengxumiaodaren/cpp-learning (github.com)](https://github.com/chengxumiaodaren/cpp-learning)。[CPP学习资料汇总 - 飞书云文档 (feishu.cn)](https://lb3fn675fh.feishu.cn/docx/VUjdd8uCdoufThxHEOzcQQaonCh)。
- [C++11/14/17/20/23新特性，哪些是必须掌握的，哪些基本用得不多？ - 知乎 (zhihu.com)](https://www.zhihu.com/question/474664436/answer/3612037757)。

**C++ 精品仓库**

下面这些 C++ 笔记 / 仓库可牛了（这些仓库大部已离线到 `C++学习相关Github仓库收集` 文件夹下！）

- [chengxumiaodaren/cpp-learning (github.com)](https://github.com/chengxumiaodaren/cpp-learning)。好内容非常多。这个没有离线到本地。
- [linux-cpp-tutorial: 基于Linux的C++ 教程合集， 包括C++基础， C++服务器， C++专题 - Gitee.com](https://gitee.com/andy-upp/linux-cpp-tutorial/tree/master)。
- [czs108/Cpp-Primer-5th-Notes-CN: 📚 《C++ Primer中文版（第5版）》笔记 (github.com)](https://github.com/czs108/Cpp-Primer-5th-Notes-CN)。
- [demon90s/CppStudy: My study notes for c/cpp language (github.com)](https://github.com/demon90s/CppStudy)。
- [Light-City/CPlusPlusThings: C++那些事 (github.com)](https://github.com/Light-City/CPlusPlusThings)。



- [0voice/introduce_c-cpp_manual: 一个收集C/C++新手学习的入门项目，整理收纳开发者开源的小项目、工具、框架、游戏等，视频，书籍，面试题/算法题，技术文章。 (github.com)](https://github.com/0voice/introduce_c-cpp_manual)。
- [0voice/cpp_new_features: 2021年最新整理， C++ 学习资料，含C++ 11 / 14 / 17 / 20 / 23 新特性、入门教程、推荐书籍、优质文章、学习笔记、教学视频等 (github.com)](https://github.com/0voice/cpp_new_features)。好内容非常多。这个没有离线到本地。



- [FunctionDou/STL: STL源码分析 (github.com)](https://github.com/FunctionDou/STL)。
- 推荐源码库可读 1：[你读过的最好的 C++ 开源代码是什么？ - 知乎 (zhihu.com)](https://www.zhihu.com/question/21376384)。
- 推荐源码库可读 2：[你读过的最好的 C++ 开源代码是什么？ - 知乎 (zhihu.com)](https://www.zhihu.com/question/21376384/answer/29689529)。
- 推荐源码库可读 3：[chenshuo/muduo: Event-driven network library for multi-threaded Linux server in C++11 (github.com)](https://github.com/chenshuo/muduo)。
- [miloyip/json-tutorial: 从零开始的 JSON 库教程 (github.com)](https://github.com/miloyip/json-tutorial)。



- [CnTransGroup/EffectiveModernCppChinese: 《Effective Modern C++》- 完成翻译 (github.com)](https://github.com/CnTransGroup/EffectiveModernCppChinese)。
- [balloonwj/CppGuide: C/C++学习，后端开发进阶指南。 (github.com)](https://github.com/balloonwj/CppGuide)。

**C++ 精品杂文**

- [C++_路过的小熊~的博客-CSDN博客](https://blog.csdn.net/qq_32348883/category_11547008.html)。
- [C++ 实例 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-examples.html)。



- [C/C++ 编程技术 - 知乎 (zhihu.com)](https://www.zhihu.com/column/c_1662775871361613824)。
- [C/C++ Linux 软件开发模拟面试 - 知乎 (zhihu.com)](https://www.zhihu.com/column/c_1697924273321160704)。
- [Linux 开发 - 知乎 (zhihu.com)](https://www.zhihu.com/column/c_1697391693194809344)。



- .etc

**C++ 参考 / 字典 / 特性快速索引**

- 首推 [cppreference](https://zh.cppreference.com/w/首页)。这个网站里面的描述可能大多 "比较官话"，相关的关键字可以网搜文章来学，这个网站对于广大应用者来说可以认为是比较全的列出来 "都有什么"。

  [离线查看的归档 - cppreference.com](https://zh.cppreference.com/w/Cppreference:Archives)。[cppreference离线文档下载 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/651697815)。

  [C++ 标准库标头 - cppreference.com](https://zh.cppreference.com/w/cpp/header)。

- hackingcpp，容器 & argo库 等 图形化展示 [C++ Cheat Sheets & Infographics | hacking C++ (hackingcpp.com)](https://hackingcpp.com/cpp/cheat_sheets.html)。

- [mortennobel/cpp-cheatsheet: Modern C++ Cheatsheet (github.com)](https://github.com/mortennobel/cpp-cheatsheet)。

- [C++ 有用的资源 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-useful-resources.html)。

  以下挑出上面没有的做补充

  > 以下资源包含了 C++ 有关的网站、书籍和文章。请使用它们来进一步学习 C++ 的知识。
  >
  > C++ 有用的网站：
  >
  > - [C++ Programming](http://en.wikibooks.org/wiki/C++_Programming) − 这本书涵盖了 C++ 语言编程、软件交互设计、C++ 语言的现实生活应用。
  > - [C++ FAQ](http://www.sunistudio.com/cppfaq/) − C++ 常见问题
  > - [Free Country](http://www.thefreecountry.com/sourcecode/cpp.shtml) − Free Country 提供了免费的 C++ 源代码和 C++ 库，这些源代码和库涵盖了压缩、存档、游戏编程、标准模板库和 GUI 编程等 C++ 编程领域。
  > - [C and C++ Users Group](http://www.hal9k.com/cug/) − C 和 C++ 的用户团体提供了免费的涵盖各种编程领域 C++ 项目的源代码，包括 AI、动画、编译器、数据库、调试、加密、游戏、图形、GUI、语言工具、系统编程等。

- 有不清楚的概念直接问 AI 工具。

- .etc

## C/C++ 精品库 汇总

看到的小巧精良的小型 c/cpp 库/项目列举。



C 精品仓库

[jobbole/awesome-c-cn: C 资源大全中文版，包括了：构建系统、编译器、数据库、加密、初中高的教程/指南、书籍、库等。 (github.com)](https://github.com/jobbole/awesome-c-cn)。



C++ 精品仓库

[Your list / 实用库 / EE-CS (github.com)](https://github.com/stars/Staok/lists/实用库-ee-cs)。



以及 见同目录的 `C-C++实用库备查.md` 文章。



## 编程经验、调试、性能和内存检查工具集合

见同目录的 `编程经验、调试、性能和内存检查工具集合` 文章。



## Shell 脚本 汇总

- [fengyuhetao/shell: Linux命令行与shell脚本编程大全案例 (github.com)](https://github.com/fengyuhetao/shell)。



## C/C++ 数据结构与算法 / 设计模式

学习一些设计模式和实践经验，写更健壮和好维护的程序。

总结整理仓库：

C-C++-数据结构与算法简述 [Staok/C-Cpp-data-struct-algo: C-C++-数据结构与算法相关优秀资料集子 (github.com)](https://github.com/Staok/C-Cpp-data-struct-algo)。

C-C++-设计模式综合 [Staok/C-Cpp-design-patterns: C/C++设计模式相关优秀资料集子 (github.com)](https://github.com/Staok/C-Cpp-design-patterns)。



## C++ (11 / 14 / 17 / 20) 基础

主要围绕 C++ 11 / 14 / 17 / 20 以及以上 的 各版本特性 展开

下面各小节的顺序没有处理。

下面给出的基础语法和例子，实践的时候可举一反三使用，写东西时候先多思考架构，不必一上来就写 等 情况的出现，减少后面 debug 和 重构的时间。



TODO:

```
《C++ Primer Plus（第六版 ）》书 已经看完 4、5、6、7（7章最后还差一点）章节，开始弄c++总结时候，先将前面这些 书上 画线、笔记 总结到这里；

当Linux应用完之后，接着看完C加加书的第7章，然后将4 5 6 7章的所有划线部分都零散的总结进去，然后再接着看后面的计划的章节：10、13章，还有 16.1、16.3、16.7。
```



### C++ 各版本优质参考

- [C++11 - cppreference.com](https://zh.cppreference.com/w/cpp/11)，[C++14 - cppreference.com](https://zh.cppreference.com/w/cpp/14)，[C++17 - cppreference.com](https://zh.cppreference.com/w/cpp/17)，[C++20 - cppreference.com](https://zh.cppreference.com/w/cpp/20)。
- [c++14新特性总结 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/588826142)。
- [当面试官问我C++ 11新特性的时候，应该怎样回答？ - 知乎 (zhihu.com)](https://www.zhihu.com/question/65209863/answer/1957019832)。
- [chengxumiaodaren/cpp-learning (github.com)](https://github.com/chengxumiaodaren/cpp-learning)。
- [C++11/14/17/20/23新特性，哪些是必须掌握的，哪些基本用得不多？ - 知乎 (zhihu.com)](https://www.zhihu.com/question/474664436/answer/3612037757)。
- [c++11 新特性总结（一）——关键字篇 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/463616036)。



### 基础

*p.s 与 C 大同小异的部分不做展开。*



#### 变量与作用域

**变量**

补充参考 [C++ 数据类型 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-data-types.html)、[C++ 变量类型 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-variable-types.html)、[C++ 变量作用域 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-variable-scope.html)；[C++ 常量 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-constants-literals.html)、[C++ 修饰符类型 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-modifier-types.html)。[C++变量的定义位置 (biancheng.net)](http://c.biancheng.net/view/2195.html)，[C++布尔类型（bool） (biancheng.net)](http://c.biancheng.net/view/2197.html)。

```c
void
bool（true/false）
char、wchar_t、short、int、long
float、double

// c++11 新增了几种数据类型:
nullptr(在 c++ 中替代 NULL，专用于 表示 空指针；NULL 本质上是个 int 型的 0，不是个指针)
long long
char16_t、char32_t (Unicode 字符)

 ---

signed、unsigned

 ---

struct // 结构体  c++的结构体里面可以写函数，通过 “结构体.函数名(..)” 来调用
enum   // 枚举    c++ enum的新特性之enum class enum struct：https://blog.csdn.net/qq_32348883/article/details/122866241
union  // 联合

 ---

const、static、volatile
typedef // 类型定义
extern  // 对其它文件可见
```



**作用域**

1. 全局作用域（全局变量）。
2. 局部作用域 / 块作用域（语句块 `{...} `内的变量，局部变量）。
3. 类域（class），命名空间作用域（namespace）。

块的内外部均定义有同名变量情况下，在运行到块内部时，仅使用块内部的同名变量而隐藏掉块外部的同名变量。



关于 auto、static、thread_local、extern、mutable 这些 存储类 说明符 / 修饰符 的 说明 和 使用范围：

[存储类说明符 - cppreference.com](https://zh.cppreference.com/w/cpp/language/storage_duration)。



#### 预处理

补充参考 [C++ 预处理器 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-preprocessor.html)。

```
#include
#if、#ifdef、#ifndef、#elif、#else、#endif
#define

#  后文转字符串
## 左右文拼接

__func__、__LINE__、__FILE__、__DATE__、__TIME__
```



**__has_include 预处理 表达式**

> ```c++
> #if defined __has_include
>     #if __has_include(<charconv>)
>     	#define has_charconv 1
>     	#include <charconv>
>     #endif
> #endif
> 
> std::optional<int> ConvertToInt(const std::string& str) {
>     int value{};
> #ifdef has_charconv // 判断是否有包含某个头文件 或 库，根据实际 include 的东西 选择处理方式
>     const auto last = str.data() + str.size();
>     const auto res = std::from_chars(str.data(), last, value);
>     if (res.ec == std::errc{} && res.ptr == last) return value;
> #else
>     // alternative implementation...
>     // 其它方式实现
> #endif
>     return std::nullopt;
> }
> ```
>
> 



#### 循环和分支结构

```
循环：for、while、do{ }while + continue、break
分支：if、if-else、if-else if-...-else、switch
```



### 命名空间

补充参考 [C++ 命名空间 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-namespaces.html)、[C++命名空间（名字空间）详解 (biancheng.net)](http://c.biancheng.net/view/2192.html)。

- 本意即 区分不同库中**相同名称**的函数、类、变量等。本质上，命名空间就是定义了一个范围。
- 是一种作用域的划分，通常用于区分项目中的模块或组件，其中可定义变量、函数等。
- 可分布式定义，可嵌套，可取别名。推荐使用`::`来引用命名空间里的对象。

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

namespace first_space // 分布式定义，为 命名空间 first_space 添加成员
{
    int a;
}

// 定义第二个命名空间
namespace second_space
{
    int b;
    void func()
    {
        cout << "Inside second_space" << endl;
    }
}

int cc1 = 10;

namespace cd 
{
   int c = ::cc1; // 引用全局变量 cc1
    
   namespace d    // 命名空间 嵌套
   {
      int d;
   }
}

// using namespace cd; 		// 访问 cd 中的成员
// using namespace cd::d; 	// 访问 d 中的成员

/* 使用 :: 运算符来访问嵌套的命名空间中的成员：
		
		使用 using 引用（不推荐常用在命名空间）：using namespace cd::d::d;

		或者直接引用（推荐）：cd::d::d

	   要保证同名的函数、变量等的唯一性，不能同时：
		using namespace first_space; 和 using second_space ;
*/

namespace n = cd;     // 给 命名空间 cd 取别名为 n
namespace dd = cd::d; // 给 命名空间 d  取别名为 dd

using namespace first_space;

int main ()
{
 
   // 上面 using 表明 其后面的程序使用 first_space 命名空间的内容，这里直接调用第一个命名空间中的函数
   func();
   
   // 使用 :: 调用第二个命名空间中的函数
   second_space::func(); 
 
   return 0;
}

// namespace 嵌套，C++ 17 起
// 多层的命名空间可以这么定义
namespace A::B::C {
    void func();)
}

```



**下面开始介绍 c++ STL 标准库里的 常用数据结构实现，常用的有 string、vector、list、hash 等。**

### string

参考：[C++ string类型理解_xuewu0zhijing的博客-CSDN博客](https://blog.csdn.net/xuewu0zhijing/article/details/105375414)。[c++ string常见用法汇总_路过的小熊~的博客-CSDN博客_c++ string 使用](https://blog.csdn.net/qq_32348883/article/details/124551731)。

**各种方法，用时可以在 [cppreference](https://zh.cppreference.com/w/%E9%A6%96%E9%A1%B5) 里现找即可。**

下面的就是看着玩的。

#### 各种基本方法

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



#### 流的格式控制

这里面方法很多，难全记，所以**实际常问 AI 工具去写**。

参考 [C++输出流格式控制_iomanip_51CTO博客_c++ 输出格式控制](https://blog.51cto.com/u_15790456/6569587)，[C++输入输出流格式控制_c++输入输出格式控制_GNG的博客-CSDN博客](https://blog.csdn.net/so_geili/article/details/70406921)。

两种方式：具体写发看参考即可。

- 使用控制符：引用头文件 `iomanip`，使用方式 `cout << 控制符 << 数据 << endl;`。
- 使用 cout 成员函数：例如 `cout.setf(ios::left);// 设置左对齐`，`cout.width(4);// 宽度为4`，`cout.precision(2);// 设置浮点数精度为2` 等等。



#### std::string_view

> 通常我们传递一个string时会触发对象的拷贝操作，大字符串的拷贝赋值操作会触发堆内存分配，很影响运行效率，有了string_view就可以避免拷贝操作，平时传递过程中传递string_view即可。
>
> ```c++
> void func(std::string_view stv) { cout << stv << endl; }
> 
> int main(void) {
>     std::string str = "Hello World";
>     std::cout << str << std::endl;
> 
>     std::string_view stv(str.c_str(), str.size());
>     cout << stv << endl;
>     func(stv);
>     return 0;
> }
> ```
>
> 



### 容器

首要说明，以下列出常用容器，有的可组合使用。**各容器的方法，可以在 [cppreference](https://zh.cppreference.com/w/%E9%A6%96%E9%A1%B5) 里现找，或者 [C++ Standard Library Containers | hacking C++ (hackingcpp.com)](https://hackingcpp.com/cpp/std/containers.html)**。

注意所有容器使用 at() 方法 等的时候，若没有项 则会抛异常，要处理！

参考：

- 都有什么 [容器库 - cppreference.com](https://zh.cppreference.com/w/cpp/container)。
- [c++容器--vector deque list set map stack queue特性及其选取准则_路过的小熊~的博客-CSDN博客](https://blog.csdn.net/qq_32348883/article/details/123223993)。



常用的：

- vector，动态数组，内存连续，增删 O(n)，改查 O(1)

- list，链表结构，内存不连续，增删 O(1)，改查 O(n)

- set，平衡二叉搜索树（红黑树），有序的、不重复的元素集合，创建时可指定自定义排序 插入时即排好序，查找、插入和删除 O(logn)

- map，红黑树，只可对 key 排序，插入的时间是O(logn),查询时间是O(logn)，不允许重复 key，若有重复 key 则用 mutilmap

  注意：set 和 map 定义好排序规则后 新插入数据 就排序好（遍历出来），这种数据结构不建议中途改排序规则，因为需要全清

  若要 插入和搜索 均为 O(1) 且又能随时排序 的 数据结构，参考使用 结合 list + unordered_map 的 LRU

- unordered_map，哈希，不可排序，插入的时间是 O(logn)，查询时间是 O(1)，其它基本同 map



这些容器常用的操作要熟悉：插入（push_back()、[]、insert()）、查找（find()）、遍历（熟悉迭代器使用），还有排序（std提供的排序，自定义排序）

删除节点，遍历删除节点等。

遍历，一般用 `for (it = myMap.begin(); it != myMap.end(); it++)` 和 `for (const auto& elem : myMap)` 这两种



#### 基础类型 vector / list / stack / queue ...

**vector**

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

// 遍历所有项
void print(const std::vector<int>& vec) {
    for (const auto& i : vec) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

// 删除某个项的方法
void erase(std::vector<int>& vec, int a) {
    for (auto iter = vec.begin(); iter != vec.end();) {
        if (*iter == a) {
            iter = vec.erase(iter); // erase 返回 当前项的下一项的迭代器
        } else {
            ++iter;
        }
    }
}
```

vector 迭代器用法：

[C++ STL vector容器迭代器用法详解 (biancheng.net)](http://c.biancheng.net/view/6803.html)。



真正可以释放内存的方法是同时调用 `clear()` 与 `shrink_to_fit()` 函数，其它 容器 同理。对于内存并不紧张的场景，这个并不常用。

[C++ STL标准库容器真正减少空间的方法_vs中的std::list怎么强制清空内存-CSDN博客](https://blog.csdn.net/davidhopper/article/details/128641573)。



C++11中的emplace_back与push_back区别

[C++11中的emplace_back与push_back区别_emplaceback和pushback-CSDN博客](https://blog.csdn.net/qq_44918090/article/details/123539708)
[emplace、emplace_back等_emplace()函数的用法-CSDN博客](https://blog.csdn.net/qq_44918090/article/details/129676961)

从结果可以看出，在对vector的插入过程中，push_back方法构造了一次，移动了两次；使用emplace_back只进行了一次构造，没有进行内存的移动。

对于把较复杂的类（C++ 容器如 vector / list / map 等）作为容器的基本单位，向容器添加元素的时候建议 emplace_back()，其它原生类型（char / int 等）等建议用 push_back()，

自己定义类的构造函数，可以提供全：一般构造函数、拷贝构造函数（`className&`）、移动构造函数（`&&` 和 `std::move()`）。



**list**

链表。用法与 std::vector 大同小异。



[＜C++＞ list容器本质|常用接口|自定义排序规则_c++ list 排序-CSDN博客](https://blog.csdn.net/m0_58618795/article/details/127259452)。



对于list，遍历，把符合某个条件的项删掉给另一个list

```c++
std::list<std::string> dirs;
std::list<std::string> filesDirs_;

for(std::list<std::string>::iterator it = filesDirs_.begin() ; it != filesDirs_.end() ; ) {
    if(it->isDir ...) {
        dirs.push_back((*it));
        // Accept the iterator returned by "erase", it point to next node
        it = filesDirs_.erase(it);
        continue;
    }
    it++;
}
```



**forward_list**

> 单向链表，只可以前进，在特定场景下使用，相比于std::list节省了内存，提高了性能



**array**

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



**deque**

参考：

- [C++——deque的了解和使用_c++ deque-CSDN博客](https://blog.csdn.net/2301_80401288/article/details/144226678)。
- [std::deque - cppreference.com](https://zh.cppreference.com/w/cpp/container/deque)。

> Deque是一种线性数据结构，它允许**在两端进行插入和删除操作**。这两端通常被称为前端（front）和后端（rear），或者端点1和端点2。Deque的灵活性在于，它既可以用作队列（FIFO，先进先出），也可以用作栈（LIFO，后进先出），具体取决于元素的插入和删除操作是在哪一端进行的。deque是C++STL（标准模板库）中的一种容器，可以用于存储各种类型的元素。deque的特点是可以在队列的两端进行元素的操作，并且可以高效地在队列的任意位置进行元素的插入和删除操作。
>



**stack**

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



**queue**

先进先出（FIFO）数据结构的实现。

参考

- [c++ stl queue（FIFO，容器配接器）_c++ stl fifo-CSDN博客](https://blog.csdn.net/lz_obj/article/details/79257076)。
- [std::queue - cppreference.com](https://zh.cppreference.com/w/cpp/container/queue)。

> 从底端加入元素，顶端取得元素；除了这两种，没有其它方法可以存取queue的元素。
>
> 将元素推入queue的操作称为push，将元素推出queue的操作称为pop。
>
> 只有queue顶端的元素，才有机会被外界取用。queue不提供遍历功能，也不提供迭代器。



**set**

参考：[c++ set用法详解_斯文～的博客-CSDN博客_c++ set](https://blog.csdn.net/weixin_52341477/article/details/119248919)。[c++ STL容器set容器小结_c++ set string 查找效率-CSDN博客](https://blog.csdn.net/weixin_44487068/article/details/122704778)。

set就是集合，STL的set用二叉树实现，集合中的每个元素只出现一次(参照数学中集合的互斥性)，并且是排好序的(默认按键值升序排列，可以改为降序)，访问元素的时间复杂度是O(log_⁡2 n)。

在插入时就排序了（注意若item是结构体之类了的，其内的值改变不会重新排序，要改变的是item才会触发重新排序）。

以乱序 insert 数据之后，用其 迭代器 `set<int>::iterator i;` 来从头到尾取数据 `for( i=q.begin();i!=q.end();i++)   cout<<i<<" ";` 输出 `1 2 3 4`，可见自动按键值排序。

使用看上面链接里的教程即可。



可自定义排序，在每次 insert 操作时自动进行重新排序；set 的 item 设置为 struct，也可以插入时排序，搜索也比链表快。



允许相同元素出现多次：**multiset**

哈希实现的 set： **unordered_set**



**map**

参考：[c++中map详解_嗯嗯好的呢！的博客-CSDN博客_c++ map](https://blog.csdn.net/m0_67403076/article/details/124503868)。[【c++】map用法详解_LeeMooq的博客-CSDN博客_c++ map](https://blog.csdn.net/yyhyyhy/article/details/124531264)。

以键值对存储的数据，其类型可以自己定义，每个关键字在map中只能出现一次，关键字不能修改，值可以修改；map同set、multiset、multimap（与map的差别仅在于multimap允许一个键对应多个值）内部数据结构都是红黑树，而java中的hashmap是以hash table实现的。所以map内部有序（自动排序，单词时按照字母序排序），查找时间复杂度为O(logn)。

使用看上面链接里的教程即可。



可自定义排序（写自定义排序函数，根据输入条件必须有true和false）。

[对std::map进行排序-CSDN博客](https://blog.csdn.net/dizi9750/article/details/101448350)。



哈希实现的 map： **unordered_map**，见下面 **hash** 的介绍



#### 哈希类型 hash

即 unordered_map（hash 键值对） 和 unordered_set（hash 集合）等。

使用：

- [C++ vector和unordered_map浅析_weixin_30678821的博客-CSDN博客](https://blog.csdn.net/weixin_30678821/article/details/99304348)。
- [unordered_map 简介_菠萝开方的博客-CSDN博客_unordered_map](https://blog.csdn.net/qq_40838478/article/details/114664223)。
- [C++: unordered_map常见用法_道纪书生的博客-CSDN博客_c++ unordered_map用法](https://blog.csdn.net/qq_40682833/article/details/119933215)。
- [map/unordered_map基础用法_unorderedmap用法-CSDN博客](https://blog.csdn.net/weixin_36670529/article/details/107038261)。

这里只针对 unordered_map，使用 hash 数据结构，无序（没有顺序），一是其为键值对结构，二是其搜索时间复杂度可达 O(1)，搜索问题都可以上 unordered_map 来减小时间复杂度。无论从查找、插入上来说，unordered_map 的效率都优于 hash_map（java里面的），更优于map；而空间复杂度方面，hash_map最低，unordered_map次之，map最大。对于那些有顺序要求的问题，用 map 会更高效一些。对于查找问题，unordered_map 会更加高效一些。

无序映射（Unordered maps）是用于存储键值和映射值组合成的元素的关联容器，并允许基于其键快速检索各个元素。在unordered_map中，键值通常用于唯一地标识元素，而映射值是具有与该键关联的内容的对象。键的类型和映射的值可能会有所不同。

```c++
#include <unordered_map>

unordered_map<char, int> map;
unordered_map<int, string> myMap = { { 5, "张大" },{ 6, "李五" } }; // 使用{}赋值


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



**tuple**

数据打包。

> ```c++
> int main() {
>     std::tuple<int, int, int> tuple = std::make_tuple(2, 3, 4);
>     std::cout << "a " << std::get<0>(tuple) << " b " << std::get<1>(tuple) << " c " << std::get<2>(tuple) << "\n";
>     return 0;
> }
> ```
>
> 引自 [这些知识点你都知道吗，测试你的C++入门程度 (qq.com)](https://mp.weixin.qq.com/s?__biz=MzkyODU5MTYxMA==&mid=2247493075&idx=1&sn=fcabde545f1863d5a1a2095696308b5b&source=41#wechat_redirect)。

我个人不推荐使用 std::tuple，因为 解包 或者 获取其项 的时候，用的是 `std::get<index>(tuple)`，通过 index 并不直观 而且 写的很长 。还是用结构体，来打包一系列不同类型的数据来进行传递。

std::pair 是其一个特例实现。



围绕 std::tuple 有不少辅助函数：

std::apply

std::make_from_tuple



**pair**

std::pair / std::make_pair



#### 多类型



**std::variant**

参考 [std::variant - cppreference.com](https://zh.cppreference.com/w/cpp/utility/variant)。C++ 17 起。

[std::variant 详解-CSDN博客](https://blog.csdn.net/chenpeizhi/article/details/143035296)

[C++ 可变体(variant)_c++ variant-CSDN博客](https://blog.csdn.net/weixin_45925735/article/details/129687498)

[C++17之std::variant-CSDN博客](https://blog.csdn.net/janeqi1987/article/details/100568096)



TODO: 有待补充例子



**std::optional**

参考 [std::optional - cppreference.com](https://zh.cppreference.com/w/cpp/utility/optional)。C++ 17 起。

> ```c++
> std::optional<int> StoI(const std::string &s) {
>     try {
>         return std::stoi(s);
>     } catch(...) {
>         return std::nullopt;
>     }
> }
> 
> void func() {
>     std::string s{"123"};
>     std::optional<int> o = StoI(s);
>     if (o) {
>         cout << *o << endl;
>     } else {
>         cout << "error" << endl;
>     }
> }
> ```
>
> 



[C++标准库教程：std::optional详解-CSDN博客](https://blog.csdn.net/cfl997/article/details/132038827)。



**std::any**

参考 [std::any - cppreference.com](https://zh.cppreference.com/w/cpp/utility/any)。C++ 17 起。

> 可以存储任何类型的单个值
>
> ```c++
> int main() { // c++17可编译
>     std::any a = 1;
>     cout << a.type().name() << " " << std::any_cast<int>(a) << endl;
>     
>     a = 2.2f;
>     cout << a.type().name() << " " << std::any_cast<float>(a) << endl;
>     
>     if (a.has_value()) {
>         cout << a.type().name();
>     }
>     
>     a.reset();
>     
>     if (a.has_value()) {
>         cout << a.type().name();
>     }
>     
>     a = std::string("a");
>     
>     cout << a.type().name() << " " << std::any_cast<std::string>(a) << endl;
>     
>     return 0;
> }
> ```
>
> 



### lambda

参考 [lambda 表达式 (C++11 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/lambda)。

[[C++\]lambda_c++ lamda-CSDN博客](https://blog.csdn.net/weixin_52345097/article/details/131499309)

[Lambda 表达式 - OI Wiki (oi-wiki.org)](https://oi-wiki.org/lang/lambda/)



完整格式：
`auto fun_xxx = [ 捕获变量 ] ( 形参 ) mutable -> void { 函数内容 };`



`[]`：捕捉列表，捕捉上下文中的变量，然后用于lambda使用。
`()`：参数列表，与函数的参数列表类似，如果不需要传递参数 可以不写 ()。
`mutable`：默认条件下，lambda总是有一个const特性，即捕获的变量不能修改，我们可以通过mutable取消掉它的这个特，加上mutable时，()不能省略。
`-> returntype`：返回值类型，当没有返回值可以不写，当返回值类型非常明确，也可以不写，编译器会推导。
`{}`：函数体，也就是我们写函数时需要用{}包起来的部分。



可以将 lambda 函数 赋值给 某个变量，可以在后面调用

```c++
auto getUrl = [archive, &rels, this](ByteArray const & type, String & result) { ...}
getUrl("xxx1", xxx1);
getUrl("xxx2", xxx2_);
```



说明，即便是相同参数和返回值的 lambda 和 函数指针，二者的类型也不同；

使用 `std::function::target_type().name()` 看出，而且如果 std::function 存一个 lambda，用 `std::function::target<函数指针类型>()` 会返回 null，使用 `std::function::target<lambda 类型>()` 才会返回填入的 lambda；一个 c 函数如果接收 函数指针 那么不能接受 同类型的参数和返回值的 存于 std::function 的 lambda。为了 c/c++ 同时的可移植性，还是多考虑下 软件分层的 哪一层 用哪个，一般 高层次的应用层 c++ 多一些，偏底层的 就是 c 的写法。

```c++
// 判断的写法：
typedef void(*lv_btn_cb_fun)(lv_event_t*);
const std::function<void(lv_event_t*)> _fun = ...

if(!_fun) {
    LV_LOG_ERROR("empty _fun");
    return -1;
}
const lv_btn_cb_fun* callBackFun = _fun.target<lv_btn_cb_fun>();
// if the fun in "_fun" is not "lv_btn_cb_fun" type, "_fun.target<>()" will return null,
// use lambda fun storage in "_fun", the target_type is not "lv_btn_cb_fun", and it can't pass to "lv_obj_add_event_cb", so no use of it
if(!callBackFun) {
    LV_LOG_ERROR("null _fun");
    return -1;
}
```



**constexpr lambda 表达式**

C++ 17 起。

> 使得 lambda 在编译期计算。

> ```c++
> constexpr auto lamb = [] (int n) { return n * n; };
> static_assert(lamb(3) == 9, "a");
> ```

> 注意：constexpr函数有如下限制：
>
> 函数体不能包含汇编语句、goto语句 / label、try块、静态变量、线程局部存储、没有初始化的普通变量，不能动态分配内存，不能有new delete等，不能虚函数。



### 类型别名 using

参考 [类型别名，别名模板 (C++11 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/type_alias)。

例子：

> ```c++
> template<class T>
> using Vec = vector<T, Alloc<T>>; // 类型标识为 vector<T, Alloc<T>>
>  
> Vec<int> v; // Vec<int> 等同于 vector<int, Alloc<int>>
> ```



### 类型推导 auto & decltype

基本用法：

> auto 用于推导变量类型，decltype 用于推导表达式返回值类型
>
> ```c++
> int main() {
>  auto a = 10;  // 10是int型，可以自动推导出a是int
> 
>     int x = 0;
>  decltype(x) y;      // y是int类型
>     decltype(x + y) z;  // z是int类型
>    
>     return 0;
> }
>    ```
> 
> 引自 [这些知识点你都知道吗，测试你的C++入门程度 (qq.com)](https://mp.weixin.qq.com/s?__biz=MzkyODU5MTYxMA==&mid=2247493075&idx=1&sn=fcabde545f1863d5a1a2095696308b5b&source=41#wechat_redirect)。



更详细的：



可参考 [C++11的类型推导详解 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/137662774)，有很多例子，举例了各种情况。



C++14， auto 可用于 函数返回值 类型推导，模板函数返回值 类型推导，lambda 函数的形参 类型推导。

但是感觉这些并不常用，返回值什么的，若不是在写模板，还是标好一些地方的类型吧，少做谜语人。

> ```c++
> #include <iostream>
> using namespace std;
> 
> // --- 
> auto func(int i) {
>     return i;
> }
> 
> // --- 
> template<typename T> auto func(T t) { return t; }
> 
> cout << func(4) << endl;
> cout << func(3.4) << endl;
> 
> // ---
> 
> auto f = [] (auto a) { return a; };
> cout << f(1) << endl;
> cout << f(2.3f) << endl;
> ```
>
> 引自 [C++14新特性的所有知识点全在这儿啦！ - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/165389083)。



### 枚举类 enum class

枚举类 为 带有作用域的枚举类型，可在 C++ 环境中 完全替代 enum，使用类似 命名空间的方式用 各个枚举变量，防止原来 enum 的 全局重名 和 不同 enum 类型的变量可互相直接赋值 等问题。



> ```c++
> 
> enum class AColor {
>     kRed,
>     kGreen,
>     kBlue
> };
> 
> enum class BColor {
>     kWhite,
>     kBlack,
>     kYellow
> };
> 
> int main() {
>     if (AColor::kRed == BColor::kWhite) { // 编译失败
>         cout << "red == white" << endl;
>     }
>     return 0;
> }
> ```
>
> 引自 [这些知识点你都知道吗，测试你的C++入门程度 (qq.com)](https://mp.weixin.qq.com/s?__biz=MzkyODU5MTYxMA==&mid=2247493075&idx=1&sn=fcabde545f1863d5a1a2095696308b5b&source=41#wechat_redirect)、



> c++11 的 union 中 允许数据成员类型有 非POD类型。
>
> POD类型 大体上可以理解为对象可以直接memcpy的类型。
>
> [C++ POD与非POD类型的区别 - 问答 - 亿速云 (yisu.com)](https://www.yisu.com/ask/6905433.html)。



### 编译期计算 constexpr



constexpr：修饰 常量 和 函数，由编译期来完成 计算 和 函数"内敛功能"（特别是在定义小的、编译时可计算的函数时） 等。

constexpr 保证的是编译时的常量性，而 inline 则是建议编译器进行内联展开以优化性能。

> ```c++
> constexpr int32_t constNum = 1 + 2 + 3;
> constexpr int func(int i) {
>     return i + 1;
> }
> ```



> C++14中可以使用局部变量和循环。C++11中constexpr函数必须必须把所有东西都放在一个单独的return语句中，而 C++14 的 constexpr则无此限制。
>
> ```c++
> constexpr int factorial(int n) { // C++11中不可，C++14中可以
>     int ret = 0;
>     for (int i = 0; i < n; ++i) {
>         ret += i;
>     }
>     return ret;
> }
> 
> constexpr int func(bool flag) { // C++11中不可，C++14中可以
>     if (flag) return 1;
>     else return 0;
> }
> ```
>
> 引自 [C++14新特性的所有知识点全在这儿啦！ - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/165389083)。



### 编译期检查 static_assert

参考 [static_assert 声明 (C++11 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/static_assert)。

c++11 引入，用于编译期进行检查，若第一个参数值为 false，则打印 message，报编译失败错误。

例子：

> ```c++
> static_assert(true/false, message);
> ```



### 二进制字面量

参考 [整数字面量 - cppreference.com](https://zh.cppreference.com/w/cpp/language/integer_literal)。



> ```c++
> int a = 0b0001'0011'1010;
> double b = 3.14'1234'1234'1234;
> ```
>
> 二进制字面量与整形字面量分隔符，[C++14新特性的所有知识点全在这儿啦！ - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/165389083)。



### 字符字面量

参考 [字符字面量 - cppreference.com](https://zh.cppreference.com/w/cpp/language/character_literal)，这里面有例子。

> - `u8'.'`：UTF-8 字符字面量，例如 u8'a'。这种字面量具有 char(C++20 前)char8_t(C++20 起) 类型，且它的值等于*c字符* ﻿的。
> - `u'.'`：UTF-16 字符字面量，例如 u'猫'，但不是 u'🍌'（u'\U0001f34c'）。这种字面量具有 char16_t 类型。只要该值能以单个 UTF-16 代码单元表示（即*c字符* ﻿处于范围 0x0-0xFFFF（含边界）内）。
> - `U'.'`：UTF-32 字符字面量，例如 U'猫' 或 U'🍌'。这种字面量具有 char32_t 类型。
> - `L'.'`：宽字符字面量，例如 L'β' 或 L'猫'。这种字面量具有 wchar_t 类型。



参考 [字符串字面量 - cppreference.com](https://zh.cppreference.com/w/cpp/language/string_literal)，这里面有例子。

- 一些修饰字符串的符号，下面，不带 `R` 的 为 `s字符序列`：就是基本字符串，带 `R` 的 为 `d字符序列`：不包括括号、反斜杠和空格。

  参考 [字符集与编码 - cppreference.com](https://zh.cppreference.com/w/cpp/language/charset#.E5.9F.BA.E6.9C.AC.E5.AD.97.E7.AC.A6.E9.9B.86)。

- `"..."`，`R"..."`：普通字符串字面量 `const char[N]`。
- `L"..."`，`LR"..."`：宽字符串字面量 `const wchar_t[N]`。
- `u8"..."`，`u8R"..."`：UTF-8 字符串字面量 `const char[N] (C++20 前)`，`const char8_t[N] (C++20 起)`。
- `u"..."`，`uR"..."`：UTF-16 字符串字面量 `const char16_t[N]`。
- `U"..."`，`UR"..."`：UTF-32 字符串字面量 `const char32_t[N]`。



### 自定义字面量



个人觉得还是少用，太谜语人了，写完后也许自己很清楚，但是别人看着会比较绕。



> ```c++
> constexpr long double operator"" _d2r( long double deg )
> {
>        long double radians = deg * std::numbers::pi_v<long double> / 180;
>        return radians;
> }
> double x_rad = 90.0_d2r;  //x_rad = 1.570796
> ```
>
> 引自 [C++ 的用户自定义字面量_c++ 自定义字面量-CSDN博客](https://blog.csdn.net/orbit/article/details/142871607)。



> ```c++
> struct mytype {
>        unsigned long long value;
> };
> 
> constexpr mytype operator"" _mytype ( unsigned long long n ) {
>        return mytype{n};
> }
> 
> mytype mm = 123_mytype;
> cout << mm.value << endl;
> ```
>
> 引自 [c++11新特性，所有知识点都在这了！ - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/139515439) 里面 `自定义字面量` 一节。



参考 [用户定义字面量 (C++11 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/user_literal)。

支持的种类：

> - 用户定义整数字面量，例如 `12_km`
> - 用户定义浮点字面量，例如 `0.5_Pa`
> - 用户定义字符字面量，例如 `'c'_X`
> - 用户定义字符串字面量，例如 `"abd"_L` 或 `u"xyz"_M`



### 动态创建内存对齐的对象

参考 [内存对齐 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/139520591)。

结构体和类的基本内存对齐规则 很基础可网搜。

> 什么是内存对齐
>
> 理论上计算机对于任何变量的访问都可以从任意位置开始，然而实际上系统会对这些变量的存放地址有限制，通常将变量首地址设为某个数N的倍数，这就是内存对齐。
>
> 为什么要内存对齐
>
> 1. 硬件平台限制，内存以字节为单位，不同硬件平台不一定支持任何内存地址的存取，一般可能以双字节、4字节等为单位存取内存，为了保证处理器正确存取数据，需要进行内存对齐。
> 2. 提高CPU内存访问速度，一般处理器的内存存取粒度都是N的整数倍，假如访问N大小的数据，没有进行内存对齐，有可能就需要两次访问才可以读取出数据，而进行内存对齐可以一次性把数据全部读取出来，提高效率。
>
> 内存对齐规则
>
> 1. 数据成员对齐规则：struct或者union的数据成员，第一个数据成员放在offset为0的地方，以后每个数据成员都按照#pragma pack数值和这个数据成员自身大小中更小的那个进行对齐。
> 2. 整体对齐规则：struct或者union的首地址按照内部最大数据成员的大小和#pragma pack数值较小的那个N进行对齐，并且结构体的总大小为N的整数倍，如有必要编译器也会在最后一个成员后面填充一些字节用于对齐。



静态自定义内存对齐的数据结构：声明自定义内存对齐的结构体或类

```c++
// c 语言标准关键字：#pragma pack
// pragma pack(n) alignment must be a power of two
#pragma pack(2) //指定按两字节对齐
...
#pragma pack() // 取消指定对齐

// ---

// gcc 编译器扩展关键字 __attribute__((aligned))
struct A {
    char a;
    ...
} __attribute__((aligned)) / __attribute__((aligned(1))) / __attribute__((packed));

// __attribute__((packed))告诉编译器取消编译中的内存对齐优化，采用实际占用的字节数进行对齐
// __attribute__((aligned(N))) 告诉编译器在编译过程中按照N字节对齐，经过测试这个N只有大于结构体中最大的变量的大小才有用
// __attribute__((aligned)) 后面不接数字，告诉编译器根据目标机制采用最大最有益的方式对齐，基本上就是16字节对齐
// alignof(X) 返回某类型的对齐大小，与std::alignment_of类似，这两个功能完全相同，但是std::alignment_of可以用于模板元编程
```



动态创建自定义内存对齐的对象：

> ```c++
> class A {
>        int a;
>        char d;
>    };
> 
> // 创建给定类型对象大小满足对齐要求的未初始化内存块，在一个内存对齐的缓冲区上创建对象
> // C++11后可以这样操作
> void align_cpp11_after()
> {
>  static std::aligned_storage<sizeof(A),
>                                 alignof(A)>::type data;
>     A *attr = new (&data) A;
>    }
> 
> // C++11之前
> void align_cpp11_before()
> {
>  static char data[sizeof(void *) + sizeof(A)];
>     const uintptr_t kAlign = sizeof(void *) - 1;
>     char *align_ptr =
>         reinterpret_cast<char *>(reinterpret_cast<uintptr_t>(data + kAlign) & ~kAlign);
>     A *attr = new (align_ptr) A;
>    }
> ```



关于 `alignof` 和 `alignas`：

- [alignof 运算符(C++11 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/alignof)。
- [alignas 说明符 (C++11 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/alignas)。



### 内存申请和释放 new & delete

补充参考和引用：

- [C++ 动态内存 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-dynamic-memory.html)、[C++ new和delete运算符简介 (biancheng.net)](http://c.biancheng.net/view/2199.html)。[new、new()和new 三者的区别_西雅图_Seattle的博客-CSDN博客_new()](https://blog.csdn.net/Seattle_panchaoyi/article/details/51703015)。
- [new[]和delete[]为何要配对使用？](https://mp.weixin.qq.com/s?__biz=MzkyODU5MTYxMA==&mid=2247492989&idx=1&sn=35cdef727c312378fd7f29cafa8103d0&source=41#wechat_redirect) 为了自定义类型（如类）的正确 释放 / 析构。



```c++
/* 获取数组的成员个数 */
#define ARR_SIZE(arr) sizeof(arr)/sizeof((arr)[0])

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



struct 里面有 std::string，申请和释放这个 struct 内存用 new 和 delete

在为string分配空间时需要调用string的构造方法，而malloc无法调用，故程序会报错，而new拥有调用构造函数的功能

[c++链表/结构体中含有string类型使用malloc分配内存失败/报错_结构体内部有c++类型却使用了malloc-CSDN博客](https://blog.csdn.net/m0_74131274/article/details/129819245)



### 智能指针

参考

- [C++ 智能指针_TABE_的博客-CSDN博客_c++智能指针](https://blog.csdn.net/TABE_/article/details/117391903)。[c++智能指针详解_bitcarmanlee的博客-CSDN博客_c++ 智能指针](https://blog.csdn.net/bitcarmanlee/article/details/124847634)。[c++ 智能指针_lucky九年的博客-CSDN博客_c++智能指针](https://blog.csdn.net/qq_44139121/article/details/125937906)。
- [c++11新特性之智能指针 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/137958974)。
- [内存管理库 - cppreference.com](https://zh.cppreference.com/w/cpp/memory#.E6.99.BA.E8.83.BD.E6.8C.87.E9.92.88).



- 推荐多用智能指针管理内存，可一定程度防止内存泄漏等。
- 推荐多做 RAII（利用对象生命周期管理资源）风格编码，如 使用 智能指针。



- [unique_ptr](https://zh.cppreference.com/w/cpp/memory/unique_ptr)，拥有独有对象所有权的智能指针。
  - 推荐使用 [std::make_unique](https://zh.cppreference.com/w/cpp/memory/unique_ptr/make_unique) （C++14）创建。

- [shared_ptr](https://zh.cppreference.com/w/cpp/memory/shared_ptr)，拥有共享对象所有权的智能指针。
  - 推荐使用 [std::make_shared](https://zh.cppreference.com/w/cpp/memory/shared_ptr/make_shared) 创建。
  - 自定义类 继承 [enable_shared_from_this](https://zh.cppreference.com/w/cpp/memory/enable_shared_from_this)，则允许 类 创建 并 通过 [shared_from_this()](https://zh.cppreference.com/w/cpp/memory/enable_shared_from_this/shared_from_this) 来获得 指向 this 的 `shared_ptr`。
  - 对于上两点，`unique_ptr` 和 `weak_ptr` 同理。
- [weak_ptr](https://zh.cppreference.com/w/cpp/memory/weak_ptr)，使用 `std::shared_ptr` 所管理对象的弱引用，可解决 `std::shared_ptr` 中出现 互相引用 导致资源永不释放 的 问题。

可看链接里面，有多种基础例子。



shared_ptr：

当一个 shared_ptr 实例对象超出作用域 就会释放其包含的指针对应的内存，或者调用 .reset()，推荐使用 make_shared() 创建 shared_ptr 对象

[C++:共享指针shared_ptr的理解与应用_shareptr-CSDN博客](https://blog.csdn.net/weixin_41504987/article/details/124396989) 有很多好例子
[智能指针——shared_ptr_sharedptr-CSDN博客](https://blog.csdn.net/weixin_45732589/article/details/115741770) 原理和注意事项



各个智能指针 std::auto_ptr、std::unique_ptr、std::shared_ptr 的设计思路和模拟实现，逐个进化，并且存在的特定环境下出现的问题

[智能指针 smart_ptr_smartptr-CSDN博客](https://blog.csdn.net/qq_68006585/article/details/131129484)

[【C++修炼之路】32.智能指针_ptradc->ptrmax[ch\] = (ptradc->ptrdata[ch] > ptradc-CSDN博客](https://blog.csdn.net/NEFUT/article/details/131603769)

好处：不需要显式地释放资源。采用这种方式，对象所需的资源在其生命期内始终保持有效。



```c++
// 简单测试：创建 std::shared_ptr 指针的几种写法，但推荐 std::make_shared
std::shared_ptr<int> p0     = std::make_shared<int>();
std::shared_ptr<int> p00    = std::make_shared<int>(5);
std::shared_ptr<int> p1     = std::shared_ptr<int>(new int(10)); // 由 new int(10) 分配的内存的地址用std::shared_ptr类型构造 再赋值给 p1
std::shared_ptr<int> p2(new int(15));
std::shared_ptr<int> p22(nullptr);
std::shared_ptr<int> p222 = nullptr;
std::shared_ptr<int> p222_(p00);
std::shared_ptr<int> p222__ = p1;
std::cout << " -- 1 p0 -- " << p0.use_count() << " -- " << *p0 << std::endl;
std::cout << " -- 1 p00 -- " << p00.use_count() << " -- " << *p00 << std::endl;
std::cout << " -- 1 p1 -- " << p1.use_count() << " -- " << *p1 << std::endl;
std::cout << " -- 1 p2 -- " << p2.use_count() << " -- " << *p2 << std::endl;
std::cout << " -- 1 p22 -- " << p22.use_count() << " -- " << "no *p22" << std::endl;
std::cout << " -- 1 p222 -- " << p222.use_count() << " -- " << "no *p222" << std::endl;
std::cout << " -- 1 p222_ -- " << p222_.use_count() << " -- " << *p222_ << std::endl;
std::cout << " -- 1 p222__ -- " << p222__.use_count() << " -- " << *p222__ << std::endl;
*p1 = 99;
std::cout << " -- 2 -- " << p1.use_count() << " -- " << *p1 << std::endl;
{
    std::shared_ptr<int> ppp1 = p1;
    *ppp1 = 11;
    std::cout << " -- 3 -- " << p1.use_count() << " -- " << *p1 << std::endl;
}
std::cout << " -- 4 -- " << p1.use_count() << " -- " << *p1 << std::endl;
p1.reset(); // set nullptr, free mem
std::cout << " -- 5 -- " << p1.use_count() << std::endl;
// 再使用 *p1 就会报错

// 打印：引用计数的变化，若 p1 出了生命周期 或者 其计数 为 0，就自动释放内存
 -- 1 p0 -- 1 -- 0
 -- 1 p00 -- 2 -- 5
 -- 1 p1 -- 2 -- 10
 -- 1 p2 -- 1 -- 15
 -- 1 p22 -- 0 -- no *p22
 -- 1 p222 -- 0 -- no *p222
 -- 1 p222_ -- 2 -- 5
 -- 1 p222__ -- 2 -- 10
 -- 2 -- 2 -- 99
 -- 3 -- 3 -- 11
 -- 4 -- 2 -- 11
 -- 5 -- 0
```



shared_ptr 存在的一些潜在的内存泄漏的场景

[shared_ptr产生内存泄漏的场景_shared指针泄漏-CSDN博客](https://blog.csdn.net/sinat_31608641/article/details/131591022)



std::shared_ptr 用于 多个对象共享同一资源，当不再需要资源时会自动销毁资源。

weak_ptr 的主要作用是 避免循环引用，即当两个 shared_ptr 互相引用对方时，会导致引用计数无法归零，从而内存无法释放。

std::weak_ptr 用于避免 循环引用，允许对对象进行观察，但不会增加引用计数，通常与 shared_ptr 配合使用。



### 类型转换 cast

可参考 这个链接里面的 `类型转换` 一节，各种类型转换的情况一看便知：[这些知识点你都知道吗，测试你的C++入门程度 (qq.com)](https://mp.weixin.qq.com/s?__biz=MzkyODU5MTYxMA==&mid=2247493075&idx=1&sn=fcabde545f1863d5a1a2095696308b5b&source=41#wechat_redirect)。

> ```c++
> // static_cast，通常用于 c/c++ 基础类型相互之间的转换
> 
> float f = 1.0f;
> int a = static_cast<int>(f);
> 
> 
> // const_cast，解 const 指针的，不推荐用
> 
> const char* cc = "hello world\n";
> char* c = const_cast<char*>(cc);
> 
> 
> // dynamic_cast，基类指针 转 子类指针。反过来，则 子类指针变量 可以直接 通过 等号 赋值 给 基类指针变量
> 
> struct Base {};
> struct Derive : public Base {};
> void func() {
>     Base* base = new Derive;
>     Derive* derive = dynamic_cast<Derive*>(base);
> }
> 
> // reinterpret_cast，void* 和 类指针之间 相互转
> 
> A *a = new A;
> void* d = reinterpret_cast<void*>(a);
> ```



对于 `std::shared_ptr` 的 基类指针 转 子类指针，使用 `std::dynamic_pointer_cast()`。



[C++四种cast的详细介绍_c++ cast-CSDN博客](https://blog.csdn.net/weixin_43340455/article/details/124595862)。



### 引用

补充参考 [C++引用精讲，C++ &用法全面剖析 (biancheng.net)](http://c.biancheng.net/cplus/25/)。[c++引用_路过的小熊~的博客-CSDN博客](https://blog.csdn.net/qq_32348883/article/details/123316063)。

[引用 - OI Wiki (oi-wiki.org)](https://oi-wiki.org/lang/reference/)。



作用： 给变量起别名。 语法： `数据类型& 别名 = 原名`。本质：引用的本质在c++内部实现是一个常量指针

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
    const int& ra=a1;
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
    /* 编译器发现 ref1 是引用，自动帮我们转换为: *ref1 = 1000; */
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



**std::ref、std::cref**

参考：

- [C++库std::ref-CSDN博客](https://blog.csdn.net/qq_41898196/article/details/139499283)。
- [C++11的std::ref、std::cref源码解析 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/716614888)。

遇到 std::bind 或者 给函数传入变量的时候，为了确保是传入 的 引用 而不是 拷贝，使用 std::ref、std::cref 给 实参 套上。

> 在实际应用中，能用 直接引用 就使用 `直接引用`。
> 当：
>
> 1. 使用 `标准库算法`。
> 2. 函数对象、回调。
> 3. 使用 `std::bind` 或其他类似工具。
> 4. 多线程编程中将引用传递给线程函数。
>
> 直接传引用不适用，使用 `std：：ref`。



### 右值引用 & 移动语义 & 完美转发

参考

- [左值引用、右值引用、移动语义、完美转发，你知道的不知道的都在这里 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/137662465)。
- [c++11 新特性总结（三）——右值引用和完美转发 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/558517874)。TODO 待看下



**右值**

下面任意一个条件成立即算：

> - 不可以放到等号左边的东西。
>
> - 不能取地址的没有名字的东西。
>
> - 不可访问内存地址的值。
>
> - 运算表达式产生的临时变量、不和对象关联的原始字面量、非引用返回的临时变量、lambda表达式等都是纯右值
>
> - 将亡值（临时产生的，不打算再用了，要把资源搬运给别的变量，自己不再 hold 一份）
>
>   将亡值是指C++11新增的和右值引用相关的表达式，通常指将要被移动的对象、T&&函数的返回值、std::move函数的返回值、转换为T&&类型转换函数的返回值，将亡值可以理解为即将要销毁的值，通过“盗取”其它变量内存空间方式获取的值，在确保其它变量不再被使用或者即将被销毁时，可以避免内存空间的释放和分配，延长变量值的生命周期，常用来完成移动构造或者移动赋值的特殊任务。

我理解 右值引用（T&&）、移动语义（std::move），在实践意义上，即主要用于 转移所有权，省去拷贝负担；就是这个资源，要 转移 / 搬运 到别的地方（而不是拷贝一份，是内存上这块资源所处变量 的 换主），就转为右值引用 然后用 移动语义 送出去，送走资源后的变量，就当作亡值不要用了，资源转移出去了，由接着资源的变量来替代了。

```c++
T&& t = std::move(...); // 这个，一般用于 函数形参 和 实参
```

> 对于那种基本类型int、float等没有任何优化作用，还是会拷贝，因为它们实现没有对应的 移动构造函数。
>
> C++所有的STL都实现了移动语义。



右值变量 给 右值 取别名。右值：不能取地址的值、将亡值。

用于构造函数：移动构造（减少拷贝）（编译器会生成浅拷贝的移动构造，类里面没有涉及到内存申请释放的可以直接用默认的，否则需要自己实现深拷贝的移动构造）

用于模板函数：万能引用（T&& t）+ 完美转发（`std::forward<T>()`）



[C++右值引用与左值详解：移动语义、完美转发的应用-CSDN博客](https://blog.csdn.net/weixin_55582891/article/details/134980889)

[【C++】右值引用和移动语义（带你理解C++为何如此高效）_c++右值引用和移动语义-CSDN博客](https://blog.csdn.net/c565114/article/details/142909059)



**完美转发 / 转发右值引用**

> 写一个 接受任意实参 的 函数模板 A，并 调用 其它函数 B 和 直接传入参数，目标函数 B 会收到 与 转发函数 A 完全相同的实参。

TODO：参考 上面 链接 里面的。还需要自己相关的，总结下放这里



**返回值优化**

> 返回值优化(RVO)是一种C++编译优化技术。当函数需要返回一个对象实例时候，就会创建一个临时对象并通过 复制构造函数 将目标对象复制到临时对象，这里有复制构造函数和析构函数会被多余的调用到，有代价，而通过返回值优化，C++标准允许省略调用这些复制构造函数。

> 触发编译器的返回值优化，同时满足如下：
>
> 1. return的值类型与函数的返回值类型相同
> 2. return的是一个局部对象
>
> 下面这段代码会触发RVO，不拷贝也不移动，不生成临时对象：
>
> ```c++
> std::vector<int> return_vector(void)
> {
>     std::vector<int> tmp {1,2,3,4,5};
>     return tmp;
> }
> 
> std::vector<int> rval_ref = return_vector();
> ```



[值类别 - 复制消除 - OI Wiki (oi-wiki.org)](https://oi-wiki.org/lang/value-category/#复制消除)。[值类别 - 常见误区 - OI Wiki (oi-wiki.org)](https://oi-wiki.org/lang/value-category/#常见误区)。

> 复制消除中的返回值优化（Return Value Optimization，RVO）。

> - 在 `f1` 中返回 `std::move(x)` 是多余的，并不会带来性能上的提升，反而会干扰编译器进行 NRVO 优化。
> - 在 `f2` 中返回 `std::move(x)` 是危险的，函数返回右值引用指向了已被销毁的局部变量 `s`，出现了悬空引用问题。
>
> ```c++
> std::string f1() {
>   std::string s = "123";
>   // 等价于 return std::string(std::move(s))
>   return std::move(s);
> }
> 
> std::string&& f2() {
>   std::string s = "123";
>   return std::move(s);
> }
> ```



### 函数默认值 & 占位参数 & 重载

**函数默认值**

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



**函数占位参数**



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



**函数重载**

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



### 异常处理

- 参考 [C++ 异常处理 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-exceptions-handling.html)。[C++异常处理（try catch）从入门到精通 (biancheng.net)](http://c.biancheng.net/cplus/exception/)。
- 参考视频 [shellmad-c++_57 异常处理_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1iA411q7hx/)。
- [C++异常处理详解-CSDN博客](https://blog.csdn.net/dreamsparkc/article/details/38323415)。



基本的异常处理写法：可以写成一个宏，后面调用宏来包裹起来会抛异常的代码段

```c++
try {
    // run something
} catch (const std::exception& e) {
    std::cout << " catch exception: %s" << e.what() << std::endl;
} catch (...) {
    std::cout << " catch exception" << std::endl;
}
```



抛异常相关：

1.

直接使用 `std::runtime_error`、`std::invalid_argument` 等标准异常类，这些类都允许传递错误消息。例如：

```c++
try {
    throw std::runtime_error("Something went wrong during execution!");
} catch (const std::exception& e) {
    std::cout << "Caught an exception: " << e.what() << std::endl;  // 打印异常信息
}
```

C++ 标准库中有很多内置的异常类型，它们都继承自 std::exception，并且允许你传递一个错误消息。比如其它的标准异常类：

- std::invalid_argument：表示无效参数的异常。
- std::out_of_range：表示超出范围的异常。
- std::logic_error：表示程序逻辑错误的异常。
- std::domain_error：表示非法域的异常。
- std::length_error：表示容器的大小超过允许范围。

2.

可以创建一个继承自 std::exception 的类。这个类需要重载 what() 方法来返回异常信息。



自己的习惯：

1、自己写的程序，尽量不主动抛异常（代码一复杂、层次一多，就麻了）。

2、写 C++ 的代码中，所有可能抛异常的地方均用 try catch 处理并打印 log（用上面的宏 TRY_CATCH(_exec) 套上即可），防止此类的 crash。



从机制上，c++做不到可能抛异常的API没有加try catch就编译给警告或报错；而且也不推荐强制做。

> 异常是动态的，抛出的异常类型是在运行时确定的，而不是在编译时可以精确推断的。C++ 并没有强制要求所有可能抛出异常的代码都必须被 try-catch 包围。相反，C++ 的异常处理设计允许开发者灵活地选择是否处理异常，这样可以根据具体的应用需求和性能考虑来决定是否使用异常机制。
> 如果编译器强制要求捕获所有可能抛出的异常，可能会导致额外的性能开销和代码复杂性，这违背了 C++ 作为一门高效编程语言的设计理念。



- [你的c++团队还在禁用异常处理吗？ (qq.com)](https://mp.weixin.qq.com/s?__biz=MzkyODU5MTYxMA==&mid=2247492949&idx=1&sn=3ead6a2141dcc07bb5344a53c197d78d&source=41#wechat_redirect)

  虽然链接中文章表示异常是比返回值更好的处理错误的方式，但是本文作者个人表示自己写的程序还是尽量不抛出异常，程序一大不好控制，得总是分出点注意力来处理异常（且容易忘），一旦函数嵌套层数一多就容易乱且难维护，使用库的方法可能抛出异常则必须要写上 catch 异常，除非能够保证输入参数等一定正确使用使得方法不抛异常。但是也不要过度是使用返回值的判断（一串 if else 的判断）和层层返回传递，某一层出错，视情况严重性，是直接终止程序（后面依靠比较完备的测试来逐渐收敛程序 bug 来提高程序健壮性），还是及时在当下来处理错误（如给个默认值等）。

  下面是链接文章中的一些精华，也可以参考：

  > 异常处理对于错误的处理更简洁，可以更方便的把错误信息反馈给调用者，同时不需要调用者使用额外的ifelse分支来处理成功或者不成功的情况。如果不是特别特别注重实时性能或者特别在乎程序的体积我们完全可以使用异常处理替代我们平时使用的c语言中的那种错误码处理方式。
  >
  > **如果有更多的运算，或者有更多的错误码，异常处理的优势会更明显。**
  >
  > - 使用异常可以使得代码逻辑更清晰，将代码按正确的逻辑列出来，逻辑更紧密代码更容易读懂，而错误处理可以单独放到最后做处理。
  > - 异常可以选择自己处理或者传递给上层处理
  >
  > **异常处理的关键点**
  >
  > 1. 不应该使用异常处理做什么？
  >
  > 2. - throw仅用于抛出一个错误，标识函数没有按设想的方式去执行
  >    - 只有在知道可以处理错误时，才使用catch来捕获错误，例如转换类型或者内存分配失败
  >    - 不要使用throw来抛出编码错误，应该使用assert或者其它方法告诉编译器或者崩溃进程收集debug信息
  >    - 如果有必须要崩溃的事件，或者无法恢复的问题，不应该使用throw抛出，因为抛出来外部也无法处理，就应该让程序崩溃
  >    - try、catch不应该简单的用于函数返回值，函数的返回值应该使用return操作，不应该使用catch，这会给编程人员带来误解，同时也不应该用异常来跳出循环
  >
  > 3. 异常处理看似简单好用，但它需要项目成员严格遵守开发规范，定好什么时候使用异常，什么时候不使用，而不是既使用异常又使用错误码方式。
  >
  > 4. 构造函数可以抛出异常吗？可以而且建议使用异常，因为构造函数没有返回值，所以只能抛出异常，也有另一种办法就是添加一个成员变量标识对象是否构造成功，这种方法那就会额外添加一个返回该返回值的函数，如果定义一个对象数组那就需要对数组每个对象都判断是否构造成功，这种代码不太好。
  >
  > 5. 构造函数抛出异常会产生内存泄漏吗？不会，构造函数抛出异常产生内存泄漏那是编译器的bug，已经在21世纪修复，不要听信谣言。
  >
  >    ```c++
  >    void f() {
  >     X x;             // If X::X() throws, the memory for x itself will not leak
  >     Y* p = new Y();  // If Y::Y() throws, the memory for *p itself will not leak
  >    }
  >    ```
  >
  > 6. 永远不要在析构函数中把异常抛出，还是拿对象数组举例，数组里有多个对象，如果其中一个对象析构过程中抛出异常，会导致剩余的对象都无法被析构，析构函数应该捕获异常并把他们吞下或者终止程序，而不是抛出。
  >
  > 7. 构造函数内申请完资源后抛出异常怎么办？使用智能指针，关于char*也可以使用std::string代替。
  >
  >    ```c++
  >    #include <memory>
  >    
  >    using namespace std;
  >    
  >    class SPResourceClass {
  >    private:
  >       shared_ptr<int> m_p;
  >       shared_ptr<float> m_q;
  >    public:
  >       SPResourceClass() : m_p(new int), m_q(new float) { }
  >       // Implicitly defined dtor is OK for these members,
  >       // shared_ptr will clean up and avoid leaks regardless.
  >    };
  >    ```
  >
  > 8. 永远通过值传递方式用throw抛出异常，通过引用传递用catch来捕获异常。
  >
  > 9. 可以抛出基本类型也可以抛出对象，啥都可以
  >
  > 10. catch(...)可以捕获所有异常
  >
  > 11. catch过程中不会触发隐式类型转换
  >
  > 12. 异常被抛出，但是直到main函数也没有被catch，就会std::terminate()
  >
  > 13. c++不像java，不会强制检查异常，throw了外层即使没有catch也会编译通过
  >
  > 14. 异常被抛出时，在catch之前，try和throw之间的所有局部对象都会被析构
  >
  > 15. 如果一个成员函数不会产生任何异常，可以使用noexcept关键字修饰
  >
  > 16. 通过throw可以重新抛出异常



指定函数不会抛出异常 以及验证 函数是否会抛异常 `noexcept`：

参考 [noexcept 说明符 (C++11 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/noexcept_spec)。[noexcept 运算符 (C++11 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/noexcept)

> ```c++
> void f() noexcept;            // 函数 f() 不会抛出
> void (*fp)() noexcept(false); // fp 指向可能会抛出的函数
> 
> void may_throw();
> void no_throw() noexcept;
> // !noexcept(may_throw())   为 true， 即 可能会 抛异常
> // !noexcept(no_throw())    为 false，即 不会   抛异常
> ```



### 属性

参考：

- [属性说明符序列 (C++11 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/attributes)。



> ### 标准属性
>
> C++ 标准定义了下列属性。
>
> 标准属性不能在语法上被忽略：它们不能包含语法错误，必须应用到正确的目标，并且实参中的实体都会被 [ODR 使用](https://zh.cppreference.com/w/cpp/language/definition#ODR_.E4.BD.BF.E7.94.A8)。
>
> 标准属性也不能在语义上被忽略：程序在去掉某个标准属性的所有实例的情况下的行为必须是该程序在保留该属性的情况下遵守标准要求的行为。
>
> | 属性                                                      | 释义                                                         |
> | --------------------------------------------------------- | ------------------------------------------------------------ |
> | **`[[noreturn]]`**(C++11)                                 | 指示函数不返回 (属性指示符)                                  |
> | `[[carries_dependency]]`(C++11)                           | 指示在函数内外传播“释放-消费”[std::memory_order](https://zh.cppreference.com/w/cpp/atomic/memory_order) 中的依赖链 |
> | `[[deprecated]]`(C++14) `[[deprecated("*原因*")]]`(C++14) | 指示以此属性声明的名字或实体，允许使用但因某种 *原因*  而不鼓励使用 |
> | **`[[fallthrough]]`**(C++17)                              | 指示从前一 case 标号的直落是故意的，且会警告直落的编译器不应当对此诊断 |
> | **`[[maybe_unused]]`**(C++17)                             | 抑制对于未使用实体的编译器警告，如果有                       |
> | `[[nodiscard]]`(C++17) `[[nodiscard("*原因*")]]`(C++20)   | 鼓励编译器在返回值被丢弃时发出警告                           |
> | **`[[likely]]`**(C++20) **`[[unlikely]]`**(C++20)         | 指示编译器应当针对此种情况进行优化：通过某条语句的执行路径比其他任何执行路径更可能或不可能发生 |
> | `[[no_unique_address]]`(C++20)                            | 指示一个非静态数据成员不必具有与类中的其他所有非静态数据成员都不同的地址 |
> | `[[assume(*表达式*)]]`(C++23)                             | 指示 *表达式* 在给定的位置永远为 true                        |
> | `[[indeterminate]]`(C++26)                                | 指示对象在未初始化时具有不确定值                             |
> | `[[optimize_for_synchronized]]`(TM TS)                    | 指示函数定义应当为从[同步语句](https://zh.cppreference.com/w/cpp/language/transactional_memory)中调用的情况优化 |



常用的：

- [C++ 属性： maybe_unused (C++17 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/attributes/maybe_unused)。

- [C++ 属性： fallthrough (C++17 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/attributes/fallthrough)。

- [C++ 属性： noreturn (C++11 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/attributes/noreturn)。

- [C++ 属性： likely, unlikely (C++20 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/attributes/likely)。这个 C++ 属性 太新了，慎用。可以用 gcc 的扩展关键字：

  ```c
  #define likely(x) __builtin_expect(!!(x), 1)
  #define unlikely(x) __builtin_expect(!!(x), 0)
  ```

- 



### 结构化绑定

参考 https://zh.cppreference.com/w/cpp/language/structured_binding。C++ 17 起。



> ```c++
> auto[i, d] = std::tuple(1, 2.2);
> cout << i << endl;
> cout << d << endl;
> 
> // ---
> 
> std::pair a(1, 2.3f);
> auto[i, f] = a; // 拷贝赋值
> 
> // 对于 std::array 也中
> 
> // ---
> 
> map<int, string> m = {
>     {0, "a"},
>     {1, "b"},  
> };
> for (const auto &[i, s] : m) {
>     cout << i << " " << s << endl;
> }
> 
> // ---
> 
> // 也可以通过结构化绑定改变对象的值
> std::pair a(1, 2.3f);
> auto& [i, f] = a;
> i = 2;
> cout << a.first << endl; // 2
> 
> // ---
> 
> constexpr auto[x, y] = std::pair(1, 2.3f); // C++20 可以
> 
> // ---
> 
> // 对于结构体
> struct Point {
>     int x;
>     int y;
> };
> Point func() {
>     return {1, 2};
> }
> const auto [x, y] = func();
> ```
>
> 
>
> 实现自定义类的结构化绑定：
>
> ```c++
> // 需要实现相关的tuple_size和tuple_element和get<N>方法。
> class Entry {
> public:
>     void Init() {
>         name_ = "name";
>         age_ = 10;
>     }
> 
>     std::string GetName() const { return name_; }
>     int GetAge() const { return age_; }
> private:
>     std::string name_;
>     int age_;
> };
> 
> template <size_t I>
> auto get(const Entry& e) {
>     if constexpr (I == 0) return e.GetName();
>     else if constexpr (I == 1) return e.GetAge();
> }
> 
> namespace std {
>     template<> struct tuple_size<Entry> : integral_constant<size_t, 2> {};
>     template<> struct tuple_element<0, Entry> { using type = std::string; };
>     template<> struct tuple_element<1, Entry> { using type = int; };
> }
> 
> int main() {
>     Entry e;
>     e.Init();
>     auto [name, age] = e;
>     cout << name << " " << age << endl; // name 10
>     return 0;
> }
> ```
>
> 



### if 语句初始化

> ```c++
> // if (init; condition)
> 
> if (int a = GetValue()); a < 101) {
>     cout << a;
> }
> 
> string str = "Hi World";
> if (auto [pos, size] = pair(str.find("Hi"), str.size()); pos != string::npos) {
>     std::cout << pos << " Hello, size is " << size;
> }
> ```
>
> 使用这种方式可以约束作用域，可读性可能略有下降但还好



## 类封装

参考 [C++ 类 & 对象 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-classes-objects.html)、[C++类和对象（class和object） (biancheng.net)](http://c.biancheng.net/cplus/class/)。[复习100分钟拿下100分，你能做得到吗？【C++】(面向对象程序设计)（总复习）_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1ta411k7Yn)。[C++ 数据抽象 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-data-abstraction.html) 介绍将数据封装为类的一些概念。

参考 [类 - cppreference.com](https://zh.cppreference.com/w/cpp/language/classes)。



### 封装概念

p.s 首先说，类内的 变量 和 函数，在这里统一叫 成员变量 和 成员函数。



类定义的一般做法，写成 .c 与 .h 的库形式：

- 类内编写 私有数据（变量） + 公有方法（函数的声明），然后放到 .h 里面。即 成员变量/类属性 和 成员函数/类方法 声明在 类 里面。
- 类中函数的定义 在 .c 文件中，形式为：`函数返回值类型 类名::函数名(...)`。使用双冒号`::`  在 类的 外面 进行定义等 成员变量 和 成员函数。



三种访问权限（public/private/protected 关键字，如不定义则默认为 private）。类内可以访问到所有成员，但类外要看这三种权限。

- 公共权限 public：类内可以访问  类外可以访问。
- 私有权限 private：类内可以访问  类外不可以访问，包括 子类/孩子类 也不能访问；但可以通过 在 public 下定义 set/get 操作 的 函数 来专门访问到 这些 private 变量 而间接对外开放，函数内可以做一些 检查/合法化 等操作，如果是设置 set 或 get 操作 的 函数 就让这些 私有变量 变成 只写 或 只读。
- 保护权限 protected：类内可以访问  类外不可以访问，但是 子类 进行 公有或保护继承 后，子类内部可以访问 到 基类 的 protected 成员。



> c++11 中 sizeof 可以直接用在类的数据成员上。
>
> 例子：`cout << "size " << sizeof(A::data) << endl;`，其中 A 可以是 结构体 或 类。



实例见后面。

### 特殊修饰 const / static

补充参考：

- [C++ const成员变量和成员函数（常成员函数） (biancheng.net)](http://c.biancheng.net/view/2230.html)，[C++ const对象（常对象） (biancheng.net)](http://c.biancheng.net/view/2232.html)；[C++ static静态成员变量详解 (biancheng.net)](http://c.biancheng.net/view/2227.html)，[C++ static静态成员函数详解 (biancheng.net)](http://c.biancheng.net/view/2228.html)。
- [shellmad-c++_40 常成员函数_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1ET4y1378r/)，[shellmad-c++_41 常成员变量及初始化列表_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1RQ4y1N7yQ/)；[shellmad-c++_42 静态成员变量_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1hV411d7JB/)，[shellmad-c++_43 静态成员函数_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1EZ4y1p7q5/)。

**const**

类内的 成员变量 和 成员函数 可以加 const 修饰，对于 常成员变量（在变量声明的最左边加），则初始化后（可以在声明/定义时候初始化值，也可以在构造函数的初始化列表上加）不允许修改，对于 常成员函数（在函数声明的函数名的右边加，类外定义函数的地方不用再加），是下面的情况：

- const 成员函数可以使用类中的所有成员变量，但是不能修改它们的值。
- 常对象（在最前面 用 const 修饰 来 创建新对象，如 `const A a;`），此时，常对象 只能 调用其 常成员函数。
- 必须在成员函数的声明和定义处同时加上 const 关键字。



**static**

可参考 [static 成员 - cppreference.com](https://zh.cppreference.com/w/cpp/language/static#.E9.9D.99.E6.80.81.E6.88.90.E5.91.98.E5.87.BD.E6.95.B0)。

类内的 成员变量 加 static 修饰，则为 类的对象们共享的变量。

类内 静态的（static 修饰的）成员变量  和 静态或非静态的  成员函数  这三者 均不占 对象空间，即 只有一份/一个实例，所有成员都用这一份/一个实例；而对于 非静态的 成员变量 占用 对象空间，每次例化 新的 对象，都会对 这些 变量 新申请空间。

静态成员函数（在函数声明的最左边加，类外定义函数的地方不用再加）只能访问（包括读写） 类内的静态成员。

例子：

```c++
class A
{
    private:

        int class_a_num;
    
    public:

        static unsigned int class_a_count;

        A()
        {
            class_a_count++;
            cout << "A() class_a_count:" << class_a_count << endl;
        }

        ~A()
        {
            class_a_count--;
            cout << "A() class_a_count:" << class_a_count << endl;
        }

        static void class_a_count_show() // 静态函数成员，可以用 A::class_a_count_show() 来全局访问；所有类的实例都用这一份
        {
            cout << "static void class_a_count_show():" << class_a_count << endl;
            // class_a_count = class_a_num; 静态成员函数 只能访问 静态成员变量
        }
};

unsigned int A::class_a_count = 0; // 静态变量成员 的 初始化必须写到类的外面

int main()
{
    cout << " ----- start ----- " << endl;

    A a[5];

    cout << " ----- end ----- " << endl;
    system("pause");
    return 0;
}
```



**内联变量**

C++ 17 起。可在头文件中，初始化类的静态变量成员。

> C++类的静态成员变量在头文件中是不能初始化的，但是有了内联变量，就可以达到此目的。

> ```c++
> // header file
> struct A {
>     static const int value;  
> };
> inline int const A::value = 10;
> 
> // ==========或者========
> struct A {
>     inline static const int value = 10;
> }
> ```
>
> 



### 构造 & 析构函数

构造函数 和 析构函数 的 作用 分别为 对 对象 的 初始化 和 清理，定义好之后 分别 由 对象创造 和 销毁 的时候自动调用。

构造函数 三种：无参数、有参数（新对象的某些参数的初始化，即传入变量参数） 和 拷贝构造函数（用于对新对象的成员变量用老对象的成员变量赋值，即传入类的引用，理解为构造函数的函数重载）。

构造函数在对象被定义的时候 自动被调用，析构函数在对象 出作用域 时候 自动被调用。如果 类B 中嵌套了定义 类A 的对象（类A 为 类B 的成员类），那么 类B 在例化对象的时候，先调用 类A 的构造，再调用 类B 的构造，析构顺序与之相反；子类 继承 基类，那么先调用 基类 构造，再 子类 构造；如果 子类 中 继承 和 成员类 均有的情况，那么先 基类 再 成员类 再 子类自己，析构顺序与之相反。

类的构造函数，类例化一个对象时可传参用于对象内 成员变量 的初始化，且可写成函数重载。

- 类例化时候传参（或者 new 的时候，或者 make_shared() 的 时候，这些均同理）：`类名 对象名(参数);`。

- 类内编写构造函数：有几种情况，根据实际需求来

  下面是抽象的总结，用于复习，新学习可以看视频，讲的比较清楚 [C++40个入门知识点_24_ 浅拷贝与深拷贝_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1jJ41127Zt/)。

  - 如果不写（则均不用编写构造和析构函数），则编译器生成一个默认的无参的构造函数。或可以显式的指示：`类名() = default;`（显示的标记，使用编译器生成的无参构造函数）；显式的指示不用构造函数：`类名() = delete;`。

  - 如果类内不需要申请内存空间，只给一些变量赋值（这是也不需要显式的编写析构函数），可以直接写带传参参数的构造函数：`类名(传参){...进行类内变量赋值初始化...}`。可以写不同的几个带参数构造函数进行函数重载。或者使用编译器生成的浅拷贝构造函数：

    浅拷贝构造函数编译器可以帮着生成，即可以不写，也可以显式的写 ：`类名(类名& obj) = default;`，写为 `=delete;` 即不用拷贝构造函数 / 不许对象进行拷贝构造。类例化时候这样写：`类名 对象2 = 对象1;` 或 `类名 对象2(对象1);`，浅拷贝构造函数即：将 对象1 中所有变量拷贝给 对象2（如果类中有承载申请内存空间的指针变量，那么也包括申请了内存的指针地址拷贝过去，这样新对象中这个指针地址空间也使用了和老对象一块内存空间，使用时候会冲突，而且析构时候会多次释放会出错，因此除了特殊用途，类内有申请内存的指针变量的时候就只用浅拷贝）。

  - 如果类内需要申请内存空间（比如给 char* 变量 申请字符串内存空间，给数组、结构体等等申请内存），构造函数就成为拷贝构造函数，即构造函数的传参为类的引用，个人理解为构造函数的一种函数重载。

    每次类例化的对象都重新申请属于自己的内存空间，这里就是深拷贝构造函数，需要手写，在拷贝构造函数 `类名(类名& obj){...}` 里面，重新申请内存 给 `this->承载申请的内存空间的指针`，将obj下的内存数据复制到 `this->承载申请的内存空间的指针` 里即可完成深拷贝构造。此时的析构函数：每次对象销毁（出作用域）的时候自动调用析构函数，在里面要进行内存释放。



例子：在 main() 里面两次以不同方式例化对象（两次构造），再两次释放（两次析构）。

```c++
class test1
{
    private:
        unsigned int   test1_a = 10;
        unsigned int * test1_b_ptr;
        char* test1_str;
            unsigned int test1_str_len;
            #define MAX_STR_LEN 10

    public:

        /* 带参数 构造函数，给类的成员变量进行初始化 */
        test1(unsigned int test1_a_in, unsigned int test1_b_in, 
            char* test1_str_in, unsigned int test1_str_in_len)
        {
            test1_a = test1_a_in;                   /* 初始化 test1_a */

            test1_b_ptr = new unsigned int(10);     /* 初始化 test1_b （先申请空间） */
            *test1_b_ptr = test1_b_in;

            if(test1_str_in_len >MAX_STR_LEN)      /* 初始化 test1_str （先申请空间） */
            {
                delete test1_b_ptr;
                return;
            }
            test1_str_len = test1_str_in_len;
            test1_str = new char[test1_str_len];
            memset(test1_str, '\0', test1_str_len);
            memcpy(test1_str, test1_str_in, test1_str_len);

            cout << "class test1 init with parameter in" << endl;
        }

        // test1(const test1& obj) = default; // 这一句就是 使用默认的浅拷贝，由编译器自动生成

        // test1(const test1& obj) = delete; // 这一句就是 不允许使用拷贝构造来初始化新对象
        
        /* 使用自写的深拷贝 */
        test1(const test1& obj)
        {
            this->test1_a = obj.test1_a;            /* 初始化 test1_a */

            test1_b_ptr = new unsigned int(10);     /* 初始化 test1_b （先申请空间） */
            *this->test1_b_ptr = *obj.test1_b_ptr;

            this->test1_str_len = obj.test1_str_len;    /* 初始化 test1_str （先申请空间） */
            this->test1_str = new char[this->test1_str_len];
            memset(this->test1_str, '\0', this->test1_str_len);
            memcpy(this->test1_str, obj.test1_str, this->test1_str_len);

            cout << "class test1 init with obj" << endl;
        }
    
        // 并且要实现 operate= 操作符， 当使用 test1 b = a; 的时候也许是调用浅拷贝构造函数
        // 一般不建议允许使用 类之间的 直接等于号来 赋值 / 复制拷贝，就用 explicit 来修饰构造函数。

        ~test1()
        {
            test1_a = 0;
            delete test1_b_ptr;
            delete[] test1_str;

            cout << "class test1 release" << endl;
        }
};

int main()
{
    cout << " ----- start ----- " << endl;

    char* temp_str = "AbCd.!";

    {
        /* 例化 类 test1 对象 带 参数 进行初始化 */
        test1 test1_obj1(5, 10, temp_str, sizeof(temp_str));

        /* 使用拷贝构造函数，具体使用深或者浅的，看类里面的拷贝构造函数实现 */
        test1 test1_obj2(test1_obj1);
        // 或写为 test1 test1_obj2 = test1_obj1; 效果一样，这么写也是 调用拷贝构造函数，
        // 如果 先例化对象 test1_obj2，再单独写一句 test1_obj2 = test1_obj1; 这就是运算符重载，不再调用拷贝构造函数了

        system("pause");
    }


    cout << " ----- end ----- " << endl;
    system("pause");
    return 0;
}

```

关于类里面使用 this 指针，其指向 当前所在 / 所处的类。若 函数 的形参 和 类内的 成员变量 名字一致，则用 `this->成员变量` 来专门表示 类内的那个成员 而不是 形参，用于区分，这只是一种情况，可灵活运行。



各个默认构造函数

> ```c++
> struct trivial
> {
>     trivial() = default;                          // 默认构造
>     trivial(const trivial&) = default;            // 默认拷贝（通过引用传入）构造
>     trivial(trivial&&) = default;                 // 默认移动（通过右值引用传入）构造
> 
>     trivial& operator=(const trivial&) = default; // 默认 赋值 拷贝（通过引用传入）构造
>     trivial& operator=(trivial&&) = default;      // 默认 赋值 移动构造
> 
>     ~trivial() = default;                         // 默认析构
> };
> ```
>
> 引自 [函数声明 - cppreference.com](https://zh.cppreference.com/w/cpp/language/function)。



关于各种 拷贝（或引用） / 移动 构造函数（构造的实现又分 浅拷贝、深拷贝）、赋值拷贝（或赋值引用） / 赋值移动 构造函数的比较全的例子，可见下面链接中 `class & struct` 一节：

> 参考 [这些知识点你都知道吗，测试你的C++入门程度 (qq.com)](https://mp.weixin.qq.com/s?__biz=MzkyODU5MTYxMA==&mid=2247493075&idx=1&sn=fcabde545f1863d5a1a2095696308b5b&source=41#wechat_redirect) 里面 `class & struct：` 一节。
>
> - 拷贝/引用构造函数的定义及使用
> - 移动构造函数的定义及使用
> - 赋值拷贝/引用构造函数的定义及使用
> - 赋值移动函数的定义及使用



**构造函数模板推导**

参考 [类模板实参推导（CTAD）(C++17 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/class_template_argument_deduction)。

> ```c++
> pair<int, double> p(1, 2.2); // before c++17
> 
> pair p(1, 2.2); // c++17 自动推导
> vector v = {1, 2, 3}; // c++17
> 
> // ---
> 
> std::pair p(2, 4.5);     // 推导出 std::pair<int, double> p(2, 4.5);
> std::tuple t(4, 3, 2.5); // 同 auto t = std::make_tuple(4, 3, 2.5);
> std::less l;             // 同 std::less<void> l;
> ```



**析构函数**

父类指针释放子类对象会发生什么

[父类指针释放子类对象会发生什么_delete父类指针-CSDN博客](https://blog.csdn.net/pingis58/article/details/127557501)

[多态与纯虚函数解析-CSDN博客](https://blog.csdn.net/baidu_35260565/article/details/101316319)

一些定义类时候的良好习惯：

- 基类（会被继承的类）的析构函数定义为 虚函数（这样 delete 基类指针时候会正确的 先释放子类实例，即先调子类析构函数，再调基类析构函数）。
- 尽量所有类的构造和析构函数定义在 public。



### 类的构造和析构时刻

关于c++一些类的构造和析构时刻的试验

```c++
// 实验用的类：
class TestClass {
public:
    explicit TestClass() = default;
    explicit TestClass(const int32_t& _priv)
     : mPriv(_priv)
    {
        GUIFE_LOGI(" --> construct TestClass, mPriv: %d", mPriv);
    }
    virtual ~TestClass(void)
    {
        GUIFE_LOGI(" <-- de-construct TestClass");
    }
private:
    int32_t mPriv;
};
```

```c++
// 执行：
for(uint32_t i = 0; i < 3; i++) {
    TestClass testClassInst(i);
    GUIFE_LOGI(" ------ i: %d", i);
}

// 打印：
[User]  (0.520, +0)      testClass:  --> construct testClass, mPriv: 0  (in Test.cpp line #596)
[User]  (0.520, +0)      test:  ------ i: 0     (in Test.cpp line #624)
[User]  (0.520, +0)      ~testClass:  <-- de-construct testClass        (in Test.cpp line #600)
[User]  (0.520, +0)      testClass:  --> construct testClass, mPriv: 1  (in Test.cpp line #596)
[User]  (0.520, +0)      test:  ------ i: 1     (in Test.cpp line #624)
[User]  (0.520, +0)      ~testClass:  <-- de-construct testClass        (in Test.cpp line #600)
[User]  (0.520, +0)      testClass:  --> construct testClass, mPriv: 2  (in Test.cpp line #596)
[User]  (0.520, +0)      test:  ------ i: 2     (in Test.cpp line #624)
[User]  (0.520, +0)      ~testClass:  <-- de-construct testClass        (in Test.cpp line #600)

// 结论：每次 for 的循环，开始会构造，结束会析构
```

```c++
// 执行：结论在注释
TestClass TestClassInst(1);
TestClass TestClassInst2(10);
TestClass TestClassInst3(20);

std::list<TestClass> tests;

GUIFE_LOGI("复制");
tests.push_back(TestClassInst); // TestClassInst 只在上面构造一次，在这里直接复制进 tests，没有新构造发生, TestClassInst 不析构

GUIFE_LOGI("原位构造 再 push_back");
tests.push_back(TestClass(2)); // 构造一个新的 TestClass(2) 再复制进 tests

GUIFE_LOGI("原位构造 再 直接 emplace_back");
tests.emplace_back(TestClass(3)); // 同上，emplace_back 是 使用引用 传入，即 构造一个新的 TestClass(3) 通过引用给到 tests

GUIFE_LOGI("变量直接 emplace_back");
tests.emplace_back(TestClassInst2); // emplace_back 是 使用引用 传入
GUIFE_LOGI("TestClassInst2.getPriv(): %d", TestClassInst2.getPriv());

GUIFE_LOGI("直接移动");
tests.emplace_back(std::move(TestClassInst3)); // emplace_back 使用移动（右值引用）传入
GUIFE_LOGI("TestClassInst3.getPriv(): %d", TestClassInst3.getPriv());

GUIFE_LOGI("start clear~");
tests.clear();
// 析构顺序：
//    tests 里面的所有 类 成员的 析构，tests 里面的 项 从前往后的顺序 挨个 析构
//    TestClassInst3, TestClassInst2, TestClassInst
```

```c++
// 执行：结论在注释
std::list<TestClass*> testPtrs;

GUIFE_LOGI("new 之后 用 push_back");
testPtrs.push_back(new TestClass(1)); // 执行一次构造

GUIFE_LOGI("new 之后 用 emplace_back");
testPtrs.emplace_back(new TestClass(2)); // 同上

GUIFE_LOGI("start clear~");
testPtrs.clear();
// 调用 存储 类指针 的 容器的 clear 并不会调用 其 项 的 析构，所以这种情况，需要 clear 之前，对其每一项先用 delete !!
```

```c++
// 执行：结论在注释
std::list<std::shared_ptr<TestClass>> testPtrs;

GUIFE_LOGI("new 之后 用 push_back");
testPtrs.push_back(std::make_shared<TestClass>(1)); // 执行一次构造

GUIFE_LOGI("new 之后 用 emplace_back");
testPtrs.emplace_back(std::make_shared<TestClass>(2)); // 同上

GUIFE_LOGI("用个变量引用 testPtrs.front()");
auto it = testPtrs.front();

GUIFE_LOGI("start clear~");
testPtrs.clear();
// 调用 存储 shared_ptr 类型 类指针 的 容器的 clear 后，其中 若项 的 shared_ptr 的引用次数会归为 0 因而会被析构
// 用 vector 效果也一样
// 但是 testPtrs.front() 不会析构 因为 指针被 it 用走了一份

GUIFE_LOGI("it.use_count(): %ld", it.use_count());

GUIFE_LOGI("it = nullptr;");
it = nullptr; // 这里就会析构 it 指向的 类实例
GUIFE_LOGI("it.use_count(): %ld", it.use_count());

// 对于放到一个结构体里面，如下
struct TestStruct {
    std::string str;
    uint32_t num;
    TestClassSharedPtr testClassPtr;
};
std::vector<TestStruct> testPtrs;
// 进行相同的操作，结果也一样
```



### 友元

使用 friend 关键字 在左边 修饰 在 类A 内 声明的 但定义在外面的 函数 或 类B内的函数 或 类B，则在外面定义的 函数 或 类B内的函数 可以访问到 类A 的 **私有变量**。缺点是破坏了类的封装性和私有性，不推荐用，但是某些运算符重载和特殊情况可以酌情用。

例子：在 类A 中设置一些友元，在 main() 里面用这些函数操作 类A 的私有变量。

```c++
/* 首先声明 类 A 和 B */
    /* 因为后面 类B 里面 void set_class_A_obj_private_a(A& obj, int a); 里面有 A，不提前声明则编译会提示不存在 */
class A;
class B;

class B
{
    private:

    public:
        B() = default;
        ~B() = default;

    /* 声明在这里，定义在外面 */
    void set_class_A_obj_private_a(A& obj, int a); 
    void set_class_A_obj_private_b(A& obj, int b);
};

/* 声明一个全局函数，定义在后面 */
void set_class_A_obj_private_a(A& obj, int a);

class A
{
    private:
        int private_a;
        int private_b;

    public:
        A() = default;
        ~A() = default;

        /* 声明友元 */

        friend void set_class_A_obj_private_a(A& obj, int a);       /* 把一个 全局函数当作友元*/

        friend void B::set_class_A_obj_private_a(A& obj, int a);    /* 把一个 类B 的函数当作友元*/

        friend B;   /* 把 类B 当作友元 */
};

void set_class_A_obj_private_a(A& obj, int a)
{
    obj.private_a = a;
}

void B::set_class_A_obj_private_a(A& obj, int a)
{
    obj.private_a = a;
}

void B::set_class_A_obj_private_b(A& obj, int b)
{
    obj.private_b = b;
}

int main()
{
    cout << " ----- start ----- " << endl;

    A class_a_obj1;
    B class_b_obj1;

    set_class_A_obj_private_a(class_a_obj1, 10);
    class_b_obj1.set_class_A_obj_private_a(class_a_obj1, 20);
    class_b_obj1.set_class_A_obj_private_b(class_a_obj1, 20);

    cout << " ----- end ----- " << endl;
    system("pause");
    return 0;
}
```



### 初始化列表实现 std::initializer_list

不同于 `类构造函数的初始化列表`，那个也有叫 `委托构造函数`，这里是 自写类实现 `= { ..., ...}` 形式的初始化。

参考

- [std::initializer_list - cppreference.com](https://zh.cppreference.com/w/cpp/utility/initializer_list)。
- [c++11新特性之列表初始化 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/137851769)。

TODO: 这里还需要补充



并可使用 `基于范围的for循环`，实现如下的效果：TODO：再查下自写的类，怎么写实现这种用法

> ```cpp
> for (int i : vec) { // c++11基于范围的for循环
>     cout << "i" << endl;
> }
> ```



### 各类型初始化写法

[初始化 - cppreference.com](https://zh.cppreference.com/w/cpp/language/initialization)。

不完全列举，其中包括：

- [默认初始化](https://zh.cppreference.com/w/cpp/language/default_initialization)。
- [值初始化](https://zh.cppreference.com/w/cpp/language/value_initialization)。
- [引用初始化](https://zh.cppreference.com/w/cpp/language/reference_initialization)。
- [复制初始化](https://zh.cppreference.com/w/cpp/language/copy_initialization)。
- [聚合初始化](https://zh.cppreference.com/w/cpp/language/aggregate_initialization)。
- [列表初始化](https://zh.cppreference.com/w/cpp/language/list_initialization)。
- [直接初始化](https://zh.cppreference.com/w/cpp/language/direct_initialization)。

例子：

> ```c++
> #include <string>
>  
> std::string s1;            // 默认初始化
> // 值初始化
> char& c = a[0];         // 引用初始化
> std::string s3 = "hello"; // 复制初始化
> char a[3] = {'a', 'b'};   // 聚合初始化（C++11 起是列表初始化的一部分）
> std::string s4("hello");  // 直接初始化
> std::string s5{'a'};      // 列表初始化（C++11 起）
> // 直接初始化
> ```
>
> 



### 杂项



**在 lambda 表达式 用 `*this` 捕获对象副本**

> 正常情况下，lambda表达式中访问类的对象成员变量需要捕获this，但是这里捕获的是this指针，指向的是对象的引用，正常情况下可能没问题，但是如果多线程情况下，函数的作用域超过了对象的作用域，对象已经被析构了，还访问了成员变量，就会有问题。
>
> C++17增加了新特性，捕获*this，不持有this指针，而是持有对象的拷贝，这样生命周期就与对象的生命周期不相关啦。
>
> ```c++
> struct A {
>     int a;
>     void func() {
>         auto f = [*this] { // 这里
>             cout << a << endl;
>         };
>         f();
>     }  
> };
> int main() {
>     A a;
>     a.func();
>     return 0;
> }
> ```



## 类继承

补充参考 [C++ 继承 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-inheritance.html)、[C++继承和派生简明教程 (biancheng.net)](http://c.biancheng.net/view/2264.html)。

子类/派生类 继承于 父类/基类（后面以 子类 和 基类 来叫）。子类 从基类继承过来的 表现共性，子类 再自己增加的成员 体现个性。

### 继承

三种继承/派生（继承和派生这里一个意思）：公共继承、保护继承、私有继承。

写法例子：`class B : public A, protected AO {...};`，即 类B 公有继承 类A 且 类B 保护继承 类AO。

基类 中 a 权限的成员 被以 b 权限 继承到子类，那么子类中该成员的权限为 取 a 和 b 中较低的那一个；基类的 私有成员，无论什么类型的继承，子类都不能访问到。子类 继承 基类 后，基类 所有 成员变量 均添加到 子类 的头部，子类 创建对象后，在对象的内存上，首先是 基类 所有 成员变量 的内存空间，然后再是 子类 新添加的 成员变量 的内存空间，虽然 子类 中 基类的 私有成员 看不见（编译器在编译的时候使其这样的），但内存上可以操作到 基类 的所有成员变量。

子类继承基类后，当创建子类对象，先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反。



初始化列表：例化 子类 对象的时候 不能给 基类 的构造函数 传参，那么就给 子类的构造函数 后面 添加 初始化列表，里面的语句会逐个执行，在里面可以添加 调用基类的带参数的构造函数的语句，这是一种写法，也可以添加 子类 成员变量赋值的语句，此乃 初始化列表。

- 补充参考 [C++40个入门知识点_31 派生类中的函数隐藏_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV17J41127gP/?spm_id_from=333.999.0.0&vd_source=c633af9518bed5572b1614612e2be3df)，[P2继承_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1ta411k7Yn?p=2) 的4分半的地方。

- 子类的构造函数中对类成员变量进行初始化，要先用 初始化列表 来初始化 基类 的 成员变量，再去在函数内初始化 子类的 成员变量，比较规范。包括 const 修饰的变量也可以写在初始化列表里面。




写法例子：

```c++
class A
{
    private:

        int class_a_num;
    
    public:
        A()
        {
            cout << "A()" << endl;
        }

        A(int class_a_num_in)
        {
            class_a_num = class_a_num_in;
            cout << "A(int class_a_num_in)" << endl;
        }

        ~A() = default;
};

class B : public A // 类B 公有继承 类A
{
    private:

        int class_b_num;

    public:
        B() : A(1), class_b_num(2) // 初始化列表，调用 类A 的带参数构造函数，给自己 成员变量初始化值
        {
            cout << "B()" << endl;
        }

        ~B() = default;
};

int main()
{
    cout << " ----- start ----- " << endl;

    B b;

    cout << " ----- end ----- " << endl;
    system("pause");
    return 0;
}
```



继承 的时候 如果 是修饰为 类指针 或者 引用 类型（而且不使用 new / malloc 创建空间），则不为其分配内存，只是继承过来一个类的对象的指针。

c++ explicit 修饰只有一个参数的构造函数，即取消隐式转换，在例化对象时候只能用函数的方式，不能用赋值的方式，赋值 = 用操作符重载去做。



### 虚继承 / 菱形继承

一个类（孙子类）继承多个类（子类），而这多个类中至少有两个类（子类） 又 继承自 同一个类（父类/基类），从而导致 孙辈的类 会包含 多个来自 父辈类的副本成员，因此要使用 虚继承。多个子类（至少两个） 继承 基类 时候使用 `virtual` 修饰，这样 孙子类 继承多个 子类 后，只有一个 基类 的副本。

例子：

```c++
class A
{
    protected:
        int class_a_num;
    public:
        A()  { cout <<  "A()" << endl; }
        ~A() { cout << "~A()" << endl; }
};

class B1 : virtual public A
{
    protected:
        int class_b1_num;
    public:
        B1()  { cout <<  "B1()" << endl; }
        ~B1() { cout << "~B1()" << endl; }
};

class B2 : virtual public A
{
    protected:
        int class_b2_num;
    public:
        B2()  { cout <<  "B2()" << endl; }
        ~B2() { cout << "~B2()" << endl; }
};

class C : public B1, public B2
{
    private:
        int class_c_num;
    public:
        C()  { cout <<  "C()" << endl; }
        ~C() { cout << "~C()" << endl; }

        void class_c_set_and_show(int class_a_num, int class_b1_num, int class_b2_num, int class_c_num)
        {
            this->class_a_num = class_a_num;
            this->class_b1_num = class_b1_num;
            this->class_b2_num = class_b2_num;
            this->class_c_num = class_c_num;

            cout << class_a_num << '\t' << class_b1_num << '\t' \
                << class_b2_num << '\t' << class_c_num << '\t' << endl;
        }
};

int main()
{
    cout << " ----- start ----- " << endl;

    {
        C c;
        c.class_c_set_and_show(1, 2, 3 ,4);
    }
    
    cout << " ----- end ----- " << endl;
    system("pause");
    return 0;
}

/* 
打印信息：
----- start -----
A()
B1()
B2()
C()
1       2       3       4
~C()
~B2()
~B1()
~A()
 ----- end -----
*/
```



## 类多态

补充参考：[C++ 多态 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-polymorphism.html)，[C++多态与虚函数 (biancheng.net)](http://c.biancheng.net/cplus/polymorphism/)。

调用基类的虚函数（表共性的），就调用了子类中同名函数（表特点的），达到这样一个效果。

基类中定义虚函数，函数前面添加 `virtual` 修饰，就成了虚函数（可以直接调用，写为 `对象名.虚函数名();`），因基类虚函数一般为实现类多态，子类会覆写同名函数带有具体内容，因此基类这里的虚函数可写为空（花括号里面为空）；基类中虚函数也可以写为 `virtual 函数返回值 函数名() = 0;`，则成为纯虚函数，有纯虚函数的类是抽象类，抽象类不允许创建对象（抽象类一般是基础的、提供接口规范的，不提供实际具体功用，是用来被继承的，因此就不允许创建对象了）。子类继承抽象类后，子类里面必须实现有同名函数（函数名、返回值、函数参数必须一致）（至少写成 `函数返回值 函数名(){...}`，而且仍为虚函数）（若函数不完全同名，比如参数有区别，那就不覆盖，而且基类继承过来并且和子类的都存在，属于函数重载了），子类才能创建对象，否则子类也是抽象类就不能创建对象。

子类的地址可以 赋值给 基类的指针 或 基类的引用，这是安全的（子类空间比基类相等或更大，基类指针操作时候不会越界）。

关于虚函数的直接调用（就是调用谁就运行谁，没有多态性）（`基类对象名.虚函数名()；` 和 `子类对象指针.基类类名::虚函数名();`（这是明确类域范围的用指针调用，用引用同理））和间接调用（有了多态性）（用指针或引用去调用，但不明确写出类域范围），编译时期会有区别，间接调用的话调用虚函数时候会有一个查找虚函数表里面到底要调用哪一个的过程（除了直接调用和明确类域范围的用指针调用），具体可看一下 [shellmad-c++_37 虚函数的直接调用与间接调用_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1n54y1X76T/) 和 [shellmad-c++_47 虚函数的多态性_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1pi4y147dZ/)。

例子：

```c++
class shape
{
    public:
        virtual void area()
        {
            cout << "shape area()" << endl;
        }
        // virtual void area() = 0; 这么写就是纯虚函数，则 类 shape 变为抽象类，则不允许定义对象
    
        /* 基类的普通成员函数中调用多态函数，也具有多态性
        	但是在构造和析构函数中调用 多态函数，就不具备多态了（就是调用基类自己的那个虚函数了） */
        void shape_area()
        {
            cout << "shape shape_area()" << endl;
            area(); // 本质上是 this->area(); 是具有多态性的，就是看是哪个子类的指针，去调用那个子类的 area()
        }
};

class circle : public shape
{
    public:
        virtual void area()
        {
            cout << "circle area()" << endl;
        }
};

class rectangle : public shape
{
    public:
        virtual void area()
        {
            cout << "rectangle area()" << endl;
        }
};

void show_shape_area(shape& s)
{
    s.area();
}

int main()
{
    cout << " ----- start ----- " << endl;

    shape sh;
    circle c;
    rectangle r;

    shape* s[2] = {&c, &r};

    /* 直接调用，没有多态性，调用谁直接运行谁 */
    sh.area();
    c.shape::area();

    cout << "-------------" << endl;

    /* 间接调用，具有多态性：两种写法，一个是指针直接用，一个是写个函数用引用 */
    s[0]->area();   show_shape_area(c);
    s[1]->area();   show_shape_area(r);

    cout << "-------------" << endl;

    /* 基类的普通成员函数中调用多态函数，也具有多态性 */
    s[0]->shape_area();

    cout << " ----- end ----- " << endl;
    system("pause");
    return 0;
}

/*
打印内容：
 ----- start -----
shape area()
shape area()
-------------
circle area()
circle area()
rectangle area()
rectangle area()
-------------
shape shape_area()
circle area()
 ----- end -----
*/
```



类的（尤其是抽象类（基类））的析构函数最好定义为虚函数（子类继承后，子类里的析构函数也都成为虚函数），具体可看 [shellmad-c++_46 虚析构函数的作用_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1BA411t7K9/)。一个小的点，虚析构函数 可以写为 纯虚析构，那么必须要有实现（有花括号），例 `virtual ~类名() = 0 { }`。例子：

```c++
class base
{
    public:
        base()
        {
            cout << "base()" << endl;
        }
        virtual ~base() // 基类 且要被继承的基类 的虚构函数 最好写为 虚函数
        {
            cout << "~base()" << endl;
        }
};

class child : public base
{
    public:
        child()
        {
            cout << "child()" << endl;
        }
        virtual ~child() // 也可以修饰为虚函数（也可以不，除非被别的类再继承）
        {
            cout << "~child()" << endl;
        }
};

int main()
{
    cout << " ----- start ----- " << endl;
    
    /* 在使用这种方式 来使用 基类的时候，释放 对象指针 b 时候，
           若基类的析构函数 修饰为虚函数，则会调用 基类 和 父类的 析构函数
           若基类的析构函数不修饰为虚函数，则释放 对象指针 b 时候，只会调用 子类的虚构函数，基类的虚构函数没有调用到，就不安全
    */
    base* b = new child; 
    delete b;

    cout << " ----- end ----- " << endl;
    system("pause");
    return 0;
}
```



更多的多态的基础例子，还可以参考这个链接里面 `多态` 一节：[这些知识点你都知道吗，测试你的C++入门程度 (qq.com)](https://mp.weixin.qq.com/s?__biz=MzkyODU5MTYxMA==&mid=2247493075&idx=1&sn=fcabde545f1863d5a1a2095696308b5b&source=41#wechat_redirect)。



[(05)重学C++：多态 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/621299561)。



## 运算符重载

- 参考 [C++ 重载运算符和重载函数 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-overloading.html)、[C++函数重载详解 (biancheng.net)](http://c.biancheng.net/view/2206.html)、[C++运算符重载基础教程 (biancheng.net)](http://c.biancheng.net/view/2306.html)。


- 参考视频：[shellmad-c++_51 运算符重载_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV13A411q7bE/)，[shellmad-c++_52 cin&cout的奥秘_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1kC4y1H7G7/)，[shellmad-c++_53 自己动手编写字符串类_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1eC4y1H7uC/?vd_source=c633af9518bed5572b1614612e2be3df)，[shellmad-c++_54 转换运算符_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV15z411B7W8/)。


- [C++类和对象(4):运算符重载——=、==、()函数调用运算符_重载操作符=和()-CSDN博客](https://blog.csdn.net/ITJAVAtao/article/details/120922956)。
- [C++基础-运算符重载详解_C++语言-CSDN专栏](https://download.csdn.net/blog/column/12435130/135169738)。



TODO: 这里还需要补充例子



## 模板 / 泛型

模板是泛型编程的基础。C++ 用 模板 来支持 泛型编程，即 一种 类 或 函数 支持多种数据类型，关注算法实现。

模板一节，会包含一些较新的 c++ 版本 的 模板特性。

基础参考：

- [C++ 模板 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-templates.html)，[C++模板和泛型程序设计 (biancheng.net)](http://c.biancheng.net/cplus/70/)，[c++高效编程之模板函数、模板结构体、模板类的使用_路过的小熊~的博客-CSDN博客_c++ 结构体模板](https://blog.csdn.net/qq_32348883/article/details/122044301)。
- [c++11新特性之模板的改进 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/137851516)。
- [C++函数模板5分钟入门教程 (biancheng.net)](http://c.biancheng.net/view/2317.html)，[shellmad-c++_55 函数模板_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1Ug4y1B78H/)。中文语境下 也叫 “模板函数”。
- [C++类模板5分钟入门教程 (biancheng.net)](http://c.biancheng.net/view/2318.html)，[shellmad-c++_56 类模板_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1NC4y1p7FB/)。中文语境下 也叫 “模板类”。
- [大话C++模板编程的来龙去脉 (biancheng.net)](http://c.biancheng.net/view/2319.html)，STL（Standard Template Library，标准模板库）就是 C++ 模板实现库。

- [C++模板-CSDN博客](https://blog.csdn.net/weixin_63246738/article/details/130758826)。



指定调用模板函数：

[c++模板:调用模板成员函数需不需要加template关键字?_调用类模板的特化函数,需要带template关键字吗?-CSDN博客](https://blog.csdn.net/10km/article/details/123571339)。



可变参数模板类和函数：

[可变参数模板 - OI Wiki (oi-wiki.org)](https://oi-wiki.org/lang/new/#可变参数模板)。

[包 (C++11 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/pack)。



精品参考：

- [Mq-b/Modern-Cpp-templates-tutorial: 现代C++模板教程 (github.com)](https://github.com/Mq-b/Modern-Cpp-templates-tutorial)。
- [wuye9036/CppTemplateTutorial: 中文的C++ Template的教学指南。与知名书籍C++ Templates不同，该系列教程将C++ Templates作为一门图灵完备的语言来讲授，以求帮助读者对Meta-Programming融会贯通。(正在施工中) (github.com)](https://github.com/wuye9036/CppTemplateTutorial)。



- [STL/6 模板中class与typename区别.md at master · FunctionDou/STL (github.com)](https://github.com/FunctionDou/STL/blob/master/6 模板中class与typename区别.md)。
- [STL/template之模板注意事项.md at master · FunctionDou/STL (github.com)](https://github.com/FunctionDou/STL/blob/master/template之模板注意事项.md)。
- [STL/template之类相关.md at master · FunctionDou/STL (github.com)](https://github.com/FunctionDou/STL/blob/master/template之类相关.md)。
- [STL/template之非类型模板参数.md at master · FunctionDou/STL (github.com)](https://github.com/FunctionDou/STL/blob/master/template之非类型模板参数.md)。





TODO: 这里还需要补充





**变量模板**

[变量模板 (C++14 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/variable_template)。

> ```c++
> template<class T>
> constexpr T pi = T(3.1415926535897932385L);
> 
> int main() {
>     cout << pi<int> << endl; // 3
>     cout << pi<double> << endl; // 3.14159
>     return 0;
> }
> ```
>



**别名模板**

C++ 14 起。

> ```c++
> template<typename T, typename U>
> struct A {
>     T t;
>     U u;
> };
> 
> template<typename T>
> using B = A<T, int>;
> 
> int main() {
>     B<double> b;
>     b.t = 10;
>     b.u = 20;
>     cout << b.t << endl;
>     cout << b.u << endl;
>     return 0;
> }
> ```
>



**折叠表达式**

参考 [折叠表达式(C++17 起) - cppreference.com](https://zh.cppreference.com/w/cpp/language/fold)。

C++ 17 起。

> ```c++
> template <typename ... Ts>
> auto sum(Ts ... ts) {
>     return (ts + ...);
> }
> int a {sum(1, 2, 3, 4, 5)}; // 15
> std::string a{"hello "};
> std::string b{"world"};
> cout << sum(a, b) << endl; // hello world
> 
> // ---
> 
> template<typename... Args>
> bool all(Args... args) { return (... && args); }
>  
> bool b = all(true, true, true, false);
> // 在 all() 中，一元左折叠展开成
> //  return ((true && true) && true) && false;
> // b 是 false
> ```
>
> 



## 多线程编程基础

参考 和 引用：

- [并发支持库 (C++11 起) - cppreference.com](https://zh.cppreference.com/w/cpp/thread)。
- 很清楚的总结 [C++ 中，std::async 可以完全替代 std::thread 来开启异步的多线程操作吗？ - 知乎 (zhihu.com)](https://www.zhihu.com/question/547132461/answer/2657296340)。
- [【C++11多线程】异步任务：async、packaged_task、promise_c++ async-CSDN博客](https://blog.csdn.net/qq_42815188/article/details/102505884)。
- [async的两个坑 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/484355423)。
- [关于多线程的一些心得 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/398428022)。
- [c++11新特性之线程相关所有知识点 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/137914574)。
- [c++11 新特性总结（二）——多线程篇 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/547970094)。
- [Mq-b/ModernCpp-ConcurrentProgramming-Tutorial: 现代C++并发编程教程 (github.com)](https://github.com/Mq-b/ModernCpp-ConcurrentProgramming-Tutorial)。
- 比较全面的总结 [C++多线程+线程池（全详解） - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/650522122)。
- 用法归纳 [C++中的thread最全用法归纳_c++ thread用法-CSDN博客](https://blog.csdn.net/zzh516451964zzh/article/details/128421574)。
- [std::thread（线程）-CSDN博客](https://blog.csdn.net/weixin_40087851/article/details/82685510/)。
- [C++：std::thread：线程用法_std::thread用法-CSDN博客](https://blog.csdn.net/u013620306/article/details/128565614)。
- [C++ std::thread调用类成员函数_std::thread 类成员函数-CSDN博客](https://blog.csdn.net/IsaiahX/article/details/123303200)。



### 创建线程

相关方法：过于基础的暂不提供例子。

- thread

  创建线程

  > ```c++
  > ...
  > std::thread t(func, funcPara); // 可传入 lambda、函数指针等等，并后跟着函数入参；也可传入 std::packaged_task 变量
  > if (t.joinable()) {
  >     t.detach();
  > }
  > ...
  > ```

  更多线程相关 API 例子：

  > ```c++
  > std::thread t(func);
  > cout << "当前线程ID " << t.get_id() << endl;
  > cout << "当前cpu个数 " << std::thread::hardware_concurrency() << endl;
  > auto handle = t.native_handle();// handle可用于pthread相关操作
  > std::this_thread::sleep_for(std::chrono::seconds(1));
  > ```

- std::call_once

  ```c++
  ...
  for(uint32_t i = 0; i < 5; i++) {
      std::thread t(
          []() -> void {
              static auto func = []() -> void {
                  std::cout << " --- just run once" << std::endl;
              };
              static std::once_flag onceflag;
              std::call_once(onceflag,func);
          }
      );
      if(t.joinable()) {
          t.detach();
      }
  }
  
  std::this_thread::sleep_for(std::chrono::seconds(3));
  ...
  ```



### 线程间同步机制

- 互斥锁：mutex

  注意先的各种锁的种类，来自于不同的 C++ 版本，可参考 [锁（mutex）使用（c++11、c++14、c++17）_c++11、c++14、c++17多线程读写锁的区别-CSDN博客](https://blog.csdn.net/liguan1102/article/details/116236702)。

  mutex 种类：

  [互斥 - cppreference.com](https://zh.cppreference.com/w/cpp/thread#.E4.BA.92.E6.96.A5)。

  - std::mutex：独占的互斥量，不能递归使用，不带超时功能
    - shared_mutex (C++17) 可实现读写锁
    - shared_timed_mutex (C++14)，同上，带等待超时功能。
  - std::recursive_mutex：递归互斥量，可重入，不带超时功能
  - std::timed_mutex：带等待超时的互斥量，不能递归
  - std::recursive_timed_mutex：带等待超时的互斥量，可以递归使用

  在 C++ 中通常不直接使用 std::mutex 来进行锁定，而是使用 std::unique_lock、std::lock_guard 或 std::scoped_lock（从 C++17 起可用）等类，以更加安全地管理锁定。这些类提供了更好的异常安全性，在临界区中的代码发生异常，std::unique_lock 也会在超出作用域时自动释放锁定，确保资源被正确地释放，从而提供更好的异常安全性。

  unique_lock 和 lock_guard：如果需要更多的灵活性、手动控制锁定或支持移动语义，则选择 std::unique_lock。而如果只需要简单的自动锁定和释放，且不需要额外的功能，则选择 轻量级 std::lock_guard 更为合适。二者默认 创建时候 加锁，超出作用域时 自动解锁 和 释放。

  

  通过 try_lock 方法，可以在多次执行一个 函数的时候，判断是否有其它线程已经在执行了，若不需要同时执行（比如按键的回调函数，当按键多次点击，不需要并行执行的时候），就可以用 try_lock 方法来判断，选择要不要 return。灵活去用 锁 的 各种方法。

  有 try_to_lock、defer_lock 等更灵活的用法。例如，如果一个线程函数不希望在其它线程正在运行这个函数还没有结束的时候再执行，就可以用 try_to_lock 方法，如果 lock.owns_lock() 返回 false 是没有锁上就表明其它线程正在占用 所以直接 return 即可。

  上锁：

  - 锁变量直接调用其方法来上锁 (lock() / try_lock())。

  - RAII 风格（利用对象生命周期管理资源）
    
    [通用互斥体管理 - cppreference.com](https://zh.cppreference.com/w/cpp/thread#.E9.80.9A.E7.94.A8.E4.BA.92.E6.96.A5.E4.BD.93.E7.AE.A1.E7.90.86)。
    
    - unique_lock（有 try_lock 等方法）
    - shared_lock (C++14)
    - lock_guard
    - scoped_lock (C++17)（TODO: 有待补充）
    
    指定锁定策略 [std::defer_lock, std::try_to_lock, std::adopt_lock, std::defer_lock_t, std::try_to_lock_t, std::adopt_lock_t - cppreference.com](https://zh.cppreference.com/w/cpp/thread/lock_tag)。

  实现读写锁，可用 shared_mutex 或 shared_timed_mutex（相较 前者多了超时功能），可参考：

  - [C++多线程——读写锁shared_lock/shared_mutex_princeteng-GitCode 开源社区 (csdn.net)](https://gitcode.csdn.net/65ec508a1a836825ed798052.html)。
  - [多线程同步原语std::shared_timed_mutex 和 std::shared_lock_std shared lock-CSDN博客](https://blog.csdn.net/vmt/article/details/143677873)。

- 条件变量：condition_variable，参考 [std::condition_variable - cppreference.com](https://zh.cppreference.com/w/cpp/thread/condition_variable)。

  看例子即可，使用与 ptherad 中的都比较类似。

  其中 wait(m, pred) 的 pred 可以认为是其它线程发送的条件变量到底是不是给我听的（返回 false 指示不是给自己的，反之则是），参考 [std::condition_variable::wait - cppreference.com](https://zh.cppreference.com/w/cpp/thread/condition_variable/wait)。

- atomic，可用时现查。

  [std::atomic - cppreference.com](https://zh.cppreference.com/w/cpp/atomic/atomic)。
  
  [C++并发编程 | 原子操作std::atomic-CSDN博客](https://blog.csdn.net/weixin_44479862/article/details/128059243)。
  
  互斥量锁保护的数据范围比较大，我们期望更小范围的保护。并且当共享数据为一个变量时，使用 std::atomic 建立原子变量 效率更高。
  
  并提供了原子操作的 读写、加减 等 API。
  
  



### future / packaged_task

promise / future / shared_future

[std::promise - cppreference.com](https://zh.cppreference.com/w/cpp/thread/promise)。[std::future - cppreference.com](https://zh.cppreference.com/w/cpp/thread/future)。[std::shared_future - cppreference.com](https://zh.cppreference.com/w/cpp/thread/shared_future).

std::promise 用于生成值或异常，并将其与 std::future 关联起来，而 std::future 则用于获取异步操作的结果或状态。它们通常一起使用，实现线程间的协作和通信，以便在异步环境中进行数据共享和控制流管理。

> ```c++
> // future from a promise
> std::promise<int> p;
> std::future<int> f3 = p.get_future();
> std::thread p([&p]{ p.set_value_at_thread_exit(9); }); p.detach();
> ...
> ```



[C++11中std::future的具体使用方法_C/C++_服务器之家 (zzvips.com)](http://www.zzvips.com/article/183327.html)。

std::future 是独占的，即它只能与一个 std::promise 对象关联，并且不能被复制或共享；一旦与 std::promise 关联的值被设置，std::future 就无法再次与其他 std::promise 关联；std::future 对象是一次性的，一旦获取了异步操作的结果，就不能再次获取。

std::shared_future 可以与多个 std::promise 对象关联，并且可以被多个线程同时访问；std::shared_future 允许多个线程同时等待异步操作的完成，并且可以多次获取相同的结果。

当需要允许多个线程同时等待相同的异步操作结果时，也可以使用 std::shared_future；在某些情况下，使用 std::shared_future 可以减少资源的重复计算，因为多个线程可以共享相同的结果，而不是每个线程都需要独立计算一次。



packaged_task

用于更灵活的线程返回值控制。

std::packaged_task 承载一个将要 异步执行 的可调用对象（函数、函数对象或 Lambda 表达式），然后可以获得其 std::future 或 std::shared_future 对象，自己手动创建个 thread 并将 std::packaged_task 对象移入 来异步执行函数，然后 通过 future 对象 获取 异步执行的返回结果。

相比较 std::async 更灵活，可操作性大。

> ```c++
> #include <future>
> #include <iostream>
> #include <thread>
> int main() {
>     std::packaged_task<int(int, int)> task([](int a, int b) { return a + b; });
>     auto f = task.get_future();
>     std::thread t(std::move(task), 1, 2);
>     std::cout << f.get() << std::endl;
>     if (t.joinable()) t.join();
> }
> ```
>



### async

std::async 是一个函数模板，用于启动一个异步任务，并返回一个与该任务关联的 std::future 或 std::shared_future 对象，用于获取任务的结果，可以选择其内部自动创建个新的 thread 来执行（选择策略为 std::launch::async，即创建新线程并立即执行） 或 在调用线程中执行任务（选择策略为 std::launch::deferred，即在调用 std::future::get() 或 std::future::wait() 的线程中执行，即 延迟执行任务）。简化了代码编写。

```c++
// future from an async()
std::future<int>f2= std::async(std::launch::async, []{ return 8;}};

    auto f = std::async(
        std::launch::async,
        [](void) mutable -> uint32_t {
            std::this_thread::sleep_for(std::chrono::seconds(3));
            return 0;
        }
    );
    f.get(); // will block until thread of async exit, for "f.wait();" too
    // f.wait();

 	// 关于 std::chrono，可以用时现查，其方法比较多，也可以问 AI。

    // wait_for
    // auto f_state = f.wait_for(std::chrono::milliseconds(100));
    // if(f_state == std::future_status::ready) {
    //     // ...
    // }

    // wait_until
    // std::chrono::system_clock::time_point two_seconds_passed
    //     = std::chrono::system_clock::now() + std::chrono::seconds(2);
    // auto f_state = f.wait_until(two_seconds_passed);
    // if(f_state == std::future_status::timeout) {
    //     // ...
    // }
```

关于 async 返回 future 在析构的时候会阻塞直到线程函数执行完毕，为了不阻塞 async 后面的执行，两种写法来解：

1、搞个 全局的 future 变量来承接 async 的返回，在需要的地方对其 get 或 wait_for；

2、把 async 返回的 future 局部变量 用 std::thread t(...); t.detach(); 创建个专门线程，用  右值引用（std::move）的传参方式 传进去（future 生命周期就转移到 t 的线程函数里面），在里面对其 get 或 wait_for。

1 例程：

```c++
#include <chrono>
#include <cstdint>
#include <future>
#include <iostream>
#include <thread>

void test(void);
void test2(void);

static std::future<uint32_t> f_async;

int main(void)
{
    std::cout << " -------- main begin" << std::endl;
    test();
    test2();
    std::cout << " -------- main end" << std::endl;
}

void test(void)
{
    std::cout << " ------------------ test begin" << std::endl;

    f_async = std::async(
        std::launch::async,
        [](void) mutable -> uint32_t {
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            return 0;
        }
    );

    std::cout << " ------------------ test end" << std::endl;
    return;
}

void test2(void)
{
    std::cout << " ------------------ test2 begin" << std::endl;

    for(;;) {
        auto f_async_state = f_async.wait_for(std::chrono::milliseconds(100));
        if(f_async_state == std::future_status::timeout) {
            std::cout << " ... f_async wait_for 100 ms" << std::endl;
        } else if (f_async_state == std::future_status::ready) {
            std::cout << " ... f_async ready" << std::endl;
            break;
        }
    }

    std::cout << " ------------------ test2 end" << std::endl;
    return;
}

/* print:

 -------- main begin
 ------------------ test begin
 ------------------ test end
 ------------------ test2 begin
 ... f_async wait_for 100 ms
 ... f_async wait_for 100 ms
 ... f_async ready
 ------------------ test2 end
 -------- main end

*/
```

2 例程：

```c++
#include <chrono>
#include <cstdint>
#include <future>
#include <iostream>
#include <thread>

void test(void);

int main(void)
{
    std::cout << " -------- main begin" << std::endl;
    test();
    std::cout << " -------- main end" << std::endl;
}

void test(void)
{
    std::cout << " ------------------ test begin" << std::endl;

    std::future<uint32_t> f_async = std::async(
        std::launch::async,
        [](void) mutable -> uint32_t {
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            return 0;
        }
    );

    bool is_f_async_done = false;
    std::thread t_process_f_async(
        [&is_f_async_done](std::future<uint32_t>&& f_async) mutable -> void {
            for(;;) {
                auto f_async_state = f_async.wait_for(std::chrono::milliseconds(100));
                if(f_async_state == std::future_status::timeout) {
                    std::cout << " ... f_async wait_for 100 ms" << std::endl;
                } else if (f_async_state == std::future_status::ready) {
                    std::cout << " ... f_async ready" << std::endl;
                    is_f_async_done = true; // or call a callback fun
                    break;
                }
            }
        },
        std::move(f_async)
    );
    t_process_f_async.detach();

    for(;;){
        if(is_f_async_done) {
            std::cout << " ... is_f_async_done" << std::endl;
            break;
        }
    };

    std::cout << " ------------------ test end" << std::endl;
    return;
}
/* print:

 -------- main begin
 ------------------ test begin
 ... f_async wait_for 100 ms
 ... f_async wait_for 100 ms
 ... f_async ready
 ... is_f_async_done
 ------------------ test end
 -------- main end

*/
```

当然这两种可能不规范，还是软件工程要提前划分好子任务，线程间解耦。



### thread_local

参考 [c++11新特性，所有知识点都在这了！ - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/139515439) 里面 `thread_local` 一节。



> c++11引入thread_local，用thread_local修饰的变量具有thread周期，每一个线程都拥有并只拥有一个该变量的独立实例，一般用于需要保证线程安全的函数中。
>
> 一个线程私有变量，一个线程拥有且只拥有一个该实例，类似于static。



> ```c++
> #include <iostream>
> #include <thread>
> 
> class A {
>    public:
>     A() {}
>     ~A() {}
> 
>     void test(const std::string &name) {
>         thread_local int count = 0;
>         ++count;
>         std::cout << name << ": " << count << std::endl;
>     }
> };
> 
> void func(const std::string &name) {
>     A a1;
>     a1.test(name);
>     a1.test(name);
>     A a2;
>     a2.test(name);
>     a2.test(name);
> }
> 
> int main() {
>     std::thread(func, "thread1").join();
>     std::thread(func, "thread2").join();
>     return 0;
> }
> 
> /* 输出
> thread1: 1
> thread1: 2
> thread1: 3
> thread1: 4
> thread2: 1
> thread2: 2
> thread2: 3
> thread2: 4
> */
> ```



## 现代高性能并发编程

- [parallel101/course: 高性能并行编程与优化 - 课件 (github.com)](https://github.com/parallel101/course)。
- 更多可参考 `C-C++实用库备查` 里面的线程池等相关的 github 实现。
- 更多可参考 `C-C++实用库备查` 里面的 高并发 处理库，会用，善用。
- [深入理解C11/C++11内存模型(白嫖新知识~) - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/464207968)。



TODO 有待补充

event

epoll

一些 并发库，从 `C-C++实用库备查` 里面拿出来，写几个用例。



## C++ 标准库 / STL

参考 菜鸟教程、C 语言中文网等。这里只是罗列库函数，解决“都有什么”的问题，每一个 API 的具体用法需要用时现查。

很多可以用时现查，或者问 AI 工具，但是，知道 **都有什么** 很重要。



### C++ 的 以及参考

cpp 标准库 参考：这里是全的，可以时不时的刷刷看看。

里面的各种方法太多，所以**实际常问 AI 工具去写**，但是，还是要看一下 **都有什么**，知道用什么才更好，有方向性的去问 AI。

std 提供了很多实用 API 可以不必自己实现。

TODO：这里面的库的罗列，可以复制出来放下面

- [C++ 标准库 - cppreference.com](https://zh.cppreference.com/w/cpp/standard_library)。
- [C++ 标准库标头 - cppreference.com](https://zh.cppreference.com/w/cpp/header)。
- [C++ STL 教程 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-stl-tutorial.html)。
- [STL教程：C++ STL快速入门（非常详细） (biancheng.net)](http://c.biancheng.net/stl/)。
- [C++ Cheat Sheets & Infographics | hacking C++ (hackingcpp.com)](https://hackingcpp.com/cpp/cheat_sheets.html)。



库：



--

下面只是之前零碎整理，不全，但是删了又暂时不想删，先放着。



- fstream：文件操作库，用时现查即可。

  可参考 [C++ 文件和流 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-files-streams.html)。[C++文件操作 (biancheng.net)](http://c.biancheng.net/cplus/60/)。
  
  [文件系统库 - cppreference.com](https://zh.cppreference.com/w/cpp/experimental/fs)。
  
  fstream / ifstream / ofstream 的用法，各种方法 和 控制符。



- regex

  可参考 [正则表达式库 (C++11 起) - cppreference.com](https://zh.cppreference.com/w/cpp/regex)。

  一般，可以由 GPT 等工具生成来写。但是最好，正则表达式要懂一些。



- chrono
  - duration
  - time_point
  - clocks
    - steady_clock
    - system_clock
    - high_resolution_clock



- std::function

  类似于定义函数指针，但写法简单，用于承接 普通函数、模板函数、lambda、仿函数（类或结构图实现“()”的操作符重载）等

   [c++11新特性之std::function和lambda表达式 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/137884434)。

  [std::function详解-CSDN博客](https://blog.csdn.net/weixin_44378800/article/details/115210731)

  丰富用法例子 [std::function简介与使用 | 码农家园 (codenong.com)](https://www.codenong.com/cs105710781/)

  std::function 变量 比较 和 类的变量成员 [std::function对象比较的问题_std::function 比较-CSDN博客](https://blog.csdn.net/ability_555/article/details/119451100)



- std::bind

  [std::bind - cppreference.com](https://zh.cppreference.com/w/cpp/utility/functional/bind)

   [【C++】C++11的std::function和std::bind用法详解_c++11 新增了 std::function、std::bind-CSDN博客](https://blog.csdn.net/qq_38410730/article/details/103637778)。

  https://zh.cppreference.com/w/cpp/utility/functional/bind
  [C++11中的std::bind 简单易懂-CSDN博客](https://blog.csdn.net/Jxianxu/article/details/107382049)



- random

  > 可以选择概率分布类型。
  >
  > 整数均匀分布和浮点数均匀分布：
  >
  > ```c++
  > ...
  > std::default_random_engine random(time(nullptr));
  > 
  > std::uniform_int_distribution<int> int_dis(0, 100); // 整数均匀分布
  > std::uniform_real_distribution<float> real_dis(0.0, 1.0); // 浮点数均匀分布
  > 
  > for (int i = 0; i < 10; ++i) {
  >     cout << int_dis(random) << ' ';
  > }
  > cout << endl;
  > 
  > for (int i = 0; i < 10; ++i) {
  >     cout << real_dis(random) << ' ';
  > }
  > cout << endl;
  > ...
  > ```
  >
  > c++11 提供的概率分布类型还有好多，例如伯努利分布、正态分布等。



#### algorithm

参考 [算法库 - cppreference.com](https://zh.cppreference.com/w/cpp/algorithm)。

参考 [C++ Standard Library Algorithms Visual Overview | hacking C++ (hackingcpp.com)](https://hackingcpp.com/cpp/std/algorithms.html)。

- 搜索算法：find() 、search() 、count() 、find_if() 、find_if_not() 、search_if() 、count_if()

- 分类排序：sort() 、merge()

- 删除算法：unique() 、remove()

- 生成和变异：generate() 、fill() 、transformation() 、copy() 、copy_if()

- 关系算法：equal() 、min() 、max()

- 条件：all_of()、any_of()、none_of()

- minmax_element() 返回容器内 最大元素 和 最小元素 的 迭代器

- itoa() 对容器内的元素 逐个 递增 赋值

- is_sorted() 、is_sorted_until() 返回容器内元素是否已经排好序

- 等等



#### IO

参考 [输入/输出库 - cppreference.com](https://zh.cppreference.com/w/cpp/io)。



iostream

该文件定义了 **cin、cout、cerr** 和 **clog** 对象（**iostream** 类的实例），分别对应于标准输入流、标准输出流、非缓冲标准错误流 和 缓冲标准日志流。

使用 cerr 流来显示错误消息，而其他的日志消息则使用 clog 流来输出。



一些设置输出模式的 API（比如 设置/清除 左/右对齐、保留几位小数、科学计数法、16禁止输出，还有 iostream 中定义的操作符 等）：

参考 [C++ 基本的输入输出 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-basic-input-output.html)，[C++ cout格式化输出（超级详细） (biancheng.net)](http://c.biancheng.net/view/7578.html)。



也可以用 c 的标准输入输出 API 如 scanf()、printf()、getchar()、putchar() 等等。



sstream

各种类型和字符串类型的互转，以及逐个提取字符串（默认空格、回车分割）

[std::basic_stringstream - cppreference.com](https://zh.cppreference.com/w/cpp/io/basic_stringstream)

[C++之stringstream类-基本用法详解-CSDN博客](https://blog.csdn.net/zxy_ZXY123/article/details/136207246)



fstream

文件的流式访问
[std::basic_fstream - cppreference.com](https://zh.cppreference.com/w/cpp/io/basic_fstream)



std::quoted

C++14。[std::quoted - cppreference.com](https://zh.cppreference.com/w/cpp/io/manip/quoted)。

> 对字符串做转义，同时也支持自定义的转义符。

个人觉得不常用。



#### utility

参考 [工具库 - cppreference.com](https://zh.cppreference.com/w/cpp/utility)。

参考 [标准库标头  - cppreference.com](https://zh.cppreference.com/w/cpp/header/utility)。



std::bitset

[std::bitset - cppreference.com](https://zh.cppreference.com/w/cpp/utility/bitset)

可以替代所有 C 原生的 位运算操作，不容易出错



std::exchange

C++14。[std::exchange - cppreference.com](https://zh.cppreference.com/w/cpp/utility/exchange)。

> 作用是把第二个值赋值给第一个值，同时返回第一个值的旧值。
>
> exchange 的第二个值是 完美转发，是既可以接收左值，也可以接收右值。



std::integer_sequence

C++14。[std::integer_sequence - cppreference.com](https://zh.cppreference.com/w/cpp/utility/integer_sequence)。

人话参考：

- [【模板进阶】std::integer_sequence_integer sequence-CSDN博客](https://blog.csdn.net/Antonio915/article/details/143806938)。
- [【C++ 14 新特性 std__integer_sequence 】了解 std__integer_sequence 的使用 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/679456805)。



#### Math

参考 [数值库 - cppreference.com](https://zh.cppreference.com/w/cpp/numeric)。



Complex 复数库

[标准库标头  - cppreference.com](https://zh.cppreference.com/w/cpp/header/complex)



#### Memory

参考 [内存管理库 - cppreference.com](https://zh.cppreference.com/w/cpp/memory)。

参考 [低层内存管理 - cppreference.com](https://zh.cppreference.com/w/cpp/memory/new)。



std::launder

参考 [std::launder - cppreference.com](https://zh.cppreference.com/w/cpp/utility/launder)。

可参考 [C++笔记：尝试用人话解释std::launder - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/3218510623)。

> std::launder‌ 用于处理指针的生命周期和编译器优化问题。其主要作用是防止编译器对通过特定指针进行的操作进行优化，确保程序的运行结果符合预期。



### C 带来的

可以参考这里比较全的总结：

[coding-style-and-more/额外文档/各种C标准库详解和用例 at main · Staok/coding-style-and-more (github.com)](https://github.com/Staok/coding-style-and-more/tree/main/额外文档/各种C标准库详解和用例)。



--

下面只是之前零碎整理，不全，但是删了又暂时不想删，先放着。

- cmath：常用数学函数。

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

- ctime：时间和日期。

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

- cstdlib：

  rand()

  这个头文件里面还有很多方法

- cstring：与 c 的 string.h 大同小异。

  |      | cstring 库函数                                               |
  | ---- | ------------------------------------------------------------ |
  | 1    | strcpy(s1, s2);    复制字符串 s2 到字符串 s1。               |
  | 2    | strcat(s1, s2);    连接字符串 s2 到字符串 s1 的末尾。连接字符串（string 类型的）也可以用 **+** 号，例如: `string str1 = "runoob"; string str2 = "google"; string str = str1 + str2;` |
  | 3    | strlen(s1);    返回字符串 s1 的长度。                        |
  | 4    | strcmp(s1, s2);    如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；如果 s1>s2 则返回值大于 0。 |
  | 5    | strchr(s1, ch);    返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。 |
  | 6    | strstr(s1, s2);    返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。 |
  |      | ....                                                         |

