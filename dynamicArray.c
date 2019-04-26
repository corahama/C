#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  double *array = NULL;

  for (int count = 0; count < 10; count++){
    array = realloc(array, sizeof(double)*(count+1));
    if (array == NULL) {
      perror("Cannot allocate enought memory");
      break;
    }
    array[count] = count;
    printf("count %d :", count);
    for (int count2 = 0; count2 <= count; count2++){
      printf("%.f", array[count2]);
    }
    printf("\n");
  }

  free(array);

  return 0;
}
