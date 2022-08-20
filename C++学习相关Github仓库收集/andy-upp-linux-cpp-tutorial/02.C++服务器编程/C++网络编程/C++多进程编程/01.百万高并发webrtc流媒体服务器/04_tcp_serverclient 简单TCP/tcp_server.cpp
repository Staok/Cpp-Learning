#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8444
#define MESSAGE_SIZE 1024

int main(){

  int ret = -1;

  int socket_fd = -1;
  int accept_fd = -1;

  int curpos = 0;
  int backlog = 10;
  int flag = 1;

  char in_buf[MESSAGE_SIZE] = {0,};
  struct sockaddr_in local_addr, remote_addr;

  //create a tcp socket
  //创建一个TCP套接字，使用IPV4协议，数据传输方式为SOCK_STREAM，使用TCP协议
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socket_fd == -1 ){
    perror("create socket error");
    exit(-1);
  }

  //set option of socket
  //给socket设置选项，参数分别是socket_id,socket层级的level，地址重用，设置启动，设置整形大小
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

  //loop
  for(;;){
    socklen_t addr_len = sizeof( struct sockaddr_in );
    //accept an new connection
    accept_fd = accept( socket_fd, (struct sockaddr *)&remote_addr, &addr_len );
    for(;;){
      memset(in_buf, 0, MESSAGE_SIZE);

      //receive network data and print it
      ret = recv( accept_fd ,(void*)in_buf ,MESSAGE_SIZE ,0 );
      if(ret == 0 ){
        break; 
      } 
      printf( "receive message:%s\n", in_buf );
      send(accept_fd, (void*)in_buf, MESSAGE_SIZE, 0); 
    }
    printf("close client connection...\n");
    close(accept_fd);
  }

  printf("quit server...\n");
  close(socket_fd);

  return 0;
}

