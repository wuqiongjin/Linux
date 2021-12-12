#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int main()
{
  if(!fork())
  {
    cout << "Child Exit!" << endl; 
    exit(1);
  }

  sleep(1000);
  return 0;
}
