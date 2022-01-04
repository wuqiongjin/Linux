#pragma once 
#include <iostreamear
#include <unistd.h>
#include <vector>
#include <semaphore.h>
#include <pthread.h>

template <class T>
class RingQueue
{
  public:
    RingQueue(size_t num = 10)
      :cap(num),
       pro_index(0),
       con_index(0)
    {
      rq.resize(cap); 
      sem_init(&blank_sem, 0, cap);
      sem_init(&data_sem, 0, 0);
    }
    
    void Put(T& data)
    {
      sem_wait(&blank_sem);
      rq[pro_index++] = data;
      pro_index %= cap;
      sem_post(&data_sem);
    }

    void Get(T& data)
    {
      sem_wait(&data_sem);
      data = rq[con_index++];
      con_index %= cap;
      sem_post(&blank_sem);
    }

    ~RingQueue()
    {
      sem_destroy(&blank_sem);
      sem_destroy(&data_sem);
    }
  private:
    std::vector<T> rq;
    size_t cap;
    size_t pro_index;
    size_t con_index;
    sem_t blank_sem;
    sem_t data_sem;
};
