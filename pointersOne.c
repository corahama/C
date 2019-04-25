#include<stdio.h>

int main(int argc, char *argv[]){
  int ages[] = {23, 54, 82, 13, 33};
  char *names[] = {"Fernando", "Luis", "Alan", "Alejandro", "Emliy"};

  int count = sizeof(ages)/sizeof(int);
  int i;

  for (i = 0; i < count; i++)
    printf("%s tiene %d años de edad\n", names[i], ages[i]);

  printf("---\n");

  int *cur_ages = ages;
  char **cur_names = names;

  for (i = 0; i < count; i++)
    printf("%s tiene %d años de edad\n", *(cur_names + i), *(cur_ages + i));

  printf("---\n");

  for (i = 0; i < count; i++)
    printf("%s tiene %d años de edad\n", cur_names[i], cur_ages[i]);

  for (cur_ages = ages, cur_names = names; (cur_ages - ages) < count; cur_ages++, cur_names++)
    printf("%s tiene %d años de edad\n", *cur_names, *cur_ages);

  printf("\n");
  return 0;
}
