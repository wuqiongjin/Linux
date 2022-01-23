#include "ThreadPool.h"
using namespace std;

int main()
{
  ThreadPool<Task>* tp = new ThreadPool<Task>(10);
  tp->PoolInit();
  int i = 100;
  while(i--)
  {
    Task t(i);
    tp->Push(t);
    sleep(1);
  }
  return 0;
}
