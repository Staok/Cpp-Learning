#ifndef _CELL_TASK_H_
#define _CELL_TASK_H_

#include<thread>
#include<mutex>
#include<list>

#include<functional>

#include"CELLSemaphore.hpp"

//ִ������ķ�������
class CellTaskServer 
{
public:
	//����serverid
	int serverId = -1;
private:
	typedef std::function<void()> CellTask;
private:
	//��������
	std::list<CellTask> _tasks;
	//�������ݻ�����
	std::list<CellTask> _tasksBuf;
	//�ı����ݻ�����ʱ��Ҫ����
	std::mutex _mutex;
	//
	bool	_isRun = false;
	//
	CELLSemaphore _sem;
public:
	//�������
	void addTask(CellTask task)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		_tasksBuf.push_back(task);
	}
	//���������߳�
	void Start()
	{
		_isRun = true;
		//�߳�
		std::thread t(std::mem_fn(&CellTaskServer::OnRun),this);
		t.detach();
	}

	void Close()
	{
		printf("CellTaskServer%d.Close begin\n", serverId);
		if (_isRun)
		{
			_isRun = false;
			_sem.wait();
		}
		printf("CellTaskServer%d.Close end\n", serverId);
	}
protected:
	//��������
	void OnRun()
	{
		while (_isRun)
		{
			//�ӻ�����ȡ������
			if (!_tasksBuf.empty())
			{
				std::lock_guard<std::mutex> lock(_mutex);
				for (auto pTask : _tasksBuf)
				{
					_tasks.push_back(pTask);
				}
				_tasksBuf.clear();
			}
			//���û������
			if (_tasks.empty())
			{
				std::chrono::milliseconds t(1);
				std::this_thread::sleep_for(t);
				continue;
			}
			//��������
			for (auto pTask : _tasks)
			{
				pTask();
			}
			//�������
			_tasks.clear();
		}
		printf("CellTaskServer%d.OnRun exit\n", serverId);
		_sem.wakeup();
	}
};
#endif // !_CELL_TASK_H_
