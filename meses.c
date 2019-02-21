// Crea un algoritmo que te diga cuantos dias tiene el mes que seleccionaste.
// Clase 11 de febrero

#include <stdio.h>
#include <stdlib.h>

int main(){
  int mes;

  printf("Introduce un mes: ");
  scanf("%i", &mes);
  char mensaje[20] = "Este es un mensaje";
  switch(mes){
    case 0 :
      printf("%s \n", mensaje);
      break;
    case 1 :
      printf("Enero tiene 31 dias\n");
      break;

    case 2 :
      printf("Febrero tiene 28 dias\n");
      break;

    case 3 :
      printf("Marzo tiene 31 dias\n");
      break;

    case 4 :
      printf("Abril tiene 30 dias\n");
      break;

    case 5 :
      printf("Mayo tiene 31 dias\n");
      break;

    case 6 :
      printf("Junio tiene 30 dias\n");
      break;

    case 7 :
      printf("Julio tiene 31 dias\n");
      break;

    case 8 :
      printf("Agosto tiene 30 dias\n");
      break;

    case 9 :
      printf("Semptiembre tiene 31 dias\n");
      break;

    case 10 :
      printf("Octubre tiene 30 dias\n");
      break;

    case 11 :
      printf("Noviembre tiene 31 dias\n");
      break;

    case 12 :
      printf("Diciembre tiene 30 dias\n");
      break;

}


  return 0;
}
