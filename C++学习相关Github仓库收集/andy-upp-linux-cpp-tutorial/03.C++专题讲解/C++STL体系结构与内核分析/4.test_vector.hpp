#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
#include <algorithm> 	//sort()

namespace jj02
{
void test_vector(long& value)
{
	cout << "\ntest_vector().......... \n";
     
vector<string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.push_back(string(buf));     		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			     //曾經最高 i=58389486 then std::bad_alloc
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "vector.max_size()= " << c.max_size() << endl;	//1073747823
	cout << "vector.size()= " << c.size() << endl;		
	cout << "vector.front()= " << c.front() << endl;	
	cout << "vector.back()= " << c.back() << endl;	
	cout << "vector.data()= " << c.data() << endl;
	cout << "vector.capacity()= " << c.capacity() << endl << endl;		

																				
string target = get_a_target_string();
    {
	timeStart = clock();
auto pItem = find(c.begin(), c.end(), target);
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;  
	 
  	if (pItem != c.end())
    	cout << "found, " << *pItem << endl << endl;
  	else
    	cout << "not found! " << endl << endl;
    }

	{
	timeStart = clock();
    sort(c.begin(), c.end());
	cout << "sort(), milli-seconds : " << (clock()-timeStart) << endl; 
	
	timeStart = clock();	    
string* pItem = (string*)::bsearch(&target, (c.data()), 
                                   c.size(), sizeof(string), compareStrings); 
	cout << "bsearch(), milli-seconds : " << (clock()-timeStart) << endl; 
	   
  	if (pItem != NULL)
    	cout << "found, " << *pItem << endl << endl;
  	else
    	cout << "not found! " << endl << endl;	
	}
	
	c.clear();
	test_moveable(vector<MyString>(),vector<MyStrNoMove>(), value);	
}	
}