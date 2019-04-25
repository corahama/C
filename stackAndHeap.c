// #include <stdio.h>
//
// double multiplyByTwo (double input) {
//   double twice = input * 2.0;
//   return twice;
// }
//
// int main (int argc, char *argv[])
// {
//   int age = 30;
//   double salary = 12345.67;
//   double myList[3] = {1.2, 2.3, 3.4};
//
//   printf("double your salary is %.3f\n", multiplyByTwo(salary));
//
//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>

double *multiplyByTwo(double input){
  double *twice = malloc(sizeof(double));
  *twice = input * 2.0;

  return twice;
}

int main(int argc, char *argv[]){
  int *age = malloc(sizeof(age));
  *age = 30;
  double *salary = malloc(sizeof(double));
  *salary = 1234.56;
  double *myList = malloc(3 * sizeof(double));
  myList[0] = 1.2;
  myList[1] = 2.2;
  myList[2] = 3.2;

  double *function = multiplyByTwo(*salary);

  printf("The salary twice is: %f\n", *function);

  free(age);
  free(salary);
  free(myList);
  free(function);

  return 0;
}
