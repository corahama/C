#include <stdio.h>

int main() {
    int numAls, numCalfs;

    printf("Introduzca el numero de alumnos: ");
    scanf("%d", &numAls);
    printf("Introduzca el numero de calificaciones: ");
    scanf("%d", &numCalfs);

    int calfs[numAls][numCalfs];
    int sumAls[numAls];
    int sumCalfs[numCalfs];

    for (int j = 0; j < numCalfs; j++)
        sumCalfs[j] = 0;

    for (int i = 0; i < numAls; i++) {
        sumAls[i] = 0;
        printf("**Calificacion del alumno %d**\n", i+1);
        for (int j = 0; j < numCalfs; j++) {
            printf("Introduzca la calificacion %d: ", j+1);
            scanf("%d", &calfs[i][j]);
            sumAls[i] += calfs[i][j];
            sumCalfs[j] += calfs[i][j];
        }
    }

    printf("\n**Promedios por alumno**\n");
    for (int i = 0; i < numAls; i++)
        printf("%d: %.2f, ", i+1, (float) sumAls[i]/numCalfs);
    printf("\n");

    printf("**Promedios por evaluación**\n");
    for (int j = 0; j < numCalfs; j++)
        printf("%d: %.2f, ", j+1, (float) sumCalfs[j]/numAls);
    printf("\n");

    return 0;
}