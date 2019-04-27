#include <stdio.h>

void str(char *provinces);

int main(int argc, char *argv[]){
  char c = 'a';
  printf("%c - 32 = %c\n", c, c-32);

  char *provinces[] = { "British Columbia", "Alberta", "Saskatchewan",
                        "Manitoba", "Ontario", "Quebec", "New Brunswick",
                        "Nova Scotia", "Prince Edward Island", "Newfoundland",
                        "Yukon", "Northwest Territories", "Nunavut" };
  int i;

  for (i=0; i<13; i++)
    str(*(provinces+i));

  return 0;
}

void str(char *provinces){
  for (int count = 0; *(provinces+count) != '\0'; count++){
    if (*(provinces+count) > 95)
      printf("%c", *(provinces+count)-32);
    else
      printf("%c", *(provinces+count));
  }
  printf("\n");
}
