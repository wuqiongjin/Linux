#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>
using namespace std;

int main()
{
  mkfifo("myFIFO", 0666);
  int fd = open("myFIFO", O_RDWR);

  int id = fork();
  if(id == 0)
  {
    //进程A进行写入
    const char* msg = "i am process A";
    write(fd, msg, strlen(msg));
  }
  else 
  {
    char buffer[256];
    read(fd, buffer, sizeof(buffer));
    cout << buffer << endl;
  }
  
  close(fd);
  return 0;
}
