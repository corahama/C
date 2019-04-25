#include<stdio.h>

int test();

int main(int argc, char *argv[]){

  if (test())
    printf("return true");
  else
    printf("return false");

  printf("\n");

  return 0;
}

int test(){

  return 0 || 1;
}
