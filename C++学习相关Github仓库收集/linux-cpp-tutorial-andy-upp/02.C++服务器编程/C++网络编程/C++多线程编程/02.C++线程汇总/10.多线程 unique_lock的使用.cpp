/*
unique_lock的特点：
1，灵活。可以在创建unique_lock的实例时，不锁，然后手动调用lock_a.lock()函数，
或者std::lock(lock_a, …),来上锁。当unique_lock的实例被析构时，会自动调用unlock函数，释放锁。
unique_lock<mutex> lock_a(d1.m, std::defer_lock);

2，unique_lock的实例可以调用unlock函数。这个意味着，在unique_lock的实例销毁前，
你可以有选择的在程序的分支释放锁。持有锁的时间比所需时间更长，可能会导致性能下降，因为其他等待该锁的线程，
被阻止运行的时间超过了所需的时间。
注意：有个弊端，当不拥有锁的时候，调用了unlock成员方法,程序崩溃。崩溃信息如下：
terminate called after throwing an instance of 'std::system_error'
  what():  Operation not permitted
Aborted (core dumped)

3，可以在作用域之间转移锁的所有权。右值的话，会自动被转移；左值的话，必须手动调用std::move()函数，
来进行锁的所有权的转移。
通常使用这种模式，是在待锁定的互斥元依赖于程序的当前状态，或者依赖于传递给返回std::unique_lock对象的函数的地方。
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
  //if(d1 == d2) return;

  //造成死锁
  //d1.add_list(11);
  unique_lock<mutex> lock_a(d1.m, std::defer_lock);
  unique_lock<mutex> lock_b(d2.m, std::defer_lock);
  std::lock(lock_a, lock_b);
  swap(d1.alist, d2.alist);

  //有unlock成员函数,并可以手动调用unlock函数
  //如果没有持有锁，就调用unlock成员函数就会导致程序崩溃。所以要检查是否拥有锁。
  if(lock_a.owns_lock() && lock_b.owns_lock()){
    lock_a.unlock();
    lock_b.unlock();
  }
}
int main(){
  data_protect d1, d2;
  swap(d1, d2);
  d2.add_list(11);
}
