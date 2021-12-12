#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(int argc, char* argv[], char* envp[])
{
  if(argc == 1)
  {
    cout << "No arguments!, No execution!" << endl;
  }
  else if(argc == 2)
  {
    if(strcmp(argv[1], "-d") == 0)
        cout << __DATE__ << endl;
    else if(strcmp(argv[1], "-l") == 0)
      cout << getenv("PWD") << endl;
    else
      cout << "Wrong Arguments!" << endl;
  }
  else if(argc == 3)
  {
    for(int i = 1; i <= 2; ++i)
    {
      if(strcmp(argv[i], "-d") == 0)
        cout << __DATE__ << endl;
      else if(strcmp(argv[i], "-l") == 0)
        cout << getenv("PWD") << endl;
      else 
        cout << "Wrong Arguments!" << endl;
    }
  }
  return 23;
}
