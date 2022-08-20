/*
当要同时操作2个对象时，就需要同时锁定这2个对象，而不是先锁定一个，然后再锁定另一个。
同时锁定多个对象的方法：std::lock(对象1.锁，对象2.锁...)
额外说明：lock_guard<mutex> lock_a(d1.m, std::adopt_lock);

上面这句是为了解开std::lock的锁。
参数std::adopt_lock的作用：告诉lock_guard，d1.m已经被上锁了，你不要再去锁它了，沿用它原来的锁就好。
*/

#include <list>
#include <iostream>
#include <mutex>
#include <algorithm>
#include <thread>
#include <unistd.h>

using namespace std;
class data_protect;

void swap(data_protect& , data_protect& );

//是线程安全的
class data_protect{
  friend void swap(data_protect& , data_protect& );
private:
  list<int> alist{1,2};
  mutex m;
public:  
  void add_list(int val){
    //操作双向链表时，加锁了
    lock_guard<mutex> g(m);
    alist.push_back(val);
  }

  bool contains(int val){
    //操作双向链表时，加锁了
    lock_guard<mutex> g(m);
    return find(alist.begin(), alist.end(), val) != alist.end();
  }
};

void swap(data_protect& d1, data_protect& d2){
  std::lock(d1.m, d2.m);
  
  //造成死锁
  //d1.add_list(11);
  lock_guard<mutex> lock_a(d1.m, std::adopt_lock);
  lock_guard<mutex> lock_b(d2.m, std::adopt_lock);
  swap(d1.alist, d2.alist);
}

int main(){
  data_protect d1, d2;
  swap(d1, d2);
}