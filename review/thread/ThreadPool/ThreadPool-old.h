#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include <iostream>
#include <queue>
#include <unistd.h>
#include <pthread.h>

#define NUM 10

class Task
{
  public:
    Task() {}

    ~Task() {}
  private:
    int _base;
};

template <typename T>
class ThreadPool 
{
  public:
    bool IsEmpty() { return taskQueue.size() == 0; };

  public:
    ThreadPool(int num = NUM)
      :max_size(num)
    {
      pthread_mutex_init(&mtx, nullptr);
      pthread_cond_init(&cond, nullptr);
    }
    
    static void* Routine(void* arg)
    {
      ThreadPool* p_this = (ThreadPool*)arg;
      
      pthread_mutex_lock(&p_this->mtx);
      while(p_this->IsEmpty())
      {
        pthread_cond_wait(&p_this->cond, &p_this->mtx);
      }
      
      T data; 
      p_this->taskQueue
    }

    void PoolInit()
    {
      pthread_t tid;
      for(int i = 0; i < max_size; ++i)
      {
        int ret = pthread_create(&tid, nullptr, Routine, (void*)this);
        if(ret != 0)  //不等于0说明线程创建失败
        {
          std::cout << "thread create failed!" << std::endl;
          exit(1);
        }
      }
    }

    void Put(T& data)
    {
      pthread_mutex_lock(&mtx); 
      taskQueue.push(data);
      pthread_mutex_unlock(&mtx);
    }

    void Get(T& data)
    {
      
    }

    ~ThreadPool()
    {
      pthread_mutex_destroy(&mtx);
      pthread_cond_destroy(&cond);
    }
  private:
    std::queue<T*> taskQueue;
    int max_size; //线程的数量
    pthread_mutex_t mtx;
    pthread_cond_t cond;
    bool quit = false;
};


#endif 
