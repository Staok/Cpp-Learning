/*
std::call_once的应用：类成员的延迟初始化，并只初始化一次。和static的作用很像，
都要求是线程安全的，c++11之前在多线程的环境下，static好像不是线程安全的，c++11开始，
static是线程安全的了。
注意：即使某一个特定的线程里，多次调用了std::call_once，实际的效果是std::call_once里
的函数也只被执行一次。
例子：模仿建立数据库的连接，只有在放生send_data或者receive_data的时候，才去连接数据库，
并且只连接了一次。即使，既调用了send_data也调用了receive_data，但是open_connection
只被执行了一次，
也就是说数据库的连接只建立一次就够了，不管你是要接收，还是要发送。
*/

#include <mutex>
#include <thread>
#include <iostream>

class X{
  int connect_detail;
  std::once_flag connect_init_flag;
  void open_connection(){
    std::cout << "open:" << connect_detail << std::endl;
    //open();
  }

public:
  X(int detail):connect_detail(detail){}
  void send_data(){
    std::call_once(connect_init_flag, &X::open_connection, this);
    //send();
  }
  void receive_data(){
    std::call_once(connect_init_flag, &X::open_connection, this);
    //receive();
  }
};

int main(){
  X x(10);
  x.send_data();
  x.receive_data();
}