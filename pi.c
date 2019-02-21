#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int num;
  double result = 0;

  for (int counter = 1 ; counter < 10000; counter++){
    result += 6/pow(counter,2);
  }

  result = sqrt(result);

  printf("PI es igual a: %.2lf", result);

  return(0);
}
