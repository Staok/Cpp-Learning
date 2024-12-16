#define WIN32_LEAN_AND_MEAN

#include<windows.h>
#include<WinSock2.h>
#include<stdio.h>

#pragma comment(lib,"ws2_32.lib")

enum CMD
{
	CMD_LOGIN,
	CMD_LOGOUT,
	CMD_ERROR
};
struct DataHeader
{
	short dataLength;
	short cmd;
};
//DataPackage
struct Login
{
	char userName[32];
	char PassWord[32];
};

struct LoginResult
{
	int result;

};

struct Logout
{
	char userName[32];
};

struct LogoutResult
{
	int result;

};

int main()
{
	//启动Windows socket 2.x环境
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);
	//------------
	//-- 用Socket API建立简易TCP客户端
	// 1 建立一个socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == _sock)
	{
		printf("错误，建立Socket失败...\n");
	}
	else {
		printf("建立Socket成功...\n");
	}
	// 2 连接服务器 connect
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);
	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	int ret  = connect(_sock, (sockaddr*)&_sin, sizeof(sockaddr_in));
	if (SOCKET_ERROR == ret)
	{
		printf("错误，连接服务器失败...\n");
	}
	else {
		printf("连接服务器成功...\n");
	}

	while (true)
	{
		//3.输入请求命令
		char cmdBuf[128] = {};
		scanf("%s",cmdBuf);
		//4 处理请求命令
		if (0 == strcmp(cmdBuf, "exit"))
		{
			printf("收到exit命令，任务结束。\n");
			break;
		}else if (0 == strcmp(cmdBuf, "login")) {
			Login login = {"lyd","lydmm"};
			DataHeader dh = { sizeof(login),CMD_LOGIN};
			//5 向服务器发送请求命令 分别发送包头和包体
			send(_sock, (const char *)&dh, sizeof(dh), 0);
			send(_sock, (const char *)&login, sizeof(login), 0);
			// 接收服务器返回的数据
			DataHeader retHeader = {};
			LoginResult loginRet = {};
			recv(_sock, (char*)&retHeader, sizeof(retHeader), 0);
			recv(_sock, (char*)&loginRet, sizeof(loginRet), 0);
			printf("LoginResult: %d \n", loginRet.result);
		}
		else if (0 == strcmp(cmdBuf, "logout")) {
			Logout logout = { "lyd" };
			DataHeader dh = { sizeof(logout), CMD_LOGOUT };
			//5 向服务器发送请求命令
			send(_sock, (const char *)&dh, sizeof(dh), 0);
			send(_sock, (const char *)&logout, sizeof(logout), 0);
			// 接收服务器返回的数据
			DataHeader retHeader = {};
			LogoutResult logoutRet = {};
			recv(_sock, (char*)&retHeader, sizeof(retHeader), 0);
			recv(_sock, (char*)&logoutRet, sizeof(logoutRet), 0);
			printf("LogoutResult: %d \n", logoutRet.result);
		}
		else {
			printf("不支持的命令，请重新输入。\n");
		}
	}
	// 7 关闭套节字closesocket
	closesocket(_sock);
	//清除Windows socket环境
	WSACleanup();
	printf("已退出。");
	getchar();
	return 0;
}