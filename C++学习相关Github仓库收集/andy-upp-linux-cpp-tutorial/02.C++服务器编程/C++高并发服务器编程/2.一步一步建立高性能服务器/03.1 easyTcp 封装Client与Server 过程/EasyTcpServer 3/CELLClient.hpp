#ifndef _CellClient_hpp_
#define _CellClient_hpp_

#include"CELL.hpp"

//�ͻ�����������
class CellClient
{
public:
	CellClient(SOCKET sockfd = INVALID_SOCKET)
	{
		_sockfd = sockfd;
		memset(_szMsgBuf, 0, RECV_BUFF_SZIE);
		_lastPos = 0;

		memset(_szSendBuf, 0, SEND_BUFF_SZIE);
		_lastSendPos = 0;
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
};

#endif // !_CellClient_hpp_



