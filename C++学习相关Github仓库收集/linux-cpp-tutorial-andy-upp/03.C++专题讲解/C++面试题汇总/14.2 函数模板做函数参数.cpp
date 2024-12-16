
#include <iostream>
using namespace std;
 
template<typename T, typename T2>
void sortArray(T *a, T2 num)
{
	T tmp ;
	int i, j ;
	for (i=0; i<num; i++)
	{
		for (j=i+1; j<num; j++)
		{
			if (a[i] < a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}
 
template<class T>
void pirntArray(T *a, int num)
{
	int i = 0;
	for (i=0; i<num; i++)
	{
		cout<<a[i]<<" ";
	}
	cout << endl;
}
 
int main()
{
	int num = 0;
	char a[] = "ddadeeettttt";
	num = strlen(a);
 
	cout << "排序之前" << endl;
	pirntArray<char>(a, num);
 
	sortArray<char, int>(a, num); //显示类型调用 模板函数 <>
	cout << "排序之后" << endl;
	pirntArray<char>(a, num);
	cout<<"hello..."<< endl;
	return 0;
}