#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct {
  char name[30];
  char lastname[30];
  char email[30];
  int age;
} client;

typedef struct {
  client cliente;
  char name[40];
  char date[20];
  char clasification[10];
  int rate;
} movie;

int main(int argc, char *argv[]) {
  FILE *fp;
  fp = fopen("db.bin", "ab+");
  if (!fp)
    fp = fopen("db.bin", "wb+");

  printf("*****Bienvenido al programa \"sistema administrativo\"*****\n-Para agregar un nuevo cliente ingresa: 1.\n-Para eliminar un cliente ingresa: 2.\n-Para modificar un cliente ingresa: 3.\n-Para ver los Clientes almacenados ingresa: 4.\n-Para terminar el programa ingresa: 0.\n");
  int choise;
  printf("%s", "Introduce una operacion: ");
  scanf("%d", &choise);

  if (choise < 0 || choise > 4) {
    while (choise < 0 || choise > 4) {
      printf("%s\n", "Error: opcion invalida, vuelve a introducir otro numero");
      scanf("%d", &choise);
    }
  } else {
    while (choise != 0) {

      switch (choise) {
        // CREAR UN CLIENTE Y UNA PELICULA
        case 1:;
        client cliente;
        printf("%s", "Introduce el nombre (solo nombre) del cliente: ");
        scanf("%s", cliente.name);
        printf("%s", "Introduce el apellido del cliente: ");
        scanf("%s", cliente.lastname);
        printf("%s", "Introduce el correo del cliente: ");
        scanf("%s", cliente.email);
        printf("%s", "Introduce la edad del cliente: ");
        scanf("%d", &cliente.age);

        fwrite(&cliente, sizeof(cliente), 1, fp);
        break;

        // ELIMINAR UN NOMBRE Y PELICULA
        case 2:;
        char delete[40];
        printf("%s", "Introduce el nombre del usuario que quieres eliminar: ");
        scanf("%s", delete);

        FILE *fp_rename = fopen("db_temp.bin", "wb+");
        client write;
        fseek(fp, 0, SEEK_SET);

        while (fread(&write, sizeof(client), 1, fp)) {
          if (strcmp(write.name, delete) == 0){
          } else
            fwrite(&write, sizeof(client), 1, fp_rename);
        }

        remove("db.bin");
        rename("db_temp.bin", "db.bin");
        fclose(fp_rename);
        fp = fopen("db.bin", "ab+");
        break;

        // MODIFICAR UN CLIENTE
        case 3:;
        char rewrite[40];
        printf("%s", "Introduce el nombre del usuario que quieres modificar: ");
        scanf("%s", rewrite);

        client modify;
        printf("%s", "Introduce el nuevo nombre: ");
        scanf("%s", modify.name);
        printf("%s", "Introduce el nuevo apellido: ");
        scanf("%s", modify.lastname);
        printf("%s", "Introduce el nuevo correo: ");
        scanf("%s", modify.email);
        printf("%s", "Introduce la nueva edad: ");
        scanf("%d", &modify.age);

        client newClient;
        FILE *fp_temp = fopen("db_temp.bin", "wb+");
        fseek(fp, 0, SEEK_SET);

        while (fread(&newClient, sizeof(client), 1, fp)) {
          if (strcmp(newClient.name, rewrite) == 0) {
            strcpy(newClient.name, modify.name);
            strcpy(newClient.lastname, modify.lastname);
            strcpy(newClient.email, modify.email);
            newClient.age = modify.age;
            fwrite(&newClient, sizeof(client), 1, fp_temp);
          } else
            fwrite(&newClient, sizeof(client), 1, fp_temp);
        }

        fclose(fp_temp);
        remove("db.bin");
        rename("db_temp.bin", "db.bin");
        fp = fopen("db.bin", "ab+");
        break;

        // LEER EL ARCHIVO
        case 4:;
        fseek(fp, 0, SEEK_SET);
        client rCliente;

        while (fread(&rCliente, sizeof(client), 1, fp)) {
          printf("%s %s %s %d\n", rCliente.name, rCliente.lastname, rCliente.email, rCliente.age);
        }

        break;
      }

      printf("\n%s", "Siguiente operacion: ");
      scanf("%d", &choise);
      if (choise < 0 || choise > 4){
        while (choise < 0 || choise > 4) {
          printf("%s\n", "Error: opcion invalida, vuelve a introducir otro numero");
          scanf("%d", &choise);
        }
      }
    }

  }

// CERRAR EL ARCHIVO
  fclose(fp);

  return 0;
}
