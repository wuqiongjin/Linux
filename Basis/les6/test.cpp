#include <iostream>
using namespace std;

int SumToNum()
{
  int  sum = 0;
  for(int i = 0; i < 10; ++i)
  {
    sum += i;
  }
  return sum;
}

int main()
{
  int sum = SumToNum();
  cout << sum << endl;
  return 0;
}
