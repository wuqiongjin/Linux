#include <iostream>
#include <unistd.h>
#include <pthread.h>
using namespace std;

void* Routine(void* arg)
{
  pthread_detach(pthread_self()); //线程分离后就不用主线程再join子线程了
  cout << (char*)arg << endl; 
  pthread_exit((void*)1);
}

int main()
{
  pthread_t tid;
  const char* msg = "A message!";
  pthread_create(&tid, NULL, Routine, (void*)msg);
  
  sleep(1);
  
  if(pthread_join(tid, NULL) == 0)
  {
    cout << "join thread Success!" << endl; 
  }
  else 
  {
    cout << "join thread Failed!" << endl;
  }

  return 0;
}
