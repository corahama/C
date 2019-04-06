#include<stdio.h>
#include<stdbool.h>

bool test(int num, int array2[4]);

int main(){

  int num = 8;
  int array2[4] = {2, 4, 6, 8};

  if (test(num, array2) == true)
    printf("True\n");
  else
    printf("False\n");

  return 0;
}

bool test(int num, int array2[4]){
  for(int count = 0; count < 4; count++){
      if (num == array2[count])
        return true;
  }

  return false;
}
