#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Función que crea la permutacion inversa de pi
int* permutation(int* target, int n) {
    int value;
    int* permutation;

    permutation = malloc(n * sizeof(int));
    for (int index = 0; index < n; index += 1) {
        value = target[index];
        permutation[value - 1] = index + 1;
    }
    return permutation;
}