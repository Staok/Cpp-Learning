#ifndef _CPP_NET_100_DLL_H_
#define _CPP_NET_100_DLL_H_

#include<string>

extern "C"
{
	int _declspec(dllexport) Add(int a, int b)
	{
		return a + b;
	}

	typedef void(*CallBack1)(const char* str);

	void _declspec(dllexport) TestCall1(const char* str1, CallBack1 cb)
	{
		std::string s = "Hello ";
		s += str1;
		cb(s.c_str());
	}
}

#endif //_CPP_NET_100_DLL_H_