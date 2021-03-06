#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <cstring>
using namespace std;

int main()
{
  int fd[2];
  pipe(fd);
  pid_t id = fork();
  
  if(id == 0)
  {
    //子进程
    close(fd[1]); //关闭写端
    char buffer[128];
    ssize_t num = read(fd[0], buffer, sizeof(buffer));
    buffer[num] = '\0';
    cout << buffer;
  }
  else 
  {
    //父进程
    close(fd[0]); //关闭读端
    const char* buffer = "this is father porcess!\n";
    write(fd[1], buffer, strlen(buffer));
    wait(NULL);
  }

  return 0;
}
