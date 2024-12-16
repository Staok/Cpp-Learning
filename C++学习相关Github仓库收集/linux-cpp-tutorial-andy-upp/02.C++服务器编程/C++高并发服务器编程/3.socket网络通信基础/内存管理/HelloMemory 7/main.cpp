//#include"Alloctor.h"
#include<stdlib.h>
#include<iostream>
#include<thread>
#include<mutex>//锁
#include<memory>
#include"CELLTimestamp.hpp"
#include"CELLObjectPool.hpp"

using namespace std;
//原子操作   原子 分子 
mutex m;
const int tCount = 8;
const int mCount = 100000;
const int nCount = mCount/tCount;
void workFun(int index)
{
	char* data[nCount];
	for (size_t i = 0; i < nCount; i++)
	{
		data[i] = new char[(rand()%128)+1];
	}
	for (size_t i = 0; i < nCount; i++)
	{
		delete[] data[i];
	}
}//抢占式

class ClassA: public ObjectPoolBase<ClassA,10>
{
public:
	ClassA(int n)
	{
		num = n;
		printf("ClassA\n");
	}

	~ClassA()
	{
		printf("~ClassA\n");
	}
public:
	int num = 0;
};

class ClassB : public ObjectPoolBase<ClassB,10>
{
public:
	ClassB(int n,int m)
	{
		num = n*m;
		printf("ClassB\n");
	}

	~ClassB()
	{
		printf("~ClassB\n");
	}
public:
	int num = 0;
};

ClassA& fun(ClassA& pA)
{//引用计数  
	pA.num++;
	return pA;
}

void fun(shared_ptr<ClassA>& pA)
{//引用计数  
	pA->num++;
}

void fun(ClassA* pA)
{//引用计数  
	pA->num++;
}

int main()
{
	/*
	thread t[tCount];
	for (int n = 0; n < tCount; n++)
	{
		t[n] = thread(workFun, n);
	}
	CELLTimestamp tTime;
	for (int n = 0; n < tCount; n++)
	{
		t[n].join();
		//t[n].detach();
	}
	cout << tTime.getElapsedTimeInMilliSec() << endl;
	cout << "Hello,main thread." << endl;
	*/

	/*
	int* a = new int;
	*a = 100;
	delete a;
	//printf("a=%d\n", *a);
	//C++标准库智能指针的一种
	shared_ptr<int> b = make_shared<int>();
	*b = 100;
	//printf("b=%d\n", *b);
	*/

	/*
	{
		shared_ptr<ClassA> b = make_shared<ClassA>(100);
		b->num = 200;
		CELLTimestamp tTime;
		for (int n = 0; n < 100000000; n++)
		{
			fun(b);
		}
		cout << tTime.getElapsedTimeInMilliSec() << endl;
	}
	{
		ClassA* b = new ClassA(100);
		b->num = 200;
		CELLTimestamp tTime;
		for (int n = 0; n < 100000000; n++)
		{
			fun(b);
		}
		cout << tTime.getElapsedTimeInMilliSec() << endl;
	}
	*/

	ClassA* a1 = new ClassA(5);
	delete a1;

	ClassA* a2 = ClassA::createObject(6);
	ClassA::destroyObject(a2);

	ClassB* b1 = new ClassB(5, 6);
	delete b1;

	ClassB* b2 = ClassB::createObject(5,6);
	ClassB::destroyObject(b2);
	return 0;
}