#include <stdio.h>

int isPrime(int num, int primes[], int count) {
    for (int i = 0; i < count; i++) {
        if (num % primes[i] == 0)
            return count;
    }

    primes[count++] = num;
    return count;
}

int main() {
    int li, ls, count = 0, countTemp;
    int primes[100];

    printf("Introduce el limite inferior: ");
    scanf("%d", &li);
    printf("Introduce el limite superior: ");
    scanf("%d", &ls);
    printf("\n");

    if (li < 2) li = 2;

    for (int i = 2; i < li; i++) {
        count = isPrime(i, primes, count);
    }

    for (int i = li; i <= ls; i++) {
        countTemp = count;
        count = isPrime(i, primes, count);
        if (countTemp != count)
            printf("%d\n", i);
    }

    return 0;
}