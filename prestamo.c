// Calcula el interes de un ingreso
// Clase 7 de febrero

#include <stdio.h>
#include <stdlib.h>

int main(){
  float cantidad, interes, meses;
  printf("Ingresa la cantidad de ingreso: ");
  scanf("%f", &cantidad);
  interes = cantidad * 0.2;
  printf("El interes es de: %f\n", interes);

  return 0;
}
