//https://www.cnblogs.com/xiaoshiwang/p/10029493.html

#include <iostream> 
#include <future>     

int do_get_value() { return 10; }
void th1(std::shared_future<int> sf){
  std::cout << sf.get() << std::endl;
}
void th2(std::shared_future<int> sf){
  std::cout << sf.get() << std::endl;
}
int main(){
  std::future<int> fut = std::async(do_get_value);
  //std::shared_future<int> sf2(std::move(fut));
  //std::shared_future<int> sf2 = fut.share();
  //std::thread t1(th1, sf2);
  //std::thread t2(th1, sf2);

  //t1.join();
  //t2.join();
  std::promise<int> pro;
  std::shared_future<int> sf1(pro.get_future());
  std::thread t1(th1, sf1);
  std::thread t2(th1, sf1);
  pro.set_value(110);
  t1.join();
  t2.join();
}