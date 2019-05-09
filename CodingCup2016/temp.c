#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int array[] = {1,1,3,4,5,5,7,7,7};

  // int **sort = NULL;

  // for (int i = 0; i < sizeof(array)/sizeof(int); ++i) {
  //   **sort = realloc(**sort, );
  // }

  int *ptr = malloc(sizeof(int) * 4);

  printf("%ld\n", sizeof(*ptr));

  return 0;
}
