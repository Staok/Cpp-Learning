#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
  int msgid;
  msgid = msgget(IPC_PRIVATE, 0600);//msgget系统调用创建一个消息队列，或者获取一个已有到消息队列
  if(msgid < 0){
    perror("msgget");
    return 1;
  }
  printf("%d\n", msgid);
  return 0;
}