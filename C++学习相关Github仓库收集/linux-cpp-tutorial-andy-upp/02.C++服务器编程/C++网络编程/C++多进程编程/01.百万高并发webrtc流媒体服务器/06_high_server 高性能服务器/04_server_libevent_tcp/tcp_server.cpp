#include <iostream>

#define PORT 8111

//定义有客户链接时的回调函数
void on_accept_cb(struct evconnlistener *listener,
                  evutil_socket_t fd,
                  struct sockaddr* addr,
                  int socklen,
                  void* ctx)
{
    
}




int main(int argc, char* argv[])
{
    struct socket_sin serveraddr; //设置地址到数据结构
    struct event_base *base = NULL;
    base = event_base_new(); //创建libevent内部到处理结构和epoll对象
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = INADDR_ANY;




    // //链接 绑定和侦听socket，accept_conn_cb是当有客户端链接时的回调函数
    evconnlistenner_new_bind(base,on_accept_cb,NULL,LEV_OPT_REUSEABLE,10,(struct sockaddr*)serveraddr,sizeof(server));
    return 0;
}