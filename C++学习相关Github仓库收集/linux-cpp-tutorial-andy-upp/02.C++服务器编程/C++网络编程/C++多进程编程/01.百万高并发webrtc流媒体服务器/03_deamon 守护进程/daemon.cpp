//#include "apue.h"
#include <stdio.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>

/**
 * 注释1：因为我们从shell创建的daemon子进程，所以daemon子进程会继承shell的umask，如果不清除的话，会导致daemon进程创建文件时屏蔽某些权限。
 * 
 * 注释3：
 * 注释4：最好在这里再次fork。这样使得daemon进程不再是会话首进程，那么永远没有机会获得控制终端。如果这里不fork的话，会话首进程依然可能打开控制终端。
 * 注释5：
 * 注释6：在子进程中关闭从父进程中继承过来的那些不需要的文件描述符。可以通过_SC_OPEN_MAX来判断最高文件描述符(不是很必须).
 * 
 */
void daemonize(const char *cmd){
  int i, fd0, fd1, fd2;
  //
  pid_t pid;
  //struct rlimit rl;
  //struct sigaction sa;

  /* * Clear file creation mask. */
  //umask(0);//注释1

  /* * Get maximum number of file descriptors. */
  //if (getrlimit(RLIMIT_NOFILE, &rl) < 0)
  //  err_quit("%s: can't get file limit", cmd);

  /* * Become a session leader to lose controlling TTY. */
  //注释2：fork后让父进程退出，子进程获得新的pid，肯定不为进程组组长，这是setsid前提。
  //fork()后生成了一个新的pid，如果这个进程id<0, 则说明创建失败
  if ((pid = fork()) < 0) {
    printf("%s: can't fork", cmd);  
    exit(-1);
  }else if (pid != 0){/* parent */ //如果pid不为0，则创建父进程成功,返回的pid = 0就是子进程了
    //如果创建父进程成功，就将父进程退出，这样就保证了只有子进程，这时候子进程就是一个孤儿进程
    exit(0);
  }

  //注释3 调用setsid来创建新的进程会话。这使得daemon进程成为会话首进程，脱离和terminal的关联。
  //重新设置它的sessionid
  setsid();
  
  /* * Ensure future opens won't allocate controlling TTYs. */
  /*
  sa.sa_handler = SIG_IGN;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;

  if (sigaction(SIGHUP, &sa, NULL) < 0)
    err_quit("%s: can't ignore SIGHUP", cmd);
  if ((pid = fork()) < 0)//注释4
    err_quit("%s: can't fork", cmd);
  */
  /*else if (pid != 0) *//* parent */
  /*
    exit(0);
  */

  /* * Change the current working directory to the root so * we won't prevent file systems from being unmounted. */
  //注释5 将当前工作目录切换到根目录。父进程继承过来的当前目录可能mount在一个文件系统上，如果不切换到根目录，那么这个文件系统不允许unmount。
  if (chdir("/") < 0) {
    printf("%s: can't change directory to /", cmd);
    //出错后，直接退出
    exit(-1);
  }


  /* * Close all open file descriptors. */
  /*
  if (rl.rlim_max == RLIM_INFINITY)
    rl.rlim_max = 1024;

  for (i = 0; i < rl.rlim_max; i++)
    close(i);//注释6
  */

  /* * Attach file descriptors 0, 1, and 2 to /dev/null. */
  //注释7：打开/dev/null复制到0,1,2，因为dameon进程已经和terminal脱离了，所以需要重新定向标准输入，标准输出和标准错误(不是很必须).
  //O_RDWR表示可读可写
  fd0 = open("/dev/null", O_RDWR);
  //fd1 = dup(0);//注释7
  //fd2 = dup(0);//注释7
  //用重定向函数dup2将 标准输入重定向到fd0
  dup2(fd0, STDIN_FILENO);
  dup2(fd0, STDOUT_FILENO);
  dup2(fd0, STDERR_FILENO);

  /* * Initialize the log file. */
  /*
  openlog(cmd, LOG_CONS, LOG_DAEMON);
  if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
    syslog(LOG_ERR, "unexpected file descriptors %d %d %d",fd0, fd1, fd2);
    exit(1);
  }
  */

}

int main(int argc, char* argv[])
{
  daemonize("test");

  while(1)
  {
    //每1秒休息一下，避免消耗掉全部CPU
    sleep(1);
  }

}
