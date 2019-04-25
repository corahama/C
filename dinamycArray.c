#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int *array = malloc(sizeof(int));
  *array = 0;

  for (int count = 0; count < 10; count++){
    if (*(array + count) == '\0')
      array = realloc(array, sizeof(int));
    array[count] = count;
    printf("%d\n", array[count]);
  }

  free(array);

  return 0;
}
