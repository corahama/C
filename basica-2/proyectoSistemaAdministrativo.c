#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int dia;
    int mes;
    int año;
} fecha;

typedef struct {
    fecha fecha;
    char motivo[80];
    char empleadoAtendio[80];
} historico;

typedef struct {
    char numSerie[15];
    int tipoEquipo;
    char marca[20];
    char modelo[20];
    historico historico[10];
    int historicoIndice;
} equipo;


void listarOpciones();
char* obtenerTipo(int tipo);
void imprimirDatosEquipo(equipo eq);


int main(int argc, char *argv[]) {
    FILE *fptr;
    if ((fptr = fopen("db.bin", "rb+")) == NULL) {
        if((fptr = fopen("db.bin", "wb+")) == NULL) {
            printf("Error: el archivo no existe ni se ha podido crear.\n");
            exit(1);
        }
    }

    int op;
    printf("*********Bienvenido al Sistema Informatico*********\n");
    listarOpciones();
    printf("Selecciona una de las opciones anteriores para empezar: ");
    scanf("%d", &op);

    // variables para casos 2, 3, 5 y 6
    char n_eq[15];
    int encontrado;

    equipo eq;
    while (op != 0) {
        switch (op) {
            // Crear un nuevo equipo
            case 1:
                printf("Introduce los datos del equipo.\n");
                printf("Numero de serie: ");
                scanf("%s", eq.numSerie);
                printf("Tipo de equipo (1=CPU, 2=Monitor, 3=Impresora, 4=Scaner): ");
                scanf("%d", &eq.tipoEquipo);
                while(eq.tipoEquipo < 1 || eq.tipoEquipo > 4) {
                    printf("Error: tipo de equipo invalido, los valores permitidos son: ");
                    printf("1=CPU, 2=Monitor, 3=Impresora, 4=Scaner.\n");
                    printf("Ingresa un valor valido: ");
                    scanf("%d", &eq.tipoEquipo);
                }
                printf("Marca: ");
                scanf("\n%[^\n]s", eq.marca);
                printf("Modelo: ");
                scanf("\n%[^\n]s", eq.modelo);
                eq.historicoIndice = 0;

                fseek(fptr, 0, SEEK_END);
                fwrite(&eq, sizeof(equipo), 1, fptr);
                printf("· Operación realizada con exito!\n");

                break;

            // Actualizar un equipo
            case 2:
                fseek(fptr, 0, SEEK_SET);

                n_eq[0] = '\0';
                printf("Introduce el numero de serie del equipo: ");
                scanf("%s", n_eq);

                encontrado = 0;
                while (fread(&eq, sizeof(equipo), 1, fptr)) {
                    if (strcmp(eq.numSerie, n_eq) == 0) {
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado) {
                    printf("· Equipo encontrado. Introduce los nuevos datos.\n");
                    printf("Numero de serie: ");
                    scanf("%s", eq.numSerie);
                    printf("Tipo de equipo: ");
                    scanf("%d", &eq.tipoEquipo);
                    while(eq.tipoEquipo < 1 || eq.tipoEquipo > 4) {
                        printf("Error: tipo de equipo invalido, los valores permitidos son: ");
                        printf("1=CPU, 2=Monitor, 3=Impresora, 4=Scaner.\n");
                        printf("Ingresa un valor valido: ");
                        scanf("%d", &eq.tipoEquipo);
                    }
                    printf("Marca: ");
                    scanf("\n%[^\n]s", eq.marca);
                    printf("Modelo: ");
                    scanf("\n%[^\n]s", eq.modelo);

                    fseek(fptr, -sizeof(equipo), SEEK_CUR);
                    fwrite(&eq, sizeof(equipo), 1, fptr);
                    printf("Equipo actualizado correctamente!");
                } else
                    printf("· No se ha encontrado ningun equipo.\n");

                break;

            // Buscar un equipo
            case 3:
                fseek(fptr, 0, SEEK_SET);

                n_eq[0] = '\0';
                printf("Introduce el numero de serie del equipo: ");
                scanf("%s", n_eq);

                encontrado = 0;
                while (fread(&eq, sizeof(equipo), 1, fptr)) {
                    if (strcmp(eq.numSerie, n_eq) == 0) {
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado) {
                    printf("\n");
                    imprimirDatosEquipo(eq);
                } else
                    printf("· No se ha encontrado ningun equipo.\n");

                break;

            // Listar todos los equipos
            case 4:
                fseek(fptr, 0, SEEK_SET);
                fread(&eq, sizeof(equipo), 1, fptr);
                if (feof(fptr)) {
                    printf("No hay equipos registrados.\n");
                    break;
                }

                printf("Lista de equipos registrados:\n");
                int i = 1;
                while (!feof(fptr)) {
                    printf("***** %d *****\n", i);
                    imprimirDatosEquipo(eq);
                    printf("\n");

                    fread(&eq, sizeof(equipo), 1, fptr);
                    i++;
                }

                break;

            // Eliminar un equipo
            case 5:
                fseek(fptr, 0, SEEK_SET);

                n_eq[0] = '\0';
                printf("Introduce el numero de serie del equipo a eliminar: ");
                scanf("%s", n_eq);

                encontrado = 0;

                FILE *tempFptr;
                if ((tempFptr = fopen("temp_db.bin", "wb")) == NULL) {
                    printf("Hubo un problema creando el archivo temporal.");
                    exit(1);
                }

                while (fread(&eq, sizeof(equipo), 1, fptr)) {
                    if (strcmp(eq.numSerie, n_eq) == 0) {
                        encontrado = 1;
                    } else {
                        fwrite(&eq, sizeof(equipo), 1, tempFptr);
                    }
                }

                fclose(fptr);
                remove("db.bin");

                rename("temp_db.bin", "db.bin");
                fclose(tempFptr);

                if ((fptr = fopen("db.bin", "rb+")) == NULL) {
                    printf("Ha ocurrido un error leyendo el archivo.");
                    exit(1);
                }

                if (!encontrado)
                    printf("· No se ha encontrado ningun equipo.\n");
                else
                    printf("· Equipo eliminado exitosamene!");

                break;

            // Agregar un registro de servicio a un equipo
            case 6:
                fseek(fptr, 0, SEEK_SET);
                
                n_eq[0] = '\0';
                printf("Introduce el numero de serie del equipo: ");
                scanf("%s", n_eq);

                encontrado = 0;
                while (fread(&eq, sizeof(equipo), 1, fptr)) {
                    if (strcmp(eq.numSerie, n_eq) == 0) {
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado) {
                    if (eq.historicoIndice == 10) {
                        printf("· Ya se ha alcanzado el limite de registros para este equipo!");
                        break;
                    }

                    printf("Equipo encontrado. Inserta los datos del servicio.\n");
                    printf("Dia: ");
                    scanf("%d", &eq.historico[eq.historicoIndice].fecha.dia);
                    while (eq.historico[eq.historicoIndice].fecha.dia < 1 || 
                    eq.historico[eq.historicoIndice].fecha.dia > 31) {
                        printf("Dia invalido, solo se permiten valores entre 1 y 31. ");
                        printf("Intenta de nuevo: ");
                        scanf("%d", &eq.historico[eq.historicoIndice].fecha.dia);
                    }
                    printf("Mes: ");
                    scanf("%d", &eq.historico[eq.historicoIndice].fecha.mes);
                    while (eq.historico[eq.historicoIndice].fecha.mes < 1 || 
                    eq.historico[eq.historicoIndice].fecha.mes > 12) {
                        printf("Mes invalido, solo se permiten valores entre 1 y 12. ");
                        printf("Intenta de nuevo: ");
                        scanf("%d", &eq.historico[eq.historicoIndice].fecha.mes);
                    }
                    printf("Año: ");
                    scanf("%d", &eq.historico[eq.historicoIndice].fecha.año);
                    while (eq.historico[eq.historicoIndice].fecha.año < 1 || 
                    eq.historico[eq.historicoIndice].fecha.año > 2050) {
                        printf("Año invalido, solo se permiten valores entre 1 y 2050. ");
                        printf("Intenta de nuevo: ");
                        scanf("%d", &eq.historico[eq.historicoIndice].fecha.año);
                    }
                    
                    printf("Motivo: ");
                    scanf("\n%[^\n]s", eq.historico[eq.historicoIndice].motivo);
                    printf("Empleado que atendió: ");
                    scanf("\n%[^\n]s", eq.historico[eq.historicoIndice].empleadoAtendio);

                    eq.historicoIndice++;

                    fseek(fptr, -sizeof(equipo), SEEK_CUR);
                    fwrite(&eq, sizeof(equipo), 1,  fptr);

                    printf("· Registro agregado con exito!");

                } else
                    printf("· No se ha encontrado ningun equipo.\n");

                break;

            // Listar las opciones
            case 10:
                listarOpciones();

                break;
            
            default:
                printf("\nError: Opción seleccionada invalida.\n");
        }

        printf("\nIntroduce una nueva opcion (10 para volver a listarlas): ");
        scanf("%d", &op);

    }

    printf("Programa finalizado.\n");
    return 0;
}


void listarOpciones() {
    printf("Opciones: \n");
    printf("1) Crear un equipo.\n");
    printf("2) Editar un equipo.\n");
    printf("3) Buscar un equipo.\n");
    printf("4) Listar todos los equipos.\n");
    printf("5) Borrar un equipo.\n");
    printf("6) Agregar un registro de servicio a un equipo.\n");
    printf("0) Terminar el programa\n");
}

char* obtenerTipo(int tipo) {
    switch (tipo) {
        case 1:
            return "CPU";
        case 2:
            return "Monitor";
        case 3:
            return "Impresora";
        case 4:
            return "Escaner";
        default:
            return "";
    }
}

void imprimirDatosEquipo(equipo eq) {
    printf("Numero de serie: %s\n", eq.numSerie);
    printf("Tipo de equipo: %s\n", obtenerTipo(eq.tipoEquipo));
    printf("Marca: %s\n", eq.marca);
    printf("Modelo: %s\n", eq.modelo);
    printf("-Historial de servicios\n");
    if (eq.historicoIndice == 0)
        printf(" · Sin servicios\n");
    else {
        for (int i = 0; i < eq.historicoIndice; i++) {
            printf(" %d. Fecha: %d/%d/%d | Motivo: %s | Empleado que atendió: %s\n",
                    i+1, eq.historico[i].fecha.dia, eq.historico[i].fecha.mes, 
                    eq.historico[i].fecha.año, eq.historico[i].motivo,
                    eq.historico[i].empleadoAtendio);
        }
    }
}