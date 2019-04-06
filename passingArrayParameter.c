#include<stdio.h>

int print(int array[4], int size);

int main(){
  int array[4] = {1 ,2, 3, 4};
  int size = sizeof(array)/sizeof(int);

  print(array, size);

  return 0;
}

int print(int array[4], int size){

  for (int count = 0; count < size; count++){
    printf("%d ", array[count]);
  }

}
