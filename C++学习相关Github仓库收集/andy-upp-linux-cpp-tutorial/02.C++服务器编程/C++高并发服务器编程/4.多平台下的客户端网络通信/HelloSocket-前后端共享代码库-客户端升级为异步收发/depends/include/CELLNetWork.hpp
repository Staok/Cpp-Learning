#ifndef _CELL_NET_WORK_HPP_
#define _CELL_NET_WORK_HPP_

#include"CELL.hpp"

class CELLNetWork
{
private:
	CELLNetWork()
	{
#ifdef _WIN32
		//启动Windows socket 2.x环境
		WORD ver = MAKEWORD(2, 2);
		WSADATA dat;
		WSAStartup(ver, &dat);
#endif

#ifndef _WIN32
		//if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		//	return (1);
		//忽略异常信号，默认情况会导致进程终止
		signal(SIGPIPE, SIG_IGN);
#endif
	}

	~CELLNetWork()
	{
#ifdef _WIN32
		//清除Windows socket环境
		WSACleanup();
#endif
	}
public:
	static void Init()
	{
		static  CELLNetWork obj;
	}
};

#endif // !_CELL_NET_WORK_HPP_
