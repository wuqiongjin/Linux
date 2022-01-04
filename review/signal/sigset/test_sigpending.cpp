#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;

void handler(int signo)
{
  cout << "Catch signal: " << signo << endl;
}

int main()
{
  signal(2, handler);
  sigset_t set;
  sigemptyset(&set);
  sigaddset(&set, 2);
  sigprocmask(SIG_BLOCK, &set, NULL);

  int cnt = 0;
  while(1)
  {
    ++cnt;
    cout << "cnt: " << cnt << endl;
    if(cnt == 5)
      sigprocmask(SIG_UNBLOCK, &set, NULL);
    sleep(1);
  }

  return 0;
}
