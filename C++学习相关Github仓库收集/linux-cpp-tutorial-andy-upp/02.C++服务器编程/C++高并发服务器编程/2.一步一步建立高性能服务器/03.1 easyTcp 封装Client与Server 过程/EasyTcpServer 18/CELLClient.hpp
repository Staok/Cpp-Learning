#ifndef _CellClient_hpp_
#define _CellClient_hpp_

#include"CELL.hpp"

//�ͻ����������������ʱʱ��
#define CLIENT_HREAT_DEAD_TIME 60000
//�ڼ��ָ��ʱ���
//�ѷ��ͻ������ڻ������Ϣ���ݷ��͸��ͻ���
#define CLIENT_SEND_BUFF_TIME 200
//�ͻ�����������
class CellClient
{
public:
	int id = -1;
	//����serverid
	int serverId = -1;
public:
	CellClient(SOCKET sockfd = INVALID_SOCKET)
	{
		static int n = 1;
		id = n++;
		_sockfd = sockfd;
		memset(_szMsgBuf, 0, RECV_BUFF_SZIE);
		_lastPos = 0;

		memset(_szSendBuf, 0, SEND_BUFF_SZIE);
		_lastSendPos = 0;

		resetDTHeart();
		resetDTSend();
	}

	~CellClient()
	{
		printf("s=%d CellClient%d.~CellClient\n", serverId, id);
		if (INVALID_SOCKET != _sockfd)
		{
#ifdef _WIN32
			closesocket(_sockfd);
#else
			close(_sockfd);
#endif
			_sockfd = INVALID_SOCKET;
		}
	}


	SOCKET sockfd()
	{
		return _sockfd;
	}

	char* msgBuf()
	{
		return _szMsgBuf;
	}

	int getLastPos()
	{
		return _lastPos;
	}
	void setLastPos(int pos)
	{
		_lastPos = pos;
	}

	//������������
	int SendDataReal(netmsg_DataHeader* header)
	{
		SendData(header);
		SendDataReal();
	}

	//���������ͻ����������ݷ��͸��ͻ���
	int SendDataReal()
	{
		int ret = SOCKET_ERROR;
		//������������
		if (_lastSendPos > 0 && SOCKET_ERROR != _sockfd)
		{
			//��������
			ret = send(_sockfd, _szSendBuf, _lastSendPos, 0);
			//����β��λ������
			_lastSendPos = 0;
			//
			resetDTSend();
		}
		return ret;
	}

	//��������
	int SendData(netmsg_DataHeader* header)
	{
		int ret = SOCKET_ERROR;
		//Ҫ���͵����ݳ���
		int nSendLen = header->dataLength;
		//Ҫ���͵�����
		const char* pSendData = (const char*)header;

		while (true)
		{
			if (_lastSendPos + nSendLen >= SEND_BUFF_SZIE)
			{
				//����ɿ��������ݳ���
				int nCopyLen = SEND_BUFF_SZIE - _lastSendPos;
				//��������
				memcpy(_szSendBuf + _lastSendPos, pSendData, nCopyLen);
				//����ʣ������λ��
				pSendData += nCopyLen;
				//����ʣ�����ݳ���
				nSendLen -= nCopyLen;
				//��������
				ret = send(_sockfd, _szSendBuf, SEND_BUFF_SZIE, 0);
				//����β��λ������
				_lastSendPos = 0;
				//
				resetDTSend();
				//���ʹ���
				if (SOCKET_ERROR == ret)
				{
					return ret;
				}
			}
			else {
				//��Ҫ���͵����� ���������ͻ�����β��
				memcpy(_szSendBuf + _lastSendPos, pSendData, nSendLen);
				//��������β��λ��
				_lastSendPos += nSendLen;
				break;
			}
		}
		return ret;
	}

	void resetDTHeart()
	{
		_dtHeart = 0;
	}

	void resetDTSend()
	{
		_dtSend = 0;
	}

	//�������
	bool checkHeart(time_t dt)
	{
		_dtHeart += dt;
		if (_dtHeart >= CLIENT_HREAT_DEAD_TIME)
		{
			printf("checkHeart dead:s=%d,time=%ld\n",_sockfd, _dtHeart);
			return true;
		}
		return false;
	}

	//��ʱ������Ϣ���
	bool checkSend(time_t dt)
	{
		_dtSend += dt;
		if (_dtSend >= CLIENT_SEND_BUFF_TIME)
		{
			//printf("checkSend:s=%d,time=%d\n", _sockfd, _dtSend);
			//���������ͻ����������ݷ��ͳ�ȥ
			SendDataReal();
			//���÷��ͼ�ʱ
			resetDTSend();
			return true;
		}
		return false;
	}
private:
	// socket fd_set  file desc set
	SOCKET _sockfd;
	//�ڶ������� ��Ϣ������
	char _szMsgBuf[RECV_BUFF_SZIE];
	//��Ϣ������������β��λ��
	int _lastPos;

	//�ڶ������� ���ͻ�����
	char _szSendBuf[SEND_BUFF_SZIE];
	//���ͻ�����������β��λ��
	int _lastSendPos;
	//����������ʱ
	time_t _dtHeart;
	//�ϴη�����Ϣ���ݵ�ʱ��
	time_t _dtSend;
};

#endif // !_CellClient_hpp_



