#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  double result, total = 1;
  for (int counter = 1; counter <= 10000; counter++){
    result = pow((2*counter), 2)/(((2*counter)-1)*((2*counter)+1));
    total = total * result;
  }
  total = 2 * total;
  printf("%.4lf", total);
}
