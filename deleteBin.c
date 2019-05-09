#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[20];
  int age;
  int id;
} str;

int main(int argc, char *argv[]) {
  str name1 = {"fer", 22, 1};
  str name2 = {"lau", 21, 2};
  str name3 = {"paul", 32, 3};

  FILE *fp = fopen("db1.bin", "wb+");

// ESCRIBIMOS EN ARCHIVO INICIAL
  fwrite(&name1, sizeof(str), 1, fp);
  fwrite(&name2, sizeof(str), 1, fp);
  fwrite(&name3, sizeof(str), 1, fp);

  fseek(fp, 0, SEEK_SET);

// LEEMOS LAS ESTRUCTURAS DEL ARCHIVO INICIAL
  str read;
  while (fread(&read, sizeof(str), 1, fp)) {
    printf("%s %d\n", read.name, read.age);
  }

  fseek(fp, 0, SEEK_SET);
  printf("\n");

// COPIAMOS LAS ESTRUCTURAS A UN NUEVO ARCHIVO
// Y ELIMINAMOS UNA DE LAS ESTRUCTURAS
  int delete;
  printf("%s", "Cual estructura quieres eliminar: ");
  scanf("%d", &delete);
  FILE *fp_temp = fopen("db1_temp.bin", "wb+");
  str write;
  while (fread(&write, sizeof(str), 1, fp)) {
    if (write.id == delete){
    }else
      fwrite(&write, sizeof(str), 1, fp_temp);
  }

  fseek(fp, 0, SEEK_SET);
  remove("db1.bin");
  rename("db1_temp.bin", "db1.bin");
  fclose(fp);
  fclose(fp_temp);

// LEEMOS LAS ESTRUCTURAS DEL NUEVO ARCHIVO
  // FILE *fp1 = fopen("db1.bin", "ab+");
  fp = fopen("db1.bin", "rb");
  while (fread(&read, sizeof(str), 1, fp)) {
    printf("%s %d\n", read.name, read.age);
  }

  fclose(fp);

  return 0;
}
