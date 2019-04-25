#include <stdio.h>
#include <stdlib.h>

void value(int val){
  val = 5;
  printf("%d\n", val);
}

void value2(int *val){
  *val = 6;
  printf("%d\n", *val);
}

int main(int argc, char *argv[]){
  int *ptr = malloc(sizeof(int));
  *ptr = 4;

  value2(ptr);
  value(*ptr);

  printf("%d\n", *ptr);

  free(ptr);
  return 0;
}
