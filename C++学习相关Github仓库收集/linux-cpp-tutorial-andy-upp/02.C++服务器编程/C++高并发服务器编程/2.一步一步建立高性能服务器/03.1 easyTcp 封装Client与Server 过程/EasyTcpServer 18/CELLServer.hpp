#ifndef _CELL_SERVER_HPP_
#define _CELL_SERVER_HPP_

#include"CELL.hpp"
#include"INetEvent.hpp"
#include"CELLClient.hpp"
#include"CELLSemaphore.hpp"

#include<vector>
#include<map>

//������Ϣ���մ��������
class CellServer
{
public:
	CellServer(int id)
	{
		_id = id;
		_pNetEvent = nullptr;
		_taskServer.serverId = id;
	}

	~CellServer()
	{
		printf("CellServer%d.~CellServer exit begin\n", _id);
		Close();
		printf("CellServer%d.~CellServer exit end\n", _id);
	}

	void setEventObj(INetEvent* event)
	{
		_pNetEvent = event;
	}

	//�ر�Socket
	void Close()
	{
		printf("CellServer%d.Close begin\n", _id);
		if (_isRun)
		{
			_taskServer.Close();
			_isRun = false;
			_sem.wait();
		}
		printf("CellServer%d.Close end\n", _id);
	}

	//����������Ϣ
	void OnRun()
	{
		while (_isRun)
		{
			if (!_clientsBuff.empty())
			{//�ӻ��������ȡ���ͻ�����
				std::lock_guard<std::mutex> lock(_mutex);
				for (auto pClient : _clientsBuff)
				{
					_clients[pClient->sockfd()] = pClient;
					pClient->serverId = _id;
					if (_pNetEvent)
						_pNetEvent->OnNetJoin(pClient);
				}
				_clientsBuff.clear();
				_clients_change = true;
			}

			//���û����Ҫ����Ŀͻ��ˣ�������
			if (_clients.empty())
			{
				std::chrono::milliseconds t(1);
				std::this_thread::sleep_for(t);
				//�ɵ�ʱ���
				_oldTime = CELLTime::getNowInMilliSec();
				continue;
			}

			//�������׽��� BSD socket
			fd_set fdRead;//��������socket�� ����
						  //������
			FD_ZERO(&fdRead);
			if (_clients_change)
			{
				_clients_change = false;
				//����������socket�����뼯��
				_maxSock = _clients.begin()->second->sockfd();
				for (auto iter : _clients)
				{
					FD_SET(iter.second->sockfd(), &fdRead);
					if (_maxSock < iter.second->sockfd())
					{
						_maxSock = iter.second->sockfd();
					}
				}
				memcpy(&_fdRead_bak, &fdRead, sizeof(fd_set));
			}
			else {
				memcpy(&fdRead, &_fdRead_bak, sizeof(fd_set));
			}

			///nfds ��һ������ֵ ��ָfd_set����������������(socket)�ķ�Χ������������
			///���������ļ����������ֵ+1 ��Windows�������������д0
			timeval t{ 0,1 };
			int ret = select(_maxSock + 1, &fdRead, nullptr, nullptr, &t);
			if (ret < 0)
			{
				printf("select���������\n");
				Close();
				return;
			}
			//else if (ret == 0)
			//{
			//	continue;
			//}
			ReadData(fdRead);
			CheckTime();
		}
		printf("CellServer%d.OnRun exit\n", _id);

		ClearClients();
		_sem.wakeup();
	}

	void CheckTime()
	{
		//��ǰʱ���
		auto nowTime = CELLTime::getNowInMilliSec();
		auto dt = nowTime - _oldTime;
		_oldTime = nowTime;

		for (auto iter = _clients.begin(); iter != _clients.end(); )
		{
			//�������
			if (iter->second->checkHeart(dt))
			{
				if (_pNetEvent)
					_pNetEvent->OnNetLeave(iter->second);
				_clients_change = true;
				delete iter->second;
				auto iterOld = iter;
				iter++;
				_clients.erase(iterOld);
				continue;
			}
			//��ʱ���ͼ��
			iter->second->checkSend(dt);
			iter++;
		}
	}

	void ReadData(fd_set& fdRead)
	{
		#ifdef _WIN32
			for (int n = 0; n < fdRead.fd_count; n++)
			{
				auto iter = _clients.find(fdRead.fd_array[n]);
				if (iter != _clients.end())
				{
					if (-1 == RecvData(iter->second))
					{
						if (_pNetEvent)
							_pNetEvent->OnNetLeave(iter->second);
						_clients_change = true;
						delete iter->second;
						_clients.erase(iter);
					}
				}
				else {
					printf("error. if (iter != _clients.end())\n");
				}
			}
#else
			std::vector<CellClient*> temp;
			for (auto iter : _clients)
			{
				if (FD_ISSET(iter.second->sockfd(), &fdRead))
				{
					if (-1 == RecvData(iter.second))
					{
						if (_pNetEvent)
							_pNetEvent->OnNetLeave(iter.second);
						_clients_change = true;
						temp.push_back(iter.second);
					}
				}
			}
			for (auto pClient : temp)
			{
				_clients.erase(pClient->sockfd());
				delete pClient;
			}
#endif
	}

	//�������� ����ճ�� ��ְ�
	int RecvData(CellClient* pClient)
	{
		//���տͻ�������
		char* szRecv = pClient->msgBuf() + pClient->getLastPos();
		int nLen = (int)recv(pClient->sockfd(), szRecv, (RECV_BUFF_SZIE)-pClient->getLastPos(), 0);
		_pNetEvent->OnNetRecv(pClient);
		//printf("nLen=%d\n", nLen);
		if (nLen <= 0)
		{
			//printf("�ͻ���<Socket=%d>���˳������������\n", pClient->sockfd());
			return -1;
		}
		//����ȡ�������ݿ�������Ϣ������
		//memcpy(pClient->msgBuf() + pClient->getLastPos(), _szRecv, nLen);
		//��Ϣ������������β��λ�ú���
		pClient->setLastPos(pClient->getLastPos() + nLen);

		//�ж���Ϣ�����������ݳ��ȴ�����Ϣͷnetmsg_DataHeader����
		while (pClient->getLastPos() >= sizeof(netmsg_DataHeader))
		{
			//��ʱ�Ϳ���֪����ǰ��Ϣ�ĳ���
			netmsg_DataHeader* header = (netmsg_DataHeader*)pClient->msgBuf();
			//�ж���Ϣ�����������ݳ��ȴ�����Ϣ����
			if (pClient->getLastPos() >= header->dataLength)
			{
				//��Ϣ������ʣ��δ�������ݵĳ���
				int nSize = pClient->getLastPos() - header->dataLength;
				//����������Ϣ
				OnNetMsg(pClient, header);
				//����Ϣ������ʣ��δ��������ǰ��
				memcpy(pClient->msgBuf(), pClient->msgBuf() + header->dataLength, nSize);
				//��Ϣ������������β��λ��ǰ��
				pClient->setLastPos(nSize);
			}
			else {
				//��Ϣ������ʣ�����ݲ���һ��������Ϣ
				break;
			}
		}
		return 0;
	}

	//��Ӧ������Ϣ
	virtual void OnNetMsg(CellClient* pClient, netmsg_DataHeader* header)
	{
		_pNetEvent->OnNetMsg(this, pClient, header);
	}

	void addClient(CellClient* pClient)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		//_mutex.lock();
		_clientsBuff.push_back(pClient);
		//_mutex.unlock();
	}

	void Start()
	{
		if (!_isRun)
		{
			_isRun = true;
			std::thread t = std::thread(std::mem_fn(&CellServer::OnRun), this);
			t.detach();
			_taskServer.Start();
		}
	}

	size_t getClientCount()
	{
		return _clients.size() + _clientsBuff.size();
	}

	//void addSendTask(CellClient* pClient, netmsg_DataHeader* header)
	//{
	//	_taskServer.addTask([pClient, header]() {
	//		pClient->SendData(header);
	//		delete header;
	//	});
	//}
private:
	void ClearClients()
	{
		for (auto iter : _clients)
		{
			delete iter.second;
		}
		_clients.clear();

		for (auto iter : _clientsBuff)
		{
			delete iter;
		}
		_clientsBuff.clear();
	}
private:
	//��ʽ�ͻ�����
	std::map<SOCKET, CellClient*> _clients;
	//����ͻ�����
	std::vector<CellClient*> _clientsBuff;
	//������е���
	std::mutex _mutex;
	//�����¼�����
	INetEvent* _pNetEvent;
	//
	CellTaskServer _taskServer;
	//���ݿͻ�socket fd_set
	fd_set _fdRead_bak;
	//
	SOCKET _maxSock;
	//�ɵ�ʱ���
	time_t _oldTime = CELLTime::getNowInMilliSec();
	//
	CELLSemaphore _sem;
	//
	int _id = -1;
	//�ͻ��б��Ƿ��б仯
	bool _clients_change = true;
	//�Ƿ�����
	bool _isRun = false;
};

#endif // !_CELL_SERVER_HPP_
