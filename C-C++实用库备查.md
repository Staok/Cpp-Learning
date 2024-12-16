# C / C++实用库备查

网络参考源：

- [Your list / 实用库 / EE-CS (github.com)](https://github.com/stars/Staok/lists/实用库-ee-cs)。
- [你工作中最推荐的 C/C++ 程序库有哪些，为什么？ - 知乎 (zhihu.com)](https://www.zhihu.com/question/51134387)。

以下是自总结的平时用到的、好用的库和一些网络上推荐的库的集合。基本上，每个领域只推荐一个 或 两个 相关领域 最常用的、最主流的。排序不分先后。

~~每个库会尽量有这几个部分：自写的一段话简介（库所提供的基础能力概括）、项目网址（官网 或者 github 仓库网址 等）、网友写的一些比较好的入门教程、win 以及 linux 上的安装（保证方法具有普适性，必能跑通）、几段使用例子（由简单到复杂，是自己本地跑起来的自写的例子，以及指明官方提供的较系统的 demo 所在）。~~



## Misc



### introduce_c-cpp_manual

本repo搜集全网适合C/C++新手学习的入门项目，整理收纳开发者开源的小项目、工具、框架、游戏等，帮助大家更好地学习c/c++。

[0voice/introduce_c-cpp_manual: 一个收集C/C++新手学习的入门项目，整理收纳开发者开源的小项目、工具、框架、游戏等，视频，书籍，面试题/算法题，技术文章。 (github.com)](https://github.com/0voice/introduce_c-cpp_manual)



### GLib

GLib is the low-level core library that forms the basis for projects such as GTK and GNOME. It provides data structure handling for C, portability wrappers, and interfaces for such runtime functionality as an event loop, threads, dynamic loading, and an object system.

[GNOME/glib: Read-only mirror of https://gitlab.gnome.org/GNOME/glib (github.com)](https://github.com/GNOME/glib)



### dlib

Dlib is a modern C++ toolkit containing machine learning algorithms and tools for creating complex software in C++ to solve real world problems. See [http://dlib.net](http://dlib.net/) for the main project documentation and API reference.

[davisking/dlib: A toolkit for making real world machine learning and data analysis applications in C++ (github.com)](https://github.com/davisking/dlib)



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



## Parallel / Async



几个库的使用场景（使用 gpt）

> - **oneTBB** 适合大规模并行计算和高效利用多核处理器的场景。
> - **workflow** 适合需要并行计算和异步网络处理的复杂应用，尤其在分布式和高性能环境中。
> - **workspace** 更加适用于轻量级异步任务调度和并发执行，尤其在需要精细控制优先级和任务管理时。
> - **taskflow** 适合高效的任务调度系统，特别是有异构计算需求的场景（例如同时使用 CPU 和 GPU）。
> - **Asio** 则专注于网络和 I/O 密集型任务，尤其是需要处理大量并发连接的应用。



### oneTBB

oneAPI Threading Building Blocks (oneTBB)

[uxlfoundation/oneTBB: oneAPI Threading Building Blocks (oneTBB) (github.com)](https://github.com/uxlfoundation/oneTBB)



### workflow

C++ Parallel Computing and Asynchronous Networking Framework

[sogou/workflow: C++ Parallel Computing and Asynchronous Networking Framework (github.com)](https://github.com/sogou/workflow)



### workspace *

workspace是基于C++11的轻量级异步执行框架，支持：通用任务异步并发执行、优先级任务调度、自适应动态线程池、高效静态线程池、异常处理机制等。

[CodingHanYa/workspace: workspace是基于C++11的轻量级异步执行框架，支持：通用任务异步并发执行、优先级任务调度、自适应动态线程池、高效静态线程池、异常处理机制等。 (github.com)](https://github.com/CodingHanYa/workspace)



### taskflow *

A General-purpose Task-parallel Programming System using Modern C++

Taskflow helps you quickly write parallel and heterogeneous task programs in modern C++

[taskflow/taskflow: A General-purpose Task-parallel Programming System using Modern C++ (github.com)](https://github.com/taskflow/taskflow)



### Asio *

Asio C++ Library

Asio is a cross-platform C++ library for network and low-level I/O programming that provides developers with a consistent asynchronous model using a modern C++ approach.

[chriskohlhoff/asio: Asio C++ Library (github.com)](https://github.com/chriskohlhoff/asio)



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



### libuv

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



### libhv *

比libevent/libuv/asio更易用的网络库。A c/c++ network library for developing TCP/UDP/SSL/HTTP/WebSocket/MQTT client/server.

[ithewei/libhv: 🔥 比libevent/libuv/asio更易用的网络库。A c/c++ network library for developing TCP/UDP/SSL/HTTP/WebSocket/MQTT client/server. (github.com)](https://github.com/ithewei/libhv)



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



#### Ada *

Ada is a fast and spec-compliant URL parser written in C++. Specification for URL parser can be found from the [WHATWG](https://url.spec.whatwg.org/#url-parsing) website.

The Ada library passes the full range of tests from the specification, across a wide range of platforms (e.g., Windows, Linux, macOS). It fully supports the relevant [Unicode Technical Standard](https://www.unicode.org/reports/tr46/#ToUnicode).

[ada-url/ada: WHATWG-compliant and fast URL parser written in modern C++, part of Node.js, Clickhouse, Redpanda, Kong, Telegram and Cloudflare Workers. (github.com)](https://github.com/ada-url/ada)



#### MQTT-C *

MQTT-C is an [MQTT v3.1.1](http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/os/mqtt-v3.1.1-os.html) client written in C. MQTT is a lightweight publisher-subscriber-based messaging protocol that is commonly used in IoT and networking applications where high-latency and low data-rate links are expected. The purpose of MQTT-C is to provide a **portable** MQTT client, **written in C**, for embedded systems and PC's alike. MQTT-C does this by providing a transparent Platform Abstraction Layer (PAL) which makes porting to new platforms easy. MQTT-C is completely thread-safe but can also run perfectly fine on single-threaded systems making MQTT-C well-suited for embedded systems and microcontrollers. Finally, MQTT-C is small; there are only two source files totalling less than 2000 lines.

[LiamBindle/MQTT-C: A portable MQTT C client for embedded systems and PCs alike. (github.com)](https://github.com/LiamBindle/MQTT-C)



#### nlohmann/json *

There are myriads of [JSON](https://json.org/) libraries out there, and each may even have its reason to exist. Our class had these design goals:

- **Intuitive syntax**. In languages such as Python, JSON feels like a first class data type. We used all the operator magic of modern C++ to achieve the same feeling in your code. Check out the [examples below](https://github.com/nlohmann/json#examples) and you'll know what I mean.
- **Trivial integration**. Our whole code consists of a single header file [`json.hpp`](https://github.com/nlohmann/json/blob/develop/single_include/nlohmann/json.hpp). That's it. No library, no subproject, no dependencies, no complex build system. The class is written in vanilla C++11. All in all, everything should require no adjustment of your compiler flags or project settings.
- **Serious testing**. Our code is heavily [unit-tested](https://github.com/nlohmann/json/tree/develop/tests/src) and covers [100%](https://coveralls.io/r/nlohmann/json) of the code, including all exceptional behavior. Furthermore, we checked with [Valgrind](https://valgrind.org/) and the [Clang Sanitizers](https://clang.llvm.org/docs/index.html) that there are no memory leaks. [Google OSS-Fuzz](https://github.com/google/oss-fuzz/tree/master/projects/json) additionally runs fuzz tests against all parsers 24/7, effectively executing billions of tests so far. To maintain high quality, the project is following the [Core Infrastructure Initiative (CII) best practices](https://bestpractices.coreinfrastructure.org/projects/289).

Other aspects were not so important to us:

- **Memory efficiency**. Each JSON object has an overhead of one pointer (the maximal size of a union) and one enumeration element (1 byte). The default generalization uses the following C++ data types: `std::string` for strings, `int64_t`, `uint64_t` or `double` for numbers, `std::map` for objects, `std::vector` for arrays, and `bool` for Booleans. However, you can template the generalized class `basic_json` to your needs.
- **Speed**. There are certainly [faster JSON libraries](https://github.com/miloyip/nativejson-benchmark#parsing-time) out there. However, if your goal is to speed up your development by adding JSON support with a single header, then this library is the way to go. If you know how to use a `std::vector` or `std::map`, you are already set.

[nlohmann/json: JSON for Modern C++ (github.com)](https://github.com/nlohmann/json)



#### sjson

a light weight json streaming library, run fast without any memory allocation

[tristanlee/sjson: a light weight json streaming library, run fast without any memory allocation (github.com)](https://github.com/tristanlee/sjson)



#### tinyxml2 *

TinyXML-2 is a simple, small, efficient, C++ XML parser that can be easily integrated into other programs.

[leethomason/tinyxml2: TinyXML2 is a simple, small, efficient, C++ XML parser that can be easily integrated into other programs. (github.com)](https://github.com/leethomason/tinyxml2)



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



### zlib

zlib is a general purpose data compression library.  All the code is thread safe.  The data format used by the zlib library is described by RFCs (Request for Comments)

[madler/zlib: A massively spiffy yet delicately unobtrusive compression library. (github.com)](https://github.com/madler/zlib)



### libzip *

This is libzip, a C library for reading, creating, and modifying zip and zip64 archives. Files can be added from data buffers, files, or compressed data copied directly from other zip archives. Changes made without closing the archive can be reverted. Decryption and encryption of Winzip AES and legacy PKware encrypted files is supported.

libzip is fully documented via man pages. HTML versions of the man pages are on [libzip.org](https://libzip.org/documentation/) and in the [man](https://github.com/nih-at/libzip/blob/main/man) directory. You can start with [libzip(3)](https://libzip.org/documentation/libzip.html), which lists all others. Example source code is in the [examples](https://github.com/nih-at/libzip/blob/main/examples) and [src](https://github.com/nih-at/libzip/blob/main/src) subdirectories.

[nih-at/libzip: A C library for reading, creating, and modifying zip archives. (github.com)](https://github.com/nih-at/libzip)



### zstr

A C++ header-only ZLib wrapper

[mateidavid/zstr: A C++ header-only ZLib wrapper (github.com)](https://github.com/mateidavid/zstr)



### Matrix_hub

A lib of Matrix operation for C language. (矩阵运算库--C语言)

[Amoiensis/Matrix_hub: A lib of Matrix operation for C language. (矩阵运算库--C语言) (github.com)](https://github.com/Amoiensis/Matrix_hub)



### QR-Code-generator

This project aims to be the best, clearest QR Code generator library in multiple languages. The primary goals are flexible options and absolute correctness. Secondary goals are compact implementation size and good documentation comments.

[nayuki/QR-Code-generator: High-quality QR Code generator library in Java, TypeScript/JavaScript, Python, Rust, C++, C. (github.com)](https://github.com/nayuki/QR-Code-generator)





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