#include <list>
#include <iostream>
#include <mutex>
#include <algorithm>
#include <thread>
#include <unistd.h>
using namespace std;

class data_protect
{
public:
  list<int> alist{1,2};
  mutex m;

public:
    void add_list(int val)
    {
        //std::lock_guard<std::mutex>，它的好处是，即使发生了异常也能自动解锁。
        lock_guard<mutex> g(m);
        alist.push_back(val);
    }
    bool contains(int val){
        lock_guard<mutex> g(m);
        return find(alist.begin(), alist.end(), val) != alist.end();
  }
};



void func(data_protect& dp){
  dp.add_list(12);
}

int main(){
  data_protect dp;
  thread t(func, ref(dp));
  //t.join();
  t.detach();
  //sleep(1);
  dp.add_list(12);
  if(dp.contains(12)){
    cout << "contains 12" << endl;
  }
  for(auto& s : dp.alist){
    cout << s << endl;
  }
  pthread_exit(NULL);

}