#include <iostream>
#include <unistd.h>
#include <pthread.h>
using namespace std;

int tickets = 1000;

void* Get_Tickets(void* arg)
{
  int index = *(int*)arg;
  usleep(1000);
  while(1)
  {
    usleep(1000);
    if(tickets > 0)
    {
      --tickets;
      cout << "thread#" << index << " got a ticket!!! tickets:" << tickets  << endl;
    }
    else 
    {
      cout << "No tickets~" << endl;
      break;
    }
  }
  pthread_exit(NULL);
}

int main()
{
  pthread_t tid[4];
  for(int i = 0; i < 4; ++i)
  {
    pthread_create(tid + i, NULL, Get_Tickets, (void*)&i);
    usleep(1000);
  }

  for(int i = 0 ; i < 4; ++i)
    pthread_join(tid[i], NULL);
  return 0;
}
