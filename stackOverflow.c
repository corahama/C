#include "stdio.h"

void floo(int i){

  printf("%d\n", i++);

  floo(i);
}

int main(){
  int i = 0;

  floo(i);
}
