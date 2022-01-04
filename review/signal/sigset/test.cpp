#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
using namespace std;

int main()
{
  sigset_t set;
  sigemptyset(&set);
  sigaddset(&set, 2); //将2号信号加入屏蔽集
  sigprocmask(SIG_BLOCK, &set, NULL); //给当前进程设置信号集

  pid_t id = fork();
  if(id == 0)
  {
    int cnt = 0;
    while(1)
    {
      ++cnt;
      if(cnt == 5)
      {
        //5s后解除子进程对2号信号的屏蔽
        //sigdelset(&set, 2);
        sigprocmask(SIG_UNBLOCK, &set, NULL);
      }

      cout << "child# " << endl;
      sleep(1);
    }
  }
  else 
  {
    int status = 0;
    while(1)
    {
      cout << "Father sent signal to child" << endl;
      kill(id, 2);  //给子进程发送2号信号
      sleep(1);

      waitpid(id, &status, WNOHANG);
      if(status)
      {
        cout << "Child signal: " << (status & 0x7F) << endl;
        break;
      }
    }
  }
  return 0;
}
