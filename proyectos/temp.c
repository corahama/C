#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char name[] = "fernando";
  char name1[] = "fernando";

  if(!strcmp(name, name1))
    printf("%s\n", "True");

  return 0;
}
