#ifndef _CPP_NET_100_DLL_H_
#define _CPP_NET_100_DLL_H_

#include"EasyTcpClient.hpp"
#include"CELLMsgStream.hpp"

#ifdef _WIN32
#define EXPORT_DLL _declspec(dllexport)
#else
#define EXPORT_DLL
#endif // 

extern "C"
{
	typedef void(*OnNetMsgCallBack)(void* csObj, void* data, int len);
}

class NativeTCPClient : public EasyTcpClient
{
public:
	//ÏìÓ¦ÍøÂçÏûÏ¢
	virtual void OnNetMsg(netmsg_DataHeader* header)
	{
		if (_callBack)
			_callBack(_csObj, header, header->dataLength);
	}

	void setCallBack(void* csObj, OnNetMsgCallBack cb)
	{
		_csObj = csObj;
		_callBack = cb;
	}
private:
	void* _csObj = nullptr;
	OnNetMsgCallBack _callBack = nullptr;
};


extern "C"
{
/////////////////////////////Test
	EXPORT_DLL int Add(int a, int b)
	{
		return a + b;
	}

	typedef void(*CallBack1)(const char* str);

	EXPORT_DLL void TestCall1(const char* str1, CallBack1 cb)
	{
		std::string s = "Hello ";
		s += str1;
		cb(s.c_str());
	}
/////////////////////////////CELLClient

	EXPORT_DLL void* CELLClient_Create(void* csObj, OnNetMsgCallBack cb, int sendSize, int recvSize)
	{
		NativeTCPClient* obj = new NativeTCPClient();
		obj->setCallBack(csObj, cb);
		obj->InitSocket(sendSize, recvSize);
		return obj;
	}

	EXPORT_DLL bool CELLClient_Connect(NativeTCPClient* obj, const char* ip, unsigned short port)
	{
		if (obj && ip)
			return SOCKET_ERROR != obj->Connect(ip, port);
		return false;
	}

	EXPORT_DLL bool CELLClient_OnRun(NativeTCPClient* obj)
	{
		if (obj)
			return obj->OnRun();
		return false;
	}

	EXPORT_DLL void CELLClient_Close(NativeTCPClient* obj)
	{
		if (obj)
		{
			obj->Close();
			delete obj;
		}
	}

	EXPORT_DLL int CELLClient_SendData(NativeTCPClient* obj, const char* data, int len)
	{
		if (obj)
		{
			return obj->SendData(data, len);
		}
		return 0;
	}

	EXPORT_DLL int CELLClient_SendWriteStream(NativeTCPClient* obj, CELLWriteStream* wStream)
	{
		if (obj && wStream)
		{
			wStream->finsh();
			return obj->SendData(wStream->data(), wStream->length());
		}
		return 0;
	}
	/////////////////////////////CELLStream
	/////CELLWriteStream

	EXPORT_DLL void* CELLWriteStream_Create(int nSize)
	{
		CELLWriteStream* wStream = new CELLWriteStream(nSize);
		return wStream;
	}

	EXPORT_DLL bool CELLWriteStream_WriteInt8(CELLWriteStream* wStream, int8_t n)
	{
		if (wStream)
			return wStream->Write(n);
		return false;
	}

	EXPORT_DLL bool CELLWriteStream_WriteInt16(CELLWriteStream* wStream, int16_t n)
	{
		if (wStream)
			return wStream->Write(n);
		return false;
	}

	EXPORT_DLL bool CELLWriteStream_WriteInt32(CELLWriteStream* wStream, int32_t n)
	{
		if (wStream)
			return wStream->Write(n);
		return false;
	}

	EXPORT_DLL bool CELLWriteStream_WriteInt64(CELLWriteStream* wStream, int64_t n)
	{
		if (wStream)
			return wStream->Write(n);
		return false;
	}

	EXPORT_DLL bool CELLWriteStream_WriteUInt8(CELLWriteStream* wStream, uint8_t n)
	{
		if (wStream)
			return wStream->Write(n);
		return false;
	}

	EXPORT_DLL bool CELLWriteStream_WriteUInt16(CELLWriteStream* wStream, uint16_t n)
	{
		if (wStream)
			return wStream->Write(n);
		return false;
	}

	EXPORT_DLL bool CELLWriteStream_WriteUInt32(CELLWriteStream* wStream, uint32_t n)
	{
		if (wStream)
			return wStream->Write(n);
		return false;
	}

	EXPORT_DLL bool CELLWriteStream_WriteUInt64(CELLWriteStream* wStream, uint64_t n)
	{
		if (wStream)
			return wStream->Write(n);
		return false;
	}

	EXPORT_DLL bool CELLWriteStream_WriteFloat(CELLWriteStream* wStream, float n)
	{
		if (wStream)
			return wStream->Write(n);
		return false;
	}

	EXPORT_DLL bool CELLWriteStream_WriteDouble(CELLWriteStream* wStream, double n)
	{
		if (wStream)
			return wStream->Write(n);
		return false;
	}

	EXPORT_DLL bool CELLWriteStream_WriteString(CELLWriteStream* wStream, char* n)
	{
		if (wStream)
			return wStream->WriteString(n);
		return false;
	}

	/////CELLReadStream
	EXPORT_DLL void* CELLReadStream_Create(char* data, int len)
	{
		CELLReadStream* rStream = new CELLReadStream(data, len);
		return rStream;
	}

	EXPORT_DLL int8_t CELLReadStream_ReadInt8(CELLReadStream* rStream)
	{
		if (rStream)
			return rStream->ReadInt8();
		return 0;
	}

	EXPORT_DLL int16_t CELLReadStream_ReadInt16(CELLReadStream* rStream)
	{
		if (rStream)
			return rStream->ReadInt16();
		return 0;
	}

	EXPORT_DLL int32_t CELLReadStream_ReadInt32(CELLReadStream* rStream)
	{
		if (rStream)
			return rStream->ReadInt32();
		return 0;
	}

	EXPORT_DLL int64_t CELLReadStream_ReadInt64(CELLReadStream* rStream)
	{
		if (rStream)
			return rStream->ReadInt64();
		return 0;
	}

	EXPORT_DLL uint8_t CELLReadStream_ReadUInt8(CELLReadStream* rStream)
	{
		if (rStream)
			return rStream->ReadUInt8();
		return 0;
	}

	EXPORT_DLL uint16_t CELLReadStream_ReadUInt16(CELLReadStream* rStream)
	{
		if (rStream)
			return rStream->ReadUInt16();
		return 0;
	}

	EXPORT_DLL uint32_t CELLReadStream_ReadUInt32(CELLReadStream* rStream)
	{
		if (rStream)
			return rStream->ReadUInt32();
		return 0;
	}

	EXPORT_DLL uint64_t CELLReadStream_ReadUInt64(CELLReadStream* rStream)
	{
		if (rStream)
			return rStream->ReadUInt64();
		return 0;
	}

	EXPORT_DLL float CELLReadStream_ReadFloat(CELLReadStream* rStream)
	{
		if (rStream)
			return rStream->ReadFloat();
		return 0.0f;
	}

	EXPORT_DLL double CELLReadStream_ReadDouble(CELLReadStream* rStream)
	{
		if (rStream)
			return rStream->ReadDouble();
		return 0.0;
	}

	//EXPORT_DLL bool CELLReadStream_ReadString(CELLReadStream* rStream, char* buffer, int len)
	//{
	//	if (rStream && buffer)
	//	{
	//		return rStream->ReadArray(buffer, len);
	//	}
	//	return false;
	//}

	EXPORT_DLL uint32_t CELLReadStream_OnlyReadUInt32(CELLReadStream* rStream)
	{
		uint32_t len = 0;
		if (rStream)
		{
			rStream->onlyRead(len);
		}
		return len;
	}
}

#endif //_CPP_NET_100_DLL_H_