//https://www.cnblogs.com/xiaoshiwang/p/9977185.html

#include <iostream>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <thread>
#include <unistd.h>//sleep

std::mutex mut;
std::queue<int> data_queue;//-------------------①
std::condition_variable data_cond;

void data_preparation_thread(){
  int data = 0;
  while(true){
    data++;
    std::lock_guard<std::mutex> lk(mut);
    data_queue.push(data);//-------------------②
    data_cond.notify_one();//-------------------③
    std::cout << "after  notify_one" << std::endl; 
    //std::this_thread::sleep_for(1000);
    sleep(1);
  }
}

void data_process_thread(){
  while(true){
    std::unique_lock<std::mutex> lk(mut);//-------------------④
    std::cout << "before wait" << std::endl; 
    data_cond.wait(lk, []{return !data_queue.empty();});//-------------------⑤
    std::cout << "after  wait" << std::endl;
    int data = data_queue.front();
    std::cout << data << std::endl;
    data_queue.pop();
    lk.unlock();//-------------------⑥
    //假设处理数据data的函数process要花费大量时间，所以提前解锁
    //process(data);
  }
}

int main(){
  std::thread t1(data_preparation_thread);
  std::thread t2(data_process_thread);
  t1.join();
  t2.join();
}