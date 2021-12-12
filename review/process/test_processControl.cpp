#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;


int main()
{
  pid_t id = fork();  
 
  if(id == 0)
  {
    //child
    cout << "Here is Child Process!!!" << endl; 
    char* const argu[] = {"CTP", "-l", "-d", NULL}; //这里会报警告的，因为里面的是const属性，但是这里只能这么搞...数组前面加const的话又会报error
    execvp("CTP", argu);
    exit(10); 
  }
  
  int status = 0;
  waitpid(id, &status, 0);

  if(WIFEXITED(status))
  {
    cout << "信号: " << (status & 0x7F) << endl;
    cout << "子进程退出码: " << WEXITSTATUS(status) << endl;
  }
  else 
  {
    cout << "ERROR RETURN!" << endl;
  }

  return 0;
}
