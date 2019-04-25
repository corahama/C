#include<stdio.h>

int main(int argc, char *argv[]){

  if (argc == 1){
    printf("Tienes un solo argumento\n");
  }else if (argc > 1 && argc <= 4){
    printf("Aqui estan tus argumentos: \n");
    for (int count = 1; count < argc; count++){
        printf("%s ", argv[count]);
    }
    printf("\n");
  }else{
    printf("Tienes demaciados argumentos\n");
  }

  return 0;
}
