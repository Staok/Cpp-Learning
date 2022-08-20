#ifndef _CELL_SEMAPHORE_HPP_
#define _CELL_SEMAPHORE_HPP_

#include<chrono>
#include<thread>

#include<condition_variable>
//�ź���
class CELLSemaphore
{
public:
	//������ǰ�߳�
	void wait()
	{
		std::unique_lock<std::mutex> lock(_mutex);
		if (--_wait < 0)
		{
			//�����ȴ�
			_cv.wait(lock, [this]()->bool{
				return _wakeup > 0;
			});
			--_wakeup;
		}
	}
	//���ѵ�ǰ�߳�
	void wakeup()
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (++_wait <= 0)
		{
			++_wakeup;
			_cv.notify_one();
		}
	}

private:
	//�ı����ݻ�����ʱ��Ҫ����
	std::mutex _mutex;
	//�����ȴ�-��������
	std::condition_variable _cv;
	//�ȴ�����
	int _wait = 0;
	//���Ѽ���
	int _wakeup = 0;
};

#endif // !_CELL_SEMAPHORE_HPP_

//��ٻ���