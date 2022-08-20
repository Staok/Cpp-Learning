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
#include <vector>

enum CMD //枚举登录和登出
{
	CMD_LOGIN,
	CMD_LOGIN_RESULT,
	CMD_LOGOUT,
	CMD_LOGOUT_RESULT,
	CMD_NEW_USER_JOIN,
	CMD_ERROR
};

struct DataHeader //定义数据包头
{
	short dataLength;
	short cmd;
};

//子类继承父类中的数据
struct Login : public DataHeader//定义一个结构体封装数据
{
	Login()
	{
		dataLength = sizeof(Login);
		cmd = CMD_LOGIN;
	}
	char userName[32];
	char passWord[32];
};

struct LoginResult : public DataHeader  //返回登录的结果
{
	LoginResult()
	{
		dataLength = sizeof(LoginResult);
		cmd = CMD_LOGIN_RESULT;
		result = 1;
	}
	int result;
};

struct Logout : public DataHeader               //返回谁要退出
{
	Logout()
	{
		dataLength = sizeof(Logout);
		cmd = CMD_LOGOUT;
	}
	char username[32];
};
struct LogoutResult : public DataHeader         //返回登出的结果
{
	LogoutResult()
	{
		dataLength = sizeof(LogoutResult);
		cmd = CMD_LOGOUT_RESULT;
		result = 0;
	}
	int result;
};
struct NewUserJoin : public DataHeader          //新用户加入
{
	NewUserJoin()
	{
		dataLength = sizeof(NewUserJoin);
		cmd = CMD_NEW_USER_JOIN;
		scok = 0;
	}
	int scok;
};

std::vector<SOCKET> g_clients;  //存放所有的socket

int processor(SOCKET _cSock)            //专门处理接受到的消息
{

	//缓冲区
	char szRecv[4096] = {};
	int len = (int)recv(_cSock, szRecv, sizeof(DataHeader), 0);
	DataHeader* header = (DataHeader*)szRecv;
	if (len <= 0)
	{
		printf("客户端 %d 已经退出，任务结束\n",_cSock);
		return -1;
	}
	//对命令进行判断
	switch (header->cmd)
	{
    //5.send 向客户端发送一条数据
	// 登录
	case CMD_LOGIN:
	{
		//注意 这里为什么要加 sizeof(DataHe ader)和减去sizeof(DataHeader)  是因为 前面 我们已经接受了一次头  所以 这里要做地址偏移
		recv(_cSock, szRecv + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
		Login *login = (Login*)szRecv;
		printf("收到客户端 %d 的命令：CMD_LOGIN, 数据长度%d ,userName = %s Password = %s\n", _cSock, login->dataLength, login->userName, login->passWord);
		//忽略判断用户密码是否正确的过程
		LoginResult ret;
		//返回消息
		send(_cSock, (char*)&ret, sizeof(LoginResult), 0);
		break;
	}
	//登出
	case CMD_LOGOUT:
	{
		Logout *logout = (Logout*)szRecv;
		recv(_cSock, szRecv + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
		printf("收到客户端 %d 的命令：CMD_LOGOUT, 数据长度%d ,userName = %s\n", _cSock, logout->dataLength, logout->username);
		//忽略用户密码是否正确的过程
		LogoutResult ret;
		send(_cSock, (char*)&ret, sizeof(LogoutResult), 0);
		break;
	}
	default:
	{
		DataHeader header = { 0,CMD_ERROR };
		send(_cSock, (char*)&header, sizeof(header), 0);
		break;
	}
	}
	return 0;
}


int main()
{
#ifdef _WIN32
	//启动window socket 环境
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);
#endif

	//用Socket API 建立简易TCP客户端
    /*
	1. 建立一个socket
    2. bind 绑定用于接受客户端连接的网络接口
    3. listen 监听网络端口
    4. accept 等待接受客户端连接
    5. send 向客户端发送一条数据
    6. 关闭套接字 closesocket 
	*/

	//1、建立一个socket  参数： 协议类型IPV4，网络类型 面向数据流，TCP/UDP TCP
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//2、bind 绑定用于接受客户端连接的网络接口
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567); //主机到网络字节序的转换 host to net unsigned short
#ifdef _WIN32
	_sin.sin_addr.S_un.S_addr = INADDR_ANY; //或者 inet_addr("127.0.0.1")
#else
	_sin.sin_addr.s_addr = INADDR_ANY;//支持本机所有地址，此处用默认地址 或者 inet_addr("127.0.0.1") 绑定到本机 纯内网
#endif // _WIN32

     //参数： socket句柄，绑定地址，数据长度
	if (SOCKET_ERROR == bind(_sock, (sockaddr*)&_sin, sizeof(_sin)))
	{
		printf("错误，绑定端口失败...\n");
	}
	else
	{
		printf("绑定端口成功...\n");
	}

	//3、listen 监听网络端口 参数：socket句柄 最大的同时链接数
	if (SOCKET_ERROR == listen(_sock, 5))
	{
		printf("错误，监听端口失败...\n");
	}
	else
	{
		printf("监听端口成功...\n");
	}


	while (true)
	{
		//伯克利套接字 BSD socket
		fd_set fdRead;
		fd_set fdWrite;
		fd_set fdExp;

		FD_ZERO(&fdRead);
		FD_ZERO(&fdWrite);
		FD_ZERO(&fdExp);

		FD_SET(_sock, &fdRead);
		FD_SET(_sock, &fdWrite);
		FD_SET(_sock, &fdExp);
		SOCKET maxSock = _sock;
		for (int n = (int)g_clients.size() - 1; n >= 0; n--)
		{
			FD_SET(g_clients[n], &fdRead);
			if (maxSock < g_clients[n])
			{
				maxSock = g_clients[n];
			}
		}

		//nfds是一个整数值，是指fd_set集合中所有描述符（socket）的范围，而不是数量，
		//即是所有文件描述符最大值+1，再window中，该值可以写0   注意  是最大值加一！！！
		timeval t = { 1,0 };    //定时
		int ret = select(maxSock + 1, &fdRead, &fdWrite, &fdExp, &t);
		if (ret < 0)
		{
			printf("select 任务结束\n");
			break;
		}
		if (FD_ISSET(_sock, &fdRead))//FD_ISSET:判断一个文件描述符是否在一个集合中，返回值:在1,不在0
		{
			FD_CLR(_sock, &fdRead); //FD_CLR:将一个文件描述符从集合中移除

	   //4、accept 等待接收客户端的连接
		sockaddr_in clientAddr = {}; //远程客户端地址
		int nAddrLen = sizeof(sockaddr_in); //地址长度
		SOCKET _cSock = INVALID_SOCKET; //定义一个无效的socket地址
#ifdef _WIN32
			_cSock = accept(_sock, (sockaddr*)&clientAddr, &nAddrLen);
#else
       //参数  socket句柄 客户端地址 地址长度
		_cSock = accept(_sock, (sockaddr*)&clientAddr, (socklen_t *)&nAddrLen);
#endif // _WIN32
        //如果接不到客户端链接，则是一个无效的socket地址
		if (INVALID_SOCKET == _cSock)
		{
				printf("错误，接收到无效客户端...\n");
		}
		else
		{
				printf("监听端口成功 \n");
				//新的客户端还没有加入到vector之后，就先群发给所有其他成员
				for (int n = (int)g_clients.size() - 1; n >= 0; n--)
				{
					NewUserJoin userjoin;
					//向客户端发送数据 参数：客户端地址 数据 数据长度 默认值
					send(g_clients[n], (const char*)&userjoin, sizeof(NewUserJoin), 0);
				}

				g_clients.push_back(_cSock);    //新的套接字直接加入到动态数组中
				printf("新的客户端加入：Socket = %d\t IP = %s \n", _cSock, inet_ntoa(clientAddr.sin_addr));
			}
		}

		for (int n = (int)g_clients.size() - 1; n >= 0; n--)
		{
			if (FD_ISSET(g_clients[n], &fdRead))
			{
				int result = processor(g_clients[n]); //处理接受到消息的套接字的信息
				if (-1 == result)       //说明有程序退出了  我们就应该找到这个 然后移除它
				{
					auto iter = g_clients.begin()+n;
					if (iter != g_clients.end())
					{
						g_clients.erase(iter);
					}
				}
			}
		}
		//printf("空闲时间处理其他业务\n");
	}
	for (int n = (int)g_clients.size() - 1; n >= 0; n--)    //如果程序正常退出，该for语句是不会得到执行的
	{
#ifdef _WIN32
		closesocket(g_clients[n]);      //关闭
#else
		close(g_clients[n]);
#endif
	}

	//6、关闭套接字
#ifdef _WIN32
	WSACleanup();
	closesocket(_sock);
#else
	close(_sock);
#endif
	printf("已退出\n");
	getchar();
	return 0;
}