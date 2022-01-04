#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <cstring>
using namespace std;

int main()
{ 
  mkfifo("myFIFO", 0666);
  int fd = open("myFIFO", O_RDWR);

  pid_t id = fork();


  if(id == 0)
  {
    char buffer[128];
    ssize_t num = read(fd, buffer, sizeof(buffer));
    buffer[num] = '\0';
    cout << buffer;
  }
  else 
  {
    const char* buffer = "Here is Father Process!\nI'm using myFIFO to send you a message!\n";
    write(fd, buffer, strlen(buffer));
    wait(NULL);
  }

  return 0;
}
