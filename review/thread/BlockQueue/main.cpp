#include "BlockQueue.h"
#include <time.h>
#define NUM 10

void* Producer(void* arg)
{
  BlockQueue<int>* bq = (BlockQueue<int>*)arg;
  while(1)
  {
    int data = rand() % 100;      
    bq->Put(data);
    sleep(1);
  }
}

void* Consumer(void* arg)
{
  BlockQueue<int>* bq = (BlockQueue<int>*)arg;
  while(1)
  {
    usleep(10000);
    int data;
    bq->Get(data);
    std::cout << "Get a data :" << data << std::endl;
  }

}

int main()
{
  BlockQueue<int>* bq = new BlockQueue<int>(NUM);
  pthread_t tid1, tid2;
  srand(time(NULL));
  
  pthread_create(&tid1, NULL, Producer, (void*)bq);
  pthread_create(&tid2, NULL, Consumer, (void*)bq);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  return 0;
}
