#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
using namespace std;


//输出重定向
//int main()
//{
//  close(1); 
//  umask(0);
//  int fd = open("file.txt", O_WRONLY | O_CREAT, 0666);
//  const char* buffer = "Write some words to file.txt\n";
//  write(fd, buffer, strlen(buffer));
//  
//
//  close(fd);
//  return 0;
//}


//追加重定向
//int main()
//{
//  close(1);
//  int fd = open("file.txt", O_WRONLY | O_APPEND);
//  const char* buffer = "Append some words \nto the end of file\n";
//  write(1, buffer, strlen(buffer));
//  close(fd);
//  return 0;
//}

//输入重定向
//int main()
//{
//  close(0);
//  int fd = open("file.txt", O_RDONLY);
//  char buffer[128];
//  ssize_t num =  read(fd, buffer, sizeof(buffer));  //read的返回值返回实际读到的个数
//  buffer[num] = '\0'; //这里必须给结尾添加'\0'，不然打印的时候就会出乱码
//
//  cout << buffer;
//  close(fd);
//  return 0;
//}

//dup2 test
int main()
{
  int fd = open("file.txt", O_RDONLY);
  dup2(fd, 0);
  char buffer[256];
  ssize_t num = read(fd, buffer, sizeof(buffer));
  buffer[num] = '\0';

  cout << buffer;
  return 0;
}
