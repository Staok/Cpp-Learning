#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8111
#define MESSAGE_SIZE 1024

int main(){

  int ret = -1;

  int pid;
  int socket_fd = -1;
  int accept_fd = -1;

  int curpos = 0;
  int backlog = 10;
  int flag = 1;

  struct sockaddr_in local_addr, remote_addr;

  //create a tcp socket
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socket_fd == -1 ){
    perror("create socket error");
    exit(1);
  }

  //set option of socket
  ret = setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
  if ( ret == -1 ){
    perror("setsockopt error");
  }

  //set local address
  local_addr.sin_family = AF_INET;
  local_addr.sin_port = htons(PORT);
  local_addr.sin_addr.s_addr = INADDR_ANY;
  bzero(&(local_addr.sin_zero), 8);

  //bind socket
  ret = bind(socket_fd, (struct sockaddr *)&local_addr, sizeof(struct sockaddr_in));
  if(ret == -1 ) {
    perror("bind error");
    exit(1);
  }

  ret = listen(socket_fd, backlog);
  if ( ret == -1 ){
    perror("listen error");
    exit(1);
  }

  for(;;){

    int addr_len = sizeof( struct sockaddr_in );
    //accept an new connection, block......
    accept_fd = accept( socket_fd, (struct sockaddr *)&remote_addr, &addr_len );

    //create a sub process，并获取fork后的进程id
    pid = fork();

    //pid =0 ，则说明是子进程，进行客户端的收发包操作，对于父进程来说，会进入下一次循环，再次阻塞，等待新的udp包
    //通过fork方式 可以创建多个子进程，进行多人并发通信 
    if( pid==0 ){ 

      char in_buf[MESSAGE_SIZE] = {0,};
      for(;;){
        memset(in_buf, 0, MESSAGE_SIZE);

        ret = recv(accept_fd ,&in_buf, MESSAGE_SIZE, 0);
        if(ret == 0){
          break; 
        } 

        printf( "receive message:%s\n", in_buf );
        send(accept_fd, (void*)in_buf, MESSAGE_SIZE, 0);

      }

      printf("close client connection...\n");
      close(accept_fd);
    } 

    //parent process
    
  }
  //由父进程关闭
  if(pid != 0 ){
    printf("quit server...\n");
    close(socket_fd);
  }

  return 0;
}

