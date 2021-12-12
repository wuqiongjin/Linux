#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main()
{
  pid_t id = fork();
  char * const arguments[] = {"ls", "-l", "-a", NULL}; 
  if(id == 0) 
    execvp("ls", arguments);
  wait(NULL);
  return 0;
}
