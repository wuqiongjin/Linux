#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;


int main()
{
  pid_t id;
  id = fork();
  if(id == 0)
  {
    //child
    printf("Child Process!!!\n");
    sleep(3);
    exit(1);  //子进程强制退出,后面我会说
  }
  else 
  {
    printf("Father Process\n");
  }
  
  wait(nullptr);

  return 0;
}
