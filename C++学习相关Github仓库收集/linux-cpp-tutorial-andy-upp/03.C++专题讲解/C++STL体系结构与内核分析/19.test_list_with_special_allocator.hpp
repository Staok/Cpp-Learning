#include <list>
#include <stdexcept>
#include <string>
#include <cstdlib> 		//abort()
#include <cstdio>  		//snprintf()
#include <algorithm> 	//find()
#include <iostream>
#include <ctime> 

#include <cstddef>
#include <memory>	//內含 std::allocator  
	//欲使用 std::allocator 以外的 allocator, 得自行 #include <ext\...> 
#ifdef __GNUC__		
#include <ext\array_allocator.h>
#include <ext\mt_allocator.h>
#include <ext\debug_allocator.h>
#include <ext\pool_allocator.h>
#include <ext\bitmap_allocator.h>
#include <ext\malloc_allocator.h>
#include <ext\new_allocator.h>  
#endif

namespace jj20
{
//pass A object to function template impl()，
//而 A 本身是個 class template, 帶有 type parameter T,  
//那麼有無可能在 impl() 中抓出 T, 創建一個 list<T, A<T>> object? 
//以下先暫時迴避上述疑問.
	
void test_list_with_special_allocator()
{
#ifdef __GNUC__	
	cout << "\ntest_list_with_special_allocator().......... \n";
     
    //不能在 switch case 中宣告，只好下面這樣. 				//1000000次 
    list<string, allocator<string>> c1;						//3140
	list<string, __gnu_cxx::malloc_allocator<string>> c2;  	//3110
    list<string, __gnu_cxx::new_allocator<string>> c3; 		//3156
	list<string, __gnu_cxx::__pool_alloc<string>> c4;  		//4922
	list<string, __gnu_cxx::__mt_alloc<string>> c5; 		//3297
    list<string, __gnu_cxx::bitmap_allocator<string>> c6;  	//4781 														
	 
int choice;
long value;     

	cout << "select: "
		 << " (1) std::allocator "
	     << " (2) malloc_allocator "
	     << " (3) new_allocator "
	     << " (4) __pool_alloc "
	     << " (5) __mt_alloc "
		 << " (6) bitmap_allocator ";
	
	cin >> choice;
	if ( choice != 0 ) {
		cout << "how many elements: ";
		cin >> value; 		
	}
			
char buf[10];			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", i);
	        switch (choice) 
	        {
	 	        case 1 : 	c1.push_back(string(buf)); 	
		 					break;
		        case 2 : 	c2.push_back(string(buf)); 	
		 					break;		
		        case 3 : 	c3.push_back(string(buf)); 
		 					break;		
		        case 4 : 	c4.push_back(string(buf)); 	
		 					break;		
		        case 5 : 	c5.push_back(string(buf)); 		
		 					break;		
		        case 6 : 	c6.push_back(string(buf)); 	
		 					break;				
		        default: 
		 			break;		
	        }    		   		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "a lot of push_back(), milli-seconds : " << (clock()-timeStart) << endl;	
	
	 
	//test all allocators' allocate() & deallocate();
	int* p; 	
    allocator<int> alloc1;	
	p = alloc1.allocate(1);  
	alloc1.deallocate(p,1); 	
						
	__gnu_cxx::malloc_allocator<int> alloc2;  
	p = alloc2.allocate(1);  
	alloc2.deallocate(p,1);  	
		
    __gnu_cxx::new_allocator<int> alloc3; 	
	p = alloc3.allocate(1);  
	alloc3.deallocate(p,1); 	
		
	__gnu_cxx::__pool_alloc<int> alloc4;  	
	p = alloc4.allocate(2);  
	alloc4.deallocate(p,2); 	//我刻意令參數為 2, 但這有何意義!! 一次要 2 個 ints? 
		
	__gnu_cxx::__mt_alloc<int> alloc5; 	
	p = alloc5.allocate(1);  
	alloc5.deallocate(p,1);  	
			
    __gnu_cxx::bitmap_allocator<int> alloc6;  	
	p = alloc6.allocate(3);  
	alloc6.deallocate(p,3);  	//我刻意令參數為 3, 但這有何意義!! 一次要 3 個 ints? 
#endif 			
}															
}