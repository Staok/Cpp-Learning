#include <vector>
#include <iostream>
#include <boost/foreach.hpp>
#include <boost/assign.hpp>
#include <boost/timer.hpp>
#include <boost/format.hpp>
#include <string.h>

using namespace std;
using namespace boost;
//https://blog.csdn.net/m0_37406679/article/details/81162599

int main(){
 timer t;
 vector<int> v = (assign::list_of(1), 2, 3, 4, 5);

 BOOST_FOREACH(int x, v){
   cout<<x<<",";
 }

cout<<endl;
string bb = "htsaf";
cout << boost::format("writing %1%")%bb  << endl;



 cout<<t.elapsed()<<"s"<<endl;
 cout<<"hello world!"<<endl;
 return 0;

}
