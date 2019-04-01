#include <stdio.h>

int main(){
    int x = 7, factorial = 1;

    for (int count = x; count> 0; count--){
        factorial = factorial * count;
    }

    printf("El factorial de %d es: %d", x, factorial);
}
