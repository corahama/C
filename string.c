#include <stdio.h>

int main(void) {

  printf("Hello world\n");

  char c = 'p';
  char s[] = "paul";

  printf("c=%c and s=%s\n", c, s);
  printf("s is %ld elements long\n", sizeof(s));

  return 0;
}
