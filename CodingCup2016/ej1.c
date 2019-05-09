#include <stdio.h>
#include <stdlib.h>

int test(char *s, char letras[], int i);

int main(int argc, char *argv[]){
  char *s = malloc(sizeof(char));
  char *x = malloc(sizeof(char));
  int i = 0;
  char letras[32];

  printf("%s", "Introduce el String 1: ");
  scanf("%s", s);

  printf("%s", "Introduce el String 2: ");
  scanf("%s", x);

  while (1 == 1){
    char letras[32] = {0};
    for (int count = 0; *(s+count) != '\0'; count++) {
      if (test((s+count), letras, i) == 1)
      break;
      for (int count1 = 0; *(x+count1) != '\0'; count1++) {
        if (s[count] == x[count1]) {
          if (*(s+0+count) == *(x+0+count1) && *(s+1+count) == *(x+1+count1) && *(s+2+count) == *(x+2+count1)) {
            printf("%s\n", "POSIBLE");
            goto LOOP;
          }else
          letras[i++] = *(s+count);
        }
      }
    }
    printf("%s\n", "IMPOSIBLE");

    LOOP:printf("%s", "Introduce el String 1: ");
    scanf("%s", s);
    if (*s == '0'){
      free(s);
      free(x);
      return 0;
    }

    printf("%s", "Introduce el String 2: ");
    scanf("%s", x);
  }

}

int test(char *s, char letras[], int i) {
  for (int count2 = 0; count2 <= i; count2++) {
    if(*s == letras[count2]) {
      return 1;
    }
  }

  return 0;
}
