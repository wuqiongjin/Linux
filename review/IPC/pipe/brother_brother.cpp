#include <iostream>
#include <sys/wait.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <unistd.h>
using namespace std;

const int N = 2; //创建2个子进程

int main()
{
  int fd[2];
  pipe(fd);
  pid_t id[N] = { 0 };

  int index = 0; //兄弟进程之间靠index区分！！！

  //创建了N个子进程
  for(index = 0; index < N; ++index)
  {
    if(index == 0 || id[index - 1] > 0)
      id[index] = fork();

    //子进程直接退出
    if(id[index] == 0)
      break;
  }

  //Child == 1 || 2
  if(index == 0)
  {
    cout << getpid() << " " << getppid() << endl;
    //执行ls
    close(fd[0]);
    dup2(fd[1], 1);
    execlp("ls", "ls", "-l", NULL);
  }
  else if(index == 1)
  {
    cout << getpid() << " " << getppid() << endl;
    close(fd[1]);
    dup2(fd[0], 0);
    execlp("wc", "wc", "-l", NULL);
  }
  else 
  {
    close(fd[0]);
    close(fd[1]);
    //Father 
    int status = 0;
    for(int i = 0; i < N; ++i)
    {
      waitpid(id[i], &status, 0);    
      if(WIFEXITED(status))
      {
        //cout << "exit_code: " << WEXITSTATUS(status) << endl;
        //cout << "signal: " << (status & 0x7F) << endl;
        //cout << "core dump: " << (status & 0x80) << endl;
      }

    }
  }
  return 0;
}
