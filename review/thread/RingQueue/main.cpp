#include "RingQueue.h"
#include <cstdlib>
#define NUM 32

void* Producer(void* arg)
{
  RingQueue<int>* rq = (RingQueue<int>*)arg;
  while(1)
  {
    int data = rand() % 100;
    rq->Put(data);
    std::cout << "Producer Put a data!!!" << std::endl;
  }
}

void* Consumer(void* arg)
{
  RingQueue<int>* rq = (RingQueue<int>*)arg;
  while(1)
  {
    int data;
    rq->Get(data);
    std::cout << "Consumer Get a data: " << data << std::endl;
    sleep(1);
  }
}

int main()
{
  srand(unsigned(time(NULL)));
  RingQueue<int>* rq = new RingQueue<int>(NUM);
  pthread_t tid1, tid2;

  pthread_create(&tid1, NULL, Producer, (void*)rq);
  pthread_create(&tid2, NULL, Consumer, (void*)rq);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  return 0;
}
