#include <stdio.h>
#include <math.h>

int main(){
    double factorial;
    double x = 5, sin = 0, num, mult;

    for (int count = 0; count < 10; count++){
        factorial = 1.0;
        for (int count1 = 0 ; count1 < (count * 2); count1++){
            factorial += factorial * count1;
        }
        //printf("%f\n", factorial);

        num = pow(-1, count);
        //printf("%f\n", num);

        mult = pow(x, (count * 2));
        //printf("%f\n", mult);

        sin += (num/factorial)*mult;

    }

    printf("El coseno es %f", sin);
}
