/**
 * Server class
 *
 * @anchor liguanghui
 * @date 2019-11-18
 * @coypleft GPL 2.0
 */


//定义一个宏，作用是为了防止头文件被加载多次
//因为这个宏已经有了，定义过了，当你再加载的时候，实际就不能再加载了
#ifndef LINUX_CPP_TUTORIAL_SERVER_H
#define LINUX_CPP_TUTORIAL_SERVER_H

//定义一个命名空间，有了命名空间之后就不会与其他程序产生相互污染
//这个命名空间将整个class获取到
namespace avdance {
    class Server {
    public:
        //构造函数
        Server();

        //析构函数
        ~Server();

    public:
        void run();
    };
}  //namespace avdance
#endif //LINUX_CPP_TUTORIAL_SERVER
