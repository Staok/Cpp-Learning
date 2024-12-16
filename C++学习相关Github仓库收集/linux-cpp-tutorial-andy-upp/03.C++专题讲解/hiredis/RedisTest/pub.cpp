#include <stdio.h>
#include <hiredis/hiredis.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <boost/format.hpp>
using namespace std;
using namespace boost;

int main()
{
     redisContext *conn  = redisConnect("127.0.0.1",6379);
     if(conn != NULL && conn->err)
     {
         printf("connection error: %s\n",conn->errstr);
         return 0;
     }
     for(int i= 0; i < 1000; i++)
     {
        usleep(1000000);
        string bbb = "this_this_OK";

        string ccc =str(boost::format("PUBLISH aaa %1%")%bbb);
        const char* str = ccc.c_str();
        cout << str << endl;
        // redisReply *reply = (redisReply*)redisCommand(conn,"PUBLISH aaa %s",aaa);
        redisReply *reply = (redisReply*)redisCommand(conn,str);

        cout << "循环到第" << i << "次" << endl;
        freeReplyObject(reply);
     }
     
    //  reply = redisCommand(conn,"get foo");
    //  printf("%s\n",reply->str);
    //  freeReplyObject(reply);
 
     redisFree(conn);
     return 0;
}
