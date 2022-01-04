#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

sem_t sem;

void* Routine(void* arg)
{
  int index = *(int*)arg;
  while(1)
  {
    sem_wait(&sem);
    
    cout << index <<"Doing some tasks!" << endl;
    sleep(1);
    sem_post(&sem);
    usleep(1000);
  }
}

int main()
{
  sem_init(&sem, 0, 2);
  pthread_t tid[5];

  for(int i = 0; i < 5; ++i)
  {
    pthread_create(&tid[i], NULL, Routine, (void*)&i);
    usleep(1000);
  }

  for(int i = 0; i < 5; ++i)
    pthread_join(tid[i], NULL);

  sem_destroy(&sem);
  return 0;
}
