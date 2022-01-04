#include <iostream>
#include <pthread.h>
using namespace std;

pthread_mutex_t lock;

void* Routine(void* arg)
{
  while(1)
  {
    pthread_mutex_lock(&lock);
    pthread_mutex_lock(&lock);
    
    cout << "Dead Lock" << endl;

    pthread_mutex_unlock(&lock);
    pthread_mutex_unlock(&lock);

  }
  pthread_exit((void*)1); 
}

int main()
{
  pthread_mutex_init(&lock, NULL);

  pthread_t tid;
  pthread_create(&tid, NULL, Routine, NULL);

  pthread_join(tid, NULL);
  pthread_mutex_destroy(&lock);
  return 0;
}
