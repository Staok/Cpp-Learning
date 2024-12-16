#include "EasyTcpClient.hpp"
#include <thread>


void cmdThread(EasyTcpClient* client)
{
	while (true)
	{
		char cmdBuf[256] = {};
		scanf("%s", cmdBuf);
		if (0 == strcmp(cmdBuf, "exit"))
		{
			client->Close();
			printf("退出线程\n");
			break;
		}
		else if (0 == strcmp(cmdBuf, "login"))
		{
			Login login;
			strcpy(login.userName, "majun");
			strcpy(login.passWord, "518811");
			client->SendData(&login);
		}
		else if (0 == strcmp(cmdBuf, "logout"))
		{
			Logout logout;
			strcpy(logout.username, "majun");
			client->SendData(&logout);

		}
		else {
			printf("不支持的命令\n");
		}
	}
}

int main()
{   
	//创建客户端
	EasyTcpClient client;
	//client.InitSocket();
	//连接服务器
	client.Connect("192.168.56.1", 4567);
    
	//启动线程
	std::thread t1(cmdThread, &client);       //第一个是函数名 第二个就是要传入的参数
	//和主线程进行分离  一定要进行分离，不然子线程的退出会直接导致主线程也退出，
	//但是，主线程没有正常结束程序，就会产生问题
	t1.detach(); 
	while (client.isRun())
	{	
		client.OnRun();

	}
	client.Close();
	getchar();
	return 0;
}