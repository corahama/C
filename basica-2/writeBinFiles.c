#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int num1, num2, num3;
} num;


int main() {
    FILE *fptr;

    if ((fptr = fopen("db.bin","wb")) == NULL) {
        printf("Error! Archivo no encontrado.");

        exit(1);
    };


    num wNum;
    for (int i = 1; i <= 5; i++) {
        wNum.num1 = i;
        wNum.num2 = 10 + i;
        wNum.num3 = 20 + i;

        fwrite(&wNum, sizeof(num), 1, fptr);
    }

    fclose(fptr);

    return 0;
}
