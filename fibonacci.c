#include<stdio.h>

int main(){
    int f1 = 0, f2 = 0 , f3;

    printf("iteracion   valor \n");
    for (int count = 0; count < 10; count++){
            f3 = f1 + f2;
            f2 = f1;
            f1 = f3;
            if (count == 0){
                f2++;
            }
            printf("%-9d   %d\n", count, f3);
    }
}
