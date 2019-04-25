#include<stdio.h>
#include<math.h>

//funcion a integrar f(x) = x^2 + 2x + 2;
int main(){
    int counter = 0 ;
    double A = 0, size = 0.000001, x = 0.0, y1, y2;

    for (x; x < 5; x += size){
        y1 = pow(x, 2) + 2*x + 2;
        y2 = pow(x+size, 2) + 2*(x+size) + 2;
        A += ((x+size)-x)*y1 + ((y2-y1)*((x+size)-x))/2.0;
    }

    printf("%.2f", A);

    return 0;
}
