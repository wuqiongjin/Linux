#include "common.h"


int main()
{
  key_t key = ftok(PATHNAME, PROJ_ID);
  int shmid = shmget(key, SIZE, IPC_CREAT);
  int* mm = (int*)shmat(shmid, NULL, 0);
  
  while(1)
  {
    
  }

  shmdt(mm);
  return 0;
}
