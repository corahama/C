#include<stdio.h>
#include<math.h>

int main(){
    int array[3][3] = {
        {3,2,-3},
        {7,-1,0},
        {2,-4,5},
    };
    int determinante = 0;

    for (int count = 0; count < sqrt(sizeof(array)/sizeof(int)); count ++){
        for (int count1 = 0; count1 < sqrt(sizeof(array)/sizeof(int)); count1 ++){
            printf("%d ", array[count][count1]);
        }
        printf("\n");
    }

    determinante = array[0][0]*array[1][1]*array[2][2] + array[0][1]*array[1][2]*array[2][1] + array[0][2]*array[1][0]*array[2][1] - array[0][2]*array[1][1]*array[2][0] - array[0][0]*array[1][2]*array[2][1] - array[0][1]*array[1][0]*array[2][2];


    printf("El determinante de la matriz es: %d", determinante);

    return 0;
}
