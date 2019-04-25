// Este algoritmo permite ordenar de menor a mayor los elementos de una matriz
#include<stdio.h>
#include<stdbool.h>

bool test(int num, int array[1], int size);

int main() {
    int min, max, max2, countArray = 0;
    int array[] = {4, 4, 6, 1, 0, 3, 6, 9, 9, 0};
    int size = size = sizeof(array)/sizeof(int);
    int array2[size];
    int array3[size];

    printf("Matriz inicial: ");
    for (int count = 0; count < size; count ++){
        printf("%d ", array[count]);
    }

    // Este for es para obtener el valor mas alto en la matriz
    max = array[0];
    for (int count = 0; count < size; count ++){
      if (array[count] > max)
        max = array[count];
    }

    // Este for es para obtener el valor mas bajo en la matriz
    min = array[0];
    for (int count = 0; count < size; count ++){
      if (array[count] < min)
        min = array[count];
    }

    // Este for es para ordenar los numeros dentro de la nueva matriz
    for (int count = 0; count < size; count++){
        max2 = max;
        for (int count2 = 0; count2 < size; count2++){
            if (test(count2, array3, size) == true){
                if ((array[count2] - min) <= max2){
                  array2[countArray] = array[count2];
                  max2 = array[count2] - min;
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
bool test(int num, int array3[1], int size){
  for(int count = 0; count < size; count++){
      if (num == array3[count])
        return false;
  }

  return true;
}
