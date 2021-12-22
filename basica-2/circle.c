#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
    float radio, area, perimetro;

    printf("Ingresa el radio: ");
    scanf("%f", &radio);

    if (radio >= 0) {
        area = M_PI * powf(radio, 2);
        perimetro = 2 * M_PI * radio;
    } else {
        area = 0;
        perimetro = 0;
    }

    printf("El area del circulo es: %.4f: ", area);
    printf("El perimetro del circulo es: %.4f: ", perimetro);

    return 0;
}
