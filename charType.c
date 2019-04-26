#include<stdio.h>
#include<stdio.h>

int canPrintIt(char ch);
void printLetters(char argv[]);

void printArguments(int argc, char *argv[]) {

  for (int count = 0; count < argc; count++)
    printLetters(argv[count]);

}

void printLetters(char argv[]){
  for (int count = 0; argv[count] != '\0'; count++){
    char ch = argv[count];
    if (canPrintIt(ch))
      printf("'%c' == %d ", ch, ch);
  }

  printf("\n");
}

int canPrintIt(char ch){
  return isalpha(ch) || isblank(ch);
}


int main(int argc, char *argv[]){

  printArguments(argc, argv);

  return 0;
}
