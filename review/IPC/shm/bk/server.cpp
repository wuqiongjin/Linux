#include "common.h"

int main()
{
  key_t key = ftok(PATHNAME, PROJ_ID);
  int shmid = shmget(key, SIZE, IPC_CREAT | IPC_EXCL | 0644);
  
  int* mm = (int*)shmat(shmid, NULL, 0);

   

  shmdt(mm);;
  shmctl(shmid, IPC_RMID, NULL);
  return 0;
}
