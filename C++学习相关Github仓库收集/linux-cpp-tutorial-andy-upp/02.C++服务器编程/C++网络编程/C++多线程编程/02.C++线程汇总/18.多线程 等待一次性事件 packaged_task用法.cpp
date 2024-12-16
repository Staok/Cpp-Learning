//https://www.cnblogs.com/xiaoshiwang/p/10014219.html

#include <deque>
#include <mutex>
#include <future>
#include <thread>
#include <iostream>
#include <unistd.h>
#include <string>
//#include <utility>

std::mutex mut;
std::deque<std::packaged_task<std::string(int)>> tasks;

void manage_tasks(){
  while(true){
    sleep(1);
    //std::cout << "please wait for a moument" << std::endl;
    std::packaged_task<std::string(int)> task;
    {
      std::lock_guard<std::mutex> lg(mut);
      if(tasks.empty()) continue;
      std::cout << "----------------------not empty---------------" << std::endl;
      task = std::move(tasks.front());
      tasks.pop_front();
    }
    task(1);
    //std::string s = task(10);
  }
}

template<typename Call>
std::future<std::string> add_task(Call ca){
  std::cout << "----------------------add_task---------------" << std::endl;  
  std::packaged_task<std::string(int)> task(ca);
  std::future<std::string> ret = task.get_future();
  std::lock_guard<std::mutex> lg(mut);
  tasks.push_back(std::move(task));
  return ret;
}

std::string call_texi(int i = 0){
  std::cout << "-------------jiaoche---------------" << std::endl;
  if(i == 1){
    return "aaa";
  }else{
    return "bbb";
  }
}

std::string call_zhuanche(int i){
  std::cout << "zhuanche:" << i << std::endl;
  return std::to_string(i);
}
int main(){
  
  std::thread background_thread(manage_tasks);
  background_thread.detach();

  std::future<std::string> fut1 = add_task(call_texi);
  std::cout << fut1.get() << std::endl;
  
  std::future<std::string> fut2 = add_task(call_zhuanche);
  std::cout << fut2.get() << std::endl;

  pthread_exit(NULL);

}
