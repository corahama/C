#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int num1, num2, num3;
} num;


int main() {
    FILE *fptr;
    if ((fptr = fopen("db.bin", "rb")) == NULL) {
        printf("Error! Archivo no encontrado");
        exit(1);
    }

    // num rNum;
    // for (int i = 0; i < 5; i++) {
    //     fread(&rNum, sizeof(num), 1, fptr);
    //     printf("1: %d, 2: %d, 3: %d\n", rNum.num1, rNum.num2, rNum.num3);
    // }


    num rNum;
    fread(&rNum, sizeof(num), 1, fptr);
    while (!feof(fptr)) {
        printf("1: %d, 2: %d, 3: %d\n", rNum.num1, rNum.num2, rNum.num3);
        fread(&rNum, sizeof(num), 1, fptr);
    }


    fclose(fptr);
    printf("\n");
    return 0;

}