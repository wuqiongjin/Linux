#include <stdio.h>

// 测试宏替换 -D选项
//void func()
//{
//  printf("%d\n", VALUE);
//  VALUE = 30;
//  printf("%d\n", VALUE);
//  
//  //printf(argv[0]);
//}
//
//int main(int argc, char* argv[], char* envp[])
//{
//  
//  func();
//  return 0;
//}

int main()
{
  printf("VALUE = %d\n", VALUE);
  return 0;
}



//int main()
//{
//#ifdef TEST_GCC_D
//  printf("TEST_GCC_D is defined!\n");
//  printf("TEST_GCC_D = %d\n", TEST_GCC_D);
//#else
//  printf("TEST_GCC_D is not defined\n");
//#endif
//  return 0;
//}
