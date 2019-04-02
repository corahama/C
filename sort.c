#include<stdio.h>

int main() {

    int min, min2 = 0, countArray = 0;
    int array[4] = {2, 4, 1, 3};
    int array2[4];

    for (int count = 0; count < sizeof(array)/sizeof(int); count ++){
        printf("%d ", array[count]);
    }

    for (int count = 0; count < sizeof(array)/sizeof(int); count++){
        min = array[0];
        for (int count2 = 0; count2 < sizeof(array)/sizeof(int); count2++){
            if (array[count2] <= min && array[count2] > min2)
                min = array[count2];
        }
        array2[countArray++] = min;
        min2 = min;
    }

    printf("\n");
    for (int count = 0; count < sizeof(array2)/sizeof(int); count ++){
        printf("%d ", array2[count]);
    }

    return 0;
}
