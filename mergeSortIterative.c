#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


typedef struct {
    int value;
    int pos;
} Pair;

// Función para fusionar dos subarreglos ya ordenados
void merge(Pair* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Pair* L = malloc(n1 * sizeof(Pair));
    Pair* R = malloc(n2 * sizeof(Pair));

    // Recuperamos el arreglo izquierdo
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    // Recuperamos el arreglo derecho
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Ordenamos por comparacion de ambos
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        // Actualizamos el arreglo original con el menor valor
        if (L[i].value <= R[j].value)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    // Actualizamos el arreglo original con los valores
    // que no pudieron ser comparados
    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

// Merge Sort recursivo
void mergeSort(Pair* arr, int n) {
    int curr_size, left_start;
    
    for(curr_size = 1; curr_size<=n-1; curr_size *= 2){
        for (left_start = 0; left_start < n-1; left_start += 2*curr_size) {
            int mid = left_start + curr_size - 1;
            int right_end = (left_start + 2*curr_size - 1) < (n-1) ? (left_start + 2*curr_size - 1) : (n-1);

            merge(arr, left_start, mid, right_end);
        }
    }
}

// Función que crea la permutacion inversa de pi usando MergeSort
int* inversaIterativa(int* pi, int n) {
    // Creamos el arreglo de pares valor-posicion
    Pair *pairs = malloc(n * sizeof(Pair));
    for (int i = 0; i < n; i++) {
        pairs[i].value = pi[i];
        pairs[i].pos = i + 1;
    }

    // Ordenamos el arreglo de pares por la primera componente
    mergeSort(pairs, n);

    // Proyectamos solo la segunda componente en un nuevo arreglo
    int *proyectado = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        proyectado[i] = pairs[i].pos;
    }

    free(pairs);

    // Retornamos el nuevo arreglo
    return proyectado;
}