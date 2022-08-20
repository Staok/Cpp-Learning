/*************************************************************************
    > File Name: redis_publisher.h
    > Author: chenzengba
    > Mail: chenzengba@gmail.com 
    > Created Time: Sat 23 Apr 2016 10:15:09 PM CST
    > Description: 封装hiredis，实现消息发布给redis功能
 ************************************************************************/
 
#ifndef REDIS_PUBLISHER_H
#define REDIS_PUBLISHER_H
 
#include <stdlib.h>
#include <hiredis/async.h>
#include <hiredis/adapters/libevent.h>
#include <string>
#include <vector>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <boost/tr1/functional.hpp>
 
class CRedisPublisher
{
public:    
    CRedisPublisher();
    ~CRedisPublisher();
 
    bool init();
    bool uninit();
    bool connect();
    bool disconnect();
    
    bool publish(const std::string &channel_name, 
        const std::string &message);
 
private:
     // 下面三个回调函数供redis服务调用
    // 连接回调
    static void connect_callback(const redisAsyncContext *redis_context,
        int status);
	
	// 断开连接的回调
    static void disconnect_callback(const redisAsyncContext *redis_context,
        int status);
 
	// 执行命令回调
    static void command_callback(redisAsyncContext *redis_context,
        void *reply, void *privdata);
 
    // 事件分发线程函数
    static void *event_thread(void *data);
    void *event_proc();
 
private:
     // libevent事件对象
    event_base *_event_base;
	// 事件线程ID
    pthread_t _event_thread;
	// 事件线程的信号量
    sem_t _event_sem;
	// hiredis异步对象
    redisAsyncContext *_redis_context;
};
 
#endif
