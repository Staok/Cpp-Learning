#include<iostream>
#include <unistd.h>
//标准头文件
#include <stdlib.h>

int main(int argc, char* argv[])
{ 
  //daemon的两个参数，第一个0表示我们要切换到根目录下，第二个0表示将标准输入和输出重定向到NULL文件下
  if(daemon(0,0) == -1){
    std::cout << "error\n" << std::endl;
    //如果失败直接退出
    exit(-1);
  }
  while(1)
  {
    sleep(1);
  }
  return 0;
}
