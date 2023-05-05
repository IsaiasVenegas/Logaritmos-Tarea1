#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Función que crea la permutacion pi dado u n
int* createNIntegers(int n) {
    // Creamos el espacio en memoria para el arreglo pi
    int* pi;
    pi = malloc(n * sizeof(int));
    // Verificamos si el espacio se asignó correctamente
    if(pi == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1);
    }

    // Asignamos valores ordenanos al arreglo pi
    for(int i=0; i<n; i++) {
        pi[i] = i+1;
    }

    // Desordenamos el arreglo pi para finalmente retornarlo
    srand(time(NULL));
    for(int i=n - 1; i>0; i--) {
        int j = rand() % (i + 1);
        int temp = pi[i];
        pi[i] = pi[j];
        pi[j] = temp;
    }

    return pi;
}