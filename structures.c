#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct Person{
  char *name;
  int age;
  int height;
  int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight){
  struct Person *who = malloc(sizeof(struct Person));
  assert(who != NULL);

  who -> name = strdup(name);
  who -> age = age;
  who -> height = height;
  who -> weight = weight;

  return who;
}

void Person_destroy(struct Person *who){
  assert(who != NULL);

  free(who -> name);
  free(who);
}

void Person_print(struct Person *who){
  printf("Name: %s\n", who -> name);
  printf("Age: %d\n", who -> age);
  printf("Height: %d\n", who -> height);
  printf("Weight: %d\n", who -> weight);

}


int main(int argc,char *argv[]){

  struct Person *Fernando = Person_create("Fernando", 22, 175, 70);

  Person_print(Fernando);


  return 0;
}
