#include <stdio.h>
#include <stdlib.h>

int *returnPointer(int value){
  int *ptr = malloc(sizeof(int));
  *ptr = value;

  return ptr;
}

int sum(int *A, int B){
  return *A + B;
}

int functionAsParameter(int (*function)(int *A, int B), int *A, int B){
  return function(A, B);
}

int main(int argc, char *argv[]){
  int num = 4;
  int *ptrNum = &num;

  printf("num * 2: %d\n", *(returnPointer(*ptrNum * 2)));
  printf("num * 2 + num: %d\n", sum(returnPointer(*ptrNum * 2), num));
  printf("num: %d\n", *ptrNum);
  printf("num + num: %d\n", functionAsParameter(sum, returnPointer(num), num));

  return 0;
}
