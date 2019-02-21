// Calcula el perimetro de una figura geometrica
// Clase 7 de febrero

#include <stdlib.h>
#include <stdio.h>
#define PI 3.14159

int main(){
  float side = 4;
  float square = side * side;
  float circule = PI *side;
  float triangule = side * 2 / 2;
  printf("El area del cuadrado es: %.4f\n", square);
  printf("El area del circulo es: %.4f\n", circule);
  printf("El area del triangulo es: %.4f\n", triangule);
  return 0;
};
