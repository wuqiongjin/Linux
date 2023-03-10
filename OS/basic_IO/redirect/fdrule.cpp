#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
using namespace std;

int main()
{
  close(1);
  umask(0);
  int fd = open("log.txt", O_WRONLY | O_CREAT, 0666);
  cout << "fd:" << fd << endl; 
  //cout << "Put words to log.txt" << endl;
  //char buffer[64] = "Put words to log.txt\n"; //要写入的话，只能用const char*去写，这种写法不对
  const char* buffer = "Put words to log.txt\n";
  //write(1, buffer, sizeof(buffer)); 
  write(1, buffer, strlen(buffer)); 

  close(fd);
  return 0;
}
