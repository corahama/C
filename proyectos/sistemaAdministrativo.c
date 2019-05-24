#include <stdio.h>
#include <string.h>

typedef struct {
  int id;
  char ubicacion[50];
  char tipo[20];
  char fecha[20];
} lugar;

typedef struct {
  int id;
  int precio;
  int calificacion;
  char fechas[30];
} historico;

int check_id(int id, char message[30]) {
  lugar test_id;
  FILE *fp_test = fopen("sa.bin", "rb");

  while (fread(&test_id, sizeof(lugar), 1, fp_test)) {
    if (test_id.id == id) {
      printf("%s", message);
      fclose(fp_test);
      return 1;
    }
  }

  fclose(fp_test);
  return 0;
}

int exists_id(int id, char message[30]) {
  lugar test_id;
  FILE *fp_test = fopen("sa.bin", "rb");

  while (fread(&test_id, sizeof(lugar), 1, fp_test)) {
    if (test_id.id == id) {
      fclose(fp_test);
      return 1;
    }
  }

  printf("%s", message);
  fclose(fp_test);
  return 0;
}


int main(int argc, char *argv[]) {
  FILE *fp;
  fp = fopen("sa.bin", "ab+");
  FILE *fp2;
  fp2 = fopen("sa2.bin", "ab+");
  lugar write_lugar;
  lugar copy_lugar;
  historico write_historico;

  printf("%s\n", "*****Bienvenido al programa Sistema Administrativo*****");
  printf("%s\n", "-Para dar de alta un alojamiento ingresa 1.");
  printf("%s\n", "-Para modificar un alojamiento ingresa 2.");
  printf("%s\n", "-Para eliminar un alojamiento ingresa 3.");
  printf("%s\n", "-Para mostrar todos los alojamientos 4.");
  printf("%s\n", "-Para dar de alta un historico ingresa 5.");
  printf("%s\n", "-Para modificar un historico ingresa 6.");
  printf("%s\n", "-Para buscar un historico por id ingresa 7.");
  printf("%s\n", "-Para buscar un historico por fecha ingresa 8.");
  printf("%s\n", "-Para mostrar todos los historicos ingresa 9.");
  printf("%s\n", "-Para cerrar el programa ingresa 0.");

  int choise;
  printf("%s", "Ingresa una instruccion: ");
  scanf("%d", &choise);

  while (choise != 0) {
    switch (choise) {

      // AGREGAR UN ALOJAMIENTO
      case 1:;
        printf("%s", "Ingresa el id: ");
        CREATE:scanf("%d", &write_lugar.id);
        if (check_id(write_lugar.id, "id ya existente, introduce otro id: "))
          goto CREATE;
        printf("%s", "Ingresa la ubicacion: ");
        scanf("\n%[^\n]", write_lugar.ubicacion);
        printf("%s", "Ingresa el tipo: ");
        scanf("\n%[^\n]", write_lugar.tipo);
        printf("%s", "Ingresa la fecha de disponibilidad: ");
        scanf("\n%[^\n]", write_lugar.fecha);

        fwrite(&write_lugar, sizeof(lugar), 1, fp);
        break;

      // MODIFICAR UN ALOJAMIENTO
      case 2:;
        int modify_id;
        int check = 0;
        int i = 1;
        printf("%s", "Introduce el id del alojamiento que quieres modificar: ");
        scanf("%d", &modify_id);

        FILE *fp_copy;
        fseek(fp, 0, SEEK_SET);
        fp_copy = fopen("csa.bin", "wb");

        while (fread(&write_lugar, sizeof(lugar), 1, fp)) {
          if (write_lugar.id == modify_id) {
            check = 1;
            printf("%s", "Introduce el nuevo id: ");
            MODIFY: scanf("%d", &write_lugar.id);
            fseek(fp, 0, SEEK_SET);
            while (fread(&copy_lugar, sizeof(lugar), 1, fp)) {
              if (copy_lugar.id == write_lugar.id && copy_lugar.id != modify_id) {
                printf("%s", "id ya existente, introduce otro id: ");
                goto MODIFY;
              }
            }
            fseek(fp, sizeof(lugar)*i, SEEK_SET);
            printf("%s", "Ingresa la nueva ubicacion: ");
            scanf("\n%[^\n]s", write_lugar.ubicacion);
            printf("%s", "Ingresa el nuevo tipo: ");
            scanf("\n%[^\n]s", write_lugar.tipo);
            printf("%s", "Ingresa la nueva fecha de disponibilidad: ");
            scanf("\n%[^\n]s", write_lugar.fecha);

            fwrite(&write_lugar, sizeof(lugar), 1, fp_copy);
            i++;
          }else {
            fwrite(&write_lugar, sizeof(lugar), 1, fp_copy);
            i++;
          }
        }

        if (check == 0)
          printf("%s\n", "id del alojamiento no encontrado.");

        fclose(fp_copy);
        remove("sa.bin");
        rename("csa.bin", "sa.bin");
        fp = fopen("sa.bin", "ab+");
        break;

      // ELIMINAR ALOJAMIENTO
      case 3:;
        int delete;
        int check1 = 0;
        printf("%s", "Introduce el id del alojamiento que quieres eliminar: ");
        scanf("%d", &delete);

        FILE *delete_fp;
        delete_fp = fopen("delete_sa.bin", "wb");

        lugar delete_lugar;
        fseek(fp, 0, SEEK_SET);
        while (fread(&delete_lugar, sizeof(lugar), 1, fp)) {
          if (delete_lugar.id == delete){
            check1 = 1;
          }else
          fwrite(&delete_lugar, sizeof(lugar), 1, delete_fp);
        }

        if (check1 == 0)
          printf("%s\n", "id de alojamiento no encontrado.");

        remove("sa.bin");
        rename("delete_sa.bin", "sa.bin");
        fclose(delete_fp);
        fp = fopen("sa.bin", "ab+");
        break;

      // MOSTRAR TODOS LOS ALOJAMIENTOS
      case 4:;
        int mostrarLugares = 0;
        fseek(fp, 0, SEEK_SET);
        while (fread(&write_lugar, sizeof(lugar), 1, fp)) {
          printf("-Id: %d | Ubicacion: %s | Tipo: %s | Fecha: %s\n", write_lugar.id, write_lugar.ubicacion, write_lugar.tipo, write_lugar.fecha);
          mostrarLugares++;
        }
        if (mostrarLugares == 0)
          printf("%s\n", "No se encontraron alojamientos");
        break;

      // DAR DE ALTA UN HISTORICO
      case 5:;
        int check_lugar = 0;
        printf("%s", "Introduce el id del alojamiento: ");
        CREATE_HISTORICO:scanf("%d", &write_historico.id);
        if (!exists_id(write_historico.id, "Alojamiento no encontrado, introduce otro id: "))
          goto CREATE_HISTORICO;
        printf("%s", "Introduce el precio del historico: ");
        scanf("%d", &write_historico.precio);
        printf("%s", "Introduce la calificacion del historico: ");
        scanf("%d", &write_historico.calificacion);
        printf("%s", "Introduce la fecha de entrada y salida del historico: ");
        scanf("\n%[^\n]s", write_historico.fechas);

        fwrite(&write_historico, sizeof(historico), 1, fp2);

        break;

      // MODIFICAR UN HISTORICO
      case 6:;
        int modify_historico_id;
        char modify_historico_fechas[30];
        FILE *fp2_modify = fopen("sa2_modify.bin", "wb");

        // COMPROBAR EXISTENCIA DE ID
        printf("%s", "Introduce el id del alojamiento: ");
        FALSE_ID:scanf("%d", &modify_historico_id);
        fseek(fp, 0, SEEK_SET);
        while(fread(&copy_lugar, sizeof(lugar), 1, fp)) {
          if (copy_lugar.id == modify_historico_id)
            goto TRUE_ID;
        }
        printf("%s", "Id no encontrado, introduce otro id: ");
        goto FALSE_ID;

        // COMPROBAR EXISTENCIA DE FECHAS
        TRUE_ID:printf("%s", "Introduce la fecha de entrada y salida del historico o \"cancel\" para cancelar la operacion: ");
        FALSE:scanf("\n%[^\n]s", modify_historico_fechas);
        if(!strcmp(modify_historico_fechas, "cancel"))
          goto CANCEL;
        fseek(fp2, 0, SEEK_SET);
        while (fread(&write_historico, sizeof(historico), 1, fp2)) {
          if (!strcmp(modify_historico_fechas, write_historico.fechas))
            goto TRUE;
        }
        printf("%s", "Fechas no encontradas, introduce una nueva fecha o \"cancel\" para cancelar la operacion: ");
        goto FALSE;

        // MODIFICAR HISTORICO
        TRUE:fseek(fp2, 0, SEEK_SET);
        while (fread(&write_historico, sizeof(historico), 1, fp2)) {
          if (write_historico.id == modify_historico_id && !strcmp(write_historico.fechas, modify_historico_fechas)) {
            printf("%s", "Introduce el nuevo id del alojamiento: ");
            ERROR_ID:scanf("%d", &write_historico.id);
            if (!exists_id(write_historico.id, "id de alojamiento no encontrado, introduce otro id: "))
              goto ERROR_ID;
            printf("%s", "Introduce el precio del historico: ");
            scanf("%d", &write_historico.precio);
            printf("%s", "Introduce la calificacion del historico: ");
            scanf("%d", &write_historico.calificacion);
            printf("%s", "Introduce la fecha de entrada y salida del historico: ");
            scanf("\n%[^\n]s", write_historico.fechas);

            fwrite(&write_historico, sizeof(historico), 1, fp2_modify);
          }else
            fwrite(&write_historico, sizeof(historico), 1, fp2_modify);
        }

        remove("sa2.bin");
        rename("sa2_modify.bin", "sa2.bin");
        fclose(fp2_modify);
        fp2 = fopen("sa2.bin", "ab+");
        break;

      // BUSCAR HISTORICO POR ID
      case 7:;
        int search_id;
        printf("%s", "Introduce el id de busqueda: ");
        scanf("%d", &search_id);

        fseek(fp2, 0, SEEK_SET);
        while(fread(&write_historico, sizeof(historico), 1, fp2)) {
          if (write_historico.id == search_id)
            printf("id: %d | precio: %d | calificacion: %d | fechas: %s\n", write_historico.id, write_historico.precio, write_historico.calificacion, write_historico.fechas);
        }
        break;

      // BUSCAR HISTORICO POR FECHA
      case 8:;
        char search_fecha[30];
        printf("%s", "Introduce las fechas de busqueda: ");
        scanf("%s", search_fecha);

        fseek(fp2, 0, SEEK_SET);
        while (fread(&write_historico, sizeof(historico), 1, fp2)) {
          if(!strcmp(write_historico.fechas, search_fecha))
            printf("id: %d | precio: %d | calificacion: %d | fechas: %s\n", write_historico.id, write_historico.precio, write_historico.calificacion, write_historico.fechas);
        }
        break;

      // MOSTRAR TODOS LOS HISTORICOS
      case 9:;
        int mostrarHistoricos = 0;
        fseek(fp2, 0, SEEK_SET);
        while (fread(&write_historico, sizeof(historico), 1, fp2)) {
          printf("id: %d | precio: %d | calificacion: %d | fechas: %s\n", write_historico.id, write_historico.precio, write_historico.calificacion, write_historico.fechas);
          mostrarHistoricos++;
        }
        if (mostrarHistoricos == 0)
          printf("%s\n", "No se encontraron historicos");
        break;

      default:
        printf("%s", "Intruccion invalida, introduce otra: ");
        goto DEFAULT;
    }
    CANCEL:printf("\n%s", "Ingresa otra intruccion: ");
    DEFAULT:scanf("%d", &choise);
  }

  fclose(fp);
  fclose(fp2);

  return 0;
}
