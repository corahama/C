#include <stdio.h>

int main(int argc, char *argv[]) {

  FILE *fp;
  int bytesread;
  int yy, mm, dd;
  int thedata[5];

  fp = fopen("data.bin", "r");
  if (fp == NULL) {
    printf("error opening data.bin\n");
    return 1;
  }
  else {
    // read the header
    bytesread = fread(&yy, sizeof(int), 1, fp);
    bytesread = fread(&mm, sizeof(int), 1, fp);
    bytesread = fread(&dd, sizeof(int), 1, fp);
    printf("year=%d, month=%d, day=%d\n", yy, mm, dd);
    // read the data
    bytesread = fread(thedata, sizeof(int), 5, fp);
    printf("data = [%d,%d,%d,%d,%d]\n",
           thedata[0], thedata[1],thedata[2],thedata[3],thedata[4]);
    fclose(fp);
  }

  return 0;
}
