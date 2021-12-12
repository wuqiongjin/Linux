#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int main()
{
  if(fork())
  {
    cout << "Father Exit!" << endl; 
    exit(1);
  }
  
  sleep(1);
  cout << "Here is Child and become a orphan!"<< endl;
  sleep(1000);
  return 0;
}
