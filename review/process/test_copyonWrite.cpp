#include <iostream>
#include <unistd.h>
using namespace std;

int g_val = 0;

int main()
{
  pid_t id;
  id = fork();
  
  if(id > 0)
  {
    sleep(3);
    cout << "Father:" << g_val << " address:"<<&g_val << endl;
  }
  else 
  {
    g_val = 233;
    cout << "Child:" << g_val << " address:" << &g_val << endl;
  }

  sleep(1);
  return 0;
}
