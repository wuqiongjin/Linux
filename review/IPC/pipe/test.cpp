#include <iostream>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <unistd.h>
using namespace std;

int main()
{
  int fd[2];
  pipe(fd);
  pid_t id = fork();
  
  if(id == 0)
  {
    //Child
    //关闭fd[1]，子进程是read端
    close(fd[1]);

    //stdin重定向到管道文件上，因为wc要从管道文件中读取
    dup2(fd[0], 0);
    
    execlp("wc", "wc", NULL);
    
  }
  else 
  {
    //Father
    //父端关闭fd[0]读端，父进程是write端
    close(fd[0]);
    //stdout重定向到管道中, 因为ls会输出到stdout上
    dup2(fd[1], 1);
    execlp("ls", "ls", "-l", "-i", "-a", NULL);
  }
  return 0;
}
