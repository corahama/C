#include <stdio.h>

int main(int argc, char *argv[]){

  char *name[1];

  printf("Introduce tu nombre: ");
  scanf("%s", name[0]);

  printf("Hola %s\n", name[0]);

  return 0;
}
