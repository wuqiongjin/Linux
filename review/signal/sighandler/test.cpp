#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;

void handler(int signal)
{
  cout << "signal: " << signal << endl;
}

int main()
{
  //signal(2, handler);
  struct sigaction newact, oldact;
  newact.sa_handler = handler;
  newact.sa_flags = 0;

  sigaction(2, &newact, &oldact);
  while(1);
  return 0;
}




