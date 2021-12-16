#include <stdio.h>
#include <string.h>

int main()
{
  FILE* fp = fopen("bite", "r");
  char buffer[128];
  fread(buffer, sizeof(char), sizeof(buffer), fp);

  printf("%s", buffer);
  fclose(fp);

  //FILE* fp = fopen("bite", "w");
  //const char* buffer = "linux so easy!\n";
  //fwrite(buffer, sizeof(char), strlen(buffer), fp);
  //
  //fclose(fp);
  return 0;
}
