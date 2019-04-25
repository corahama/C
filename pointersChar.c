#include <stdio.h>


int main(int argc, char *argv[]){

  char *name = "Fernando";
  char name1[] = "Fernando";

  // name = &name1;
  // printf("Introduce un nombre: ");
  // scanf("%s\n", name);

  printf("%s\n", name1);
  printf("%s\n", name);
  printf("%d\n", *name);

  return 0;
}
