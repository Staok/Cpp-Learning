#include <typeinfo>  //typeid()
template<typename T>
void output_static_data(const T& myStr)
{
	cout << typeid(myStr).name() << " -- " << endl; 
	cout << " CCtor=" << T::CCtor 	
		 << " MCtor=" << T::MCtor 
	     << " CAsgn=" << T::CAsgn 		 
		 << " MAsgn=" << T::MAsgn 
		 << " Dtor="  << T::Dtor 
		 << " Ctor="  << T::Ctor 
		 << " DCtor=" << T::DCtor 		 
		 << endl;	
}

#include <ctime>  //clock_t, clock()
template<typename M, typename NM>	
void test_moveable(M c1, NM c2, long& value)
{ 	
char buf[10];
			
	//測試 move 
	cout << "\n\ntest, with moveable elements" << endl;			
	typedef typename iterator_traits<typename M::iterator>::value_type  V1type; 	
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	snprintf(buf, 10, "%d", rand());    		
        auto ite = c1.end();
        c1.insert(ite, V1type(buf));	
	}
	cout << "construction, milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "size()= " << c1.size() << endl;		
	output_static_data(*(c1.begin()));

	timeStart = clock();	
M c11(c1);						
	cout << "copy, milli-seconds : " << (clock()-timeStart) << endl;	

	timeStart = clock();	
M c12(std::move(c1));						
	cout << "move copy, milli-seconds : " << (clock()-timeStart) << endl;
		
	timeStart = clock();	
	c11.swap(c12);						
	cout << "swap, milli-seconds : " << (clock()-timeStart) << endl;		

	
	
	//測試 non-moveable 	
	cout << "\n\ntest, with non-moveable elements" << endl;		
	typedef typename iterator_traits<typename NM::iterator>::value_type  V2type; 				
    timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	snprintf(buf, 10, "%d", rand());    		
        auto ite = c2.end();
        c2.insert(ite, V2type(buf));	
	}

	cout << "construction, milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "size()= " << c2.size() << endl;			
	output_static_data(*(c2.begin()));

	timeStart = clock();	
NM c21(c2);						
	cout << "copy, milli-seconds : " << (clock()-timeStart) << endl;	

	timeStart = clock();	
NM c22(std::move(c2));						
	cout << "move copy, milli-seconds : " << (clock()-timeStart) << endl;
		
	timeStart = clock();	
	c21.swap(c22);						
	cout << "swap, milli-seconds : " << (clock()-timeStart) << endl;			
}	
//-----------------
long get_a_target_long()
{
long target=0;

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	return target;
}

string get_a_target_string()
{
long target=0;
char buf[10];

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	snprintf(buf, 10, "%d", target);
	return string(buf);
}

int compareLongs(const void* a, const void* b)
{
  return ( *(long*)a - *(long*)b );
}

int compareStrings(const void* a, const void* b)
{
  if ( *(string*)a > *(string*)b )
     	return 1;
  else if ( *(string*)a < *(string*)b )
     	return -1;  
  else      	
        return 0;  
}