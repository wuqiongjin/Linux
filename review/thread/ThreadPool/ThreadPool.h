#pragma once 

#include <iostream>
#include <queue>
#include <unistd.h>
#include <pthread.h>

#define NUM 5

class Task
{
  public:
    Task(int base = 10)
      :_base(base)
    {}

    void Run()
    {
      _base *= 10;
      std::cout << "Run a task:" << _base << std::endl;
    }

    ~Task(){}
  private:
    int _base;
};


template <class T>
class ThreadPool 
{
  public:
    bool IsEmpty() { return taskQueue.empty(); };
    void LockQueue() { pthread_mutex_lock(&mtx); };
    void UnlockQueue() {pthread_mutex_unlock(&mtx); };
    void ThreadWait() { pthread_cond_wait(&cond, &mtx); };
  
    //线程创建
    void PoolInit()
    {
      pthread_t t;
      for(int i = 0; i < threadNum; ++i)
      {
        int ret = pthread_create(&t, nullptr, Routine, this);
        if(ret < 0)
        {
          std::cout << "thread create failed!" << std::endl;
          exit(1);
        }
      }
    }
  public:
    ThreadPool(int num = NUM)
      :threadNum(NUM)
    {
      pthread_mutex_init(&mtx, nullptr);
      pthread_cond_init(&cond, nullptr);
    }
    
    static void* Routine(void* arg)
    {
      pthread_detach(pthread_self()); //线程分离
      std::cout << "detach!!!!!!!!!!!!!!!" << std::endl;
      ThreadPool<T>* pthis = (ThreadPool<T>*)arg;
      while(true)
      {
        pthis->LockQueue();
        //任务队列空的话就让线程等待
        while(pthis->IsEmpty())
        {
          std::cout << "waitting~~~" << std::endl;
          usleep(5000);
          pthis->ThreadWait(); 
        }

        //任务队列不为空，处理任务
        T data;        
        pthis->Get(data);

        pthis->UnlockQueue();
        data.Run();
      }
    }

    void Get(T& data)
    {
      T* tmp = taskQueue.front();
      data = *tmp;
      taskQueue.pop();
    }

    void Push(T& data)
    {
      LockQueue();
      taskQueue.push(&data);
      UnlockQueue();
      pthread_cond_signal(&cond); //push一个任务后，要去signal一个线程去消化
    }


    ~ThreadPool()
    {
      pthread_mutex_destroy(&mtx);
      pthread_cond_destroy(&cond);
    }
  private:
    std::queue<T*> taskQueue;
    int threadNum;
    pthread_mutex_t mtx;
    pthread_cond_t cond;  //只有消费者线程需要等待(在任务队列为空的时候等待),而生产者线程不需要等待,因为任务队列一般满不了
};
