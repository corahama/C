#include<stdio.h>
#include<stdbool.h>

bool test(int num, int array[4]);

int main() {
    int min, max, min2 = 0, max2, countArray = 0;
    int array[4] = {10,11,10,1};
    int array2[4];
    int array3[4];

    printf("Matriz inicial: ");
    for (int count = 0; count < sizeof(array)/sizeof(int); count ++){
        printf("%d ", array[count]);
    }

    // Este for es para obtener el valor mas alto en la matriz
    max = array[0];
    for (int count = 0; count < sizeof(array)/sizeof(int); count ++){
      if (array[count] > max)
        max = array[count];
    }

    // Este for es para obtener el valor mas bajo en la matriz
    min = array[0];
    for (int count = 0; count < sizeof(array)/sizeof(int); count ++){
      if (array[count] < min)
        min = array[count];
    }

    // Este for es para ordenar los numeros dentro de la matriz
    for (int count = 0; count < sizeof(array)/sizeof(int); count++){
        max2 = max;
        for (int count2 = 0; count2 < sizeof(array)/sizeof(int); count2++){
            if (test(count2, array3) == true){
                if ((array[count2] - min) < max2){
                  array2[countArray] = array[count2];
                  max2 = array[count2];
                  array3[countArray] = count2;
                }
            }
        }
        countArray++;
    }

    printf("\nMatriz despues de ser ordenada: ");
    for (int count = 0; count < sizeof(array2)/sizeof(int); count ++){
        printf("%d ", array2[count]);
    }
    printf("\n");

    return 0;
}

// Este for es para evaluar si un numero ya fue alamacenado en la nueva matriz
bool test(int num, int array3[4]){
  for(int count = 0; count < 4; count++){
      if (num == array3[count])
        return false;
  }

  return true;
}
