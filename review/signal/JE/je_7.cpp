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
  //signal(2, sigcb);
  while(1);
  return 0;
}
