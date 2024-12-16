#include <stdio.h>
#include <mysql.h>
#include <iostream>

//https://www.cnblogs.com/wunaozai/p/3618383.html
int main(int argc,char *argv[])
{
    MYSQL conn;
    int res;
    mysql_init(&conn);
    if(mysql_real_connect(&conn,"192.168.56.1","root","123456","student_test",0,NULL,CLIENT_FOUND_ROWS)) //"root":数据库管理员 "":root 密码 "test":数据库的名字
    {
       std::cout << "connect success\n" << std::endl;
       res = mysql_query(&conn,"insert into Course values('04','物理','89')");
       if(res){
            std::cout<< "errors\n" << std::endl;
        }else{
            std::cout << "OK\n" << std::endl;
        }
       mysql_close(&conn);
    }
    return 0;
}

