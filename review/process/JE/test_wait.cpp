#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main()
{
  pid_t id = fork();

  if(id == 0)
  {
    //child
    cout << "i am child process" << endl;
    sleep(5);
    exit(23);
  }
  int status = 0;
  waitpid(id, &status, 0);
  if(WIFEXITED(status))
  {
    cout << "signal: " << (status & 0x7F)  << endl;
    cout << "coredump: " << (status &0x80) << endl;
    cout << "exit code: " << WEXITSTATUS(status) << endl;
    cout << "exit code: " << ((status >> 8) & 0xFF) << endl;
  }

  return 0;
}
