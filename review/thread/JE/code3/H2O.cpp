#include <iostream>
#include <pthread.h>
#include <functional>
#include <unistd.h>
using namespace std;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t hyd = PTHREAD_COND_INITIALIZER;
pthread_cond_t oxy = PTHREAD_COND_INITIALIZER;

void* releaseHydrogen(void* arg)
{
  while(1)
  {
    //pthread_mutex_lock(&mtx);
    cout << "HH";  
    fflush(stdout);
    sleep(1);
    pthread_cond_signal(&oxy);
    pthread_cond_wait(&hyd, &mtx);
    //pthread_mutex_unlock(&mtx);
  }
}

void* releaseOxygen(void* arg)
{
  while(1)
  {
    //pthread_mutex_lock(&mtx);
    pthread_cond_wait(&oxy, &mtx);
    cout << "O";
    fflush(stdout);
    pthread_cond_signal(&hyd); 
    //pthread_mutex_unlock(&mtx);
  }
}

class H2O {
  public:
    H2O() {
    }
    void hydrogen(function<void*(void* arg)> releaseHydrogen) {
      // releaseHydrogen() 输出 "H". Do not change or remove this line.
      releaseHydrogen(NULL);
    }
    void oxygen(function<void*(void* arg)> releaseOxygen) {
      // releaseOxygen() 输出 "O". Do not change or remove this line.
      releaseOxygen(NULL);
    }
};

int main()
{
  pthread_t tid1, tid2;
  //H2O* ph2o = new H2O;
  //ph2o->hydrogen(std::bind(releaseHydrogen));
  //ph2o->hydrogen(releaseOxygen);
 // pthread_create(&tid1, NULL, ph2o->hydrogen, NULL);
 // pthread_create(&tid2, NULL, ph2o->oxygen, NULL);
 
  pthread_create(&tid1, NULL, releaseHydrogen, NULL);
  pthread_create(&tid2, NULL, releaseOxygen, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  return 0;
}
