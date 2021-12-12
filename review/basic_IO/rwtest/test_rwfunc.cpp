#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;

int main()
{
  //umask(002);
  //int fd = open("log.txt", O_WRONLY | O_CREAT, 0666); 
  //
  //char buff[64] = "write some buffer to log.txt\n";
  //write(fd, buff, sizeof(buff));

  //close(fd);
  
  int fd = open("log.txt", O_RDONLY);

  char buffer[64];
  read(fd, buffer, sizeof(buffer));
  
  cout << buffer; //这里没有加换行哦!
  close(fd);
  return 0;
}
