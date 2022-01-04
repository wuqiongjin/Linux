#include "common.h"

int main()
{
  key_t key = ftok(PATHNAME, PROJ_ID);
  int shmid = shmget(key, SIZE, IPC_CREAT | IPC_EXCL | 0666);
  
  sleep(5);
  char* mm = (char*)shmat(shmid, NULL, 0);
  
  while(1)
  {
    cout << "client# " << mm << endl;
    sleep(1);
  }

  shmdt(mm);
  shmctl(shmid, IPC_RMID, NULL);
  return 0;
}
