#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // char *write = "Hola mundo";
  char write[] = "This is a c program";
  char *read = malloc(sizeof(char) * strlen(write));

  FILE *fp;
  fp = fopen("read&write.bin", "wb+");

  // fwrite(write, sizeof(char), strlen(write) + 1, fp);
  fputs("This is a c program", fp);
  fseek(fp, 0, SEEK_SET);
  fread(read, sizeof(char), strlen(write) + 1, fp);

  printf("%s\n", read );

  fclose(fp);

  return 0;
}
