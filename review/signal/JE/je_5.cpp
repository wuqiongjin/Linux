#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;

void handler(int signo)
{
  cout << "signal: " << signo << endl;
}

int main()
{
  //捕捉2和40号信号
  signal(2, handler);
  signal(40, handler);

  sigset_t set;
  sigemptyset(&set);
  sigaddset(&set, 2);
  sigaddset(&set, 40);
  sigprocmask(SIG_BLOCK, &set, NULL);
  
  int cnt = 0;
  while(1)
  {
    if(cnt == 5)
    {
      sigprocmask(SIG_UNBLOCK, &set, NULL);
      break;
    }
    raise(2);
    raise(40);
    ++cnt;
    sleep(1);
  }
  return 0;
}
