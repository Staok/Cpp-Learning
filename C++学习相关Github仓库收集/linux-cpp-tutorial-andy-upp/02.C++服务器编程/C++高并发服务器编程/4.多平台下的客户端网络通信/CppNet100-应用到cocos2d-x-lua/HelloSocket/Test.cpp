#include"EasyTcpClient.hpp"
#include"CELLStream.hpp"
#include"CELLMsgStream.hpp"

class MyClient : public EasyTcpClient
{
public:
	//响应网络消息
	virtual void OnNetMsg(netmsg_DataHeader* header)
	{
		switch (header->cmd)
		{
		case CMD_LOGOUT_RESULT:
		{
			CELLReadStream r(header);
			//读取消息长度
			r.ReadInt16();
			//读取消息命令
			r.getNetCmd();
			auto n1 = r.ReadInt8();
			auto n2 = r.ReadInt16();
			auto n3 = r.ReadInt32();
			auto n4 = r.ReadFloat();
			auto n5 = r.ReadDouble();
			uint32_t n = 0;
			r.onlyRead(n);
			char name[32] = {};
			auto n6 = r.ReadArray(name, 32);
			char pw[32] = {};
			auto n7 = r.ReadArray(pw, 32);
			int ata[10] = {};
			auto n8 = r.ReadArray(ata, 10);
			CELLLog::Info("<socket=%d> recv msgType：CMD_LOGOUT_RESULT\n", (int)_pClient->sockfd());
		}
		break;
		case CMD_ERROR:
		{
			CELLLog::Info("<socket=%d> recv msgType：CMD_ERROR\n", (int)_pClient->sockfd());
		}
		break;
		default:
		{
			CELLLog::Info("error, <socket=%d> recv undefine msgType\n", (int)_pClient->sockfd());
		}
		}
	}
private:

};

int main()
{
	CELLWriteStream s(128);
	s.setNetCmd(CMD_LOGOUT);
	s.WriteInt8(1);
	s.WriteInt16(2);
	s.WriteInt32(3);
	s.WriteFloat(4.5f);
	s.WriteDouble(6.7);
	s.WriteString("client");
	char a[] = "ahah";
	s.WriteArray(a, strlen(a));
	int b[] = {1,2,3,4,5};
	s.WriteArray(b, 5);
	s.finsh();
	MyClient client;
	client.Connect("192.168.1.102", 4567);

	
	while (client.OnRun())
	{
		client.SendData(s.data(), s.length());
		CELLThread::Sleep(10);
	}
	return 0;
}