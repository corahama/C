#include <stdio.h>
#include <math.h>

int main(){
    int x = 5;
    double sin = 0, num, mult, factorial;

    for (int count = 0; count < 10; count++){
        factorial = 1.0;
        for (int count1 = 0 ; count1 < (count * 2 + 1); count1++){
            factorial += factorial * count1;
        }
        //printf("%f\n", factorial);

        num = pow(-1, count);
        //printf("%f\n", num);

        mult = pow(x, (2 * count + 1));
        //printf("%f\n", mult);

        sin += (num/factorial)*mult;

    }

    printf("El seno de %d es %f", x, sin);
}
