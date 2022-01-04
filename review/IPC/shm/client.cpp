#include "common.h"

int main()
{
  key_t key = ftok(PATHNAME, PROJ_ID);
  int shmid = shmget(key, SIZE, IPC_CREAT);
  sleep(1);
  char* mm = (char*)shmat(shmid, NULL, 0);
  
  for(int i = 0; i < 26;)
  {
    mm[i] = 'a' + i;
    mm[++i] = '\0';
    sleep(1);
  }
  
  shmdt(mm);
  //shmctl(shmid, IPC_RMID, NULL);  //server端把共享内存删了，client不需要再操作了
  return 0;
}
