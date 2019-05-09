#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char name1[] = "fer";
  char name2[] = "lau";

  strcpy(name1, name2);

  printf("%s\n", name1);

  return 0;
}
