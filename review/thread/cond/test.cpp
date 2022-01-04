#include <iostream>
#include <unistd.h>
#include <pthread.h>
using namespace std;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* Run(void* arg)
{
  while(1)
  {
    pthread_cond_wait(&cond, &lock);
    cout << "Running ~~~~~" << endl;
  }
}

void* Control(void* arg)
{
  while(1)
  {
    sleep(1);
    pthread_cond_signal(&cond);
    cout << "Notify Run Thread!" << endl;
  }
}

int main()
{
  pthread_t tid1, tid2;
   
  pthread_create(&tid1, NULL, Control, NULL);
  pthread_create(&tid2, NULL, Run, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  return 0;
}
