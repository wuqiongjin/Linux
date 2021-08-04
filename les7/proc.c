#include "proc.h"

//倒计时
void Count()
{
  int i = 9;
  while(i)
  {
    printf("%2d\r", i);
    fflush(stdout);
    sleep(1);
    --i;
  }
  printf("\n");
}

//进度条
void ProcBar()
{
  char proc[101];
  memset(proc, '\0', sizeof(proc));
  int i;
  const char* label = "<^>_"; 
  for(i = 0; i <= 100; ++i)
  {
    printf("[%-100s][%d%%][%c]\r", proc, i, label[i%4]);
    proc[i] = '#';
    usleep(50000);
    fflush(stdout);
  }
  printf("\n");
}

