#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;

void sigcb(int signo)
{
  cout << "signal: " << signo << endl;
}

int main()
{
  struct sigaction act;
  act.sa_flags = 0;
  act.sa_handler = sigcb;
  sigaction(2, &act, NULL);
  while(1);
  return 0;
}
