//通过预定义宏区分 windows 平台和 linux 平台
#ifdef _WIN32
   #define WIN32_LEAN_AND_MEAN 
   #include <windows.h>  //window基础函数头文件
   #include <WinSock2.h> 
#else
   #include <unistd.h>   //unix 下的函数标准头文件
   #include <arpa/inet.h>
   #include <string.h>
   #define SOCKET int
   #define INVALID_SOCKET (SOCKET)(-0)
   #define SOCKET_ERROR           (-1)
#endif

#include <stdio.h>
#include <thread>


int main()
{
    /*
    Windows平台
    启动 windows socket 2.x 环境
    WORD ver = MAKEWORD(2,2);
    WSADATA dat;
    WSAStartup(ver,&dat);
    */
    //---------------------------------
    // 用Socket API建立简易TCP服务器
    // 1. 建立一个socket
    // 2. bind 绑定用于接受客户端连接的网络接口
    // 3. listen 监听网络端口
    // 4. accept 等待接受客户端连接
    // 5. send 向客户端发送一条数据
    // 6. 关闭套接字 closesocket 

    //---------------------------------
     
    //清除WIndows 环境







   

    return 0;
}