/*
背景：保护很少更新的数据结构时，c++标准库没有提供相应的功能。
例如：有个DNS条目缓存的map，基本上很少有更新，大部分都是读取，但是偶尔也会有更新，这种情况下，
如果在读取的函数里加上std::mutex就过于悲观了，每次只能有一个线程读取，但是想要的效果是，
多个线程可以同时读取。这个时候c++标准库就显得无能为力了。
boost库就能登场了。
boost有个共享锁：boost::shared_mutex和boost::shared_lock，用boost::shared_mutex
代替std::mutex后，当有某一个线程读取dns时，就锁住了这个共享锁，当第二个线程也要读取时，
这是第一个还没读完，也就是还没有解锁，如果用的是std::mutex的话，第二线程是无法进行读取的，
但是换成boost::shared_mutex后，第二个线程也可以读取了，即便第一个读取的线程还有结束。
但是也有限制，读取操作可以多个线程同时读取，但是某个时间点，有个线程要更新dns，是否可以更新取决于，
这个时间点是否有读的线程还没有结束。
1，如果读取的线程都结束了，也就是所有的共享锁都被解锁了，这时可以更新dns，并且在更新的同时，
所有读取的线程都要被阻塞；
2，如果读取的线程还有任意一个没有结束了，也就是说并不是所有的共享锁都被解锁了，这时，
更新的线程就会被阻塞，直到，所有的读取线程结束后，更新线程才会开始。
*/

#include <map>
#include <string>
#include <thread>
#include <mutex>
#include <functional>
#include <boost/thread/shared_mutex.hpp>

class dns_entry{

};
class dns_cache{
  std::map<std::string, dns_entry> entries;
  mutable boost::shared_mutex entry_mutex;
public:
  dns_entry find_entry(std::string const& domain)const{
    boost::shared_lock<boost::shared_mutex> lk(entry_mutex);
    std::map<std::string, dns_entry>::const_iterator const it =
      entries.find(domain);
    return (it == entries.end()) ? dns_entry() : it->second;
  }
  void update_or_add_entry(std::string const& domain, dns_entry const& dns_details){
    std::lock_guard<boost::shared_mutex> lk(entry_mutex);
    entries[domain] = dns_details;
  }
};
int main(){
  dns_entry de;
  dns_cache cache1, cache2, cache3;
  std::thread t(&dns_cache::find_entry, std::ref(cache3), "aaa");
  t.join();
  std::thread t1(&dns_cache::update_or_add_entry, std::ref(cache1), "aaa", de);
  t1.join();
  std::thread t2(&dns_cache::find_entry, std::ref(cache2), "aaa");
  t2.join();
}