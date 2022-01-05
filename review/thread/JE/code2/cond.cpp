#include <iostream>
#include <unistd.h>
#include <pthread.h>
using namespace std;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* func1(void* arg)
{
  char* name = (char*)arg;
  while(1)
  {
    pthread_cond_wait(&cond, &mtx);
    cout << "我是线程B" << endl;
    pthread_cond_signal(&cond);
  }
}

void* func2(void* arg)
{
  while(1)
  {
    pthread_cond_signal(&cond);
    cout << "我是线程A" << endl;
    pthread_cond_wait(&cond, &mtx); 
    sleep(1);
  }
}

int main()
{
  pthread_t tid1, tid2;
  pthread_create(&tid1, NULL, func1,(void*)"A");
  pthread_create(&tid2, NULL, func2,(void*)"B");

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  return 0;
}
