#ifndef _CELL_SEMAPHORE_HPP_
#define _CELL_SEMAPHORE_HPP_

#include<chrono>
#include<thread>

//信号量
class CELLSemaphore
{
public:
	void wait()
	{
		_isWaitExit = true;
		//阻塞等待OnRun退出
		while (_isWaitExit)
		{//信号量
			std::chrono::milliseconds t(1);
			std::this_thread::sleep_for(t);
		}
	}
	//
	void wakeup()
	{
		if (_isWaitExit)
			_isWaitExit = false;
		else
			printf("CELLSemaphore wakeup error.");
	}

private:
	bool	_isWaitExit = false;
};

#endif // !_CELL_SEMAPHORE_HPP_
