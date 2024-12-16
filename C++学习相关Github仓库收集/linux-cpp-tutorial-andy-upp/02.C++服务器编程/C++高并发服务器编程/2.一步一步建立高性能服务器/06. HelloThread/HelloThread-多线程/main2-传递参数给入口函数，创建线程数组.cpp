#include<iostream>
#include<thread>
using namespace std;

void workFun(int index)
{
	for (int n = 0; n < 4; n++)
		cout << index << "Hello,other thread." << endl;
}//ÇÀÕ¼Ê½

int main()
{
	thread t[4];
	for (int n = 0; n < 4; n++)
	{
		t[n] = thread(workFun,n);
	}
	for (int n = 0; n < 4; n++)
	{
		t[n].join();
		//t[n].detach();
	}

	for (int n = 0; n < 4; n++)
		cout << "Hello,main thread." << endl;
	while (true)
	{

	}
	return 0;
}