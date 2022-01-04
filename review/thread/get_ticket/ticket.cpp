#include <iostream>
#include <unistd.h>
#include <pthread.h>
using namespace std;

int tickets = 1000;
pthread_mutex_t lock; //定义一个互斥锁

void* GetTicket(void* arg)
{
  int index = *(int*)arg;
  
  while(1)
  {
    usleep(1000);
    pthread_mutex_lock(&lock);
    if(tickets > 0)
    {
      cout << "Thread[" << index << "]: get tickets!  tickets:" << tickets << endl;  
      tickets--;
      pthread_mutex_unlock(&lock);
    }
    else 
    {
      pthread_mutex_unlock(&lock);  //线程退出时可能拿着锁
      break;
    }
  }
  
  cout << "Thread[" << index << "]: Quit~~~~~~~" << endl;  
  pthread_exit((void*)1);
}

int main()
{
  pthread_mutex_init(&lock, NULL);  //初始化互斥锁
  pthread_t tid[4];
  
  for(int i = 0; i < 4; ++i)
  {
    pthread_create(&tid[i], NULL, GetTicket, (void*)&i);
    usleep(1000);
  }

  for(int i = 0; i < 4; ++i)
    pthread_join(tid[i], NULL);

  pthread_mutex_destroy(&lock); //销毁互斥锁
  return 0;
}
