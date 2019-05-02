#include <stdio.h>

int main(int argc, char *argv[]) {

  FILE *fp;
  int year = 2012;
  int month = 8;
  int day = 26;
  int mydata[5] = {2, 4, 6, 8, 10};

  fp = fopen("data.bin", "w");
  if (fp == NULL) {
    printf("error opening data.bin\n");
    return 1;
  }
  else {
    // write out the header
    int bytesout;
    bytesout = fwrite(&year, sizeof(year), 1, fp);
    bytesout = fwrite(&month, sizeof(month), 1, fp);
    bytesout = fwrite(&day, sizeof(day), 1, fp);
    // write the data
    bytesout = fwrite(mydata, sizeof(int), 5, fp);
    fclose(fp);
  }

  return 0;
}
