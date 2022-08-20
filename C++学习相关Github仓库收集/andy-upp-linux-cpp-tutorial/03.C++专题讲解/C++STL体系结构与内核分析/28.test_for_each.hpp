#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector
namespace jj35
{
void myfunc (int i) {  
    cout << ' ' << i;
}

struct myclass {       
    void operator() (int i) { cout << ' ' << i; }
} myobj;

void test_for_each()
{
  cout << "\ntest_for_each().......... \n";	
	
  vector<int> myvec;
  myvec.push_back(10);
  myvec.push_back(20);
  myvec.push_back(30);

  for_each (myvec.begin(), myvec.end(), myfunc);
  cout << endl;		//output: 10 20 30

  for_each (myvec.begin(), myvec.end(), myobj);
  cout << endl;		//output: 10 20 30
  
  //since C++11, range-based for- statement
  for (auto& elem : myvec)
       elem += 5;
  
  for (auto elem : myvec)
       cout << ' ' << elem ; 	//output: 15 25 35
}
} 