#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>

template<typename T>
class threadsave_queue{
private:
  mutable std::mutex mut;//必须是mutable，因为empty是const方法，但是要锁mut，锁操作就是改变操作
  std::queue<T> data_queue;
  std::condition_variable data_cond;
public:
  threadsave_queue(){}
  threadsave_queue(threadsave_queue const& other){
    std::lock_guard<std::mutex> lk(other.mut);
    data_queue = other.data_queue();
  }
  void push(T new_value){
    std::lock_guard<std::mutex> lk(mut);
    data_queue.push(new_value);
    data_cond.notify_one();
  }
  void wait_and_pop(T& value){
    std::unique_lock<std::mutex> lk(mut);
    data_cond.wait(lk, [this]{return !data_queue.empty();});
    value = data_queue.front();
    data_queue.pop();
  }

  std::shared_ptr<T> wait_and_pop(){
    std::unique_lock<std::mutex> lk(mut);
    data_cond.wait(lk, [this]{return !data_queue.empty();});
    std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
    data_queue.pop();
    return res;
  }
  
  bool empty()const{
    std::lock_guard<std::mutex> lk(mut);
    return data_queue.empty();
  }
};

void make_data(threadsave_queue<int>& tq, int val){
  tq.push(val);
}
void get_data1(threadsave_queue<int>& tq, int& d1){
  tq.wait_and_pop(d1);
}
void get_data2(threadsave_queue<int>& tq, int& d1){
  auto at = tq.wait_and_pop();
  d1 = *at;
}
int main(){
  threadsave_queue<int> q1;
  int d1;
  std::thread t1(make_data, std::ref(q1), 10);
  std::thread t2(get_data1, std::ref(q1),std::ref(d1));
  t1.join();
  t2.join();
  std::cout << d1 << std::endl;
  std::thread t3(make_data, std::ref(q1), 20);
  std::thread t4(get_data2, std::ref(q1),std::ref(d1));
  t3.join();
  t4.join();
  std::cout << d1 << std::endl;
  q1.empty();

}