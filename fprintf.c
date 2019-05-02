#include <stdio.h>

int main(int argc, char *argv[]) {

  FILE *fp;
  double tmpC[11] = {-10.0, -8.0, -6.0,
                      -4.0, -2.0,  0.0,  2.0,
                       4.0,  6.0,  8.0, 10.0};
  double tmpF;
  int i;

  fp = fopen("outfile.txt", "w");
  if (fp == NULL) {
    printf("sorry can't open outfile.txt\n");
    return 1;
  }
  else {
    // print a table header
    fprintf(fp, "%10s %10s\n", "Celsius", "Fahrenheit");
    for (i=0; i<11; i++) {
      tmpF = ((tmpC[i] * (9.0/5.0)) + 32.0);
      fprintf(fp, "%10.2f %10.2f\n", tmpC[i], tmpF);
    }
    fclose(fp);
  }

  return 0;
}
