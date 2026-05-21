# C / C++ 实用库备查

网络参考源：

- [Your list / 实用库 / EE-CS (github.com)](https://github.com/stars/Staok/lists/实用库-ee-cs)。
- [你工作中最推荐的 C/C++ 程序库有哪些，为什么？ - 知乎 (zhihu.com)](https://www.zhihu.com/question/51134387)。可以不时的更新收录到下面。
- [可以使用 C++ 的哪些库或函数来简化任务？ - 知乎 (zhihu.com)](https://www.zhihu.com/question/639724149)。可以不时的更新收录到下面。
- [开源 C++ 库列表 - cppreference.com](https://zh.cppreference.com/w/cpp/links/libs)。这里面有一些比较老的，有些经典的。
- [fffaraz/awesome-cpp: A curated list of awesome C++ (or C) frameworks, libraries, resources, and shiny things. Inspired by awesome-... stuff. (github.com)](https://github.com/fffaraz/awesome-cpp)。超多，可以时不时看一看，更新收录到下面。
- [不容错过的 13 个顶级 C++ 程序库_c++库-CSDN博客](https://blog.csdn.net/IncrediBuild/article/details/130288032)。
- [分享给大家的c++常用库，建议收藏！ (baidu.com)](https://baijiahao.baidu.com/s?id=1670023811243394679)。

以下是自总结的平时用到的、好用的库和一些网络上推荐的库的集合。基本上，每个领域只推荐一个 或 两个 相关领域 最常用的、最主流的。排序不分先后。

下面会尽量挑选协议商用友好的库，基本可以直接拿来用的那种，但是可能不是所有库都是，所以要注意下所用库的协议。

欢迎在原文 [github](https://github.com/Staok/Cpp-Learning) / [gitee](https://gitee.com/staok/Cpp-Learning) 仓库 提 issue 指出错误，和 提 PR 来一同建设内容。 

~~每个库会尽量有这几个部分：自写的一段话简介（库所提供的基础能力概括）、项目网址（官网 或者 github 仓库网址 等）、网友写的一些比较好的入门教程、win 以及 linux 上的安装（保证方法具有普适性，必能跑通）、几段使用例子（由简单到复杂，是自己本地跑起来的自写的例子，以及指明官方提供的较系统的 demo 所在）。~~



有不少库可以在各大包管理平台找到，或者直接下载集成到自己的 cmake 工程 等中。



TODO：以下还缺少 ui、cv、ml 领域相关的库，好用的基本上也达成共识了，ui 框架的库可以看自己 git 收藏里面的；cv的 openCV 等等 看看还有什么；ml 的 无非 pytorch、tf、keras 等（这些有 C++ 接口，但最好还是 python 来开发）



综合贴

- [jobbole/awesome-cpp-cn: C++ 资源大全中文版，标准库、Web应用框架、人工智能、数据库、图片处理、机器学习、日志、代码分析等。由「开源前哨」和「CPP开发者」微信公号团队维护更新。](https://github.com/jobbole/awesome-cpp-cn)。
- [用于数据科学的顶级 C/C++ 机器学习库整理 - Xu_Lin - 博客园](https://www.cnblogs.com/isLinXu/p/16875279.html)。



## Scripts



Oh My Zsh

[ohmyzsh/ohmyzsh: 🙃 A delightful community-driven (with 2,400+ contributors) framework for managing your zsh configuration. Includes 300+ optional plugins (rails, git, macOS, hub, docker, homebrew, node, php, python, etc), 140+ themes to spice up your morning, and an auto-update tool that makes it easy to keep up with the latest updates from the community.](https://github.com/ohmyzsh/ohmyzsh)



vimrc

[amix/vimrc: The ultimate Vim configuration (vimrc)](https://github.com/amix/vimrc)



Git alias

[GitAlias/gitalias: Git alias commands for faster easier version control](https://github.com/GitAlias/gitalias)



Linux命令行与shell脚本编程大全案例

[fengyuhetao/shell: Linux命令行与shell脚本编程大全案例](https://github.com/fengyuhetao/shell)



gitignore

[github/gitignore: A collection of useful .gitignore templates](https://github.com/github/gitignore)



regex-vis

[Bowen7/regex-vis: 🎨 Regex visualizer & editor](https://github.com/Bowen7/regex-vis)

正则表达式可视化：[Regex Vis](https://regex-vis.com/)





## Misc

这里的几个库是综合性的，内涵丰富，但也比较重型，按需。



### introduce_c-cpp_manual

本repo搜集全网适合C/C++新手学习的入门项目，整理收纳开发者开源的小项目、工具、框架、游戏等，帮助大家更好地学习c/c++。

[0voice/introduce_c-cpp_manual: 一个收集C/C++新手学习的入门项目，整理收纳开发者开源的小项目、工具、框架、游戏等，视频，书籍，面试题/算法题，技术文章。 (github.com)](https://github.com/0voice/introduce_c-cpp_manual)。



### GUN

[软件 - GNU 工程 - 自由软件基金会](https://www.gnu.org/software/software.html#allgnupkgs)。



### glibc

即 GNU C Library，Linux 的标准 c 库（直接使用并编译，不用附带加载库），Linux 下原来的 标准 c 库 libc 逐渐不再被维护。



### boost c++

[Boost C++ Libraries](https://www.boost.org/)。

[The Boost C++ Libraries (theboostcpplibraries.com)](https://theboostcpplibraries.com/)。



### GLib

GLib is the low-level core library that forms the basis for projects such as GTK and GNOME. It provides data structure handling for C, portability wrappers, and interfaces for such runtime functionality as an event loop, threads, dynamic loading, and an object system.

[GNOME/glib: Read-only mirror of https://gitlab.gnome.org/GNOME/glib (github.com)](https://github.com/GNOME/glib)。



glib是GTK+的基础库，综合用途的实用的轻量级的C程序库

glib 相关，源码中有 docs 手册

GLib包含了字符串操作、文件操作、数据校验、编解码、字符集转换、随机数生成器、命令行解析器、xml解析器、正则表达式、单链表、双链表、 数组、指针数组、双端队列、哈希表、平衡二叉树、N维树、泛型、主循环、多线程、线程池、异步队列、内存分配、内存片段、错误系统、测试框架等等一系列功能，称得上是C语言开发人员的军刀，值得研究。

功能罗列 [GLib2.0的一百个小知识点 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/613083129)。

目录说明 [1_02_GLib库入门与实践_GLib库源代码目录结构简介_glib-2.0 库源码-CSDN博客](https://blog.csdn.net/field1003/article/details/123421451)。

系列文章 [GLib库入门与实践_field1003的博客-CSDN博客](https://blog.csdn.net/field1003/category_11680135.html)。



### dlib

Dlib is a modern C++ toolkit containing machine learning algorithms and tools for creating complex software in C++ to solve real world problems. See [http://dlib.net](http://dlib.net/) for the main project documentation and API reference.

[davisking/dlib: A toolkit for making real world machine learning and data analysis applications in C++ (github.com)](https://github.com/davisking/dlib)。

[推荐开源库：DLib - 解决C++编程中常见任务的实用工具集-CSDN博客](https://blog.csdn.net/gitblog_00081/article/details/139734646)。



### cpp-tbox

**C++ Treasure Box** is a service-oriented **development framework** and **component library** based on the Reactor model, aim at make C++ development easy.

[cpp-main/cpp-tbox: A complete Linux application software development tool library and runtime framework, aim at make C++ development easy. (github.com)](https://github.com/cpp-main/cpp-tbox)。



### ffead-cpp

ffead-cpp is a web-framework, application framework, utilities all bundled into one. It also provides an embedded HTTP/Web-Socket compliant high-performance server core. It is a collection of modules all geared towards performing individual roles which together form the cohesive back-bone of ffead-cpp.

It provides a very simple to use and maintain web-framework library with advanced features like Reflection, Dependency Injection (IOC), Inbuilt REST/SOAP support, Security/Authentication features. Moreover implementation for interfacing to caching tools like Memcached/Redis are provided in-built. Database integration/ORM framework (SDORM) solves all major issues with respect to interfacing with SQL/No-SQL database alike.

Multi-level serialization or template level serialization is a high point of ffead-cpp core serialization run-time. Any C++ POCO class can be marked as serializable and the run-time will take care of marshalling/un-marshalling the object to its intended serializable form and back(JSON/XML/BINARY).

ffead-cpp can be easily driven by XML configuration, Services/Controllers/Filters/Interfaces/API(s) are all simple POCO classes without any need for them to extend any classes. The differentiating feature in ffead-cpp is the usage/implementation/support for markers (Annotations in java). Simple **#pragma** directives can now be used to drive the entire configuration in ffead-cpp, so you can just forget XML configuration.

All in all ffead-cpp is the gap in the world of C++ web application or enterprise application development which I have tried to fill with my humble/honest effort.

[sumeetchhetri/ffead-cpp: Framework for Enterprise Application Development in c++, HTTP1/HTTP2/HTTP3 compliant, Supports multiple server backends (github.com)](https://github.com/sumeetchhetri/ffead-cpp)。



企业应用程序开发框架，综合多种功能。github 仍在更新。这是一个 C++ 的 Web 框架，C++ 应用程序框架，C++ 的 REST 框架和 C++ 的 SOAP 框架，这些框架都内置其中。它包含 Linux/Windows（通过 Cygwin）的实现。



### KDUtils

A set of C++ helpers and wrappers around the C++ standard library

内涵三个库：

- KDFoundation
- KDGui
- KDUtils

MIT 协议的，可商用，但要遵守协议的一些要求。[Where is the doc link? And is this lib free for commercial use or? · Issue #53 · KDAB/KDUtils (github.com)](https://github.com/KDAB/KDUtils/issues/53)。

[KDAB/KDUtils: A set of C++ helpers and wrappers around the C++ standard library (github.com)](https://github.com/KDAB/KDUtils)。



### Misc

JUCE：专注音频开发

LibU：C语言写的多平台工具库，可以看看。github 不怎么更新了

libPhenom：Facebook发布的C语言事件框架，用于构建高性能和高可扩展的系统。支持多线程、提供内存管理和常用数据结构，2019年停止维护，可以看看代码实现。替代品 folly。

LibSourcey：LGPL-2.1+，用于实时的视频流和高性能网络应用程序的C++11 evented IO，视作 libuv, FFmpeg, OpenCV and WebRTC 结合体。github 不怎么更新了

Ultimate++：C++跨平台快速应用程序开发框架，框架应该比较大，是个新领域，看需求吧



## Robotic



### pcl

常用点云处理库。

[PointCloudLibrary/pcl: Point Cloud Library (PCL)](https://github.com/PointCloudLibrary/pcl)。

参考：

- 官方文档 [Introduction — Point Cloud Library 0.0 documentation](https://pcl.readthedocs.io/projects/tutorials/en/latest/index.html)。

- https://blog.csdn.net/yangziluomu/article/details/82631123
- https://zhuanlan.zhihu.com/p/95679543
- PCL Visualization https://zhuanlan.zhihu.com/p/107419624
- PCL Filtering https://zhuanlan.zhihu.com/p/95983353



安装：

库很大，依赖很多，就不要本地编译了，直接用现成的：

- Ubuntu 上使用：
  - 直接安装 `sudo apt install libpcl-dev`。
- Win 上使用：必须使用 MSVC 的编译器进行链接库：
  - 下载 github 仓库的 release 的 `PCL-x.xx-AllInOne-msvc2022-win64.exe`，安装，勾上给当前用户添加路径到系统环境变量。

cmake 引入：[Using PCL in your own project — Point Cloud Library 0.0 documentation](https://pcl.readthedocs.io/projects/tutorials/en/latest/using_pcl_pcl_config.html#using-pcl-pcl-config)。



## Parallel / Async / Task framework



### parallel lib comparison table

这里需要再多一些信息来区分这些库

几个库的使用场景（使用 gpt）

> - **workflow** 适合需要并行计算和异步网络处理的复杂应用，尤其在分布式和高性能环境中。
>
> - **workspace** 更加适用于轻量级异步任务调度和并发执行，尤其在需要精细控制优先级和任务管理时。
>
> - **taskflow** 适合高效的任务调度系统，特别是有异构计算需求的场景（例如同时使用 CPU 和 GPU）。
>
>   官网测试 taskflow 比  oneTBB 更好
>
> - **oneTBB** 适合大规模并行计算和高效利用多核处理器的场景。
>
> - **Asio** 则专注于网络和 I/O 密集型任务，尤其是需要处理大量并发连接的应用。
>
>   libuv 和 asio 对比 见 `libuv` 一节。



因此进行 workflow、workspace、taskflow 三个库对比，说的很清晰了：

[对比 C++ 框架库 - 豆包](https://www.doubao.com/thread/w7d037517775ebe5e)。

这个给第一次接触这几个库的人看的，但是别全信，有臆想部分，整体表述还好，就先大概看一下有个印象进行初步判读那，然后具体每个库去看文档）



若你的业务需要 “网络交互 + 并行计算”（如异步网络微服务HTTP/RPC的并行处理、分布式任务调度）→ 优先看 workflow。

**workflow 即是有点大而全的网络库（http、redis、mysql、websocket和kafka等服务）、IO、任务流编排的库。开源协议为 Apache-2.0 license，比较友好。**



若你的业务是 “纯本地任务调度”（如本地工具类程序、对编译体积敏感的场景），且想少写代码 → 优先看 workspace。

**workspace 即是一个线程池，且具有多线程负载均衡，空闲快速响应机制等。开源协议为 Apache-2.0 license，比较友好。**

是个线程池，放到了后面 `ThreadPool lib` 小节里面。



若你的业务是 “复杂并行计算”（如计算密集型应用、复杂流程编排、异构计算场景（CPU 并行预处理 + GPU 加速计算）），甚至需要 GPU → 优先看 taskflow。

**taskflow 即是函数执行流程编排编程，可并行、顺序和分支，支持cuda，可以导出 dot 流程图。开源协议为 MIT。**



**workflow**

C++ Parallel Computing and Asynchronous Networking Framework

[sogou/workflow: C++ Parallel Computing and Asynchronous Networking Framework (github.com)](https://github.com/sogou/workflow)



[workflow这个C++开源项目值得学习 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/389396903)。

[workflow开源项目学习心得 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/467427315)。



开源项目Workflow中有一个非常重要的基础模块，代码仅300行的C语言线程池。

[一个逻辑完备的线程池 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/503733481)。



**taskflow ***

A General-purpose Task-parallel Programming System using Modern C++

Taskflow helps you quickly write parallel and heterogeneous task programs in modern C++

[taskflow/taskflow: A General-purpose Task-parallel Programming System using Modern C++ (github.com)](https://github.com/taskflow/taskflow)

[Taskflow: A General-purpose Task-parallel Programming System](https://taskflow.github.io/)。



**oneTBB**

oneAPI Threading Building Blocks (oneTBB)

[uxlfoundation/oneTBB: oneAPI Threading Building Blocks (oneTBB) (github.com)](https://github.com/uxlfoundation/oneTBB)。



[Intel Threading Building Blocks 之 并行循环_intel threading building blocks在哪里下载-CSDN博客](https://blog.csdn.net/plutus_sutulp/article/details/21445193)。

[SSE_TBB加速编程_Belial_2010的博客-CSDN博客](https://blog.csdn.net/kezunhai/category_3069039.html)。



**OpenMP**

并行计算库。



### Behavioral Tree libs



btsk

[BTSK 开源项目教程-CSDN博客](https://blog.csdn.net/gitblog_00923/article/details/141414404)。

[aigamedev/btsk: Behavior Tree Starter Kit](https://github.com/aigamedev/btsk)。



### Async lib



**Asio**

Asio C++ Library

Asio is a cross-platform C++ library for network and low-level I/O programming that provides developers with a consistent asynchronous model using a modern C++ approach.

[chriskohlhoff/asio: Asio C++ Library (github.com)](https://github.com/chriskohlhoff/asio)



Folly.ThreadPoolExecutor [folly/folly/executors/ThreadPoolExecutor.h at main · facebook/folly (github.com)](https://github.com/facebook/folly/blob/main/folly/executors/ThreadPoolExecutor.h)



libuv 和 asio 对比 见 `libuv` 一节。



### ThreadPool lib



**ThreadPool ***

A simple C++11 Thread Pool implementation

[progschj/ThreadPool: A simple C++11 Thread Pool implementation (github.com)](https://github.com/progschj/ThreadPool)



**workspace ***

workspace是基于C++11的轻量级异步执行框架，支持：通用任务异步并发执行、优先级任务调度、自适应动态线程池、高效静态线程池、异常处理机制等。

[CodingHanYa/workspace: workspace是基于C++11的轻量级异步执行框架，支持：通用任务异步并发执行、优先级任务调度、自适应动态线程池、高效静态线程池、异常处理机制等。 (github.com)](https://github.com/CodingHanYa/workspace)。



**dpool**

使用 C++11 实现的动态线程池，主要特性：

- 使用简单，不易出错。
- 支持线程复用，提升性能。
- 支持懒惰创建线程。
- 必要时自动回收空闲的线程。

[senlinzhan/dpool: 使用 C++11 实现的动态线程池 (github.com)](https://github.com/senlinzhan/dpool)



**CThreadPool**

`CThreadPool` 是一个跨平台的、无任何三方依赖的、高性能的C++11（含以上版本）版本的线程池，也是 [CGraph](https://github.com/ChunelFeng/CGraph) 项目中使用的跨平台线程池组件功能的最小集。

经过CGraph和关联项目的长期迭代和验证，功能已经趋于稳定，且性能优异。因为咨询相关内容的朋友较多，故做为独立的仓库提供出来，方便大家使用。

由于是CGraph项目中的剥离出来的功能类，故在项目中保留了多处 `CGRAPH_*` 的命名方式，仅将 namespace 修改为 `CTP`，预计今后与CGraph相互独立更新。

本项目参考了[《C++并发编程实战（第二版）》](https://nj.gitbooks.io/c/content/) 中的部分内容，和github上的一些优秀实现。并在此基础上进行大量的改动、扩展和优化，在功能、性能和易用性上均有较大的提升。

[ChunelFeng/CThreadPool: 【A simple used C++ threadpool】一个简单好用，性能优异的，跨平台的C++线程池。欢迎 star & fork (github.com)](https://github.com/ChunelFeng/CThreadPool)



### libfork *

高性能协程库。

[ConorWilliams/libfork: A bleeding-edge, lock-free, wait-free, continuation-stealing tasking library built on C++20's coroutines](https://github.com/ConorWilliams/libfork)。



### minicoro

协程库，比多线程切换负担小。

Minicoro is single-file library for using asymmetric coroutines in C. The API is inspired by [Lua coroutines](https://www.lua.org/manual/5.4/manual.html#6.2) but with C use in mind.

The project is being developed mainly to be a coroutine backend for the [Nelua](https://github.com/edubart/nelua-lang) programming language.

[edubart/minicoro: Single header stackful cross-platform coroutine library in pure C. (github.com)](https://github.com/edubart/minicoro)



## Sig-Slot



### libsigc++

libsigc++ (a.k.a. libsigcplusplus) implements a typesafe callback system for standard C++. It allows you to define signals and to connect those signals to any callback function, either global or a member function, regardless of whether it is static or virtual.

libsigc++ is used by gtkmm to wrap the GTK signal system. It does not depend on GTK or gtkmm.

sigc++-2.0 and sigc++-3.0 are different parallel-installable ABIs. This file describes sigc++-3.0.

[libsigcplusplus/libsigcplusplus: libsigc++ implements a typesafe callback system for standard C++. It allows you to define signals and to connect those signals to any callback function, either global or a member function, regardless of whether it is static or virtual. (github.com)](https://github.com/libsigcplusplus/libsigcplusplus)



官方手册 [libsigc++: libsigc++ Reference Manual (libsigcplusplus.github.io)](https://libsigcplusplus.github.io/libsigcplusplus/reference/html/)。



[Unix/C++--信号与槽机制的理解_c++ libsigcplusplus库-CSDN博客](https://blog.csdn.net/qq_38880380/article/details/103315219) 各种信号槽库的介绍
[信号槽库：sigslot.h和sigc++使用 - DoubleLi - 博客园 (cnblogs.com)](https://www.cnblogs.com/lidabo/p/7338260.html)



好用而且也是业界推荐的，但是比较重的一个库。个人觉得可用下面 KDBindings 替代。



### KDBindings *

Reactive programming & data binding in C++

From plain C++ you get:

- Signals + Slots.
- Properties templated on the contained type.
- Property bindings allowing reactive code to be written without having to do all the low-level, error prone plumbing by hand.
- Lazy evaluation of property bindings.
- No more broken bindings.
- Totally stand-alone "header-only" library. No heavy Qt dependency.
- Can still be used with Qt if you so wish.

[KDAB/KDBindings: Reactive programming & data binding in C++ (github.com)](https://github.com/KDAB/KDBindings)



RxCpp

The Reactive Extensions for C++ (**RxCpp**) is a library of algorithms for values-distributed-in-time. The [**Range-v3**](https://github.com/ericniebler/range-v3) library does the same for values-distributed-in-space.

[ReactiveX/RxCpp: Reactive Extensions for C++](https://github.com/ReactiveX/RxCpp)。





## FileSystem Watcher



### efsw *

**efsw** is a C++ cross-platform file system watcher and notifier.

**efsw** monitors the file system asynchronously for changes to files and directories by watching a list of specified paths, and raises events when a directory or file change.

**efsw** supports recursive directories watch, tracking the entire sub directory tree.

**efsw** currently supports the following platforms:

- Linux via [inotify](http://en.wikipedia.org/wiki/Inotify)
- Windows via [I/O Completion Ports](http://en.wikipedia.org/wiki/IOCP)
- macOS via [FSEvents](http://en.wikipedia.org/wiki/FSEvents) or [kqueue](http://en.wikipedia.org/wiki/Kqueue)
- FreeBSD/BSD via [kqueue](http://en.wikipedia.org/wiki/Kqueue)
- OS-independent generic watcher (polling the disk for directory snapshots and comparing them periodically)

[SpartanJ/efsw: efsw is a C++ cross-platform file system watcher and notifier. (github.com)](https://github.com/SpartanJ/efsw)



本地编译过后，编译产物 投放到 编译器根目录中，使用 如下 cmek 语句引入即可，然后程序里面 引入头文件 使用即可。

```cmake
find_package(efsw REQUIRED) # 这里面查找和执行编译产物 efswTargets.cmake

target_link_libraries(${PROJECT_NAME} PRIVATE
    efsw::efsw # 查看编译产物 efswTargets.cmake，里面通过 add_library() 创建了目标，因此这里引入该目标即可
)

# 在程序里面， 通过 #include "efsw/efsw.hpp" 引入 头文件。因为上面 cmake 里面没有 target_include_directories（），因此这里 头文件路径相对于 <编译器路径>/include
```



### fswatch

`fswatch` is a file change monitor that receives notifications when the contents of the specified files or directories are modified. `fswatch` implements several monitors:

- A monitor based on the *File System Events API* of Apple macOS.
- A monitor based on *kqueue*, a notification interface introduced in FreeBSD 4.1 (and supported on most *BSD systems, including macOS).
- A monitor based on the *File Events Notification* API of the Solaris kernel and its derivatives.
- **A monitor based on *inotify*, a Linux kernel subsystem that reports file system changes to applications.**
- **A monitor based on *ReadDirectoryChangesW*, a Microsoft Windows API that reports changes to a directory.**
- A monitor which periodically stats the file system, saves file modification times in memory, and manually calculates file system changes (which works anywhere `stat (2)` can be used).

`fswatch` should build and work correctly on any system shipping either of the aforementioned APIs.

[emcrisostomo/fswatch: A cross-platform file change monitor with multiple backends: Apple macOS File System Events, *BSD kqueue, Solaris/Illumos File Events Notification, Linux inotify, Microsoft Windows and a stat()-based backend. (github.com)](https://github.com/emcrisostomo/fswatch)



注意 分为 fswatch （bin 固件，命令行使用） 和 libfswatch（C/C++ 库），具体文档：
[fswatch - Documentation (emcrisostomo.github.io)](https://emcrisostomo.github.io/fswatch/doc/)。



msys2 目前（2025.5）只提供 fswatch 的 bin 包，没有提供 libfswatch 封装为 pkg 形式的库（但是提供了 库文件 .a（后来才发现））。



因为早期没有发现 msys2 提供了库，所以费劲自己手动编译，在 win 上：github 仓库下载最新 release 源码包：

libfswatch 可选 ./configure 的方式来编译库，具体查看文档。

- [fswatch/README.windows at master · emcrisostomo/fswatch (github.com)](https://github.com/emcrisostomo/fswatch/blob/master/README.windows)。
- [fswatch/README.gnu-build-system at master · emcrisostomo/fswatch (github.com)](https://github.com/emcrisostomo/fswatch/blob/master/README.gnu-build-system)。

首先确保这几个工具都在：

```bash
* Get the GNU Build System components:
    - [Autoconf] (>= v. 2.69).
    - [Automake]: (>= v. 1.14.1).
    - [Libtool]: (>= v. 2.4.2).
    - [Gettext]: (>= v. 0.19.4).
```

基本工具都在如 gcc/g++/make 等。

使用命令：注意指定下编译器，可以用绝对路径

```bash
./configure --prefix=<path/to/build> CC=gcc CXX=g++
make
make install
```

如果编译成功，然后把编译产物放到 工具链目录里面，使用 find_package / pkg-config 等在工程里面引入即可。



注意：目前编译有报错，自己编译暂时无解...详见 [Get compile err with fswatch-1.18.3, please have a watch of this · Issue #344 · emcrisostomo/fswatch (github.com)](https://github.com/emcrisostomo/fswatch/issues/344)。



===============================



柳暗花明：

发现了 MSYS2 里面 fswatch 包下载后，在 `<编译器路径>/lib` 文件夹下提供了 库文件 `liblibfswatch.dll.a`，且提供了头文件 `<编译器路径>/include/libfswatch`，由此直接 cmake 里面引入：

```cmake
target_link_libraries(${PROJECT_NAME} PRIVATE
    libfswatch
)
```

程序中引入头文件：`#include "libfswatch/..."`，分为 C 和 C++ 的 APIs，具体看官方使用手册：

1.17.1 版本：[fswatch: fswatch (emcrisostomo.github.io)](https://emcrisostomo.github.io/fswatch/doc/1.17.1/libfswatch.html/index.html)。

CPP APIs：[fswatch: C++ API (emcrisostomo.github.io)](https://emcrisostomo.github.io/fswatch/doc/1.17.1/libfswatch.html/cpp-api.html)。

C APIs：[fswatch: C API (emcrisostomo.github.io)](https://emcrisostomo.github.io/fswatch/doc/1.17.1/libfswatch.html/c-api.html)。

可以用了。

C API 简易测试程序：

```cpp
#include "libfswatch/c/libfswatch.h"

void my_callback(
    fsw_cevent const *const events, // events 数组，结构体
    const unsigned int event_num,   // event_num 表示 events 数组 的 大小
    void *data)
{
    (void)data;
    if(event_num >= 1 && events->flags_num >= 1) {
        printf("path: %s, flags: 1: %d",
                events[0]->path, events[0]->flags[0]); // 发生事件文件的路径，flags 数组
    }
}

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    FSW_STATUS ret = fsw_init_library();

    const FSW_HANDLE handle = fsw_init_session(windows_monitor_type); // 创建一个 monitor
    fsw_add_path(handle, "D:/toolchain");

    fsw_set_recursive(handle, true); // 打开递归子目录监控，默认不打开，即只监控第一层目录
    fsw_set_callback(handle, my_callback, nullptr); // 添加回调
    // fsw_set_latency(handle, 0); 默认会延迟再调用回调函数 1s（看 .h 里面的注释说明），这里设为 不延迟
    fsw_start_monitor(handle); // 阻塞在这里，直到调用 fsw_stop_monitor()，才返回，可以判断 fsw_start_monitor() 的返回值。

    return 0;
}

```



### inotify-cpp

**Inotify-cpp** is a C++ wrapper for linux inotify. It lets you watch for filesystem events on your filesystem tree. The following usage example shows the implementation of a simple filesystem event watcher for the commandline.

[erikzenker/inotify-cpp: A C++ interface for linux inotify (github.com)](https://github.com/erikzenker/inotify-cpp)



## Socket / IO poll / Async



### async lib comparison table

对比表（GPT生成）

| 特性           | **glib**                                                     | **libuv**                                                    | **libevent**                                                 | **libev**                                                    | libhv                                                        |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 开源协议       | LGPL-2.1-or-later                                            | MIT                                                          | [3-clause BSD](https://libevent.org/LICENSE.txt)             | BSD                                                          | BSD 3-Clause                                                 |
| **主要用途**   | 全功能框架，适合 GUI 和服务程序。<br />提供了事件循环的支持，核心模块是 `GMainLoop` 和 `GSource`。 <br />集成了多种高级工具：线程池、数据结构（如动态数组、链表、哈希表等）、消息队列和日志系统。 <br />可与 GTK+ 完美结合，用于 GUI 应用的事件处理。 | 跨平台异步 IO 和事件驱动。<br />支持事件循环（基于多种底层实现，如 epoll、kqueue、IOCP 等）。<br /> 提供多种异步 IO 操作：文件系统、网络 IO、DNS 解析等。 <br />内置线程池，用于执行耗时的任务（如文件操作）。 | 高效网络 IO。<br />支持高效的事件驱动模型，底层基于 epoll、kqueue、poll 等机制。 <br />支持定时器、信号和缓存机制（例如 `bufferevent`）。 <br />轻量化设计，但功能足够丰富。 | 极简事件驱动库。<br />提供极简的事件循环，支持底层 epoll、kqueue 等。 <br />专注于高效、轻量的事件处理。 <br />不包含复杂的附加功能，例如线程池或高级 IO 操作。 | 比libevent/libuv/asio更易用的网络库。<br />A c/c++ network library for developing TCP/UDP/SSL/HTTP/WebSocket/MQTT client/server. |
| **跨平台支持** | 较好（Windows 支持有限）                                     | 非常好                                                       | 好（支持 Windows）                                           | 较差（Windows 支持弱）                                       |                                                              |
| **线程支持**   | 多线程、线程池                                               | 多线程、线程池                                               | 不支持线程池                                                 | 不支持线程池                                                 |                                                              |
| **轻量程度**   | 较重                                                         | 中等                                                         | 轻量                                                         | 极轻                                                         |                                                              |
| **性能**       | 中等                                                         | 较高                                                         | 高                                                           | 最高                                                         |                                                              |
| **复杂性**     | 高                                                           | 中等                                                         | 中等                                                         | 低                                                           |                                                              |
| **支持场景**   | 过于庞大，可能会为轻量级项目引入不必要的复杂性。 <br />性能相较其他轻量级库（如 `libev`）可能稍低。 <br />更倾向于**桌面环境的开发**。<br />**构建基于 GTK+ 的 GUI 应用程序**。 <br />GNOME 项目的插件开发或扩展。 <br />需要丰富工具支持的非网络类应用程序。 | **跨平台支持好**，代码高度一致（尤其适用于 Windows 和 Linux 的统一开发）。<br />提供内置的线程池支持，适合处理复杂异步操作（如文件 IO）。 <br />构建跨平台的高性能**网络服务**或工具。 <br />需要线程池支持的复杂 IO 操作场景（如**文件操作、DNS 解析**等）。 | 不支持线程池或高级异步操作，需要额外实现。 <br />长期以来更新速度较慢，**社区活跃度比 `libuv` 和 `libev` 稍低。**<br /><br />构建高性能的网络服务或服务器。 <br />不需要线程池或其他附加功能的事件驱动应用。 <br />专注于**事件和 IO 模型的小型项目**。 | 功能相对单一，仅适用于事件驱动。<br />**Windows 支持不佳**（虽然可以通过兼容层解决）。<br />需要开发者自行实现线程池或复杂操作的支持。<br />需要极高性能的事件驱动应用程序。 <br />构建单线程、高效的网络服务器。 <br />**Linux 或 Unix 系统上的轻量级服务**。 |                                                              |



### libuv *

Cross-platform asynchronous I/O

libuv is a multi-platform support library with a focus on asynchronous I/O. It was primarily developed for use by [Node.js](http://nodejs.org/), but it's also used by [Luvit](http://luvit.io/), [Julia](http://julialang.org/), [uvloop](https://github.com/MagicStack/uvloop), and [others](https://github.com/libuv/libuv/blob/v1.x/LINKS.md).

- Full-featured event loop backed by epoll, kqueue, IOCP, event ports.
- Asynchronous TCP and UDP sockets
- Asynchronous DNS resolution
- Asynchronous file and file system operations
- File system events
- ANSI escape code controlled TTY
- IPC with socket sharing, using Unix domain sockets or named pipes (Windows)
- Child processes
- Thread pool
- Signal handling
- High resolution clock
- Threading and synchronization primitives

[libuv/libuv: Cross-platform asynchronous I/O (github.com)](https://github.com/libuv/libuv)



libuv 和 asio 对比：

如果需要跨平台支持、基础socket、轻量级的异步 I/O功能（如文件操作等），libuv 是一个不错的选择。对于复杂的网络编程需求（如 SSL、ICMP 支持）或需要与 C++ 标准库深度集成的项目，Boost.Asio（Asio库有独立使用版本） 更为适合。
实际我都看了，就跨平台和通用性，libuv的纯c库更好。使用额外的线程池等组件配合，就可以做到便捷的网络处理编程模型。



实现的监控事件类型：

需要注意不同平台的行为略有不同，尤其是 linux 和 win 的差异，多看手册，和试验，官方文档不一定对每一块细节有详细描述，或问 AI大模型（会搜集一些网友的测试结果）

**下面打 感叹号的 为个人认为比较重要的，而其他 比如 tty、pipe、file、thread、process 这种，用更容易跨平台的哪些 API 即可。**对于文件监控有专门的库，功能更强大，可见上面的 `FileSystem Watcher` 一节。

```c
！typedef struct uv_loop_s uv_loop_t;     // 基本 loop 句柄，可以用 uv 内部默认的一个 uv_default_loop()
！typedef struct uv_handle_s uv_handle_t; // 下面 各个具体提交异步事件 的 "基类" 句柄，可看 uv.h 里面的做法，下面的 uv_xxx_t 都可以 cast 到这个，然后用基础的 api 操作，一般不推荐，用 uv_xxx_ 对应的 API 操作即可。

// 每次事件循环 按照 idle、prepare、poll io、check、close cb、update loop time / tick、timers cb 等 顺序 执行被提交的 事件 cb
// 图示见 https://docs.libuv.org/en/v1.x/design.html#the-i-o-loop
typedef struct uv_idle_s uv_idle_t;
typedef struct uv_prepare_s uv_prepare_t;
typedef struct uv_check_s uv_check_t;

// 流相关 API，uv_tcp_t、uv_pipe_t 和 uv_tty_t 都是 uv_stream_t 的子类，前者可以转为 uv_stream_t 指针后 使用 uv_stream_t 的 收发 等 API
！typedef struct uv_stream_s uv_stream_t;

// 网络相关
！typedef struct uv_tcp_s uv_tcp_t; // 注意这个 TCP 只为 AF_INET 或 AF_INET6 模式
！typedef struct uv_udp_s uv_udp_t; // 有自己单独的 收发 handle 和 API，而不用 uv_stream_t
/*
tcp udp 网络编程 调用 API 顺序：

TCP 需要建立连接，进行可靠的双向通信。
TCP 模式 API 调用顺序：
server:

socket()
bind()
listen()、accept()
recv()、send()

client:

socket()
connect()
recv()、send()

—————————
UDP 不需要建立连接，适用于快速、低延迟的通信，但不保证可靠性。
UDP 模式 API 调用顺序：
server:

socket()
bind()
recvfrom()、sendto()

client:

socket()
recvfrom()、sendto()

*/

/*
严重注意，经过查询源码，这个 uv_tcp_t 内部定死了（如 uv_tcp_init()，uv_ip4_addr()（用于填写 ip 和 端口号 产生struct sockaddr_in* 再传给 uv_tcp_bind()））是必须使用 AF_INET 或者 AF_INET6（这俩都是专用于网络通讯），不能用 AF_UNIX（专用进程间通讯的，比前面的更快）；
如要用 AF_UNIX，则用 uv_pipe_t~，如下举例：
*/

/*
用于 AF_UNIX 的 API 调用顺序：

server:
uv_pipe_init()
uv_pipe_bind()
uv_listen()、uv_accept()
uv_read_start()、uv_write()

client:

uv_pipe_init()
uv_pipe_connect()
uv_read_start()、uv_write()

用于管道的 API：
uv_pipe() 创建一对匿名管道文件
uv_pipe_open() 打开
uv_read_start()、uv_write() 读写
*/

！typedef struct uv_pipe_s uv_pipe_t; // 类似于 unix 的 管道 / 命名管道，也可以用于 TCP 的 AF_INET 方式的 socket 进行 IPC~。即 uv_pipe_t 以及相关 API 是 libuv 中用于 命名管道（Named Pipe）或 UNIX 域套接字（UNIX Domain Socket） 的接口

typedef struct uv_tty_s uv_tty_t;   // 封装了 命令行 / 串口 读写 和 设置 的一些 系统 API，就是对 串口（设备文件） 或 常规文件 进行 流式 读写的，别用于其它。

// 用于 poll 一些 文件描述符 可读、可写 事件的，对于网络 推荐用 uv_tcp 和 uv_udp 而不是这个，对于文件则有 fs_event 或 fs_poll
typedef struct uv_poll_s uv_poll_t;

// 监视 文件 或 文件夹，event 使用系统的文件事件机制，poll 则是单纯的 每个事件循环对比 文件 stat 信息
typedef struct uv_fs_event_s uv_fs_event_t;
typedef struct uv_fs_poll_s uv_fs_poll_t;

typedef struct uv_timer_s uv_timer_t; // 造各定时器，每次 事件循环（1ms） 检查 并 跑回调，可设 启动延时（timeout 参数） 和 间隔时间（repeat 参数，ms）。

typedef struct uv_async_s uv_async_t; // 提交一个 cb， 调用 uv_async_send() 一次或多次后，下一个 事件循环 会 调用一次 cb

typedef struct uv_process_s uv_process_t; // 类似于 unix 的 进程管理
typedef struct uv_signal_s uv_signal_t;   // 类似于 unix 的 信号

// 如果 回调函数里面 运行超过一次时间循环周期 如 1ms，可以调用一下 uv_update_time(loop); 来更新 uv 内部 tick 计数（跟上绝对时间） 而为 本次循环后面可能的 回调函数 里面获取最新 tick 的需要。每次事件循环一轮后会自动内部更新 tick 的。按需用。
// 使用 uv_now(loop); 获取 uv 内部 tick 计数，只自增，且开始值随机，只能用于 时差 而不是 绝对时间，tick 如 1ms 周期自增。

```

另外 libuv 还有一些杂项功能，具体看 官方手册：

- [File system operations](https://docs.libuv.org/en/stable/fs.html)，封装了常用 文件IO 的 API，可以同步也可以异步操作。

- ！[Thread pool work scheduling](https://docs.libuv.org/en/stable/threadpool.html)，往 `libuv` 内部维护的一个线程池 里面 添加待执行函数，这个 线程池独立于 default_loop。

  > `int uv_queue_work(uv_loop_t *loop, uv_work_t *req, uv_work_cb work_cb, uv_after_work_cb after_work_cb)`
  >
  > Initializes a work request which will run the given work_cb in a thread from the threadpool. Once work_cb is completed, after_work_cb will be called on the loop thread.
  >
  > 注意：work_cb 在 libuv 内部线程池 运行，运行完之后，after_work_cb 在 loop 上运行！

  `libuv` 的线程池主要用于处理一些耗时的操作，比如文件系统操作（如读写文件）、`getaddrinfo` 和 `getnameinfo` 请求等，主线程（即事件循环线程）中分离出去，交给线程池中的线程来处理。这样可以避免阻塞事件循环线程，保持事件循环的高效性。一旦这些操作完成，线程池会通过事件循环通知主线程，继续后续的回调处理。线程池大小可以修改。

  绑定到 `default_loop` 的任务（如定时器事件）会在事件循环的线程中执行。

  要注意区分这个区别。

- ！[DNS utility functions](https://docs.libuv.org/en/stable/dns.html)， 有 API，从 网址 获取 IP（可用 uv_ip4_name() 或 uv_ip_name() 把 ip 数据结构体 转换为 字符串来显示），或 反之（可用 uv_ip4_addr() 把 ip 字符串 转为 数据结构体）

- [Shared library handling](https://docs.libuv.org/en/stable/dll.html#)，提供一些如 uv_dlopen、uv_dlclose 的函数。

- [Threading and synchronization utilities](https://docs.libuv.org/en/stable/threading.html)，类似 pthread API 的封装。

- ！[Miscellaneous utilities](https://docs.libuv.org/en/stable/misc.html)，有关 内存、系统、进程、网络 等的杂项 API。如 uv_interface_addresses() 获取自己的网络信息。

- ！[Metrics operations](https://docs.libuv.org/en/stable/metrics.html)，获取 loop 的 信息 如 当前事件数等。



官方例子

[libuv/docs/code at v1.x · libuv/libuv](https://github.com/libuv/libuv/tree/v1.x/docs/code)



手册

官网 [API documentation - libuv documentation](https://docs.libuv.org/en/stable/api.html)。

网络翻译 [luohaha/Chinese-uvbook: 翻译的libuv的中文教程 (github.com)](https://github.com/luohaha/Chinese-uvbook)



网文

[libuv和libev 异步I/O库的比较 - findumars - 博客园 (cnblogs.com)](https://www.cnblogs.com/findumars/p/7465291.html)

[简单对比 Libevent、libev、libuv-腾讯云开发者社区-腾讯云 (tencent.com)](https://cloud.tencent.com/developer/article/1683144)

[libuv：构建高性能网络应用的跨平台异步I/O库详解-CSDN博客](https://blog.csdn.net/LittleBoy_IT/article/details/138140241)



c++ wrap

[skypjack/uvw: Header-only, event based, tiny and easy to use libuv wrapper in modern C++ - now available as also shared/static library! (github.com)](https://github.com/skypjack/uvw)，比较全面的封装，但是封装很浅的一层，而且写的比较抽象..

[wlgq2/uv-cpp: libuv wrapper in C++11 /libuv C++11网络库 (github.com)](https://github.com/wlgq2/uv-cpp)，但是实现的功能有限。



基于libuv实现的C++11风格网络库。接口简洁，性能优越，做过业务压测，稳定线上运行。

[wlgq2/uv-cpp: libuv wrapper in C++11 /libuv C++11网络库 (github.com)](https://github.com/wlgq2/uv-cpp)



B站上也有很多相关视频。



一个文件监控的简单例子：在 win 上测试（VsCode + clangd + MSYS2 UCRT(mingw, libuv .etc)）

```c
#include <sys/stat.h>

#include <cerrno>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

#include <iostream>
#include <ostream>
#include <string>

#include <uv.h>

uv_fs_event_t fs_event;
uv_fs_poll_t fs_poll;

void on_fs_event(uv_fs_event_t *handle, const char *filename, int events, int status)
{
    (void)status;
    (void)filename; // just the file name str passed into "uv_fs_event_start()"

    char path[1024];
    size_t size = 1023;
    uv_fs_event_getpath(handle, path, &size); // the whole path and file name str
    path[size] = '\0';

    fprintf(stdout, "Change detected in %s: ", path);

    if (events & UV_RENAME) {
        fprintf(stdout, "renamed\n");
    } else if (events & UV_CHANGE) {
        fprintf(stdout, "changed\n");
    } else {
        fprintf(stdout, "happend what?\n");
    }

     // if the file changed name to others and change back, the uv_fs_event continues watch
}

void on_fs_pool (uv_fs_poll_t* handle,
    int status,
    const uv_stat_t* prev,
    const uv_stat_t* curr)
{
    (void)prev;
    if(status < 0) {
        printf("status < 0\n"); // file deleted / renamed or something
        // if the file changed name to others and change back, the uv_fs_pool continues watch
        // uv_fs_poll_stop(&fs_poll); no need stop, keep watching the file of the very name
        return;
    }

    char path[1024];
    size_t size = 1023;
    uv_fs_poll_getpath(handle, path, &size); // the whole path and file name str
    path[size] = '\0';

    printf("Change detected in %s: ", path);
    printf("%lld, %lld, %lld, %ld, %ld - ",
            curr->st_ino, curr->st_size, curr->st_uid, curr->st_birthtim.tv_sec, curr->st_mtim.tv_sec);
    printf("is dir or file: %d", S_ISDIR(curr->st_mode));
    printf("\n");
}

int main(void)
{
    std::cout << " ------------------ main begin" << std::endl;

    // both uv_fs_event and uv_fs_poll, for file can give some detail info
    // but for dir change, only know changed, but not know what changed

    uv_fs_event_init(uv_default_loop(), &fs_event); // this know file/dir changed by fs event
    uv_fs_event_start(&fs_event, on_fs_event,
        "D:/toolchain/text1.txt",
        UV_FS_EVENT_RECURSIVE);

    uv_fs_poll_init(uv_default_loop(), &fs_poll); // this know file/dir changed just by intervaly scan
    uv_fs_poll_start(&fs_poll, on_fs_pool,
        "D:/toolchain/text.txt",
        100 ); // the interval time in ms
    
    // 对应 uv_xxx_init()，使用 uv_close() 关闭，注意要用 close_cb 在里面释放掉相关的 uv_xxx_t 的指针（如果是申请的）而不能在调用 uv_close() 后里面释放该指针，因为 loop 里面 异步的进行资源释放后 调用 close_cb，在 close_cb 里面再释放 uv_xxx_t 的指针。

    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    uv_loop_close(uv_default_loop());

    std::cout << " ------------------ main end" << std::endl;
    return;
}
```



### libhv *

比libevent/libuv/asio更易用的网络库。A c/c++ network library for developing TCP/UDP/SSL/HTTP/WebSocket/MQTT client/server.

[ithewei/libhv: 🔥 比libevent/libuv/asio更易用的网络库。A c/c++ network library for developing TCP/UDP/SSL/HTTP/WebSocket/MQTT client/server. (github.com)](https://github.com/ithewei/libhv)

协议 BSD 3-Clause。



### libev

Full-featured high-performance event loop loosely modelled after libevent

[enki/libev: Full-featured high-performance event loop loosely modelled after libevent (github.com)](https://github.com/enki/libev)



### Libevent

[libevent](https://libevent.org/)

The *libevent* API provides a mechanism to execute a callback function when a specific event occurs on a file descriptor or after a timeout has been reached. Furthermore, *libevent* also support callbacks due to **signals** or regular **timeouts**.

*libevent* is meant to replace the event loop found in event driven network servers. An application just needs to call *event_dispatch()* and then add or remove events dynamically without having to change the event loop.

[libevent/libevent: Event notification library (github.com)](https://github.com/libevent/libevent)





### Webbench

[EZLippi/WebBench: Webbench是Radim Kolar在1997年写的一个在linux下使用的非常简单的网站压测工具。它使用fork()模拟多个客户端同时访问我们设定的URL，测试网站在压力下工作的性能，最多可以模拟3万个并发连接去测试网站的负载能力。官网地址:http://home.tiscali.cz/~cz210552/webbench.html](https://github.com/EZLippi/WebBench)。



## FSM



### HFSM2

High-Performance Hierarchical Finite State Machine Framework.

[andrew-gresyk/HFSM2: High-Performance Hierarchical Finite State Machine Framework](https://github.com/andrew-gresyk/HFSM2)。



官方手册参考：[Home · andrew-gresyk/HFSM2 Wiki](https://github.com/andrew-gresyk/HFSM2/wiki)。



### StateMachine

[endurodave/StateMachine: State Machine Design in C++](https://github.com/endurodave/StateMachine)。

C++，编程风格为 定义 事件 event 下 所有 状态 的 行为。

是定义状态的进入、转出要执行的动作。

至于在这个状态下需要loop的内容，可以另外地方去写，用标志位变量控制是否运转，在这个转台的转入和转出的执行回调函数里面设置和取消设置相应标志位即可做到。



用法习惯：

- 在 `StateMachine.h` 里面 打开 宏（不注释）`#define EXTERNAL_EVENT_NO_HEAP_DATA 1`。即改为 调用状态切换方法时候 外部传入 EventData 结构体 是 栈 分配的，StateMachine 库 内部 不自动 调用释放 这个。这么用省心，不用频繁 malloc/free。

- 可以修改一下 `FaultHandler()` 函数，当状态转换遇到 `CANNOT_HAPPEN` 时候会进入，比如在里面加打印 或 设置变量通知切换状态失败，或可去掉里面的阻塞，不必要。

  ```c
  void FaultHandler(const char* file, unsigned short line)
  {
  	// If you hit this line, it means one of the ASSERT macros failed.
  // #if WIN32
  //     DebugBreak();
  
  // 	assert(0);
  // #endif
  
      printf(" ================ FaultHandler: file: %s, line: %u ==================\n",
  		file, line
  	);
  
  	// while(1); do not use infinite loop here!!!
  }
  ```



例子：（AI 阅读源码后生成演示状态机库的所有特性，快速入门使用）

```c++
// Door.h
#ifndef _DOOR_H
#define _DOOR_H

/*
================================================================================
                            简单门控制状态机
================================================================================

状态机描述：
这是一个简单的门控制系统，演示状态机库的所有特性。
门可以开启、关闭、锁定、解锁，只需要钥匙即可操作。

状态转换图：
                                Lock()
                    ┌─────────────────────────────────────────┐
                    │                                         │
                    ▼                                         │
            ┌─────────────┐                                   │
            │   LOCKED    │                                   │
            │  (锁定状态)   │                                   │
            └─────────────┘                                   │
                    │                                         │
                 Unlock()                                     │
                    │                                         │
                    ▼                                         │
            ┌─────────────┐                                   │
        ┌──►│   CLOSED    │───────────────────────────────────┘
        │   │  (已关闭)    │                                   
        │   └─────────────┘                                   
        │           │                                        
        │      OpenDoor()                                     
        │           │                                         
        │           ▼                                         
        │   ┌─────────────┐                                   
        │   │  OPENING    │                                   
        │   │ (正在开启)   │                                   
        │   └─────────────┘                                   
        │           │                                         
        │        内部事件                                      
        │           │                                         
        │           ▼                                         
        │   ┌─────────────┐                                   
        │   │   OPENED    │                                   
        │   │  (已开启)    │                                   
        │   └─────────────┘                                   
        │           │                                         
        │      CloseDoor()                                    
        │           │                                         
        │           ▼                                         
        │   ┌─────────────┐                                   
        │   │  CLOSING    │                                   
        │   │ (正在关闭)   │                                   
        │   └─────────────┘                                   
        │           │                                         
        │        内部事件                                      
        │           │                                         
        └───────────┘                                         

状态说明：
- CLOSED (关闭状态): 门已关闭，可以开启或锁定
- OPENING (开启中状态): 门正在开启，完成后自动转到开启状态
- OPENED (已开启状态): 门已开启，用户可以通行
- CLOSING (关闭中状态): 门正在关闭，完成后自动转到关闭状态
- LOCKED (锁定状态): 门已锁定，需要钥匙解锁

特性演示：
- 状态函数：每个状态执行特定逻辑
- 守卫条件：检查基本操作条件
- 进入动作：进入状态时的初始化操作
- 退出动作：离开状态时的清理操作
- 内部事件：状态内部自动触发的转换
- 外部事件：客户端触发的状态转换
- 转换映射：声明式的状态转换表

================================================================================
*/

#include "StateMachine.h"
#include <string>

//============================================================================
// 事件数据类定义
//============================================================================

/// @brief 开门事件数据 - 简单的开门请求
class OpenDoorData : public EventData
{
public:
    std::string userName;    // 用户名（可选）

    OpenDoorData(const std::string& name = "User")
        : userName(name) {}
};

/// @brief 关门事件数据 - 简单的关门请求
class CloseDoorData : public EventData
{
public:
    bool forceClose;         // 是否强制关门

    CloseDoorData(bool force = false)
        : forceClose(force) {}
};

/// @brief 锁门事件数据 - 需要钥匙
class LockData : public EventData
{
public:
    bool hasKey;             // 是否有钥匙

    LockData(bool key = true)
        : hasKey(key) {}
};

/// @brief 解锁事件数据 - 需要钥匙
class UnlockData : public EventData
{
public:
    bool hasKey;             // 是否有钥匙

    UnlockData(bool key = true)
        : hasKey(key) {}
};

// 无数据事件的类型别名
typedef EventData NoEventData;

//============================================================================
// 简单门控制状态机类
//============================================================================

/// @brief 简单门控制状态机 - 演示状态机库的所有特性
class Door : public StateMachine
{
public:
    /// @brief 构造函数 - 初始化门的状态
    Door();

    /// @brief 析构函数
    virtual ~Door();

    //========================================================================
    // 外部事件接口 - 客户端调用这些方法来控制门
    //========================================================================

    /// @brief 开门事件 - 尝试开启门
    /// @param data 开门事件数据（栈分配，因为使用了EXTERNAL_EVENT_NO_HEAP_DATA）
    void OpenDoor(const OpenDoorData* data);

    /// @brief 关门事件
    void CloseDoor(const CloseDoorData* data);

    /// @brief 锁门事件
    void Lock(const LockData* data);

    /// @brief 解锁事件
    void Unlock(const UnlockData* data);

    //========================================================================
    // 状态查询接口
    //========================================================================

    /// @brief 检查门是否锁定
    bool isLocked() const { return m_isLocked; }

    /// @brief 检查门是否开启
    bool isOpened() { return GetCurrentState() == ST_OPENED; }

    /// @brief 打印当前状态信息
    void printStatus();

private:
    //========================================================================
    // 状态枚举 - 必须与状态映射顺序一致
    //========================================================================
    enum States
    {
        ST_CLOSED = 0,       // 0 - 关闭状态
        ST_OPENING,          // 1 - 开启中状态
        ST_OPENED,           // 2 - 已开启状态
        ST_CLOSING,          // 3 - 关闭中状态
        ST_LOCKED,           // 4 - 锁定状态
        ST_MAX_STATES        // 状态总数
    };

    //========================================================================
    // 私有成员变量
    //========================================================================
    bool m_isLocked;                 // 门锁状态

    //========================================================================
    // 状态函数声明 - 使用STATE_DECLARE宏
    //========================================================================
    STATE_DECLARE(Door, Closed, NoEventData)
    STATE_DECLARE(Door, Opening, OpenDoorData)
    STATE_DECLARE(Door, Opened, NoEventData)
    STATE_DECLARE(Door, Closing, CloseDoorData)
    STATE_DECLARE(Door, Locked, NoEventData)

    //========================================================================
    // 守卫条件声明 - 使用GUARD_DECLARE宏（仅保留基本的锁定检查）
    //========================================================================
    GUARD_DECLARE(Door, CanLock, LockData)            // 进入 LOCKED 状态前 检查 是否可以锁门

    //========================================================================
    // 进入动作声明 - 使用ENTRY_DECLARE宏
    //========================================================================
    ENTRY_DECLARE(Door, OpeningEntry, OpenDoorData)   // 开门状态进入动作
    ENTRY_DECLARE(Door, ClosingEntry, CloseDoorData)  // 关门状态进入动作

    //========================================================================
    // 退出动作声明 - 使用EXIT_DECLARE宏
    //========================================================================
    EXIT_DECLARE(Door, OpeningExit)                   // 开门状态退出动作
    EXIT_DECLARE(Door, ClosingExit)                   // 关门状态退出动作

    //========================================================================
    // 辅助方法
    //========================================================================

    /// @brief 获取状态名称字符串
    std::string getStateName(int state) const;

    //========================================================================
    // 扩展状态映射 - 简化版本，展示主要特性
    //========================================================================
    BEGIN_STATE_MAP_EX
        // 进入状态的函数, 守卫条件, 进入动作, 退出动作
        STATE_MAP_ENTRY_ALL_EX(&Closed,  NULL,      NULL,           NULL)           // CLOSED
        STATE_MAP_ENTRY_ALL_EX(&Opening, NULL,      &OpeningEntry,  &OpeningExit)   // OPENING
        STATE_MAP_ENTRY_ALL_EX(&Opened,  NULL,      NULL,           NULL)           // OPENED
        STATE_MAP_ENTRY_ALL_EX(&Closing, NULL,      &ClosingEntry,  &ClosingExit)   // CLOSING
        STATE_MAP_ENTRY_ALL_EX(&Locked,  &CanLock,  NULL,           NULL)           // LOCKED
    END_STATE_MAP_EX
};

#endif // _DOOR_H

// Door.cpp ===========================================================================================
#include "Door.h"
#include <iostream>

//============================================================================
// 构造函数和析构函数
//============================================================================

Door::Door() : StateMachine(ST_MAX_STATES, ST_CLOSED)
{
    m_isLocked = false;
    std::cout << "Door::Door() - 门系统已初始化，当前状态：关闭" << std::endl;
}

Door::~Door()
{
    std::cout << "Door::~Door() - 门系统已关闭" << std::endl;
}

//============================================================================
// 外部事件实现 - 使用转换映射宏
//============================================================================

void Door::OpenDoor(const OpenDoorData* data)
{
    std::cout << "Door::OpenDoor() - 用户：" << data->userName << std::endl;

    BEGIN_TRANSITION_MAP                                   // 当前状态
        TRANSITION_MAP_ENTRY(ST_OPENING)                  // CLOSED -> OPENING
        TRANSITION_MAP_ENTRY(EVENT_IGNORED)               // OPENING -> 忽略
        TRANSITION_MAP_ENTRY(EVENT_IGNORED)               // OPENED -> 忽略
        TRANSITION_MAP_ENTRY(EVENT_IGNORED)               // CLOSING -> 忽略
        TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)               // LOCKED -> 错误
    END_TRANSITION_MAP(data)
}

void Door::CloseDoor(const CloseDoorData* data)
{
    std::cout << "Door::CloseDoor() - 强制关闭：" << (data->forceClose ? "是" : "否") << std::endl;

    BEGIN_TRANSITION_MAP                                   // 当前状态
        TRANSITION_MAP_ENTRY(EVENT_IGNORED)               // CLOSED -> 忽略
        TRANSITION_MAP_ENTRY(ST_CLOSING)                  // OPENING -> CLOSING
        TRANSITION_MAP_ENTRY(ST_CLOSING)                  // OPENED -> CLOSING
        TRANSITION_MAP_ENTRY(EVENT_IGNORED)               // CLOSING -> 忽略
        TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)               // LOCKED -> 错误
        /*
            注意：
            CANNOT_HAPPEN tells the state engine to fault. This abnormal catastrophic failure condition is never supposed to occur.
            一旦调用到 CANNOT_HAPPEN 则 库内部 crash！
        */
    END_TRANSITION_MAP(data)
}

void Door::Lock(const LockData* data)
{
    std::cout << "Door::Lock() - 有钥匙：" << (data->hasKey ? "是" : "否") << std::endl;

    BEGIN_TRANSITION_MAP                                   // 当前状态
        TRANSITION_MAP_ENTRY(ST_LOCKED)                   // CLOSED -> LOCKED
        TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)               // OPENING -> 错误
        TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)               // OPENED -> 错误
        TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)               // CLOSING -> 错误
        TRANSITION_MAP_ENTRY(EVENT_IGNORED)               // LOCKED -> 忽略
    END_TRANSITION_MAP(data)
}

void Door::Unlock(const UnlockData* data)
{
    std::cout << "Door::Unlock() - 有钥匙：" << (data->hasKey ? "是" : "否") << std::endl;

    BEGIN_TRANSITION_MAP                                   // 当前状态
        TRANSITION_MAP_ENTRY(EVENT_IGNORED)               // CLOSED -> 忽略
        TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)               // OPENING -> 错误
        TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)               // OPENED -> 错误
        TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)               // CLOSING -> 错误
        TRANSITION_MAP_ENTRY(ST_CLOSED)                   // LOCKED -> CLOSED
    END_TRANSITION_MAP(data)
}

//============================================================================
// 状态函数实现 - 使用STATE_DEFINE宏
//============================================================================

STATE_DEFINE(Door, Closed, NoEventData)
{
    std::cout << "Door::ST_Closed() - 门已关闭，安全状态" << std::endl;
    m_isLocked = false;
}

STATE_DEFINE(Door, Opening, OpenDoorData)
{
    std::cout << "Door::ST_Opening() - 门正在开启中，用户：" << data->userName << std::endl;

    // 模拟开门过程
    std::cout << "  启动门控电机..." << std::endl;
    std::cout << "  开门完成，转换到开启状态" << std::endl;

    // 触发内部事件转换到开启状态
    InternalEvent(ST_OPENED, new NoEventData());

    /*
        ExternalEvent()
        外部事件：由状态机外部调用
        用于响应外部刺激（如用户输入、传感器信号、网络消息等）
        通常在状态机的公共接口函数中调用

        InternalEvent()
        内部事件：由状态机内部调用
        在状态函数执行过程中生成，用于状态间的自动转换
        只能在状态函数、守卫函数、进入/退出动作中调用
    */
}

STATE_DEFINE(Door, Opened, NoEventData)
{
    std::cout << "Door::ST_Opened() - 门已完全开启，可以通行" << std::endl;
}

STATE_DEFINE(Door, Closing, CloseDoorData)
{
    std::cout << "Door::ST_Closing() - 门正在关闭中，强制：" << (data->forceClose ? "是" : "否") << std::endl;

    // 模拟关门过程
    std::cout << "  启动关门电机..." << std::endl;

    if (data->forceClose) {
        std::cout << "  强制关门模式" << std::endl;
    }

    std::cout << "  关门完成，转换到关闭状态" << std::endl;

    // 触发内部事件转换到关闭状态
    InternalEvent(ST_CLOSED, new NoEventData());
}

STATE_DEFINE(Door, Locked, NoEventData)
{
    std::cout << "Door::ST_Locked() - 门已锁定，安全级别最高" << std::endl;
    m_isLocked = true;
}//============================================================================
// 守卫条件实现 - 使用GUARD_DEFINE宏
//============================================================================

GUARD_DEFINE(Door, CanLock, LockData)
{
    std::cout << "Door::GD_CanLock() - 检查锁门条件..." << std::endl;

    // 简单检查：需要钥匙且门处于关闭状态
    if (!data->hasKey) {
        std::cout << "  需要钥匙才能锁门" << std::endl;
        return FALSE;
    }

    // if (GetCurrentState() != ST_CLOSED) { no need
    //     std::cout << "  只有关闭状态才能锁定" << std::endl;
    //     return FALSE;
    // }

    std::cout << "  锁门条件满足" << std::endl;
    return TRUE;
}

//============================================================================
// 进入动作实现 - 使用ENTRY_DEFINE宏
//============================================================================

ENTRY_DEFINE(Door, OpeningEntry, OpenDoorData)
{
    std::cout << "Door::EN_OpeningEntry() - 准备开门操作，用户：" << data->userName << std::endl;
}

ENTRY_DEFINE(Door, ClosingEntry, CloseDoorData)
{
    std::cout << "Door::EN_ClosingEntry() - 准备关门操作，强制否？- " << (data->forceClose ? "是" : "否") << std::endl;
}

//============================================================================
// 退出动作实现 - 使用EXIT_DEFINE宏
//============================================================================

EXIT_DEFINE(Door, OpeningExit)
{
    std::cout << "Door::EX_OpeningExit() - 完成开门操作" << std::endl;
}

EXIT_DEFINE(Door, ClosingExit)
{
    std::cout << "Door::EX_ClosingExit() - 完成关门操作" << std::endl;
}

//============================================================================
// 辅助方法实现
//============================================================================

std::string Door::getStateName(int state) const
{
    switch (state) {
        case ST_CLOSED:  return "关闭";
        case ST_OPENING: return "开启中";
        case ST_OPENED:  return "已开启";
        case ST_CLOSING: return "关闭中";
        case ST_LOCKED:  return "锁定";
        default:         return "未知";
    }
}

void Door::printStatus()
{
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "门状态报告" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    std::cout << "当前状态: " << getStateName(GetCurrentState()) << " (" << (int)GetCurrentState() << ")" << std::endl;
    std::cout << "锁定状态: " << (m_isLocked ? "已锁定" : "未锁定") << std::endl;
    std::cout << std::string(50, '=') << std::endl;
}

// main.cpp ===========================================================================================
#include "Door.h"
#include <iostream>

using namespace std;

// 辅助函数：打印分隔线
void printSeparator() {
    cout << string(50, '=') << endl;
}

int main()
{
    cout << "🚪 简单门控制状态机演示" << endl;
    printSeparator();

    Door door;
    door.printStatus();

    // 演示1：基本开关门流程
    cout << "\n🔸 开门..." << endl;
    OpenDoorData openData("用户");
    door.OpenDoor(&openData);
    door.printStatus();

    cout << "\n🔸 关门..." << endl;
    CloseDoorData closeData(false);
    door.CloseDoor(&closeData);
    door.printStatus();

    // 演示2：锁定和解锁
    cout << "\n🔸 锁门（有钥匙）..." << endl;
    LockData lockData(true);
    door.Lock(&lockData);
    door.printStatus();

    cout << "\n🔸 锁定状态下尝试开门（因为是 CANNOT_HAPPEN，所以程序应该 crash 嘿嘿嘿）..." << endl;
    OpenDoorData lockedOpenData("测试用户");
    door.OpenDoor(&lockedOpenData);

    cout << "\n🔸 解锁..." << endl;
    UnlockData unlockData(true);
    door.Unlock(&unlockData);
    door.printStatus();

    // 演示3：守卫条件测试
    cout << "\n🔸 无钥匙尝试锁门（守卫条件阻止）..." << endl;
    LockData noKeyData(false);
    door.Lock(&noKeyData);
    cout << "  ℹ️  锁门被守卫条件阻止" << endl;
    door.printStatus();

    cout << "\n✅ 演示完成！展示了状态函数、守卫条件、进入/退出动作、内部/外部事件" << endl;
    printSeparator();

    return 0;
}

```



### UML State Machine in C

[kiishor/UML-State-Machine-in-C: A minimalist UML State machine framework for finite state machine and hierarchical state machine in C](https://github.com/kiishor/UML-State-Machine-in-C)

C 语言，轻量级（可用于 mcu），表格化构建状态机，支持层级状态机。



### stateMachine

[misje/stateMachine: A feature-rich, yet simple finite state machine (FSM) implementation in C](https://github.com/misje/stateMachine)

C 语言，简易简陋超轻量状态机，可用于 mcu。



### TinyFSM

[digint/tinyfsm: A simple C++ finite state machine library](https://github.com/digint/tinyfsm)

C++ 风格浓烈，与 类模板 等 写法 强耦合，一些 API 可能会不太直观。



## HTTP



可优先 C 库，C 库 可应用的平台比 C++ 更广泛一些。

若资源受限或需嵌入式部署，选择 Mongoose 或 libcurl。



### cinatra

[qicosmos/cinatra: C++20 实现的跨平台、header only，易用的高性能http库; modern c++(c++20), cross-platform, header-only, easy to use http framework](https://github.com/qicosmos/cinatra)



### curl

libcurl is the library curl is using to do its job. It is readily available to be used by your software. Read [the libcurl manpage](https://curl.se/libcurl/c/libcurl.html) to learn how.

[curl/curl: A command line tool and library for transferring data with URL syntax, supporting DICT, FILE, FTP, FTPS, GOPHER, GOPHERS, HTTP, HTTPS, IMAP, IMAPS, LDAP, LDAPS, MQTT, POP3, POP3S, RTMP, RTMPS, RTSP, SCP, SFTP, SMB, SMBS, SMTP, SMTPS, TELNET, TFTP, WS and WSS. libcurl offers a myriad of powerful features (github.com)](https://github.com/curl/curl)



### drogon

[drogonframework/drogon: Drogon: A C++14/17/20 based HTTP web application framework running on Linux/macOS/Unix/Windows](https://github.com/drogonframework/drogon)

Drogon: A C++14/17/20 based HTTP web application framework running on Linux/macOS/Unix/Windows



### Mongoose

Mongoose - Embedded Web Server / Embedded Network Library

Mongoose is a network library for C/C++. It provides event-driven non-blocking APIs for TCP, UDP, HTTP, WebSocket, MQTT, and other protocols. It is designed for connecting devices and bringing them online.

- Cross-platform:
  - works on Linux/UNIX, MacOS, Windows, Android
  - works on ST, NXP, ESP32, Nordic, TI, Microchip, Infineon, Renesas and other chips
  - write code once - and it'll work everywhere
  - ideal for the unification of the network infrastructure code across company
- Built-in protocols: plain TCP/UDP, SNTP, HTTP, MQTT, Websocket, and other
- Asynchronous DNS resolver
- Tiny static and run-time footprint
- Source code is both ISO C and ISO C++ compliant
- Easy to integrate: just copy [mongoose.c](https://raw.githubusercontent.com/cesanta/mongoose/master/mongoose.c) and [mongoose.h](https://raw.githubusercontent.com/cesanta/mongoose/master/mongoose.h) files to your source tree
- Built-in TCP/IP stack with drivers for bare metal or RTOS systems
  - Available drivers: STM32F, STM32H; NXP RT1xxx; TI TM4C; Microchip SAME54; Wiznet W5500
  - A complete Web device dashboard on bare metal ST Nucleo boards is only 6 files
  - For comparison, a CubeIDE generated HTTP example is 400+ files
- Can run on top of an existing TCP/IP stack with BSD API, e.g. lwIP, Zephyr, Azure, etc
- Built-in TLS 1.3 ECC stack. Also can use external TLS libraries - mbedTLS, OpenSSL, or other
- Does not depend on any other software to implement networking
- Built-in firmware updates for STM32 H5, STM32 H7

See https://mongoose.ws/ for complete documentation, videos, case studies, etc.

[cesanta/mongoose: Embedded web server, with TCP/IP network stack, MQTT and Websocket (github.com)](https://github.com/cesanta/mongoose)



### LibHTTP

The project mission is to provide easy to use, powerful, C/C++ embeddable web server with IPv6, CGI and SSL support. LibHTTP has a MIT license so you can innovate without restrictions.

LibHTTP can be used by developers as a library to add web server functionality to an existing application. It can also be used by end users as a stand-alone web server. It is available as single executable, no installation is required.

LibHTTP is a fork of the Mongoose (MIT)/Civetweb family of http server libraries with the focus on event driven efficient communication, clean code and good documentation.

[lammertb/libhttp: Multi platform HTTP and HTTPS library (github.com)](https://github.com/lammertb/libhttp)



### TinyWebServer

Linux下C++轻量级WebServer服务器

[qinguoyi/TinyWebServer: :fire: Linux下C++轻量级WebServer服务器 (github.com)](https://github.com/qinguoyi/TinyWebServer)



### cpp-httplib

A C++ header-only HTTP/HTTPS server and client library

[yhirose/cpp-httplib: A C++ header-only HTTP/HTTPS server and client library (github.com)](https://github.com/yhirose/cpp-httplib)



cpp-httplib 可跨平台

[C++第三方库 【HTTP/HTTPS】— httplib库-CSDN博客](https://blog.csdn.net/m0_72563041/article/details/139184349)。

[C++ 跨平台轻量级服务器框架httplib_c++ 服务端框架-CSDN博客](https://blog.csdn.net/weixin_42627407/article/details/144050478)。



### Monkey HTTP Server

Monkey HTTP Server

[monkey/monkey: Monkey HTTP Server (github.com)](https://github.com/monkey/monkey)



### CppNet

Cppnet is a proactor mode and multithreaded network with C++11 on tcp. Support Window, Linux and macOS.

- `Simple`:
  - Only export a little interfaces, all net io insterface are asynchronous callbacks
  - Insterface as much as possible like calling the socket API of the system
  - There is only one additional buffer interface for the client
  - Support both IPv4 and IPv6
- `Fast`:
  - Use epoll, [wepoll](https://github.com/piscisaureus/wepoll) and kqueue
  - Multithreaded threads are handled by the kernel
  - Each socket has a single memory pool object. All memory requested from the memory pool is managed by an intelligent pointer
  - Using time wheel to realize timer
- `Clear`:
  - Three layers: event-driven layer, session management layer and interface layer
  - Upward notification through callbacks between layers. Clear division of responsibilities among modules, pay to Caesar what belongs to Caesar and God what belongs to God
  - The interface decoupling module is used to meet the minimum interface principle and dependency inversion principle

[caozhiyi/CppNet: Cross platform network library with C++11 (github.com)](https://github.com/caozhiyi/CppNet)



### Tinyhttpd

Tinyhttpd 是J. David Blackstone在1999年写的一个不到 500 行的超轻量型 Http Server，用来学习非常不错，可以帮助我们真正理解服务器程序的本质。官网:[http://tinyhttpd.sourceforge.net](http://tinyhttpd.sourceforge.net/)

[EZLippi/Tinyhttpd: Tinyhttpd 是J. David Blackstone在1999年写的一个不到 500 行的超轻量型 Http Server，用来学习非常不错，可以帮助我们真正理解服务器程序的本质。官网:http://tinyhttpd.sourceforge.net (github.com)](https://github.com/EZLippi/Tinyhttpd)



## Data / Log / Format



### Format / Protocol



#### format string



fmt

{fmt} is an open-source formatting library providing a fast and safe alternative to C stdio and C++ iostreams.

[fmtlib/fmt: A modern formatting library (github.com)](https://github.com/fmtlib/fmt)



inja

看看例子就知道做什么的了，还是挺花里胡哨的，对于一些自定义格式的解析挺方便。

Inja is a template engine for modern C++, loosely inspired by [jinja](http://jinja.pocoo.org/) for python. It has an easy and yet powerful template syntax with all variables, loops, conditions, includes, callbacks, and comments you need, nested and combined as you like. Of course, everything is tested in CI on all relevant compilers.

[pantor/inja: A Template Engine for Modern C++ (github.com)](https://github.com/pantor/inja)



#### url parser



Ada-url*

Ada is a fast and spec-compliant URL parser written in C++. Specification for URL parser can be found from the [WHATWG](https://url.spec.whatwg.org/#url-parsing) website.

The Ada library passes the full range of tests from the specification, across a wide range of platforms (e.g., Windows, Linux, macOS). It fully supports the relevant [Unicode Technical Standard](https://www.unicode.org/reports/tr46/#ToUnicode).

[Introduction - Ada URL (ada-url.com)](https://www.ada-url.com/introduction/)。

[ada-url/ada: WHATWG-compliant and fast URL parser written in modern C++, part of Node.js, Clickhouse, Redpanda, Kong, Telegram and Cloudflare Workers. (github.com)](https://github.com/ada-url/ada)



#### MQTT lib



#### MQTT lib comparison table

- 选择 paho.mqtt.c：如果你需要全面的 MQTT 功能支持（如 MQTT 5.0）、跨平台兼容性和较强的社区支持，特别是当你的应用需要较复杂的消息管理时，`paho.mqtt.c` 是一个优秀的选择。
- 选择 MQTT-C：如果你的应用资源受限，或者你需要一个简单、轻量的 MQTT 客户端库来快速集成，`MQTT-C` 会是一个理想选择，特别适用于嵌入式设备。
- 选择 Mosquitto：如果你已经在使用 Mosquitto 作为 Broker，或者你需要一个既能作为 Broker 又能作为客户端使用的方案，那么使用 Mosquitto 提供的客户端库会更方便，尤其是在搭建全套 MQTT 系统时。



**MQTT 服务端和客户端快速搭建**

[MQTT教程--服务器使用EMQX和客户端使用MQTTX_mqttx使用-CSDN博客](https://blog.csdn.net/weixin_39291021/article/details/140147976)。



Paho.mqtt.c *

This repository contains the source code for the [Eclipse Paho](http://eclipse.org/paho) MQTT C client library.

This code builds libraries which enable applications to connect to an [MQTT](http://mqtt.org/) broker to publish messages, and to subscribe to topics and receive published messages.

Synchronous and various asynchronous programming models are supported.

[eclipse-paho/paho.mqtt.c: An Eclipse Paho C client library for MQTT for Windows, Linux and MacOS. API documentation: https://eclipse-paho.github.io/paho.mqtt.c/](https://github.com/eclipse-paho/paho.mqtt.c)。

[eclipse-paho/paho.mqtt.cpp (github.com)](https://github.com/eclipse-paho/paho.mqtt.cpp)。



doc：

[Paho MQTT C Client Library: MQTT Client library for C (MQTTClient) (eclipse-paho.github.io)](https://eclipse-paho.github.io/paho.mqtt.c/MQTTClient/html/)



MQTT-C *

MQTT-C is an [MQTT v3.1.1](http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/os/mqtt-v3.1.1-os.html) client written in C. MQTT is a lightweight publisher-subscriber-based messaging protocol that is commonly used in IoT and networking applications where high-latency and low data-rate links are expected. The purpose of MQTT-C is to provide a **portable** MQTT client, **written in C**, for embedded systems and PC's alike. MQTT-C does this by providing a transparent Platform Abstraction Layer (PAL) which makes porting to new platforms easy. MQTT-C is completely thread-safe but can also run perfectly fine on single-threaded systems making MQTT-C well-suited for embedded systems and microcontrollers. Finally, MQTT-C is small; there are only two source files totalling less than 2000 lines.

[LiamBindle/MQTT-C: A portable MQTT C client for embedded systems and PCs alike. (github.com)](https://github.com/LiamBindle/MQTT-C)



Mosquitto

Mosquitto is an open source implementation of a server for version 5.0, 3.1.1, and 3.1 of the MQTT protocol. It also includes a C and C++ client library, and the `mosquitto_pub` and `mosquitto_sub` utilities for publishing and subscribing.

[eclipse-mosquitto/mosquitto: Eclipse Mosquitto - An open source MQTT broker (github.com)](https://github.com/eclipse-mosquitto/mosquitto)



doc:

[Documentation | Eclipse Mosquitto](https://mosquitto.org/documentation/)



#### json parser



json 语法规则：

https://www.runoob.com/json/json-syntax.html



一些json实用工具：

VsCode插件：

- JSON Crack：json 可视化
- Json Editor（Nick DeMayo）：json 交互式编辑



网页工具（可本地部署）：

交互式修改项、json 转 xml、yaml 等 https://www.jyshare.com/front-end/53/

json 差异对比 https://www.jyshare.com/front-end/9557/

交互式编辑，可自定义模板、交互式参数编辑、生成 json

- https://github.com/josdejong/jsoneditor
- https://github.com/jdorn/json-editor
- https://github.com/json-editor/json-editor



nlohmann-json *

There are myriads of [JSON](https://json.org/) libraries out there, and each may even have its reason to exist. Our class had these design goals:

- **Intuitive syntax**. In languages such as Python, JSON feels like a first class data type. We used all the operator magic of modern C++ to achieve the same feeling in your code. Check out the [examples below](https://github.com/nlohmann/json#examples) and you'll know what I mean.
- **Trivial integration**. Our whole code consists of a single header file [`json.hpp`](https://github.com/nlohmann/json/blob/develop/single_include/nlohmann/json.hpp). That's it. No library, no subproject, no dependencies, no complex build system. The class is written in vanilla C++11. All in all, everything should require no adjustment of your compiler flags or project settings.
- **Serious testing**. Our code is heavily [unit-tested](https://github.com/nlohmann/json/tree/develop/tests/src) and covers [100%](https://coveralls.io/r/nlohmann/json) of the code, including all exceptional behavior. Furthermore, we checked with [Valgrind](https://valgrind.org/) and the [Clang Sanitizers](https://clang.llvm.org/docs/index.html) that there are no memory leaks. [Google OSS-Fuzz](https://github.com/google/oss-fuzz/tree/master/projects/json) additionally runs fuzz tests against all parsers 24/7, effectively executing billions of tests so far. To maintain high quality, the project is following the [Core Infrastructure Initiative (CII) best practices](https://bestpractices.coreinfrastructure.org/projects/289).

Other aspects were not so important to us:

- **Memory efficiency**. Each JSON object has an overhead of one pointer (the maximal size of a union) and one enumeration element (1 byte). The default generalization uses the following C++ data types: `std::string` for strings, `int64_t`, `uint64_t` or `double` for numbers, `std::map` for objects, `std::vector` for arrays, and `bool` for Booleans. However, you can template the generalized class `basic_json` to your needs.
- **Speed**. There are certainly [faster JSON libraries](https://github.com/miloyip/nativejson-benchmark#parsing-time) out there. However, if your goal is to speed up your development by adding JSON support with a single header, then this library is the way to go. If you know how to use a `std::vector` or `std::map`, you are already set.

[nlohmann/json: JSON for Modern C++ (github.com)](https://github.com/nlohmann/json)



官方例子：

[nlohmann/json: JSON for Modern C++](https://github.com/nlohmann/json?tab=readme-ov-file#examples)。

[json - JSON for Modern C++](https://json.nlohmann.me/api/json/)。



一个自写使用例子：

```c++
using json = nlohmann::json;

// creat
json ex1 = json::parse(
    R"(
        {
            "pi": 3.141,
            "happy": true
        }
    )");

// creat
json j2 = {
    {"pi", 3.141},
    {"pi_str", "3.141"},
    {"happy", true},
    {"name", "Niels"},
    {"nothing", nullptr},
    {"answer", {
        {"everything", 42}
    }},
    {"list", {1, 0, 2, -3}},
    {"object", {
        {"currency", "USD"},
        {"value", 42.99}
    }}
};

// add / change
j2["pi1"] = 3.141592653589793;
j2["list"].push_back(3);

// erase
if(j2.contains("answer")) {
    j2.erase("answer");
}
if(j2.contains("object")) {
    // use "key" to erase
    if(j2["object"].contains("currency")) {
        j2["object"].erase("currency");
    }

    // use "iterator" to erase, same as above
    // auto it = j2["object"].find("currency");
    // if(it != j2["object"].end()) {
    //     j2["object"].erase(it);
    // }
}

// get
std::string name1 = j2["name"];
std::string name2 = j2["name"].template get<std::string>();
std::list<int32_t> list1 = j2["list"].template get<std::list<int32_t>>();

double value1 = 0;
// find / contains / count
if(j2.contains("object") && j2["object"].contains("value")) {
    value1 = j2["object"]["value"];
}

LOGI(" --- :\n%s", j2.dump(4).c_str());

LOGI(" --- : %s, %s, %lf", name1.c_str(), name2.c_str(), value1);

for(const auto& it : list1) {
    LOGI(" --- %d", it);
}
```



cJSON

Ultralightweight JSON parser in ANSI C.

[DaveGamble/cJSON: Ultralightweight JSON parser in ANSI C (github.com)](https://github.com/DaveGamble/cJSON)



jsmn

jsmn (pronounced like 'jasmine') is a minimalistic JSON parser in C. It can be easily integrated into resource-limited or embedded projects.

[zserge/jsmn: Jsmn is a world fastest JSON parser/tokenizer. This is the official repo replacing the old one at Bitbucket (github.com)](https://github.com/zserge/jsmn)



#### yaml parser



yaml-cpp *

`yaml-cpp` is a [YAML](http://www.yaml.org/) parser and emitter in C++ matching the [YAML 1.2 spec](http://www.yaml.org/spec/1.2/spec.html).

[jbeder/yaml-cpp: A YAML parser and emitter in C++ (github.com)](https://github.com/jbeder/yaml-cpp)



#### xml parser



tinyxml2 *

TinyXML-2 is a simple, small, efficient, C++ XML parser that can be easily integrated into other programs.

[leethomason/tinyxml2: TinyXML2 is a simple, small, efficient, C++ XML parser that can be easily integrated into other programs. (github.com)](https://github.com/leethomason/tinyxml2)



libexpat

[libexpat/libexpat: :herb: Fast streaming XML parser written in C99 with >90% test coverage; moved from SourceForge to GitHub](https://github.com/libexpat/libexpat)



#### Markdown parser - md4c

C Markdown parser. Fast. SAX-like interface. Compliant to CommonMark specification.

[mity/md4c: C Markdown parser. Fast. SAX-like interface. Compliant to CommonMark specification. (github.com)](https://github.com/mity/md4c)



#### tiny-regex-c

Small portable regex in C

[kokke/tiny-regex-c: Small portable regex in C (github.com)](https://github.com/kokke/tiny-regex-c)



#### cista

Cista++ is a simple, open source (MIT license) C++17 compatible way of (de-)serializing C++ data structures.

*Single header - no dependencies. No macros. No source code generation.*

- Raw performance - use your native structs. Supports modification/resizing of deserialized data!
- Supports complex and cyclic data structures including cyclic references, recursive data structures, etc.
- Save 50% memory: serialize directly to the filesystem if needed, no intermediate buffer required.
- Fuzzing-checked though continuous fuzzing using LLVMs LibFuzzer.
- Comes with a serializable high-performance hash map and hash set implementation based on [Google's Swiss Table](https://abseil.io/blog/20180927-swisstables).
- Reduce boilerplate code: automatic derivation of hash and equality functions.
- Built-in optional automatic data structure versioning through recursive type hashing.
- Optional check sum to prevent deserialization of corrupt data.
- Compatible with Clang, GCC, and MSVC

[felixguendling/cista: Cista is a simple, high-performance, zero-copy C++ serialization & reflection library. (github.com)](https://github.com/felixguendling/cista)



Fast-CDR

*eProsima Fast CDR* is a C++ library that provides two serialization mechanisms. One is the standard CDR serialization mechanism, while the other is a faster implementation that modifies the standard.

[eProsima/Fast-CDR: eProsima FastCDR library provides two serialization mechanisms. One is the standard CDR serialization mechanism, while the other is a faster implementation of it. Looking for commercial support? Contact info@eprosima.com (github.com)](https://github.com/eProsima/Fast-CDR)



#### command line parser



**CLI11 ***

CLI11 is a command line parser for C++11 and beyond that provides a rich feature set with a simple and intuitive interface.

[CLIUtils/CLI11: CLI11 is a command line parser for C++11 and beyond that provides a rich feature set with a simple and intuitive interface. (github.com)](https://github.com/CLIUtils/CLI11)



**argparse**

Argument Parser for Modern C++

- Single header file
- Requires C++17

[p-ranav/argparse: Argument Parser for Modern C++ (github.com)](https://github.com/p-ranav/argparse)



**cxxopts  ***

Lightweight C++ command line option parser

[jarro2783/cxxopts: Lightweight C++ command line option parser](https://github.com/jarro2783/cxxopts)



### Database



#### Database lib comparison table



**对比**

> **1. 现有选项分析**
>
> - **SQLite (+ SQLiteCpp):**
>   - **定位:** 嵌入式事实标准。全功能 SQL 关系型数据库。
>   - **优点:** 单文件存储，极其稳定，跨平台完美（Win/Linux/RTOS），支持事务（ACID），查询能力最强。
>   - **缺点:** 写入并发性能较弱（默认是一个写锁），对于极其高频的传感器日志写入（如 >10k ops/s）可能吃力。
> - **LevelDB:**
>   - **定位:** Google 开发的 KV 存储。
>   - **优点:** **写性能极强**（基于 LSM-Tree），适合且仅适合“Key-Value”存取，适合做日志存储或简单的配置存取。
>   - **缺点:** 没有 SQL，不支持复杂查询（比如“查找所有大于某时间的数据”需要遍历），断电恢复有时较慢。
> - **FlashDB:**
>   - **定位:** 专为**资源受限的 MCU（单片机）**设计，直接操作 Flash。
>   - **注意:** 如果你的 SoC 跑的是 Linux 且有文件系统（ext4, fat32），**不建议用 FlashDB**。它更适合跑在 RTOS 或裸机上，绕过文件系统层直接磨损均衡。如果是大型 C++ 项目，通常意味着有操作系统，FlashDB 可能过于简陋。
>
> **2. 补充推荐 (强力竞争者)**
>
> - **LMDB (Lightning Memory-Mapped Database):**
>   - **核心优势:** **读性能世界第一**。它使用内存映射（mmap），直接在内存中操作数据，没有二次缓存（OS Cache + DB Cache），极其节省内存。
>   - **适用:** 配置读取、模型参数加载等“读多写少”的场景。
>   - **缺点:** 写操作是全局锁，只支持单线程写。
> - **RocksDB:**
>   - **核心优势:** Facebook 基于 LevelDB 改进而来。可调优参数极其丰富，性能比 LevelDB 更强，功能更多（支持列族）。
>   - **适用:** 高吞吐量的传感器数据采集、时序数据存储。
>   - **缺点:** 库的体积比 LevelDB 大，编译时间长。
>
> *(上图展示了 LevelDB/RocksDB 的 LSM-Tree 结构与 SQLite 的 B-Tree 结构的区别，这直接决定了它们“写快”还是“读快”。)*
>
> **3. 综合对比表**
>
> | 特性           | **SQLite**                 | **LevelDB / RocksDB**      | **LMDB**                 | **FlashDB**             |
> | -------------- | -------------------------- | -------------------------- | ------------------------ | ----------------------- |
> | **数据模型**   | 关系型 (SQL)               | Key-Value (NoSQL)          | Key-Value (NoSQL)        | Key-Value (TSDB模式)    |
> | **底层结构**   | B-Tree                     | LSM-Tree                   | B+ Tree (Mmap)           | 专有 Flash 结构         |
> | **查询能力**   | **极强** (复杂Join, 过滤)  | 弱 (仅Key查询/范围扫描)    | 弱 (仅Key查询/范围扫描)  | 弱                      |
> | **写性能**     | 中等 (受限于磁盘IO)        | **极高** (追加写)          | 中等 (单写)              | 适合裸 Flash            |
> | **读性能**     | 高                         | 中等                       | **极高** (接近内存拷贝)  | 中等                    |
> | **内存占用**   | 低 (可配置)                | 中/高 (需MemTable)         | **极低** (利用OS缓存)    | 极低                    |
> | **断电安全性** | 高 (WAL模式)               | 中 (可能需Replay Log)      | 极高                     | 针对性优化              |
> | **推荐场景**   | **通用业务逻辑、复杂配置** | **高频日志、传感器数据流** | **静态配置、AI模型索引** | **MCU/RTOS 无文件系统** |



**选择建议（结论）**

> 针对你的场景，我给出以下决策路径：
>
> **1. 确定数据类型与操作系统：**
>
> - **SoC 跑的是 Linux 且有文件系统？** -> 排除 FlashDB，这个直接用于 MCU 开发。
> - **主要存业务数据（配置、用户、任务、状态）？** -> 必须选 **SQLite**。用 **SQLite** 管理由于关系复杂、查询条件多变的元数据（Metadata）。
> - **主要存波形、高频传感器日志（每秒写入 > 1MB）？** -> 必须选 **LevelDB** 或 **RocksDB**（配合压缩）。用 **LevelDB** 存储只有时间戳索引的**海量原始数据**（海量原始数据（Raw Data）。
>
> **2. 架构设计 (混合方案)：**
>
>  在大型嵌入式项目中，**SQLite + LevelDB** 混合使用是非常流行的架构：在 SQLite 中存储 LevelDB 的文件路径或 Key 索引。
>
> **3. 库的选择：**
>
> - 如果选 SQLite：建议使用 **sqlpp11** (追求极致安全和性能) 或者 **SQLite_orm** (追求开发效率)。
>
>   仅仅使用 SQLiteCpp 可能在项目变大后导致 SQL 字符串满天飞，维护困难。



#### ORM

[ORM框架详解：为什么不直接写SQL？_orm和sql-CSDN博客](https://blog.csdn.net/u012955829/article/details/142289384)。



> **你是否需要 ORM？**
>
> 对于 **大型 C++ 项目**，我的建议是：**不要用重型 ORM，但需要一层“类型安全封装” (Type-safe Wrapper)。**
>
> 
>
> **为什么不需要传统 ORM (如 Hibernate for Java 这种级别的)？**
>
> 1. **性能开销:** 嵌入式环境对内存和 CPU 敏感。传统 ORM 的反射机制（C++ 中通常用大量 Template 实现）会导致编译出的二进制体积膨胀（Code Bloat）和运行时开销。
> 2. **调试困难:** C++ 的模板报错在 ORM 中是噩梦。
> 3. **SQL 掌控力:** 嵌入式开发往往需要针对性优化 SQL（比如加索引），ORM 屏蔽了太多细节，反而碍手碍脚。
>
> 
>
> **为什么你需要“类型安全封装”？**
>
> 直接写 `sqlite3_exec(db, "SELECT * FROM table", ...)` 也就是裸写 SQL 字符串，在大型项目中是不可接受的：
>
> - 容易写出 SQL 注入漏洞（虽然嵌入式是对内的，但健壮性很重要）。
> - 重构字段名时，编译器不会报错，运行时才崩溃。



#### Disruptor *



文档：

[高性能无锁并发框架Disruptor，太强了 - 知乎](https://zhuanlan.zhihu.com/p/229338771)。

[LMAX Disruptor User Guide](https://lmax-exchange.github.io/disruptor/user-guide/index.html)。



Github 仓库：

[LMAX-Exchange/disruptor: High Performance Inter-Thread Messaging Library](https://github.com/LMAX-Exchange/disruptor)。



另一个实现：

[fsaintjacques/disruptor--: disruptor concurency pattern in c++](https://github.com/fsaintjacques/disruptor--/tree/develop)。



#### sqlite *

Official Git mirror of the SQLite source tree

[sqlite/sqlite: Official Git mirror of the SQLite source tree (github.com)](https://github.com/sqlite/sqlite)



#### SQLiteCpp

SQLiteC++ (SQLiteCpp) is a smart and easy to use C++ SQLite3 wrapper.

[SRombauts/SQLiteCpp: SQLiteC++ (SQLiteCpp) is a smart and easy to use C++ SQLite3 wrapper. (github.com)](https://github.com/SRombauts/SQLiteCpp)

[SRombauts/SQLiteCpp_Example: C++ Example project using SQLiteCpp as a Git submodule / CMake subdirectory (github.com)](https://github.com/SRombauts/SQLiteCpp_Example)



#### LevelDB

快速键值存储库。

[google/leveldb: LevelDB is a fast key-value storage library written at Google that provides an ordered mapping from string keys to string values.](https://github.com/google/leveldb)。



[Leveldb 基本介绍和使用指南 - 知乎](https://zhuanlan.zhihu.com/p/322520485)。

> ## 1.1 特性
>
> - keys 和 values 是任意的字节数组。
> - 数据按 key 值排序存储。
> - 调用者可以提供一个自定义的比较函数来重写排序顺序。
> - 提供基本的 `Put(key,value)`，`Get(key)`，`Delete(key)` 操作。
> - 多个更改可以在一个原子批处理中生效。
> - 用户可以创建一个瞬时快照(snapshot)，以获得数据的一致性视图。
> - 在数据上支持向前和向后迭代。
> - 使用 Snappy 压缩库对数据进行自动压缩
> - 与外部交互的操作都被抽象成了接口(如文件系统操作等)，因此用户可以根据接口自定义的操作系统交互。
>
> ## 1.2 局限性
>
> - 这不是一个 SQL 数据库，它没有关系数据模型，不支持 SQL 查询，也不支持索引。
> - 同时只能有一个进程(可能是具有多线程的进程)访问一个特定的数据库。
> - 该程序库没有内置的 client-server 支持，有需要的用户必须自己封装。

[Leveldb学习笔记：leveldb的使用与原理探究-CSDN博客](https://blog.csdn.net/qq_46101869/article/details/127805978)。

[入门LevelDB，这一篇文章就够了 - 墨天轮](https://www.modb.pro/db/138370)。

[LevelDB详解及实战指南-CSDN博客](https://blog.csdn.net/gitblog_00054/article/details/141237791)。

> #### 简介
>
> LevelDB是由Google开发的一个高性能键值对存储库，旨在为应用程序提供轻量级且高效的本地存储方案。该项目已被广泛应用于多个领域，包括大数据处理、实时数据库、缓存系统等。
>
> LevelDB支持多种数据结构，例如字符串、列表、集合等，提供了丰富的API来实现数据的增删查改操作。其内部采用基于磁盘的多层索引机制，能够有效地处理大量的数据，同时保证了高并发访问下的性能稳定性。
>
> #### 核心特性
>
> - **持久性**：数据存储在磁盘上，即使重启也不会丢失。
> - **事务处理**：支持原子性和一致性，可以回滚错误操作。
> - **压缩功能**：减少磁盘占用空间，提高查询速度。
> - **数据安全**：通过校验和机制确保数据完整性。
> - **兼容性强**：与多种操作系统和编译器环境相容。

> ### 应用案例和最佳实践
>
> #### 应用场景
>
> LevelDB在以下几种情况中表现优异：
>
> 1. **高速缓存系统**：用于存储临时数据，提升应用响应速度。
> 2. **日志分析工具**：记录大量事件并进行统计和分析。
> 3. **在线交易系统**：需频繁读写的金融场景，要求快速而稳定的交易记录。
> 4. **配置管理系统**：保存全局设置，方便更新和查询。
>
> #### 最佳实践
>
> - **定期整理数据库**：避免碎片过多导致读写效率下降。
> - **合理选择缓存策略**：结合业务需求调整缓存大小和时间。
> - **优化查询语句**：尽量减少全表扫描，使用索引加速查找过程。
>
> ### 典型生态项目
>
> 除了独立使用外，LevelDB还作为许多流行框架和技术的基础组件之一。以下列举几个常见的生态项目：
>
> 1. **RocksDB**：Facebook基于LevelDB改进的高性能嵌入式数据库。
> 2. **Redis**：内存数据结构存储，也可使用LevelDB作为数据持久化选项。
> 3. **Chromium**：谷歌浏览器使用LevelDB来存储浏览历史、书签等数据。
> 4. **TensorFlow**：机器学习框架中使用LevelDB存储模型参数。



#### RocksDB *

- **核心优势:** Facebook 基于 LevelDB 改进而来。可调优参数极其丰富，性能比 LevelDB 更强，功能更多（支持列族）。
- **适用:** 高吞吐量的传感器数据采集、时序数据存储。
- **缺点:** 库的体积比 LevelDB 大，编译时间长。



#### FlashDB

用于 mcu 直接 读写 Flash 的场景。

FlashDB 是一款超轻量级的嵌入式数据库，专注于提供嵌入式产品的数据存储方案。FlashDB 不仅支持传统的基于文件系统的数据库模式，而且结合了 Flash 的特性，具有较强的性能及可靠性。并在保证极低的资源占用前提下，尽可能延长 Flash 使用寿命。

FlashDB 提供两种数据库模式：

- **键值数据库** ：是一种非关系数据库，它将数据存储为键值（Key-Value）对集合，其中键作为唯一标识符。KVDB 操作简洁，可扩展性强。
- **时序数据库** ：时间序列数据库 （Time Series Database , 简称 TSDB），它将数据按照 **时间顺序存储** 。TSDB 数据具有时间戳，数据存储量大，插入及查询性能高。

[armink/FlashDB: An ultra-lightweight database that supports key-value and time series data | 一款支持 KV 数据和时序数据的超轻量级数据库 (github.com)](https://github.com/armink/FlashDB)



### Log



**log4cplus**

[log4cplus](https://github.com/log4cplus/log4cplus) is a simple to use C++23 logging API providing thread--safe, flexible, and arbitrarily granular control over log management and configuration. It is modeled after the Java log4j API.

[log4cplus/log4cplus: log4cplus is a simple to use C++ logging API providing thread-safe, flexible, and arbitrarily granular control over log management and configuration. It is modelled after the Java log4j API. (github.com)](https://github.com/log4cplus/log4cplus)



**EasyLogger**

An ultra-lightweight(ROM<1.6K, RAM<0.3k), high-performance C/C++ log library. | 一款超轻量级(ROM<1.6K, RAM<0.3k)、高性能的 C/C++ 日志库

[armink/EasyLogger: An ultra-lightweight(ROM<1.6K, RAM<0.3k), high-performance C/C++ log library. | 一款超轻量级(ROM<1.6K, RAM<0.3k)、高性能的 C/C++ 日志库 (github.com)](https://github.com/armink/EasyLogger)



**spdlog ***

Fast C++ logging library.

[gabime/spdlog: Fast C++ logging library. (github.com)](https://github.com/gabime/spdlog)



[spdlog库笔记汇总 - 明明1109 - 博客园](https://www.cnblogs.com/fortunely/p/17388565.html)。



**Minilogger**

[ysbbswork/Minilogger: Mini c++ logger tool (github.com)](https://github.com/ysbbswork/Minilogger)



### pdf

有一些命令行或者专用软件，不建议用编程的方式去操作，太繁琐。

比如 [microsoft/markitdown: Python tool for converting files and office documents to Markdown.](https://github.com/microsoft/markitdown) 等 pdf 工具。



一个好的 py 库 SoPDF

[概览 - SoMark 文档](https://docs.somark.tech/open-source-tools/sopdf)。



**JagPDF**

JagPDF is a free, open source library for generating PDF documents.

The goal of this project is to provide a fast and reliable library that is usable in both server and desktop environments. The library is written in C++ and provides bindings for other languages. It runs on x86/Linux, amd64/Linux and x86/Windows platforms.

JagPDF aims to be easy to use, have a look at Hello World examples in [C++](http://www.jagpdf.org/doc/jagpdf/usersguide/quick_start.htm#jagpdf.usersguide.quick_start.hello_world.c__), [Python](http://www.jagpdf.org/doc/jagpdf/usersguide/quick_start.htm#jagpdf.usersguide.quick_start.hello_world.python), [Java](http://www.jagpdf.org/doc/jagpdf/usersguide/quick_start.htm#jagpdf.usersguide.quick_start.hello_world.java) or [C](http://www.jagpdf.org/doc/jagpdf/usersguide/quick_start.htm#jagpdf.usersguide.quick_start.hello_world.c). The library implements a [fairly large subset](http://www.jagpdf.org/features.htm) of the PDF specification which enables creation of a broad range of [document types](http://www.jagpdf.org/samples.htm).

The library is distributed under the [MIT license](http://www.jagpdf.org/license.htm) which encourages both commercial and non-commercial usage.

[JagPDF - PDF Generation Library](http://www.jagpdf.org/index.htm)



**libharu**

Haru is a free, cross platform, open-sourced software library for generating PDF. It supports the following features.

1. Generating PDF files with lines, text, images.
2. Outline, text annotation, link annotation.
3. Compressing document with deflate-decode.
4. Embedding PNG, Jpeg images.
5. Embedding Type1 font and TrueType font.
6. Creating encrypted PDF files.
7. Using various character set (ISO8859-1~~16, MSCP1250~~8, KOI8-R).
8. Supporting CJK fonts and encodings.

You can add the feature of PDF creation by using Haru without understanding complicated internal structure of PDF.

[libharu/libharu: libharu - free PDF library (github.com)](https://github.com/libharu/libharu)



## Com



### dbus-cxx *

DBus-cxx is a C++ implementation for DBus. DBus is a Linux-specific RPC(remote procedure call) and IPC(inter-process communications) mechanism.
DBus-cxx provides an object-oriented view of all programs on the DBus, and allows an object-oriented way of exporting methods onto the DBus.

This new 2.0 version(that you are looking at now) is a complete ground-up implementation of the DBus protocol, without libdbus, in part to fix a number of known multithreading issues with libdbus. This also allows for templates to be used throughout the system, for methods, signals, and properties.

[dbus-cxx/dbus-cxx: DBus-cxx provides an object-oriented interface to DBus (github.com)](https://github.com/dbus-cxx/dbus-cxx)。



### protobuf *

Protocol Buffers (a.k.a., protobuf) are Google's language-neutral, platform-neutral, extensible mechanism for serializing structured data. You can learn more about it in [protobuf's documentation](https://protobuf.dev/).

[protocolbuffers/protobuf: Protocol Buffers - Google's data interchange format (github.com)](https://github.com/protocolbuffers/protobuf)



定义 .proto 文件描述传递消息的数据结构，使用 protoc bin 将其转换为 .h 和 .cc ，读写端都引入之，即可方便的读写消息；
使用 protobuf 库 的 API 将其序列化或反序列化。

官方推荐将 protobuf 库 使用 静态链接 引入 app，protobuf 库 不同版本之间 可能存在不兼容，如果用动态库，如果要 protobuf 库变版本，在目标机器只更新动态库可能出现问题，因此就总用静态库即可。

msys2 有此库。



官方 CPP 引导教程

[Protocol Buffer Basics: C++ | Protocol Buffers Documentation](https://protobuf.dev/getting-started/cpptutorial/)。



.proto 文件格式

[Language Guide (editions) | Protocol Buffers Documentation](https://protobuf.dev/programming-guides/editions/)。



官方 CPP API 手册

[C++ Generated Code Guide | Protocol Buffers Documentation](https://protobuf.dev/reference/cpp/cpp-generated/)。



官方例子

[protobuf/examples/README.md at main · protocolbuffers/protobuf](https://github.com/protocolbuffers/protobuf/blob/main/examples/README.md#c)。



网络教程

[IM通讯协议专题学习(一)：Protobuf从入门到精通，一篇就够！-IM开发/专项技术区 - 即时通讯开发者社区!](http://www.52im.net/thread-4080-1-1.html)。

[Protobuf 学习手册——语法篇 | Jitwxs](https://jitwxs.cn/60aca815)。



### gRPC *

gRPC is a modern, open source, high-performance remote procedure call (RPC) framework that can run anywhere. gRPC enables client and server applications to communicate transparently, and simplifies the building of connected systems.

[grpc/grpc: The C based gRPC (C++, Python, Ruby, Objective-C, PHP, C#) (github.com)](https://github.com/grpc/grpc)

[grpc/src/cpp at master · grpc/grpc (github.com)](https://github.com/grpc/grpc/tree/master/src/cpp) C++版本



[一文掌握gRPC-CSDN博客](https://blog.csdn.net/qq_43456605/article/details/138647102)

B站上也有很多相关视频。



### EmbeddedRPC

Embedded RPC

[EmbeddedRPC/erpc: Embedded RPC (github.com)](https://github.com/EmbeddedRPC/erpc)



### libmodbus

[stephane/libmodbus: A Modbus library for Linux, Mac OS, FreeBSD and Windows (github.com)](https://github.com/stephane/libmodbus)



### Modbus

[foxclever/Modbus: 一个Modbus通讯协议栈 (github.com)](https://github.com/foxclever/Modbus)



### dds

[eProsima/Fast-DDS: The most complete DDS - Proven: Plenty of success cases. Looking for commercial support? Contact info@eprosima.com](https://github.com/eProsima/Fast-DDS)。



## Crypto / Compress / QR-Code



### openssl *

TLS/SSL and crypto library

[openssl/openssl: TLS/SSL and crypto library (github.com)](https://github.com/openssl/openssl)



### tiny-AES-c

Small portable AES128/192/256 in C

This is a small and portable implementation of the AES [ECB](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Electronic_Codebook_.28ECB.29), [CTR](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Counter_.28CTR.29) and [CBC](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Cipher_Block_Chaining_.28CBC.29) encryption algorithms written in C.

You can override the default key-size of 128 bit with 192 or 256 bit by defining the symbols AES192 or AES256 in [`aes.h`](https://github.com/kokke/tiny-AES-c/blob/master/aes.h).

[kokke/tiny-AES-c: Small portable AES128/192/256 in C (github.com)](https://github.com/kokke/tiny-AES-c)



### crc-lib-c

基于C语言的CRC校验库，包括常用的21个CRC参数模型实现

[whik/crc-lib-c: 基于C语言的CRC校验库，包括常用的21个CRC参数模型实现 (github.com)](https://github.com/whik/crc-lib-c)



### zip libs

### zip libs comparison table

GPT4o 和 DeepSeek R1 回答：



| **特性**                | **zlib**                                        | **libzip**                                       |
| ----------------------- | ----------------------------------------------- | ------------------------------------------------ |
| **压缩/解压功能**       | 支持 Deflate 和 Gzip 压缩解压                   | 支持 ZIP 文件压缩/解压                           |
| **文件支持**            | 仅处理流数据（没有ZIP文件结构）                 | 支持 ZIP 文件格式，支持文件、目录结构的压缩/解压 |
| **读取和写入 ZIP 文件** | 不支持ZIP文件格式的操作，只支持压缩和解压流数据 | 支持创建、读取、修改、删除 ZIP 文件中的内容      |
| **流处理支持**          | 强大的流式压缩和解压能力，适合流式处理          | 没有专门的流处理功能，侧重ZIP文件操作            |
| **加密/压缩级别**       | 支持压缩级别和流控制（如Gzip流）                | 支持ZIP文件加密，但压缩级别相对固定              |
| **元数据支持**          | 不支持文件级的元数据（如时间戳、权限等）        | 支持ZIP文件的元数据，包括文件时间戳、权限等      |
| **压缩性能**            | 极为高效，压缩速度快，内存使用低                | 压缩速度略低，但足以满足一般需求                 |
| **解压性能**            | 解压速度非常快，内存占用小                      | 解压性能较好，但相比zlib略慢一些                 |
| **依赖性**              | 无外部依赖，仅依赖标准C库                       | 依赖zlib进行压缩解压，适用于C++开发者            |
|                         |                                                 |                                                  |



- **zlib** 主要专注于压缩和解压流数据，它不会直接处理ZIP文件，意味着它适合于仅仅需要压缩和解压原始数据流的场景。

  - **核心优势**：行业标准DEFLATE实现，被PNG、HTTP压缩等广泛采用；**内存占用低**（适合嵌入式）；支持流式压缩。

  - **局限**：仅提供数据流压缩，不支持ZIP文件结构；需手动处理多文件/目录逻辑。

  - **场景**：**网络传输压缩**（如gzip HTTP）、**嵌入式系统**、底层算法集成。

    资源占用最低，无OS依赖，适合算法集成或协议开发。

    C++ 封装：**zstr**：简化zlib流操作，自动检测格式，适合日志解压或实时数据流水线。资源受限环境（如IoT设备）。

- **libzip** 则支持完整的ZIP文件操作，包括读取、写入、修改和删除文件，支持ZIP文件结构中的目录层次和文件元数据。这使得它非常适合处理ZIP文件包的应用场景，尤其是需要操作文件内容而不仅仅是压缩解压时。

  - **核心优势**：**完整ZIP文件操作**（增删改条目）；支持多种压缩算法（DEFLATE/BZIP2等）；**提供加密接口**；跨平台稳定。

  - **局限**：C接口需手动管理资源；无原生C++封装（需自行包装）。

  - **场景**：备份工具、软件安装包处理、需精细控制ZIP元数据的应用。

    C++ 封装：**LibZippp**：C++友好API + 完整功能。**现代C++封装**（RAII管理资源）；简化libzip调用（如迭代器遍历条目）；支持ZSTD等新算法。游戏资源包加载、跨平台数据分发工具、需高可读性代码的项目。



**终极结论**：**LibZippp** 为综合最优选（2025年），平衡了现代C++开发效率与ZIP操作完整性。若项目仅需流压缩或无ZIP文件需求，可降级选用zlib或zstr。



**zlib**

zlib is a **general purpose** data compression library.  All the code is thread safe.  The data format used by the zlib library is described by RFCs (Request for Comments)

[madler/zlib: A massively spiffy yet delicately unobtrusive compression library. (github.com)](https://github.com/madler/zlib)



**zstr**

A **C++ header-only ZLib wrapper**

[mateidavid/zstr: A C++ header-only ZLib wrapper (github.com)](https://github.com/mateidavid/zstr)



**libzip**

This is libzip, a **C library** for reading, creating, and modifying zip and zip64 archives. Files can be added from data buffers, files, or compressed data copied directly from other zip archives. Changes made without closing the archive can be reverted. Decryption and encryption of Winzip AES and legacy PKware encrypted files is supported.

libzip is fully documented via man pages. HTML versions of the man pages are on [libzip.org](https://libzip.org/documentation/) and in the [man](https://github.com/nih-at/libzip/blob/main/man) directory. You can start with [libzip(3)](https://libzip.org/documentation/libzip.html), which lists all others. Example source code is in the [examples](https://github.com/nih-at/libzip/blob/main/examples) and [src](https://github.com/nih-at/libzip/blob/main/src) subdirectories.

[nih-at/libzip: A C library for reading, creating, and modifying zip archives. (github.com)](https://github.com/nih-at/libzip)



依赖：

根据官方文档 [INSTALL · libzip](https://libzip.org/INSTALL/)：zlib 时必须的；要支持加密压缩，需要列出的几个库选一个；要支持 bzip2 则可选 bzip2库。

> You’ll need [zlib](http://www.zlib.net/) (at least version 1.1.2). It comes with most operating systems.
>
> ...
>
> For AES (encryption) support, you need one of these cryptographic libraries, listed in order of preference:
>
> - Apple’s CommonCrypto (available on macOS and iOS)
> - Microsoft Windows Cryptography Framework
> - [OpenSSL](https://www.openssl.org/) >= 1.0.
> - [GnuTLS](https://www.gnutls.org/) and [Nettle](https://www.lysator.liu.se/~nisse/nettle/) (at least nettle 3.0)
> - [mbed TLS](https://tls.mbed.org/)
>
> If you don’t want a library even if it is installed, you can pass `-DENABLE_<LIBRARY>=OFF` to cmake, where `<LIBRARY>` is one of `COMMONCRYPTO`, `GNUTLS`, `MBEDTLS`, or `OPENSSL`.
>
> ...
>
> For supporting bzip2-compressed zip archives, you need [bzip2](http://bzip.org/).



**LibZippp ***

libzippp is a simple basic **C++ wrapper around the libzip library**. It is meant to be a portable and easy-to-use library for ZIP handling.

Underlying libraries：依赖项：

- [ZLib](https://zlib.net/) 1.3.1
- [libzip](https://www.nih.at/libzip) 1.11.2

[ctabin/libzippp: C++ wrapper for libzip (github.com)](https://github.com/ctabin/libzippp)。



创建、打开、读写、关闭压缩包，很像对文件的读写。

API 文档：直接查阅头文件 [`libzippp.h`](https://github.com/ctabin/libzippp/blob/master/src/libzippp.h)（头文件即文档）



### QR-Code-generator

This project aims to be the best, clearest QR Code generator library in multiple languages. The primary goals are flexible options and absolute correctness. Secondary goals are compact implementation size and good documentation comments.

[nayuki/QR-Code-generator: High-quality QR Code generator library in Java, TypeScript/JavaScript, Python, Rust, C++, C. (github.com)](https://github.com/nayuki/QR-Code-generator)



## Scientific Computing



### GNU GSL

The GNU Scientific Library (GSL) is a numerical library for C and C++ programmers. It is free software under the GNU General Public License.

The library provides a wide range of mathematical routines such as random number generators, special functions and least-squares fitting. There are over 1000 functions in total with an extensive test suite.

Unlike the licenses of proprietary numerical libraries the license of GSL does not restrict scientific cooperation. It allows you to share your programs freely with others.

[GSL - GNU Scientific Library - GNU Project - Free Software Foundation](https://www.gnu.org/software/gsl/)



### Matrix

[mlcpp/Matrix: Easy-to-use Scientific Computing library in/for C++ available for Linux and Windows. (github.com)](https://github.com/mlcpp/Matrix)



### NumCpp

A Templatized Header Only C++ Implementation of the [Python NumPy Library](http://www.numpy.org/)。

[dpilger26/NumCpp: C++ implementation of the Python Numpy library (github.com)](https://github.com/dpilger26/NumCpp)



### Matrix_hub

A lib of Matrix operation for C language. (矩阵运算库--C语言)

[Amoiensis/Matrix_hub: A lib of Matrix operation for C language. (矩阵运算库--C语言) (github.com)](https://github.com/Amoiensis/Matrix_hub)



### Evolving Objects

[Dither/evolving-objects: Evolving Objects (EO): an Evolutionary Computation Framework](https://github.com/Dither/evolving-objects)。



## Language Bind



### Lua



一种轻量级多范式脚本语言，主要设计用于嵌入使用。C 库。

[The Programming Language Lua](https://www.lua.org/)



**sol2**

一个绑定 Lua 的现代 C++ 库。

sol2 is a C++ library binding to Lua. It currently supports all Lua versions 5.1+ (LuaJIT 2.0+ and MoonJIT included). sol2 aims to be easy to use and easy to add to a project. The library is header-only for easy integration with projects, and a single header can be used for drag-and-drop start up.

[ThePhD/sol2: Sol3 (sol2 v3.0) - a C++ <-> Lua API wrapper with advanced features and top notch performance - is here, and it's great! Documentation: (github.com)](https://github.com/ThePhD/sol2)



### MicroPython



### JavaScript



**QuickJS**

QuickJS是一个小型并且可嵌入的Javascript引擎，它支持ES2020规范，包括模块，异步生成器和代理器。

它可选支持数学扩展，例如大整数 (BigInt)，大浮点数 (BigFloat) 以及运算符重载。

[quickjs-zh/QuickJS: QuickJS是一个小型并且可嵌入的Javascript引擎，它支持ES2020规范，包括模块，异步生成器和代理器。](https://github.com/quickjs-zh/QuickJS)。



**MicroQuickJS**

MicroQuickJS (aka. MQuickJS) is a JavaScript engine targeted at embedded systems. It compiles and runs JavaScript programs using as little as 10 kB of RAM. The whole engine requires about 100 kB of ROM (ARM Thumb-2 code) including the C library. The speed is comparable to QuickJS.

MQuickJS only supports a [subset](https://github.com/bellard/mquickjs#javascript-subset-reference) of JavaScript close to ES5. It implements a **stricter mode** where some error prone or inefficient JavaScript constructs are forbidden.

Although MQuickJS shares much code with QuickJS, it internals are different in order to consume less memory. In particular, it relies on a tracing garbage collector, the VM does not use the CPU stack and strings are stored in UTF-8.

[bellard/mquickjs: Public repository of the Micro QuickJS Javascript Engine](https://github.com/bellard/mquickjs)。



**ChaiScript**

ChaiScript is similar to ECMAScript (aka JavaScript(tm)), but with some modifications to make it easier to use. For usage examples see the "samples" directory, and for more in-depth look at the language, the unit tests in the "unittests" directory cover the most ground.

[ChaiScript/ChaiScript: Embedded Scripting Language Designed for C++](https://github.com/ChaiScript/ChaiScript)



## Image / Media / Sound



### ffmpeg



### LIVE555



### libVLC



### CxImage

[最好用图像处理库CxImage入门-CSDN博客](https://blog.csdn.net/jmppok/article/details/18794623)。



### CImg

[The CImg Library - C++ Template Image Processing Library](https://www.cimg.eu/)。



[CImg库介绍_c++的cimg.blur-CSDN博客](https://blog.csdn.net/fengbingchun/article/details/6002625)。



## Img enc & dec



### JPEG / PNG / GIF



**比较官方的**

以下均包含 encoder 和 decoder



libjpeg

[libjpeg-turbo/libjpeg-turbo: Main libjpeg-turbo repository](https://github.com/libjpeg-turbo/libjpeg-turbo)。



libpng

[pnggroup/libpng: LIBPNG: Portable Network Graphics support, official libpng repository](https://github.com/pnggroup/libpng)。



giflib

仓库 [GIFLIB download | SourceForge.net](https://sourceforge.net/projects/giflib/)。

官网 [The GIFLIB project](https://giflib.sourceforge.net/)。



**三方开源仓库**



一个 JPEG 的 encoder 和 decoder

- [bitbank2/JPEGENC: Arduino JPEG encoder](https://github.com/bitbank2/JPEGENC)。
- [bitbank2/JPEGDEC: An optimized JPEG decoder suitable for microcontrollers and PCs.](https://github.com/bitbank2/JPEGDEC)。



一个单头文件的 C99 的 JPEG 的 encoder（适用于 mcu）

[serge-rgb/TinyJPEG: Single header lib for JPEG encoding. Public domain. C99. stb style.](https://github.com/serge-rgb/TinyJPEG)



一个 PNG 的 encoder 和 decoder

- [bitbank2/PNGenc: An embedded-friendly PNG encoder](https://github.com/bitbank2/PNGenc)。
- [bitbank2/PNGdec: An optimized PNG decoder suitable for microcontrollers and PCs](https://github.com/bitbank2/PNGdec)。



一个 PNG 的 encoder 和 decoder

- [lvandeve/lodepng: PNG encoder and decoder in C and C++.](https://github.com/lvandeve/lodepng)。



一个 GIF 的 decoder

- [bitbank2/AnimatedGIF: An optimized GIF decoder suitable for microcontrollers and PCs](https://github.com/bitbank2/AnimatedGIF)。



### webp

- 官网 [An image format for the Web  | WebP  | Google for Developers](https://developers.google.cn/speed/webp?hl=en)。
- 库 [WebP API Documentation  | Google for Developers](https://developers.google.cn/speed/webp/docs/api?hl=en)。



## Vision



### openCV



### SimpleCV



### ccv

[liuliu/ccv: C-based/Cached/Core Computer Vision Library, A Modern Computer Vision Library](https://github.com/liuliu/ccv).



## Device



UDisks

The UDisks project provides a daemon, tools and libraries to access and manipulate disks, storage devices and technologies.

For API stability and intended audience of UDisks, see the API STABILITY and AUDIENCE section of the `udisks(8)` man page (`doc/man/udisks.xml` in the tarball and git repository).

[storaged-project/udisks: The UDisks project provides a daemon, tools and libraries to access and manipulate disks, storage devices and technologies.](https://github.com/storaged-project/udisks)



libusb *

libusb is a library for USB device access from Linux, macOS, Windows, OpenBSD/NetBSD, Haiku, Solaris userspace, and WebAssembly via WebUSB. It is written in C (Haiku backend in C++) and licensed under the GNU Lesser General Public License version 2.1 or, at your option, any later version (see [COPYING](https://github.com/libusb/libusb/blob/master/COPYING)).

libusb is abstracted internally in such a way that it can hopefully be ported to other operating systems. Please see the [PORTING](https://github.com/libusb/libusb/blob/master/PORTING) file for more information.

libusb homepage: https://libusb.info/

[libusb/libusb: A cross-platform library to access USB devices (github.com)](https://github.com/libusb/libusb)



libuvc *

`libuvc` is a cross-platform library for USB video devices, built atop `libusb`. It enables fine-grained control over USB video devices exporting the standard USB Video Class (UVC) interface, enabling developers to write drivers for previously unsupported devices, or just access UVC devices in a generic fashion.

[libuvc/libuvc: a cross-platform library for USB video devices (github.com)](https://github.com/libuvc/libuvc)



CherryUSB

Easy to study USB

In order to make it easier for users to learn USB basics, enumeration, driver loading and IP drivers, the code has been written with the following advantages:

- Lean code, simple logic, no complex C syntax
- Tree-based programming with cascading code
- Class-drivers and porting-drivers are templating and simplification
- Clear API classification (slave: initialisation, registration api, command callback api, data sending and receiving api; host: initialisation, lookup api, data sending and receiving api)

[cherry-embedded/CherryUSB: CherryUSB is a tiny and beautiful, portable and high performace USB host and device stack for embedded system with USB IP (github.com)](https://github.com/cherry-embedded/CherryUSB)



## Embedded

取自 [Your list / 嵌入式项目 / 协议栈 / 库 (github.com)](https://github.com/stars/Staok/lists/嵌入式项目-协议栈-库)。



### RTOS

[主流嵌入式操作系统（RTOS）有哪些？看这14种系统 - 知乎](https://zhuanlan.zhihu.com/p/356507840).



FreeRTOS

正点原子 等出过 FreeRTOS 的手册，看就会了





NuttX



RT-Thread



Vxworks



### Language Bind



microPython



lua



### Framework



[Staok/stm32_framework: 一个志在实现STM32F1、F2和F4工程模板的项目，集成了FreeRTOS、LWIP、FATFS、DSP、USB、IAP、菜单库、有限状态机模板等等的组件，以及未来将加入的加密、BPNN、最小二乘、音频图片视频解码、LittlevGL等诸多常用的算法或组件，并具有良好的易用性、解耦性和可剪裁性！](https://github.com/Staok/stm32_framework)。



BabyOS

专为MCU项目开发提速的代码框架

[notrynohigh/BabyOS: 专为MCU项目开发提速的代码框架 (github.com)](https://github.com/notrynohigh/BabyOS)



ETL

实现了资源节省的、固定内存分配的 C++ 的各种基本功能，采用回调函数的方式与 嵌入式 mcu 设备中的 各种 uart、timer 等中断回调进行连接，来使得能够用 c++ 来编写 mcu 代码。

C++ is a great language to use for embedded applications and templates are a powerful aspect. The standard library can offer a great deal of well tested functionality, but there are some parts of the standard library that do not fit well with deterministic behaviour and limited resource requirements. These limitations usually preclude the use of dynamically allocated memory and containers with open ended sizes.

What is needed is a template library where the user can declare the size, or maximum size of any object upfront. Most embedded compilers do not currently support the standard beyond C++ 03, therefore excluding the programmer from using the enhanced features of the later library.

This is what the ETL attempts to achieve.

[ETLCPP/etl: Embedded Template Library (github.com)](https://github.com/ETLCPP/etl)



### Drivers



各种芯片驱动！

[libdriver (LibDriver) (github.com)](https://github.com/libdriver)



按键处理

https://github.com/jiejieTop/ButtonDrive



TeenyUSB

一个简易的单片机USB主机和设备协议栈，现在支持3.0设备。

A teeny USB device and host stack for MCUs, support super speed device.

关于TeenyUSB的实现细节和使用方式请阅读《STM32 USB设备开发指南》

Lightweight USB device and host stack for STM32 and other MCUs. Ready for USB 3.0 device.

[xtoolbox/TeenyUSB: Lightweight USB device and host stack for STM32 and other MCUs. Ready for USB 3.0 device. (github.com)](https://github.com/xtoolbox/TeenyUSB)



libusb_stm32

Lightweight USB Device Stack

- Lightweight and fast
- Event-driven process workflow
- Completely separated USB hardware driver and usb core
- Easy to use.

[dmitrystu/libusb_stm32: Lightweight USB device Stack for STM32 microcontrollers (github.com)](https://github.com/dmitrystu/libusb_stm32)



W5500 系列芯片驱动封装

[Wiznet/ioLibrary_Driver: ioLibrary_Driver can be used for the application design of WIZnet TCP/IP chips as W5500, W5300, W5200, W5100 W5100S. (github.com)](https://github.com/Wiznet/ioLibrary_Driver)



### CMSIS .etc

[Arm Software](https://github.com/ARM-software)。

[ARM-software/CMSIS_6: CMSIS version 6 (successor of CMSIS_5)](https://github.com/ARM-software/CMSIS_6)。



### Comps



letter-shell

嵌入式 shell

[NevermindZZT/letter-shell: letter shell (github.com)](https://github.com/NevermindZZT/letter-shell)



nr_micro_shell

shell for MCU. 单片机命令行交互。

[Nrusher/nr_micro_shell: shell for MCU. 单片机命令行交互。 (github.com)](https://github.com/Nrusher/nr_micro_shell)



lwshell

Lightweight shell implementation for embedded systems

[MaJerle/lwshell: Lightweight shell implementation for embedded systems (github.com)](https://github.com/MaJerle/lwshell)



lwrb

Library provides generic FIFO ring buffer implementation.

[MaJerle/lwrb: Lightweight generic ring buffer manager library (github.com)](https://github.com/MaJerle/lwrb)



printf

[mpaland/printf: Tiny, fast, non-dependent and fully loaded printf implementation for embedded systems. Extensive test suite passing. (github.com)](https://github.com/mpaland/printf)



SFUD

An using JEDEC's SFDP standard serial (SPI) flash universal driver library | 一款使用 JEDEC SFDP 标准的串行 (SPI) Flash 通用驱动库

[armink/SFUD: An using JEDEC's SFDP standard serial (SPI) flash universal driver library | 一款使用 JEDEC SFDP 标准的串行 (SPI) Flash 通用驱动库 (github.com)](https://github.com/armink/SFUD)



## UI



个人对 GUI 框架设计经验总结 [Staok/GUI-Framework-Study: GUI 框架基础需求、设计和实现文章](https://github.com/Staok/GUI-Framework-Study)。



### Comprehensive

综合性的大库



**UniApp**

[UniApp 简介 | 菜鸟教程](https://www.runoob.com/uniapp/uniapp-intro.html)。

> UniApp 的应用场景
>
> - 微信小程序开发：快速开发并发布到微信小程序平台。
> - H5 网页开发：构建适配移动端的网页应用。
> - 跨平台 App 开发：开发 Android 和 iOS 应用，无需分别学习原生开发。
> - 多端统一项目：需要同时覆盖小程序、H5 和 App 的项目。



**Flutter** *

Flutter is Google's SDK for crafting beautiful, fast user experiences for **mobile, web, and desktop from a single codebase**. Flutter works with existing code, is used by developers and organizations around the world, and is free and open source.

[flutter/flutter: Flutter makes it easy and fast to build beautiful apps for mobile and beyond (github.com)](https://github.com/flutter/flutter)。



适用于 app、win、web、linux。



可以 AI 辅助编程，提示词工程合集可以使用：[bbylw/ui-ux-pro-max-skill-cn: 本网站是 UI/UX Pro Max 技能库的官方中文教程，完整翻译并本地化了原始 README 的所有内容，帮助中文开发者快速上手这个强大的 AI 设计技能。](https://github.com/bbylw/ui-ux-pro-max-skill-cn)。支持 Flutter。



`flutter-pi` 适用于 Linux 上直接通过 FB/DRM 等机制刷新 UI 的情况使用。



Flutter

- ✅ 颜值最高：不仅能画UI，还能做非常炫酷的60fps动画，现代化程度最高。

- ✅ 开发效率高：Dart语言简单，UI构建快。
- ❌ C++交互成本：如果你有大量现成的C++业务逻辑，接Flutter需要写很多“胶水代码”。
- ❌ 资源开销：运行需要Dart虚拟机和Skia引擎，对RAM和Flash要求远高于LVGL。



- dart 语言编码 UI，编译为二进制代码部署到机器内，无源码泄露风险。
- Flutter 的 UI 与 C++ 业务代码部分 之间的 交互稍微麻烦。



**SDL2**

> SDL2是跨平台的图形库，支持Windows, macOS, Linux, iOS, and Android等常见的平台，它底层使用OpenGL或Direct3D，支持硬件加速，常用于游戏开发，SDL是用C写的，可以用C++操作，也有C#和Python的绑定，它内置了键盘、鼠标、音视频的支持，自SDL2.0以来，允许开发者静态连接。



win 下，手动加入 SDL2 库：这里只是说明手动步骤，推荐用平台的包管理器来下载该库。

1. 首先下载到 SDL2 包 比如 "SDL2-devel-2.28.2-mingw"。
2. 将其中的 "x86_64-w64-mingw32" 文件夹 直接 解压放到 "mingw64" 下的 "x86_64-w64-mingw32" 文件夹下！
3. 确保 ".../mingw64/bin/" 已经加入到 环境变量 "Path" 中。
4. 并且！ 将 ".../mingw64/x86_64-w64-mingw32/bin" 加入到 环境变量 "Path" 中，因为用到了 该路径下的 SDL2.dll。
5. 添加 环境变量 后， win 下可能需要重启才能生效。
6. 然后在 cmake 中寻找并加入该库即可。

在 msys 等包管理中也已经有 sdl2 库了。



**QT**

- 在嵌入式上商用收费不可接受。直接 pass。
- 且 qml 以源码形式部署到机器中，有泄露源码风险。
- 开发桌面级别应用不受商用限制。
- 但个人觉得别扭的是，QT 有自己一套基本容器、网络、线程等的 API，我 C++ 已经很熟了，再学一套 增加学习和心智负担。



个人收集的 QT 相关的好仓库：[Your list / QT](https://github.com/stars/Staok/lists/qt)，有很多实用例子，对于需要 QT 开发的 同学 可多参考 用于学习借鉴。

个人对 QT 使用总结 [Staok/QT-QML-Learning: QT & QML 总结备查文章](https://github.com/Staok/QT-QML-Learning)。



**CopperSpice**

Qt 的一个 开源的 fork 库。几乎各方面和 Qt 很像，Qt 工程 几乎可以 平移到这个库。

[copperspice/copperspice: Set of cross platform C++ libraries (Core, Gui, Network, Multimedia, SQL, Vulkan, etc) (github.com)](https://github.com/copperspice/copperspice)。

[copperspice/cs_designer: Program used by developers to create a graphical interface .ui file (github.com)](https://github.com/copperspice/cs_designer)。



demo

[copperspice/kitchensink: C++ application examples showing how to use the CS libraries (github.com)](https://github.com/copperspice/kitchensink)。



**Tkinter**

Python 库。以下是一些UI设计辅助工具和教程。

[Tkinter-Designer/docs/README.zh-CN.md at master · ParthJadhav/Tkinter-Designer (github.com)](https://github.com/ParthJadhav/Tkinter-Designer/blob/master/docs/README.zh-CN.md)。

[iamxcd/tkinter-helper: 为tkinter打造的可视化拖拽布局界面设计小工具 (github.com)](https://github.com/iamxcd/tkinter-helper)。

[Dvlv/Tkinter-By-Example: Learn Tkinter By Example - a free book (github.com)](https://github.com/Dvlv/Tkinter-By-Example)。

适用于桌面软件。UI 使用 OS 原生 API，看起来一般。Python 自带的 UI 库。



定位：Python 的标准 GUI 库，基于 Tcl/Tk。它是 90 年代的产物，主要用于快速开发桌面小工具。

核心语言：Python。

- 优点：
  - ✅ 简单：Python 几行代码出一个窗口。
  - ✅ Linux/Windows 兼容：桌面端只要有 Python 就能跑。
- 缺点（致命伤）：
  - ❌ MCU 绝缘体：MCU 跑不了完整 Python（MicroPython 不支持标准 Tkinter）。所以直接淘汰 MCU 场景。
  - ❌ 性能差：解释型语言 + 老旧图形库，在嵌入式 Linux 上跑起来会有明显的卡顿感。
  - ❌ C/C++ 交互痛苦：你的业务逻辑是 C++，UI 是 Python。你需要通过 Python C Extension 或者 ctypes 来通信，架构非常别扭，且性能损耗大。
  - ❌ 丑：原生控件非常复古，不支持现代化的触摸交互、手势、GPU 加速动画。
- 结论：
  - 适合场景：在 PC 上写一个快速的原型验证工具。
  - 不适合场景：任何嵌入式商业产品。



**ImGui**

Dear ImGui is a **bloat-free graphical user interface library for C++**. It outputs optimized vertex buffers that you can render anytime in your 3D-pipeline-enabled application. It is fast, portable, renderer agnostic, and self-contained (no external dependencies).

Dear ImGui is designed to **enable fast iterations** and to **empower programmers** to create **content creation tools and visualization / debug tools** (as opposed to UI for the average end-user). It favors simplicity and productivity toward this goal and lacks certain features commonly found in more high-level libraries. Among other things, full internationalization (right-to-left text, bidirectional text, text shaping etc.) and accessibility features are not supported.

Dear ImGui is particularly suited to integration in game engines (for tooling), real-time 3D applications, fullscreen applications, embedded applications, or any applications on console platforms where operating system features are non-standard.

- Minimize state synchronization.
- Minimize UI-related state storage on user side.
- Minimize setup and maintenance.
- Easy to use to create dynamic UI which are the reflection of a dynamic data set.
- Easy to use to create code-driven and data-driven tools.
- Easy to use to create ad hoc short-lived tools and long-lived, more elaborate tools.
- Easy to hack and improve.
- Portable, minimize dependencies, run on target (consoles, phones, etc.).
- Efficient runtime and memory consumption.
- Battle-tested, used by [many major actors in the game industry](https://github.com/ocornut/imgui/wiki/Software-using-dear-imgui).

[ocornut/imgui: Dear ImGui: Bloat-free Graphical User interface for C++ with minimal dependencies (github.com)](https://github.com/ocornut/imgui)。



一个文件浏览实现

[AirGuanZ/imgui-filebrowser: File browser implementation for dear-imgui. C++17 is required. (github.com)](https://github.com/AirGuanZ/imgui-filebrowser)。

即说明，github 上还有更多例子和实现。



定位：它不是为了给最终用户（消费者）做 UI 的，它是为了给 开发者 做调试工具、游戏引擎编辑器、或者内部测试软件的。

- 优点：
  - ✅ C++ 集成度极高：只要几行代码就能把变量显示在窗口上，非常适合用来调节 PID 参数、查看内存数据。
  - ✅ 无状态管理：不需要操心“同步 UI 和数据”，因为 UI 代码就是每一帧直接读数据的。
  - ✅ 可移植性：只要能画三角形（OpenGL/DirectX/Vulkan），就能跑。
- 缺点（致命伤）：
  - ❌ 功耗爆炸：因为每一帧都在重绘，CPU/GPU 占用率很高，对电池供电的嵌入式设备是灾难。虽然可以魔改由事件驱动，但很麻烦。
  - ❌ 很难做“好看”：ImGui 的控件长得像 Windows 95 时代的工业软件。由于其底层原理，想做复杂的动画、炫酷的特效、自定义的不规则控件，难度比 Flutter/Qt 大十倍。
  - ❌ 不支持 MCU：虽然硬要移植也能跑在 STM32 上，但 RAM 消耗和 CPU 刷新率通常无法接受。
- 结论：
  - 适合场景：嵌入式 Linux 设备的后台调试模式、工厂测试工具。
  - 不适合场景：卖给客户的产品主界面。



**libui**

[andlabs/libui: Simple and portable (but not inflexible) GUI library in C that uses the native GUI technologies of each platform it supports. (github.com)](https://github.com/andlabs/libui)。

适用于桌面软件。UI 使用 OS 原生 API，看起来一般。生态丰富，还有可视化构建 UI 的工具。



**wxWidgets**

wxWidgets is a free and open source cross-platform C++ framework for writing advanced GUI applications using native controls.

wxWidgets allows you to write native-looking GUI applications for all the major desktop platforms and also helps with abstracting the differences in the non-GUI aspects between them. It is free for the use in both open source and commercial applications, comes with the full, easy to read and modify, source and extensive documentation and a collection of more than a hundred examples. You can learn more about wxWidgets at https://www.wxwidgets.org/ and read its documentation online at https://docs.wxwidgets.org/

[wxWidgets/wxWidgets: Cross-Platform C++ GUI Library (github.com)](https://github.com/wxWidgets/wxWidgets)。

不推荐了。比较老。



### Embeding-Colored

以下为 嵌入式强相关的

彩屏



**LVGL**

官方仓库 [lvgl/lvgl: Embedded graphics library to create beautiful UIs for any MCU, MPU and display type.](https://github.com/lvgl/lvgl)。

官方文档 [LVGL documentation](https://docs.lvgl.io/master/index.html)。



个人对 LVGL 使用总结 [Staok/LVGL-Study-Record: LVGL 总结备查文章](https://github.com/Staok/LVGL-Study-Record)。



可视化 UI 设计工具：

UI 可视化操作 有 SquareLine Studio (以及网页版的 SquareLine Vision) 和 EEZ Studio 等可视化设计器，可以拖拽生成C代码。前者有组件 component 功能，后者有事件流功能。前者比较重，且收费，后者较轻量且免费开源。组件是更需要的，需要看看后者是否支持了，如果支持了就选用后者。

- eez studio（开源免费）推荐。
- squareLine（收费）。
- [anyui](https://anyui.tech/)。
- [LVGL Visual Architect Specification](https://lvgl.btvi.com.br/)。web 在线 LVGL UI 制作，功能较简单。
- 等等。



- LVGL 官方 的 XML 编辑 UI [LVGL Pro](https://pro.lvgl.io/)（收费）。



- 将 C UI 代码转换为 HTML 文件：https://github.com/lvgl/lv_web_emscripten。LVGL ported to Emscripten to be converted to JavaScript。
- 这是一个用 Qt 写的 可视化布局 LVGL 前端界面的 工具 https://github.com/CURTLab/LVGLBuilder。玩具，看看就好。



LVGL 也有单色模式，可以兼容 OLED 等单色屏显示，LVGL 更易用且功能丰富、可裁剪。推荐嵌入式设备端优先使用 LVGL。



- ✅ 极度轻量：几十KB Flash，几KB RAM即可运行。
- ✅ C/C++亲和度满分：无需任何中间层，直接调用。
- ✅ 免费开源：MIT协议，商业无限制。
- ❌ 桌面端体验一般：在Windows/Ubuntu上主要用于开发调试，做成独立的桌面软件显得比较“嵌入式风格”，不支持系统原生窗口特性。



- 定制化内容多时候，完全的 C 语言控制 UI 增加心智负担，像素级别开发。



LVGL 相关实用例子和组件仓库收集：[Your list / LVGL](https://github.com/stars/Staok/lists/lvgl)。



**Slint**

- 功能亮点（全版本通用）：
  - 极轻量级 (MCU 友好)：
    - 可以在 < 300KB RAM 的设备上运行（如 STM32H7, ESP32-S3, RP2040）。
    - Flash 占用极低，且它是编译型语言（编译成原生二进制），不是解释型（无虚拟机开销）。
  - 桌面级渲染 (Linux/Windows)：
    - 在嵌入式 Linux 上支持 OpenGL ES 加速，也支持纯软件渲染（FrameBuffer）。
    - 在 Windows/macOS 上使用原生图形 API（DirectX/Metal）。
  - 声明式 UI 语言 (.slint)：
    - 类似于 QML 或 CSS/HTML，专门用来画界面的语言。
    - 极大降低心智负担：您不需要用 C++ 去 new Button(), button.setSize()，而是写 Button { text: "OK"; }。
  - C++ 完美集成：
    - 它的编译器会把 .slint 文件编译成 C++ 头文件。也无 UI 脚本的源码泄露风险。
    - 业务逻辑全是标准 C++，通过 getter/setter 和回调函数与 UI 交互。
  - Live Preview (实时预览)：VSCode 插件支持一边写代码，一边在侧边栏实时看到 UI 变化（类似 Flutter 的热重载，但针对设计阶段）。
- 商用协议：
  - A. GPLv3 (开源版)
    - 陷阱：GPLv3 是强传染协议。如果您用这个协议开发产品，您的整个产品的源代码（包括 C++ 业务逻辑）必须向用户公开。
    - 结论：除非您做的是纯开源硬件/软件，否则绝对不能选这个。
  - B. Royalty-Free License (免费商用/大使计划)
    - 这是 Slint 为了抢占市场推出的“杀手锏”。它允许您开发闭源的商业软件，且不花一分钱，但有交换条件。
    - 条件：
      - 归属声明：您必须在应用程序的显著位置（如启动画面 Splash Screen 或 “关于” 对话框）显示 “Made with Slint” 的字样或 Logo，并链接到 Slint 官网。
      - 桌面软件：如果是 Windows/Linux 桌面软件，必须在“关于”对话框里显示。
      - 嵌入式设备：如果是带屏幕的设备，必须在启动时或设置菜单的显眼处显示 Logo。
    - 结论：这是最适合您的选项。 如果您的产品不介意在“关于本机”里加一行小字，或者开机闪一下 Slint 的 Logo，那您就可以白嫖这个强大的框架。
  - C. Commercial License (商业付费)
    - 功能：与上述两者完全一样，唯一的区别是 “法律特权”。
    - 特权：您可以去掉所有的 Slint Logo，完全假装这个 UI 是您自己写的。同时获得官方的技术支持工单服务。
    - 价格：属于订阅制（SaaS模式），具体需询价，通常比 Qt 便宜很多，但比免费贵。



- 需要可以接受“Made with Slint”的 Logo。对于大多数工业设备、仪器仪表、非一线消费品，用户根本不在意开机界面有没有这一行小字。
- Rust 工具链依赖：虽然您写的是 C++，但在编译环境搭建时，您通常需要安装 Rust 编译器 (cargo) 来把 .slint 编译成 C++ 代码。这对纯 C/C++ 团队来说是一个额外的环境配置成本。



### Embeding-Mono

以下为 嵌入式强相关的

单色屏



**u8g2**

U8glib library for monochrome displays

[olikraus/u8g2: U8glib library for monochrome displays, version 2 (github.com)](https://github.com/olikraus/u8g2)



一个便捷制作 ui 的工具 Lopaka

- 一篇介绍 [拯救开发者！这款在线神器让LCD/OLED屏幕UI设计效率翻倍 (qq.com)](https://mp.weixin.qq.com/s?__biz=Mzg5Nzk3OTcxNw==&mid=2247484157&idx=1&sn=19342f8bcc324b35898d1c0951694168&chksm=c068c6d7f71f4fc138c461a2a39704b39f681f165ed188706980acd6c0113406cfa7a72b2190&cur_album_id=3849885104136470528&scene=189#wechat_redirect)。

- [sbrin/lopaka: Lopaka - Stunning graphics for embedded systems displays (github.com)](https://github.com/sbrin/lopaka)

- 在线地址 [Graphics editor and image converter for Arduino, ESP32, Adafruit_GFX, u8g2, TFT_eSPI (lopaka.app)](https://lopaka.app/sandbox)




初始化库和使用 [u8g2setupc · olikraus/u8g2 Wiki (github.com)](https://github.com/olikraus/u8g2/wiki/u8g2setupc#introduction)

移植 [Porting to new MCU platform · olikraus/u8g2 Wiki (github.com) ](https://github.com/olikraus/u8g2/wiki/Porting-to-new-MCU-platform) 这里面也有一些平台的模板工程可以参考

主要是 选择 `u8g2_Setup_<display>_<i2c>_<memory>()` 初始化函数，填入通讯线和杂项这两个回调函数，前者可以选择u8g2内置的软件实现的通讯协议为`u8x8_byte_xxx()` 函数，后者要自己实现并填入（一些 IO 口设置、延时 等等的回调函数） `typedef uint8_t (*u8x8_msg_cb)(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);`



API 手册 [u8g2reference · olikraus/u8g2 Wiki (github.com)](https://github.com/olikraus/u8g2/wiki/u8g2reference)



**MonoUI 库 及其衍生**

- https://github.com/Sheep118/WouoUI-PageVersion

- https://github.com/ErBWs/Easy-UI
- https://github.com/RQNG/WouoUI



## I18N



**gettext**

使用可参考：

[使用 GNU gettext 来翻译软件 - Weblate 5.12 文档](https://docs.weblate.org/zh-cn/latest/devel/gettext.html)。

> GNU gettext 使用几个文件来管理本地化工作：
>
> - `PACKAGE.pot` 包含从您的源代码中提取的字符串，典型地使用 [xgettext](https://www.gnu.org/software/gettext/manual/html_node/xgettext-Invocation.html) 或一些高级封装，如 [intltool](https://www.freedesktop.org/wiki/Software/intltool/)。
> - `LANGUAGE.po` 包含翻译为单一语言的字符串。一旦 `PACKAGE.pot` 更新，那么必须由 [msgmerge](https://www.gnu.org/software/gettext/manual/html_node/msgmerge-Invocation.html) 来更新它。您可以使用 [msginit](https://www.gnu.org/software/gettext/manual/html_node/msginit-Invocation.html) 或在 Weblate 内新建新的语言文件。
> - `LANGUAGE.mo` 包含 `LANGUAGE.po` 的二进制表达，并且应用运行时使用。它通常并不保持在版本控制之下，但在编译时使用 [msgfmt](https://www.gnu.org/software/gettext/manual/html_node/msgfmt-Invocation.html) 生成。在您想要使它处于版本控制中时，可以使用 [生成 MO 文件](https://docs.weblate.org/zh-cn/latest/admin/addons.html#addon-weblate-gettext-mo) 附加组件在 Weblate 中生成它。

[使用gettext进行多语言国际化 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/669282869)。



**libiconv**

用于不同字符编码之间的编码转换库

[libiconv - GNU Project - Free Software Foundation (FSF)](https://www.gnu.org/software/libiconv/)。



## Time



**CCTZ**

各种时间相关的工具库。

[google/cctz: CCTZ is a C++ library for translating between absolute and civil times using the rules of a time zone.](https://github.com/google/cctz)

CCTZ contains two libraries that cooperate with `<chrono>` to give C++ programmers all the necessary tools for computing with dates, times, and time zones in a simple and correct manner. The libraries in CCTZ are:

- **The Civil-Time Library** — This is a header-only library that supports computing with human-scale time, such as dates (which are represented by the `cctz::civil_day` class). This library is declared in [`include/cctz/civil_time.h`](https://github.com/google/cctz/blob/master/include/cctz/civil_time.h).
- **The Time-Zone Library** — This library uses the IANA time zone database that is installed on the system to convert between *absolute time* and *civil time*. This library is declared in [`include/cctz/time_zone.h`](https://github.com/google/cctz/blob/master/include/cctz/time_zone.h).



## Unit testing



### Unit testing libs comparison table

GPT4o 和 DeepSeek R1 回答：

| 特性/库            | Criterion                       | GoogleTest (gtest)             | Catch2                   | CppUnit                 |
| ------------------ | ------------------------------- | ------------------------------ | ------------------------ | ----------------------- |
| **易用性**         | 简洁，易上手，文档好            | 语法较繁琐，文档丰富           | 易上手，语法简洁，灵活   | 配置较复杂，文档一般    |
| **功能**           | 支持测试用例断言，性能测试      | 支持广泛的断言和Mock           | 支持BDD风格，灵活的断言  | 基本断言，支持测试集群  |
| **性能**           | 快速，尤其适用于小型项目        | 性能较高，适合大规模项目       | 性能良好，适合中型项目   | 性能一般                |
| **可扩展性**       | 灵活，支持多种插件              | 高，支持广泛的Mock和扩展       | 灵活，支持多种自定义功能 | 支持扩展，但较为繁琐    |
| **兼容性**         | 支持CMake，简单集成             | 与CMake兼容，适合大部分C++项目 | 与CMake兼容，良好的集成  | 与CMake兼容，但配置麻烦 |
| **社区支持与维护** | 活跃，持续更新                  | 非常活跃，广泛使用，更新频繁   | 社区活跃，更新及时       | 较小，更新较慢          |
| **跨平台支持**     | 优秀，支持Linux、Windows、macOS | 优秀，支持主流平台             | 优秀，跨平台支持较好     | 支持主流平台，兼容性好  |
| **集成和支持工具** | 与CI集成良好                    | 与CI集成支持很好，很多工具支持 | CI集成支持良好，轻松集成 | 支持，但集成较麻烦      |
| **测试结果展示**   | 提供易读的格式                  | 格式标准，可定制化             | 丰富的输出，易于查看     | 输出较简单              |
| **嵌入式适配性**   | 无OS依赖                        | 资源占用高                     | 受限支持                 | 无                      |
| **现代性**         | C11兼容                         | C++11/14/17                    | C++11/14/17              | C++98                   |



GoogleTest

- 优势：
  - 功能最全：支持参数化测试、类型化测试、死亡测试（检测程序崩溃）、测试夹具（Fixtures）。
  - 生态完善：直接集成Google Mock，解决复杂依赖模拟问题。
  - 输出友好：生成xUnit格式报告，与Jenkins等CI工具无缝对接。
- 劣势：
  - 编译慢：模板元编程导致编译时间显著增加。
  - 资源占用高：不适合内存受限场景（如嵌入式）。
- 场景：中大型项目、持续集成流水线、需高覆盖率与复杂测试逻辑的场景。



如果你正在选择一个综合性能最强的单元测试库，**GoogleTest** 无疑是最好的选择。它提供了最完整的功能，支持Mock、广泛的断言功能，并且有着广泛的社区和工具支持，适合大多数中大型项目。

然而，如果你需要一个轻量级、快速上手并且文档清晰的库，**Criterion** 或 **Catch2** 是不错的选择。特别是 Catch2，支持 BDD 风格，文档好，且功能也足够丰富，适合快速开发的小型到中型项目。



### Criterion

http://criterion.readthedocs.org/

Most test frameworks for C require a lot of boilerplate code to set up tests and test suites -- you need to create a main, then register new test suites, then register the tests within these suites, and finally call the right functions.

This gives the user great control, at the unfortunate cost of simplicity.

Criterion follows the KISS principle, while keeping the control the user would have with other frameworks:

-  C99 and C++11 compatible.
-  Tests are automatically registered when declared.
-  Implements a xUnit framework structure.
-  A default entry point is provided, no need to declare a main unless you want to do special handling.
-  Test are isolated in their own process, crashes and signals can be reported and tested.
-  Unified interface between C and C++: include the criterion header and it *just* works.
-  Supports parameterized tests and theories.
-  Progress and statistics can be followed in real time with report hooks.
-  TAP output format can be enabled with an option.
-  Runs on Linux, FreeBSD, macOS, and Windows (Compiling with MinGW GCC and Visual Studio 2015+).

[Snaipe/Criterion: A cross-platform C and C++ unit testing framework for the 21st century (github.com)](https://github.com/Snaipe/Criterion)



### googletest *

[GoogleTest User’s Guide | GoogleTest](https://google.github.io/googletest/)

GoogleTest - Google Testing and Mocking Framework

[google/googletest: GoogleTest - Google Testing and Mocking Framework (github.com)](https://github.com/google/googletest)



网络参考：

[【gTest】gtest简介及简单使用-CSDN博客](https://blog.csdn.net/qq_43331089/article/details/124573730)。

[GoogleTest中gMock的使用_retiresonsaturation-CSDN博客](https://blog.csdn.net/fengbingchun/article/details/129218469)。



win 上 使用 cmake-gui 编译和安装过程：

使用 cmake-gui 打开 源码包，在 cmake-gui 的 configure 里面 勾上 build_gtest 和 build_gmock，使用动态库，设置 install 路径，勾上 gtest_install。点 config 和 generate。

执行：`make -j16`，`make install`。

编译产物放到 工具链目录里面。对于 mingw 则需要放到 ...\mingw64\x86_64-w64-mingw32，并添加 到环境变量。



一般用法：

在软件工程文件夹根目录建立一个 test 目录，里面 CMakeLists.txt 中 使用 add_subdirectory() 添加 要测试的模块文件夹（对于导出头文件路径的则不必再 target_include_directories() 否则就需要），然后 target_link_libraries 引入这些模块库；并引入 gtest 库文件 和 gtest、gmock 的头文件。然后在 test.cpp 里面编写测试代码（test suit 和 test case）。



测试例子：



CMakeLists.txt 文件：

```cmake
cmake_minimum_required(VERSION 3.16)

include(FindPkgConfig) # 或者 find_package(PkgConfig REQUIRED)

if(WIN32)
    set(ENV{PKG_CONFIG_PATH} "D:/toolchain/mingw64/x86_64-w64-mingw32/lib/pkgconfig") # 使用的 pkg-config 是 gcc 的工具，PKG_CONFIG_PATH 得是系统的环境变量
endif()

project(gtest_test LANGUAGES C CXX)

add_compile_options(
    # -O2
    -Wall -Wextra
)

set(SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(${PROJECT_NAME}
    ${SRC_FILES}
)

target_compile_options(${PROJECT_NAME} PRIVATE
    -pedantic -Wpedantic
)

pkg_check_modules(gtest REQUIRED IMPORTED_TARGET gtest) # gtest 名字 来源于 gtest.pc 文件
pkg_check_modules(gmock_main REQUIRED IMPORTED_TARGET gmock_main) # gmock_main 名字 来源于 gmock_main.pc 文件

target_link_libraries(${PROJECT_NAME} PRIVATE
    PkgConfig::gtest
    PkgConfig::gmock
)
```



main.cpp 文件（一个 使用 gmock 写测试的例子）：

```c++
#include <string>
#include "gmock/gmock.h"

namespace gmock_ {

class Foo {
public:
	// Must be virtual as we'll inherit from Foo.
	virtual ~Foo() {}

	virtual bool SetName(const std::string& name) = 0;
	virtual std::string GetName() const = 0;
};

class MockFoo : public Foo {
public:
	MOCK_METHOD(bool, SetName, (const std::string&), (override));
	MOCK_METHOD(std::string, GetName, (), (const, override));
};

class Area {
public:
	virtual ~Area() {}
	virtual int area() = 0;
};

int GetValue(Area* p) { return p->area() / 2; }

class MockArea : public Area {
public:
	MOCK_METHOD(int, area, (), (override));
};

} // namespace gmock_

TEST(gmock, name) {
	using namespace gmock_;
	using ::testing::AtLeast;
	using ::testing::Return;

	MockFoo foo;
	EXPECT_CALL(foo, SetName("Mike"))
		.Times(AtLeast(2))
		.WillOnce(Return(1))
		.WillOnce(Return(0));
	EXPECT_TRUE(foo.SetName("Mike"));
	EXPECT_FALSE(foo.SetName("Mike"));

	EXPECT_CALL(foo, GetName())
		.Times(AtLeast(1))
		.WillRepeatedly(Return("Mike"));
	EXPECT_EQ("Mike", foo.GetName());
}

TEST(gmock, area) {
	using namespace gmock_;
	using ::testing::Return;

	MockArea m;
	EXPECT_CALL(m, area()).WillRepeatedly(Return(10));
	EXPECT_EQ(5, GetValue(&m));
}
```



项目根目录新建一个 build 文件夹，进去，执行：

```bash
cmake -G "MinGW Makefiles" ..
make -j16
.\gtest_test.exe
```



### Catch2

Catch2 is mainly a unit testing framework for C++, but it also provides basic micro-benchmarking features, and simple BDD macros.

Catch2's main advantage is that using it is both simple and natural. Test names do not have to be valid identifiers, assertions look like normal C++ boolean expressions, and sections provide a nice and local way to share set-up and tear-down code in tests.

[catchorg/Catch2: A modern, C++-native, test framework for unit-tests, TDD and BDD - using C++14, C++17 and later (C++11 support is in v2.x branch, and C++03 on the Catch1.x branch) (github.com)](https://github.com/catchorg/Catch2)

[C/C++生态工具链——单元测试工具Catch2简介-CSDN博客](https://blog.csdn.net/CoderZZ_2024/article/details/136467110)。



### ThrowTheSwitch/Unity

Welcome to the Unity Test Project, one of the main projects of ThrowTheSwitch.org. Unity Test is a unit testing framework built for C, with a focus on working with embedded toolchains.

This project is made to test code targetting microcontrollers big and small. The core project is a single C file and a pair of headers, allowing it to be added to your existing build setup without too much headache. You may use any compiler you wish, and may use most existing build systems including Make, CMake, etc. If you'd like to leave the hard work to us, you might be interested in Ceedling, a build tool also by ThrowTheSwitch.org.

If you're new to Unity, we encourage you to tour the [getting started guide](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityGettingStartedGuide.md).

[ThrowTheSwitch/Unity: Simple Unit Testing for C (github.com)](https://github.com/ThrowTheSwitch/Unity)



### cppunit

[CPlusPlusUnit | cppunit](http://cppunit.github.io/cppunit/)

[CPlusPlusUnit](https://github.com/Cppunit/cppunit) - Tiny single source file C++ Unit testing TDD framework with the output message format like Python unittest.

No installation is required, just copy `Cppunit` class definition form [cppunit.h](https://github.com/cppunit/cppunit/blob/master/cppunit.h) into your source file and you are all set.

[cppunit/cppunit: CPlusPlusUnit - Tiny single source file C++ Unit Testing TDD framework with the output message format like Python unittest http://cppunit.github.io](https://github.com/cppunit/cppunit)





## Fun



### pyfiglet

字符画

[pwaller/pyfiglet: An implementation of figlet written in Python](https://github.com/pwaller/pyfiglet)



更丰富的可直接使用的 UI界面的 字符画生产工具 还可见 [coding-style-and-more/C & MCU编写规范和其他.md at main · Staok/coding-style-and-more](https://github.com/Staok/coding-style-and-more/blob/main/C %26 MCU编写规范和其他.md#字符画生产工具注释的图形化描述)。