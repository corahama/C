#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int array1[] = {1,2,3,4,5};
  int array2[] = {6,7,8,9,10};

  fp = fopen("sum.txt", "w");
  if (fp == NULL)
    perror("error:file not found.");
  fprintf(fp, "%5s + %-5s %s\n", "Num1", "Num2", "Resultado");
  for (int count = 0; count < 5; count++){
    fprintf(fp, "%5d + %-5d %d\n", array1[count], array2[count], array1[count] + array2[count]);
  }
  fclose(fp);


  return 0;
}
