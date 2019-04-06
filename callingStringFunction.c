#include<stdio.h>

char message(char message[]);
char message1[] = "Hola mundo";
char message2[];

int main(){
  message2 = message(message1);
  printf("%s\n", message2);
}

char message(message){
  return message;
}
