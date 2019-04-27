#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  typedef struct{
    int *data;
    int value;
  } Matrix;

  Matrix *M = malloc(sizeof(Matrix));
  M->value = 4;
  M->data[0] = 5;


  return 0;
}
