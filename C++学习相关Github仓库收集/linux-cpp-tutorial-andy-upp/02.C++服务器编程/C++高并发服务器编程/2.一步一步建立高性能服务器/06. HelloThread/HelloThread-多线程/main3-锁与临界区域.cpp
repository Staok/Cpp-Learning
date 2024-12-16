#include<iostream>
#include<thread>
#include<mutex>//锁
#include"CELLTimestamp.hpp"
using namespace std;

mutex m;
const int tCount = 4;
int sum = 0;
void workFun(int index)
{
	for (int n = 0; n < 20000000; n++)
	{
		//临界区域-开始
		m.lock();
		sum++;
		m.unlock();
		//临界区域-结束
	}

	//cout << index << "Hello,main thread." << n << endl;
}//抢占式

int main()
{
	thread t[tCount];
	for (int n = 0; n < tCount; n++)
	{
		t[n] = thread(workFun,n);
	}
	CELLTimestamp tTime;
	for (int n = 0; n < tCount; n++)
	{
		t[n].join();
		//t[n].detach();
	}
	cout << tTime.getElapsedTimeInMilliSec()<<",sum=" <<sum<< endl;
	sum = 0;
	tTime.update();
	for (int n = 0; n < 80000000; n++)
	{
		sum++;
	}
	cout << tTime.getElapsedTimeInMilliSec() << ",sum=" << sum << endl;
	cout << "Hello,main thread." << endl;
	return 0;
}