#pragma once
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <cstdlib>
#include <queue>

template <class T>
class BlockQueue
{
  public:
    BlockQueue(size_t num = 10)
      :cap(num)
    {
      pthread_mutex_init(&lock, NULL);
      pthread_cond_init(&full, NULL);
      pthread_cond_init(&empty, NULL);
    }

    void Put(T& data)
    {
      pthread_mutex_lock(&lock);
      while(q.size() >= cap)
      {
        pthread_cond_wait(&full, &lock);
      }

      if(q.size() >= cap / 2)
        pthread_cond_signal(&empty);
      q.push(data);
      pthread_mutex_unlock(&lock);
      std::cout << "Producer Push a data!" << std::endl;
    }

    void Get(T& data)
    {
      pthread_mutex_lock(&lock);
      while(q.empty())
      {
        pthread_cond_wait(&empty, &lock);
      }
      
      if(q.size() <= cap / 4)
        pthread_cond_signal(&full);

      data = q.front();
      q.pop();
      pthread_mutex_unlock(&lock);
      std::cout << "Consumer Get a data~~~" << std::endl;
    }

    ~BlockQueue() 
    {
      pthread_mutex_destroy(&lock);
      pthread_cond_destroy(&full);
      pthread_cond_destroy(&empty);
    }
  private:
    std::queue<T> q;
    size_t cap;
    pthread_mutex_t lock;
    pthread_cond_t full;
    pthread_cond_t empty;
};
