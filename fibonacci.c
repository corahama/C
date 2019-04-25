#include<stdio.h>
#include <stdlib.h>
#include "string.h"

int main(int argc, char *argv[]){
  if (argc != 2){
    printf("Error: debes introducir un valor.\n");
    exit(0);
  }

  int f1 = 0, f2 = 0 , f3;

  printf("iteracion   valor \n");
  for (int count = 0; count < atoi(argv[1]); count++){
    f3 = f1 + f2;
    f2 = f1;
    f1 = f3;

    if (count == 0)
      f2++;

    printf("%-9d   %d\n", count + 1, f3);
  }
}
