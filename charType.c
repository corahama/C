#include<stdio.h>
#include<stdio.h>

int canPrintIt(char ch);
void printLetters(char arg[]);

void printArguments(int argc, char *argv[]) {

  for (int count = 0; count < argc; count++)
    printLetters(argv[count]);

}

void printLetters(char arg[]){
  for (int count = 0; arg[count] != '\0'; count++){
    char ch = arg[count];
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
