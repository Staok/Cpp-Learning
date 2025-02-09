# C / C++实用库备查

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



## Misc

这里的几个库是综合性的，内涵丰富，但也比较重型，按需。



### glibc

即 GNU C Library，Linux 的标准 c 库（直接使用并编译，不用附带加载库），Linux 下原来的 标准 c 库 libc 逐渐不再被维护。



### boost c++

[Boost C++ Libraries](https://www.boost.org/)

[The Boost C++ Libraries (theboostcpplibraries.com)](https://theboostcpplibraries.com/)



### introduce_c-cpp_manual

本repo搜集全网适合C/C++新手学习的入门项目，整理收纳开发者开源的小项目、工具、框架、游戏等，帮助大家更好地学习c/c++。

[0voice/introduce_c-cpp_manual: 一个收集C/C++新手学习的入门项目，整理收纳开发者开源的小项目、工具、框架、游戏等，视频，书籍，面试题/算法题，技术文章。 (github.com)](https://github.com/0voice/introduce_c-cpp_manual)



### GLib

GLib is the low-level core library that forms the basis for projects such as GTK and GNOME. It provides data structure handling for C, portability wrappers, and interfaces for such runtime functionality as an event loop, threads, dynamic loading, and an object system.

[GNOME/glib: Read-only mirror of https://gitlab.gnome.org/GNOME/glib (github.com)](https://github.com/GNOME/glib)



glib是GTK+的基础库，综合用途的实用的轻量级的C程序库

glib 相关，源码中有 docs 手册

GLib包含了字符串操作、文件操作、数据校验、编解码、字符集转换、随机数生成器、命令行解析器、xml解析器、正则表达式、单链表、双链表、 数组、指针数组、双端队列、哈希表、平衡二叉树、N维树、泛型、主循环、多线程、线程池、异步队列、内存分配、内存片段、错误系统、测试框架等等一系列功能，称得上是C语言开发人员的军刀，值得研究。

功能罗列 [GLib2.0的一百个小知识点 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/613083129)

目录说明 [1_02_GLib库入门与实践_GLib库源代码目录结构简介_glib-2.0 库源码-CSDN博客](https://blog.csdn.net/field1003/article/details/123421451)

系列文章 [GLib库入门与实践_field1003的博客-CSDN博客](https://blog.csdn.net/field1003/category_11680135.html)



### dlib

Dlib is a modern C++ toolkit containing machine learning algorithms and tools for creating complex software in C++ to solve real world problems. See [http://dlib.net](http://dlib.net/) for the main project documentation and API reference.

[davisking/dlib: A toolkit for making real world machine learning and data analysis applications in C++ (github.com)](https://github.com/davisking/dlib)

[推荐开源库：DLib - 解决C++编程中常见任务的实用工具集-CSDN博客](https://blog.csdn.net/gitblog_00081/article/details/139734646)。



### cpp-tbox

**C++ Treasure Box** is a service-oriented **development framework** and **component library** based on the Reactor model, aim at make C++ development easy.

[cpp-main/cpp-tbox: A complete Linux application software development tool library and runtime framework, aim at make C++ development easy. (github.com)](https://github.com/cpp-main/cpp-tbox)



### ffead-cpp

ffead-cpp is a web-framework, application framework, utilities all bundled into one. It also provides an embedded HTTP/Web-Socket compliant high-performance server core. It is a collection of modules all geared towards performing individual roles which together form the cohesive back-bone of ffead-cpp.

It provides a very simple to use and maintain web-framework library with advanced features like Reflection, Dependency Injection (IOC), Inbuilt REST/SOAP support, Security/Authentication features. Moreover implementation for interfacing to caching tools like Memcached/Redis are provided in-built. Database integration/ORM framework (SDORM) solves all major issues with respect to interfacing with SQL/No-SQL database alike.

Multi-level serialization or template level serialization is a high point of ffead-cpp core serialization run-time. Any C++ POCO class can be marked as serializable and the run-time will take care of marshalling/un-marshalling the object to its intended serializable form and back(JSON/XML/BINARY).

ffead-cpp can be easily driven by XML configuration, Services/Controllers/Filters/Interfaces/API(s) are all simple POCO classes without any need for them to extend any classes. The differentiating feature in ffead-cpp is the usage/implementation/support for markers (Annotations in java). Simple **#pragma** directives can now be used to drive the entire configuration in ffead-cpp, so you can just forget XML configuration.

All in all ffead-cpp is the gap in the world of C++ web application or enterprise application development which I have tried to fill with my humble/honest effort.

[sumeetchhetri/ffead-cpp: Framework for Enterprise Application Development in c++, HTTP1/HTTP2/HTTP3 compliant, Supports multiple server backends (github.com)](https://github.com/sumeetchhetri/ffead-cpp)



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



## Parallel / Async



### parallel lib comparison table

这里需要再多一些信息来区分这些库

几个库的使用场景（使用 gpt）

> - **oneTBB** 适合大规模并行计算和高效利用多核处理器的场景。
> - **workflow** 适合需要并行计算和异步网络处理的复杂应用，尤其在分布式和高性能环境中。
> - **workspace** 更加适用于轻量级异步任务调度和并发执行，尤其在需要精细控制优先级和任务管理时。
> - **taskflow** 适合高效的任务调度系统，特别是有异构计算需求的场景（例如同时使用 CPU 和 GPU）。
> - **Asio** 则专注于网络和 I/O 密集型任务，尤其是需要处理大量并发连接的应用。



### oneTBB

oneAPI Threading Building Blocks (oneTBB)

[uxlfoundation/oneTBB: oneAPI Threading Building Blocks (oneTBB) (github.com)](https://github.com/uxlfoundation/oneTBB)



[Intel Threading Building Blocks 之 并行循环_intel threading building blocks在哪里下载-CSDN博客](https://blog.csdn.net/plutus_sutulp/article/details/21445193)

[SSE_TBB加速编程_Belial_2010的博客-CSDN博客](https://blog.csdn.net/kezunhai/category_3069039.html)



### workflow

C++ Parallel Computing and Asynchronous Networking Framework

[sogou/workflow: C++ Parallel Computing and Asynchronous Networking Framework (github.com)](https://github.com/sogou/workflow)



[workflow这个C++开源项目值得学习 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/389396903)。

[workflow开源项目学习心得 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/467427315)。



开源项目Workflow中有一个非常重要的基础模块，代码仅300行的C语言线程池。

[一个逻辑完备的线程池 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/503733481)。



### workspace *

workspace是基于C++11的轻量级异步执行框架，支持：通用任务异步并发执行、优先级任务调度、自适应动态线程池、高效静态线程池、异常处理机制等。

[CodingHanYa/workspace: workspace是基于C++11的轻量级异步执行框架，支持：通用任务异步并发执行、优先级任务调度、自适应动态线程池、高效静态线程池、异常处理机制等。 (github.com)](https://github.com/CodingHanYa/workspace)



### taskflow *

A General-purpose Task-parallel Programming System using Modern C++

Taskflow helps you quickly write parallel and heterogeneous task programs in modern C++

[taskflow/taskflow: A General-purpose Task-parallel Programming System using Modern C++ (github.com)](https://github.com/taskflow/taskflow)

[Taskflow: A General-purpose Task-parallel Programming System](https://taskflow.github.io/)。



### Asio *

Asio C++ Library

Asio is a cross-platform C++ library for network and low-level I/O programming that provides developers with a consistent asynchronous model using a modern C++ approach.

[chriskohlhoff/asio: Asio C++ Library (github.com)](https://github.com/chriskohlhoff/asio)



Folly.ThreadPoolExecutor [folly/folly/executors/ThreadPoolExecutor.h at main · facebook/folly (github.com)](https://github.com/facebook/folly/blob/main/folly/executors/ThreadPoolExecutor.h)



### ThreadPool *

A simple C++11 Thread Pool implementation

[progschj/ThreadPool: A simple C++11 Thread Pool implementation (github.com)](https://github.com/progschj/ThreadPool)



### dpool

使用 C++11 实现的动态线程池，主要特性：

- 使用简单，不易出错。
- 支持线程复用，提升性能。
- 支持懒惰创建线程。
- 必要时自动回收空闲的线程。

[senlinzhan/dpool: 使用 C++11 实现的动态线程池 (github.com)](https://github.com/senlinzhan/dpool)



### CThreadPool

`CThreadPool` 是一个跨平台的、无任何三方依赖的、高性能的C++11（含以上版本）版本的线程池，也是 [CGraph](https://github.com/ChunelFeng/CGraph) 项目中使用的跨平台线程池组件功能的最小集。

经过CGraph和关联项目的长期迭代和验证，功能已经趋于稳定，且性能优异。因为咨询相关内容的朋友较多，故做为独立的仓库提供出来，方便大家使用。

由于是CGraph项目中的剥离出来的功能类，故在项目中保留了多处 `CGRAPH_*` 的命名方式，仅将 namespace 修改为 `CTP`，预计今后与CGraph相互独立更新。

本项目参考了[《C++并发编程实战（第二版）》](https://nj.gitbooks.io/c/content/) 中的部分内容，和github上的一些优秀实现。并在此基础上进行大量的改动、扩展和优化，在功能、性能和易用性上均有较大的提升。

[ChunelFeng/CThreadPool: 【A simple used C++ threadpool】一个简单好用，性能优异的，跨平台的C++线程池。欢迎 star & fork (github.com)](https://github.com/ChunelFeng/CThreadPool)



### minicoro *

Minicoro is single-file library for using asymmetric coroutines in C. The API is inspired by [Lua coroutines](https://www.lua.org/manual/5.4/manual.html#6.2) but with C use in mind.

The project is being developed mainly to be a coroutine backend for the [Nelua](https://github.com/edubart/nelua-lang) programming language.

[edubart/minicoro: Single header stackful cross-platform coroutine library in pure C. (github.com)](https://github.com/edubart/minicoro)



## Event



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



### Libevent

[libevent](https://libevent.org/)

The *libevent* API provides a mechanism to execute a callback function when a specific event occurs on a file descriptor or after a timeout has been reached. Furthermore, *libevent* also support callbacks due to **signals** or regular **timeouts**.

*libevent* is meant to replace the event loop found in event driven network servers. An application just needs to call *event_dispatch()* and then add or remove events dynamically without having to change the event loop.

[libevent/libevent: Event notification library (github.com)](https://github.com/libevent/libevent)



### inotify-cpp

**Inotify-cpp** is a C++ wrapper for linux inotify. It lets you watch for filesystem events on your filesystem tree. The following usage example shows the implementation of a simple filesystem event watcher for the commandline.

[erikzenker/inotify-cpp: A C++ interface for linux inotify (github.com)](https://github.com/erikzenker/inotify-cpp)



## Web / Net / Async



### curl

libcurl is the library curl is using to do its job. It is readily available to be used by your software. Read [the libcurl manpage](https://curl.se/libcurl/c/libcurl.html) to learn how.

[curl/curl: A command line tool and library for transferring data with URL syntax, supporting DICT, FILE, FTP, FTPS, GOPHER, GOPHERS, HTTP, HTTPS, IMAP, IMAPS, LDAP, LDAPS, MQTT, POP3, POP3S, RTMP, RTMPS, RTSP, SCP, SFTP, SMB, SMBS, SMTP, SMTPS, TELNET, TFTP, WS and WSS. libcurl offers a myriad of powerful features (github.com)](https://github.com/curl/curl)



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
| **支持场景**   | 过于庞大，可能会为轻量级项目引入不必要的复杂性。 <br />性能相较其他轻量级库（如 `libev`）可能稍低。 <br />更倾向于**桌面环境的开发**。<br />**构建基于 GTK+ 的 GUI 应用程序**。 <br />GNOME 项目的插件开发或扩展。 <br />需要丰富工具支持的非网络类应用程序。 | **跨平台支持好**，代码高度一致（尤其适用于 Windows 和 Linux 的统一开发）。<br />提供内置的线程池支持，适合处理复杂异步操作（如文件 IO）。 <br />构建跨平台的高性能**网络服务**或工具。 <br />需要线程池支持的复杂 IO 操作场景（如文件操作、DNS 解析等）。 | 不支持线程池或高级异步操作，需要额外实现。 <br />长期以来更新速度较慢，社区活跃度比 `libuv` 和 `libev` 稍低。<br /><br />构建高性能的网络服务或服务器。 <br />不需要线程池或其他附加功能的事件驱动应用。 <br />专注于**事件和 IO 模型的小型项目**。 | 功能相对单一，仅适用于事件驱动。<br />**Windows 支持不佳**（虽然可以通过兼容层解决）。<br />需要开发者自行实现线程池或复杂操作的支持。<br />需要极高性能的事件驱动应用程序。 <br />构建单线程、高效的网络服务器。 <br />**Linux 或 Unix 系统上的轻量级服务**。 |                                                              |



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



基于libuv实现的C++11风格网络库。接口简洁，性能优越，做过业务压测，稳定线上运行。

[wlgq2/uv-cpp: libuv wrapper in C++11 /libuv C++11网络库 (github.com)](https://github.com/wlgq2/uv-cpp)



### libhv

比libevent/libuv/asio更易用的网络库。A c/c++ network library for developing TCP/UDP/SSL/HTTP/WebSocket/MQTT client/server.

[ithewei/libhv: 🔥 比libevent/libuv/asio更易用的网络库。A c/c++ network library for developing TCP/UDP/SSL/HTTP/WebSocket/MQTT client/server. (github.com)](https://github.com/ithewei/libhv)

协议 BSD 3-Clause。



### Tinyhttpd

Tinyhttpd 是J. David Blackstone在1999年写的一个不到 500 行的超轻量型 Http Server，用来学习非常不错，可以帮助我们真正理解服务器程序的本质。官网:[http://tinyhttpd.sourceforge.net](http://tinyhttpd.sourceforge.net/)

[EZLippi/Tinyhttpd: Tinyhttpd 是J. David Blackstone在1999年写的一个不到 500 行的超轻量型 Http Server，用来学习非常不错，可以帮助我们真正理解服务器程序的本质。官网:http://tinyhttpd.sourceforge.net (github.com)](https://github.com/EZLippi/Tinyhttpd)



### TinyWebServer

Linux下C++轻量级WebServer服务器

[qinguoyi/TinyWebServer: :fire: Linux下C++轻量级WebServer服务器 (github.com)](https://github.com/qinguoyi/TinyWebServer)





### cpp-httplib

A C++ header-only HTTP/HTTPS server and client library

[yhirose/cpp-httplib: A C++ header-only HTTP/HTTPS server and client library (github.com)](https://github.com/yhirose/cpp-httplib)



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



## Data / Log / Format



### Format / Protocol



#### fmt

{fmt} is an open-source formatting library providing a fast and safe alternative to C stdio and C++ iostreams.

[fmtlib/fmt: A modern formatting library (github.com)](https://github.com/fmtlib/fmt)



#### inja

看看例子就知道做什么的了，还是挺花里胡哨的，对于一些自定义格式的解析挺方便。

Inja is a template engine for modern C++, loosely inspired by [jinja](http://jinja.pocoo.org/) for python. It has an easy and yet powerful template syntax with all variables, loops, conditions, includes, callbacks, and comments you need, nested and combined as you like. Of course, everything is tested in CI on all relevant compilers.

[pantor/inja: A Template Engine for Modern C++ (github.com)](https://github.com/pantor/inja)



#### Ada-url*

ada_url

Ada is a fast and spec-compliant URL parser written in C++. Specification for URL parser can be found from the [WHATWG](https://url.spec.whatwg.org/#url-parsing) website.

The Ada library passes the full range of tests from the specification, across a wide range of platforms (e.g., Windows, Linux, macOS). It fully supports the relevant [Unicode Technical Standard](https://www.unicode.org/reports/tr46/#ToUnicode).

[Introduction - Ada URL (ada-url.com)](https://www.ada-url.com/introduction/)。

[ada-url/ada: WHATWG-compliant and fast URL parser written in modern C++, part of Node.js, Clickhouse, Redpanda, Kong, Telegram and Cloudflare Workers. (github.com)](https://github.com/ada-url/ada)



#### MQTT lib comparison table

- 选择 paho.mqtt.c：如果你需要全面的 MQTT 功能支持（如 MQTT 5.0）、跨平台兼容性和较强的社区支持，特别是当你的应用需要较复杂的消息管理时，`paho.mqtt.c` 是一个优秀的选择。
- 选择 MQTT-C：如果你的应用资源受限，或者你需要一个简单、轻量的 MQTT 客户端库来快速集成，`MQTT-C` 会是一个理想选择，特别适用于嵌入式设备。
- 选择 Mosquitto：如果你已经在使用 Mosquitto 作为 Broker，或者你需要一个既能作为 Broker 又能作为客户端使用的方案，那么使用 Mosquitto 提供的客户端库会更方便，尤其是在搭建全套 MQTT 系统时。



#### Paho.mqtt.c *

This repository contains the source code for the [Eclipse Paho](http://eclipse.org/paho) MQTT C client library.

This code builds libraries which enable applications to connect to an [MQTT](http://mqtt.org/) broker to publish messages, and to subscribe to topics and receive published messages.

Synchronous and various asynchronous programming models are supported.

[eclipse-paho/paho.mqtt.c: An Eclipse Paho C client library for MQTT for Windows, Linux and MacOS. API documentation: https://eclipse-paho.github.io/paho.mqtt.c/](https://github.com/eclipse-paho/paho.mqtt.c)。

[eclipse-paho/paho.mqtt.cpp (github.com)](https://github.com/eclipse-paho/paho.mqtt.cpp)。



doc：

[Paho MQTT C Client Library: MQTT Client library for C (MQTTClient) (eclipse-paho.github.io)](https://eclipse-paho.github.io/paho.mqtt.c/MQTTClient/html/)



#### MQTT-C *

MQTT-C is an [MQTT v3.1.1](http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/os/mqtt-v3.1.1-os.html) client written in C. MQTT is a lightweight publisher-subscriber-based messaging protocol that is commonly used in IoT and networking applications where high-latency and low data-rate links are expected. The purpose of MQTT-C is to provide a **portable** MQTT client, **written in C**, for embedded systems and PC's alike. MQTT-C does this by providing a transparent Platform Abstraction Layer (PAL) which makes porting to new platforms easy. MQTT-C is completely thread-safe but can also run perfectly fine on single-threaded systems making MQTT-C well-suited for embedded systems and microcontrollers. Finally, MQTT-C is small; there are only two source files totalling less than 2000 lines.

[LiamBindle/MQTT-C: A portable MQTT C client for embedded systems and PCs alike. (github.com)](https://github.com/LiamBindle/MQTT-C)



#### Mosquitto

Mosquitto is an open source implementation of a server for version 5.0, 3.1.1, and 3.1 of the MQTT protocol. It also includes a C and C++ client library, and the `mosquitto_pub` and `mosquitto_sub` utilities for publishing and subscribing.

[eclipse-mosquitto/mosquitto: Eclipse Mosquitto - An open source MQTT broker (github.com)](https://github.com/eclipse-mosquitto/mosquitto)



doc:

[Documentation | Eclipse Mosquitto](https://mosquitto.org/documentation/)



#### nlohmann-json *

There are myriads of [JSON](https://json.org/) libraries out there, and each may even have its reason to exist. Our class had these design goals:

- **Intuitive syntax**. In languages such as Python, JSON feels like a first class data type. We used all the operator magic of modern C++ to achieve the same feeling in your code. Check out the [examples below](https://github.com/nlohmann/json#examples) and you'll know what I mean.
- **Trivial integration**. Our whole code consists of a single header file [`json.hpp`](https://github.com/nlohmann/json/blob/develop/single_include/nlohmann/json.hpp). That's it. No library, no subproject, no dependencies, no complex build system. The class is written in vanilla C++11. All in all, everything should require no adjustment of your compiler flags or project settings.
- **Serious testing**. Our code is heavily [unit-tested](https://github.com/nlohmann/json/tree/develop/tests/src) and covers [100%](https://coveralls.io/r/nlohmann/json) of the code, including all exceptional behavior. Furthermore, we checked with [Valgrind](https://valgrind.org/) and the [Clang Sanitizers](https://clang.llvm.org/docs/index.html) that there are no memory leaks. [Google OSS-Fuzz](https://github.com/google/oss-fuzz/tree/master/projects/json) additionally runs fuzz tests against all parsers 24/7, effectively executing billions of tests so far. To maintain high quality, the project is following the [Core Infrastructure Initiative (CII) best practices](https://bestpractices.coreinfrastructure.org/projects/289).

Other aspects were not so important to us:

- **Memory efficiency**. Each JSON object has an overhead of one pointer (the maximal size of a union) and one enumeration element (1 byte). The default generalization uses the following C++ data types: `std::string` for strings, `int64_t`, `uint64_t` or `double` for numbers, `std::map` for objects, `std::vector` for arrays, and `bool` for Booleans. However, you can template the generalized class `basic_json` to your needs.
- **Speed**. There are certainly [faster JSON libraries](https://github.com/miloyip/nativejson-benchmark#parsing-time) out there. However, if your goal is to speed up your development by adding JSON support with a single header, then this library is the way to go. If you know how to use a `std::vector` or `std::map`, you are already set.

[nlohmann/json: JSON for Modern C++ (github.com)](https://github.com/nlohmann/json)



#### cJSON

Ultralightweight JSON parser in ANSI C.

[DaveGamble/cJSON: Ultralightweight JSON parser in ANSI C (github.com)](https://github.com/DaveGamble/cJSON)



#### tinyxml2 *

TinyXML-2 is a simple, small, efficient, C++ XML parser that can be easily integrated into other programs.

[leethomason/tinyxml2: TinyXML2 is a simple, small, efficient, C++ XML parser that can be easily integrated into other programs. (github.com)](https://github.com/leethomason/tinyxml2)



#### yaml-cpp *

`yaml-cpp` is a [YAML](http://www.yaml.org/) parser and emitter in C++ matching the [YAML 1.2 spec](http://www.yaml.org/spec/1.2/spec.html).

[jbeder/yaml-cpp: A YAML parser and emitter in C++ (github.com)](https://github.com/jbeder/yaml-cpp)



#### md4c

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



#### CLI11 *

CLI11 is a command line parser for C++11 and beyond that provides a rich feature set with a simple and intuitive interface.

[CLIUtils/CLI11: CLI11 is a command line parser for C++11 and beyond that provides a rich feature set with a simple and intuitive interface. (github.com)](https://github.com/CLIUtils/CLI11)



### database



#### sqlite *

Official Git mirror of the SQLite source tree

[sqlite/sqlite: Official Git mirror of the SQLite source tree (github.com)](https://github.com/sqlite/sqlite)



#### SQLiteCpp

SQLiteC++ (SQLiteCpp) is a smart and easy to use C++ SQLite3 wrapper.

[SRombauts/SQLiteCpp: SQLiteC++ (SQLiteCpp) is a smart and easy to use C++ SQLite3 wrapper. (github.com)](https://github.com/SRombauts/SQLiteCpp)

[SRombauts/SQLiteCpp_Example: C++ Example project using SQLiteCpp as a Git submodule / CMake subdirectory (github.com)](https://github.com/SRombauts/SQLiteCpp_Example)



### Log

#### log4cplus *

[log4cplus](https://github.com/log4cplus/log4cplus) is a simple to use C++23 logging API providing thread--safe, flexible, and arbitrarily granular control over log management and configuration. It is modeled after the Java log4j API.

[log4cplus/log4cplus: log4cplus is a simple to use C++ logging API providing thread-safe, flexible, and arbitrarily granular control over log management and configuration. It is modelled after the Java log4j API. (github.com)](https://github.com/log4cplus/log4cplus)



#### EasyLogger

An ultra-lightweight(ROM<1.6K, RAM<0.3k), high-performance C/C++ log library. | 一款超轻量级(ROM<1.6K, RAM<0.3k)、高性能的 C/C++ 日志库

[armink/EasyLogger: An ultra-lightweight(ROM<1.6K, RAM<0.3k), high-performance C/C++ log library. | 一款超轻量级(ROM<1.6K, RAM<0.3k)、高性能的 C/C++ 日志库 (github.com)](https://github.com/armink/EasyLogger)

#### FlashDB

An ultra-lightweight database that supports key-value and time series data | 一款支持 KV 数据和时序数据的超轻量级数据库

[armink/FlashDB: An ultra-lightweight database that supports key-value and time series data | 一款支持 KV 数据和时序数据的超轻量级数据库 (github.com)](https://github.com/armink/FlashDB)



https://github.com/storaged-project/udisks)



#### spdlog

Fast C++ logging library.

[gabime/spdlog: Fast C++ logging library. (github.com)](https://github.com/gabime/spdlog)



#### pdf

##### JagPDF

JagPDF is a free, open source library for generating PDF documents.

The goal of this project is to provide a fast and reliable library that is usable in both server and desktop environments. The library is written in C++ and provides bindings for other languages. It runs on x86/Linux, amd64/Linux and x86/Windows platforms.

JagPDF aims to be easy to use, have a look at Hello World examples in [C++](http://www.jagpdf.org/doc/jagpdf/usersguide/quick_start.htm#jagpdf.usersguide.quick_start.hello_world.c__), [Python](http://www.jagpdf.org/doc/jagpdf/usersguide/quick_start.htm#jagpdf.usersguide.quick_start.hello_world.python), [Java](http://www.jagpdf.org/doc/jagpdf/usersguide/quick_start.htm#jagpdf.usersguide.quick_start.hello_world.java) or [C](http://www.jagpdf.org/doc/jagpdf/usersguide/quick_start.htm#jagpdf.usersguide.quick_start.hello_world.c). The library implements a [fairly large subset](http://www.jagpdf.org/features.htm) of the PDF specification which enables creation of a broad range of [document types](http://www.jagpdf.org/samples.htm).

The library is distributed under the [MIT license](http://www.jagpdf.org/license.htm) which encourages both commercial and non-commercial usage.

[JagPDF - PDF Generation Library](http://www.jagpdf.org/index.htm)



##### libharu

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

[dbus-cxx/dbus-cxx: DBus-cxx provides an object-oriented interface to DBus (github.com)](https://github.com/dbus-cxx/dbus-cxx)



### protobuf *

Protocol Buffers (a.k.a., protobuf) are Google's language-neutral, platform-neutral, extensible mechanism for serializing structured data. You can learn more about it in [protobuf's documentation](https://protobuf.dev/).

[protocolbuffers/protobuf: Protocol Buffers - Google's data interchange format (github.com)](https://github.com/protocolbuffers/protobuf)



### EmbeddedRPC

Embedded RPC

[EmbeddedRPC/erpc: Embedded RPC (github.com)](https://github.com/EmbeddedRPC/erpc)



## Argo / Crypto



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



### zip

#### zlib

zlib is a general purpose data compression library.  All the code is thread safe.  The data format used by the zlib library is described by RFCs (Request for Comments)

[madler/zlib: A massively spiffy yet delicately unobtrusive compression library. (github.com)](https://github.com/madler/zlib)



#### zstr

A C++ header-only ZLib wrapper

[mateidavid/zstr: A C++ header-only ZLib wrapper (github.com)](https://github.com/mateidavid/zstr)



#### libzip

This is libzip, a C library for reading, creating, and modifying zip and zip64 archives. Files can be added from data buffers, files, or compressed data copied directly from other zip archives. Changes made without closing the archive can be reverted. Decryption and encryption of Winzip AES and legacy PKware encrypted files is supported.

libzip is fully documented via man pages. HTML versions of the man pages are on [libzip.org](https://libzip.org/documentation/) and in the [man](https://github.com/nih-at/libzip/blob/main/man) directory. You can start with [libzip(3)](https://libzip.org/documentation/libzip.html), which lists all others. Example source code is in the [examples](https://github.com/nih-at/libzip/blob/main/examples) and [src](https://github.com/nih-at/libzip/blob/main/src) subdirectories.

[nih-at/libzip: A C library for reading, creating, and modifying zip archives. (github.com)](https://github.com/nih-at/libzip)



#### LibZippp

libzippp is a simple basic C++ wrapper around the libzip library. It is meant to be a portable and easy-to-use library for ZIP handling.

Underlying libraries:

- [ZLib](https://zlib.net/) 1.3.1
- [libzip](https://www.nih.at/libzip) 1.11.2

[ctabin/libzippp: C++ wrapper for libzip (github.com)](https://github.com/ctabin/libzippp)



### QR-Code-generator

This project aims to be the best, clearest QR Code generator library in multiple languages. The primary goals are flexible options and absolute correctness. Secondary goals are compact implementation size and good documentation comments.

[nayuki/QR-Code-generator: High-quality QR Code generator library in Java, TypeScript/JavaScript, Python, Rust, C++, C. (github.com)](https://github.com/nayuki/QR-Code-generator)



## Scientific Computing



### Matrix

[mlcpp/Matrix: Easy-to-use Scientific Computing library in/for C++ available for Linux and Windows. (github.com)](https://github.com/mlcpp/Matrix)



### NumCpp

A Templatized Header Only C++ Implementation of the [Python NumPy Library](http://www.numpy.org/)。

[dpilger26/NumCpp: C++ implementation of the Python Numpy library (github.com)](https://github.com/dpilger26/NumCpp)



### Matrix_hub

A lib of Matrix operation for C language. (矩阵运算库--C语言)

[Amoiensis/Matrix_hub: A lib of Matrix operation for C language. (矩阵运算库--C语言) (github.com)](https://github.com/Amoiensis/Matrix_hub)



## Language Bind

### Lua

一种轻量级多范式脚本语言，主要设计用于嵌入使用。C 库。

[The Programming Language Lua](https://www.lua.org/)



### sol2

一个绑定 Lua 的现代 C++ 库。

sol2 is a C++ library binding to Lua. It currently supports all Lua versions 5.1+ (LuaJIT 2.0+ and MoonJIT included). sol2 aims to be easy to use and easy to add to a project. The library is header-only for easy integration with projects, and a single header can be used for drag-and-drop start up.

[ThePhD/sol2: Sol3 (sol2 v3.0) - a C++ <-> Lua API wrapper with advanced features and top notch performance - is here, and it's great! Documentation: (github.com)](https://github.com/ThePhD/sol2)



## Device



### UDisks

The UDisks project provides a daemon, tools and libraries to access and manipulate disks, storage devices and technologies.

For API stability and intended audience of UDisks, see the API STABILITY and AUDIENCE section of the `udisks(8)` man page (`doc/man/udisks.xml` in the tarball and git repository).

[storaged-project/udisks: The UDisks project provides a daemon, tools and libraries to access and manipulate disks, storage devices and technologies. (github.com)](



### libusb

libusb is a library for USB device access from Linux, macOS, Windows, OpenBSD/NetBSD, Haiku, Solaris userspace, and WebAssembly via WebUSB. It is written in C (Haiku backend in C++) and licensed under the GNU Lesser General Public License version 2.1 or, at your option, any later version (see [COPYING](https://github.com/libusb/libusb/blob/master/COPYING)).

libusb is abstracted internally in such a way that it can hopefully be ported to other operating systems. Please see the [PORTING](https://github.com/libusb/libusb/blob/master/PORTING) file for more information.

libusb homepage: https://libusb.info/

[libusb/libusb: A cross-platform library to access USB devices (github.com)](https://github.com/libusb/libusb)



## Embedded



### ETL

实现了资源节省的、固定内存分配的 C++ 的各种基本功能，采用回调函数的方式与 嵌入式 mcu 设备中的 各种 uart、timer 等中断回调进行连接，来使得能够用 c++ 来编写 mcu 代码。

C++ is a great language to use for embedded applications and templates are a powerful aspect. The standard library can offer a great deal of well tested functionality, but there are some parts of the standard library that do not fit well with deterministic behaviour and limited resource requirements. These limitations usually preclude the use of dynamically allocated memory and containers with open ended sizes.

What is needed is a template library where the user can declare the size, or maximum size of any object upfront. Most embedded compilers do not currently support the standard beyond C++ 03, therefore excluding the programmer from using the enhanced features of the later library.

This is what the ETL attempts to achieve.

[ETLCPP/etl: Embedded Template Library (github.com)](https://github.com/ETLCPP/etl)



## Unit testing

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



### googletest

[GoogleTest User’s Guide | GoogleTest](https://google.github.io/googletest/)

GoogleTest - Google Testing and Mocking Framework

[google/googletest: GoogleTest - Google Testing and Mocking Framework (github.com)](https://github.com/google/googletest)



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