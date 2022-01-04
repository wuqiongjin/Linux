#include <iostream>
#include <unistd.h>
#include <cstring>
using namespace std;

int main()
{
  int fd[2];
  pipe(fd);
  pid_t id = fork();

  if(id == 0)
  {
    close(fd[1]);
    char buffer[128];
    ssize_t num = read(fd[0], buffer, sizeof(buffer));
    buffer[num] = '\0';
    cout << buffer;
  }
  else 
  {
    close(fd[0]);
    const char* buffer = "i am father\n";
    write(fd[1], buffer, strlen(buffer));
      
  }


  return 0;
}
