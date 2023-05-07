#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int value;
    int pos;
} Pair;

// Funcion para obtener el sub arreglo al que pertenece el minimo entre los valores
int findMin(Pair **p, int arity) {
    int min = INT_MAX;
    int minIndex = -1;

    for(int i=0; i<arity; i++) {
        Pair* p_i = p[i];
        if(p_i != NULL){
            int v = (*p[i]).value;
            if(v < min) {
                min = v;
                minIndex = i;
            }
        }
    }
    
    return minIndex;
}

// Función para fusionar dos subarreglos ya ordenados
void merge(Pair* arr, int l, int* m, int r, int arity) {
    int n[arity];
    n[0] = m[0] - l + 1; 
    for(int i=1; i<arity-1; i++){
        n[i] = m[i]-m[i-1];
    }
    n[arity-1]= r - m[arity-2];
    // Recuperamos cada arreglo
    Pair *S[arity];
    
    S[0] = malloc(n[0] * sizeof(Pair));
    for(int j=0; j<n[0]; j++){
            S[0][j] = arr[l + j];
        }
    for(int i=1; i<arity; i++) {
        S[i] = malloc(n[i] * sizeof(Pair));
        for(int j=0; j<n[i]; j++){
            S[i][j] = arr[m[i-1] + 1 + j];
        }
    }
    // Ordenamos por comparacion de los cuatro subarreglos
    Pair *p[arity];
    for(int i=0; i<arity; i++) {
        if(n[i]>0){
            p[i] = S[i];
        } else {
            p[i] = NULL;
        } 
    }
    int k = l;
    int minBelongsTo = findMin(p, arity);

    while(minBelongsTo != -1){
        arr[k++] = *p[minBelongsTo];
        // Si p apunta a una direccion mayor a la direccion que ocupa S
        if(p[minBelongsTo] + 1 >= S[minBelongsTo] + n[minBelongsTo]){
            p[minBelongsTo] = NULL;
        } else {
            p[minBelongsTo]++;
        }
        minBelongsTo = findMin(p, arity);
    }
    for(int i=0; i<arity; i++){
        free(S[i]);
    }
}

// Merge Sort recursivo
void mergeSort(Pair* arr, int l, int r, int arity) {
    if (l < r) {
        int m[(arity-1)];
        for(int i=0; i<arity-1; i++){
            m[i]= l + (i+1) * (r-l) /arity;
        }
        mergeSort(arr, l, m[0], arity);
        for(int i=1; i<arity-1; i++){
            mergeSort(arr, m[i-1]+1, m[i], arity);
        }
        mergeSort(arr, m[arity-2]+1, r, arity);
        merge(arr, l, m, r, arity);
    }
}

// Función que crea la permutacion inversa de pi usando MergeSort
int* inversa(int* pi, int n, int arity) {
    // Creamos el arreglo de pares valor-posicion
    Pair *pairs = malloc(n * sizeof(Pair));
    for (int i = 0; i < n; i++) {
        pairs[i].value = pi[i];
        pairs[i].pos = i + 1;
    }

    // Ordenamos el arreglo de pares por la primera componente
    mergeSort(pairs, 0, n - 1, arity);

    // Proyectamos solo la segunda componente en un nuevo arreglo
    int *proyectado = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        proyectado[i] = pairs[i].pos;
    }

    free(pairs);

    // Retornamos el nuevo arreglo
    return proyectado;
}