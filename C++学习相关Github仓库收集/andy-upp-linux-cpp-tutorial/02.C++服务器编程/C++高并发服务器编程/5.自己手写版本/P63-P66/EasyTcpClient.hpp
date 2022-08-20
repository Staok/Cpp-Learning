#ifndef _EasyTcpClient_hpp_
#define _EasyTcpClient_hpp_
#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN
	#define _WINSOCK_DEPRECATED_NO_WARNINGS
	
	#include <WinSock2.h>
	#include <windows.h>
	#pragma comment(lib,"ws2_32.lib")	//解决库调用  我们用通用的方法 已经在属性中添加了
#else
	#include <unistd.h>             //unix的标准库
	#include <arpa/inet.h>
	#include <string.h>

	//解决宏定义 
	#define SOCKET int
	#define INVALID_SOCKET (SOCKET)(~0)
	#define SOCKET_ERROR (-1)
#endif

#include <stdio.h>
#include "MessageHeader.hpp"


class EasyTcpClient
{
    SOCKET _sock;
public:
    EasyTcpClient()
    {
       _sock = INVALID_SOCKET;
    }
    //析构函数通常写成虚析构函数
    //析构函数执行时先调用派生类的析构函数，其次才调用基类的析构函数。如果析构函数不是虚函数，而程序执行时又要通过基类的指针去销毁派生类的动态对象，那么用delete销毁对象时，只调用了基类的析构函数，未调用派生类的析构函数。这样会造成销毁对象不完全。
    virtual ~EasyTcpClient()
    {
        Close();
    }

    //初始化socket
    void InitSocket()
    {
#ifdef _WIN32
	//启动window socket 环境
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);
#endif
	//1、建立一个套接字
    //如果之前不是INVALID_SOCKET，说明没有初始化
    //过，可能连接到别的服务器上了
    if (INVALID_SOCKET != _sock)
    {
        //此时客户端需要检测一下，有连接的话，就关闭掉
        printf("<socket=%d>关闭之前链接...\n",_sock);
        Close();
    }
	_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == _sock)
	{
		printf("错误，建立Socket失败...\n");
	}
	else
	{
		printf("建立Socket成功...\n");
	}
    }

    //连接服务器
    int Connect(const char* ip, unsigned short port)
    {
    //连接的时候 如果是无效的 则需要初始化
    if (INVALID_SOCKET == _sock)
    {
        InitSocket();
    }
	//2、连接服务器 connect
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(port); //连接到服务端的4567端口号
#ifdef _WIN32
	_sin.sin_addr.S_un.S_addr = inet_addr(ip);	//127.0.0.1
#else
	_sin.sin_addr.s_addr = inet_addr(ip);
#endif
	int ret = connect(_sock, (sockaddr*)&_sin, sizeof(sockaddr_in));
	if (SOCKET_ERROR == ret)
	{
		printf("错误，连接服务器失败...\n");
	}
	else
	{
		printf("连接服务器成功...\n");
	}
	return ret;
    }

    //关闭socket
    void Close()
    {
       //为了防止重复调用，否则多次析构就会有问题
       if(_sock != INVALID_SOCKET)
       {
#ifdef _WIN32
	    closesocket(_sock);
	    WSACleanup();
#else
	    close(_sock);
#endif
        _sock = INVALID_SOCKET;
        }
    }

    //处理网络消息
    bool OnRun()
    {
        if (isRun())
        {
            fd_set fdRead;
            FD_ZERO(&fdRead);
            FD_SET(_sock, &fdRead);

            timeval t = { 1,0 };//前面是秒 后面是毫秒       让select每隔1秒去扫描一下
            int ret = select(_sock + 1, &fdRead, 0, 0, &t);

            if (ret < 0)
            {
                printf("<socket=%s>select任务结束",_sock);
                return false;
            }
            if (FD_ISSET(_sock, &fdRead))
            {
                FD_CLR(_sock, &fdRead);
                if (-1 == RecvData(_sock))
                {
                    printf("<socket=%s>select任务结束",_sock);
                    return false;
                }
            }
            return true;
        }
            return false;
    }
    //判断socket是否在运行中
    bool isRun()
    {
        return _sock != INVALID_SOCKET;
    }
    
    //接收数据 处理粘包 拆分包
    int RecvData(SOCKET _cSock)
    {
        //缓冲区
        char szRecv[4096] = {};
        //接收服务器信息 参数 服务端套接字 数据缓冲区 数据缓冲区的字节数 默认值(作为预留位置)
        int len = recv(_cSock, szRecv, sizeof(DataHeader), 0);
        DataHeader* header = (DataHeader*)szRecv;
        if (len <= 0)
        {
            printf("与服务器断开连接，任务结束\n");
            return -1;
        }
        
        recv(_cSock, szRecv + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
        
        OnNetMsg(header);
        return 0;        
    }

    //响应网络消息
    void OnNetMsg(DataHeader* header)
    {
        switch (header->cmd)
        {

            case CMD_LOGIN_RESULT:
            {
                    LoginResult *login = (LoginResult*)header;
                    printf("收到服务器的消息：CMD_LOGIN_RESULT, 数据长度%d \n", header->dataLength);
                    break;
            }
            case CMD_LOGOUT_RESULT:
            {
                    LogoutResult *logout = (LogoutResult*)header;
                    printf("收到服务器的消息：CMD_LOGIN_RESULT, 数据长度%d \n", header->dataLength);
                    break;
            }
            case CMD_NEW_USER_JOIN:
            {
                    NewUserJoin *userjoin = (NewUserJoin*)header;
                    printf("收到服务器的消息：CMD_NEW_USER_JOIN, 数据长度%d \n", header->dataLength);
                    break;
            }
        }
    }

    //发送数据
    int SendData(DataHeader* header)
    {
        if(isRun() && header)
        {
            return send(_sock, (const char*)header, header->dataLength, 0 );
        }
        return SOCKET_ERROR;
    }
private:
};


#endif