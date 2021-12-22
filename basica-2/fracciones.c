#include <stdio.h>
#include <math.h>

typedef struct {
    int num, dem;
} Fraccion;


void imprimirFraccion(Fraccion frac) {
    int lim_primo;
    if (sqrt(frac.num) > sqrt(frac.dem))
        lim_primo = (int) sqrt(frac.dem);
    else
        lim_primo = (int) sqrt(frac.num);

    int primo = 2;
    while (frac.num > 1 && frac.dem > 1 && primo <= lim_primo) {
        if (frac.num % primo == 0 && frac.dem % primo == 0) {
            frac.num /= primo;
            frac.dem /= primo;
        } else {
            primo++;
        }
    }

    printf("%d/%d\n", frac.num, frac.dem);
    return;
}


int main(int argc, char *argv[]){
    Fraccion frac1, frac2, suma, resta, mult, div;
    printf("Introduce el numerador de la fraccion 1: ");
    scanf("%d", &frac1.num);
    scanf("%d", &frac1.dem);

    printf("Introduce el numerador de la fraccion 1: ");
    scanf("%d", &frac2.num);
    scanf("%d", &frac2.dem);

    printf("\nLa suma de las fracciones es: ");
    suma.num = frac1.num*frac2.dem + frac2.num*frac1.dem;
    suma.dem = frac2.dem*frac1.dem;
    imprimirFraccion(suma);

    printf("La resta de las fracciones es: ");
    resta.num = frac1.num*frac2.dem - frac2.num*frac1.dem;
    resta.dem = frac2.dem*frac1.dem;
    imprimirFraccion(resta);

    printf("La multiplicación de las fracciones es: ");
    mult.num = frac1.num*frac2.num;
    mult.dem = frac1.dem*frac2.dem;
    imprimirFraccion(mult);

    printf("La suma de las fracciones es: ");
    div.num = frac1.num*frac2.dem;
    div.dem = frac2.num*frac1.dem;
    imprimirFraccion(div);

    return 0;
}
