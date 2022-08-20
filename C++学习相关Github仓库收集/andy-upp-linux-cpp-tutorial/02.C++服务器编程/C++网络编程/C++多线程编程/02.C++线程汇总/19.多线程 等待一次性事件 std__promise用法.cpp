//https://www.cnblogs.com/xiaoshiwang/p/10016225.html

#include <future>
#include <thread>
#include <iostream>

void thread1(std::promise<int>& p, int val){
  std::cout << "in thread1" << std::endl;
  p.set_value(val);
}
int main(){
  std::promise<int> p;
  std::future<int> f = p.get_future();
  std::thread t1(thread1, std::ref(p), 10);
  t1.detach();

  std::cout << f.get() << std::endl;
  pthread_exit(NULL);
}