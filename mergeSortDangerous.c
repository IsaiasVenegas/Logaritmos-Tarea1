#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int value;
    int pos;
} Pair;

// Funcion para obtener el menor valor entre los sub arreglos y el sub arreglo al que pertenece
int getMin(int i, int j, int k, int l){
    int min = -1; // default
    int belongs_to = -1; // default
    int compararIzq = i;
    int compararDer = j;
    if(i == 0){
        compararIzq = j;
        compararDer = k;
    }
    if(i<=j){
        min = i;
        belongs_to = 1;
    }
    return belongs_to
}

// Función para fusionar dos subarreglos ya ordenados
void merge(Pair* arr, int l, int m1, int m2, int m3, int r) {
    int n1 = m1 - l + 1;
    int n2 = m2 - m1 + 1;
    int n3 = m3 - m2 + 1;
    int n4 = r - m3;
    Pair* S1 = malloc(n1 * sizeof(Pair));
    Pair* S2 = malloc(n2 * sizeof(Pair));
    Pair* S3 = malloc(n3 * sizeof(Pair));
    Pair* S4 = malloc(n4 * sizeof(Pair));

    // Recuperamos el primer arreglo
    for (int i = 0; i < n1; i++) {
        S1[i] = arr[l + i];
    }
    // Recuperamos el segundo arreglo
    for (int i = 0; i < n2; i++) {
        S2[i] = arr[m1 + 1 + i];
    }
    // Recuperamos el tercer arreglo
    for (int i = 0; i < n3; i++) {
        S3[i] = arr[m2 + 1 + i];
    }
    // Recuperamos el cuarto arreglo
    for (int i = 0; i < n4; i++) {
        S4[i] = arr[m3 + 1 + i];
    }

    // Ordenamos por comparacion de los cuatro subarreglos
    int p1 = 0, p2 = 0, p3 = 0, p4 = 0, k = l;
    while () {
        int v1 = 0;
        if(p1<n1){
            v1 = S1[p1].value;
        }
        int v2 = 0;
        if(p2<n2){
            v2 = S2[p2].value;
        }
        int v3 = 0;
        if(p3<n3){
            v3 = S3[p3].value;
        }
        int v4 = 0;
        if(p4<n4){
            v4 = S4[p4].value;
        }
        while(v1 !=0 || v2 !=0 || v3 !=0 || v4 !=0){
            int minBelongsTo = getMin(v1, v2, v3, v4); // (S1)
            if(minBelongsTo == 1) {
                arr[k++] = S1[p1++];
            }
            else if(minBelongsTo == 2) {
                arr[k++] = S2[p2++];
            }
            else if(minBelongsTo == 3) {
                arr[k++] = S3[p3++];
            }
            else if(minBelongsTo == 4) {
                arr[k++] = S4[p4++];
            }
        }
        
    }
    // Actualizamos el arreglo original con los valores
    // que no pudieron ser comparados
    while (p1 < n1)
        arr[k++] = S1[p1++];
    while (p2 < n2)
        arr[k++] = S2[p2++];
    while (p3 < n3)
        arr[k++] = S1[p3++];
    while (p4 < n4)
        arr[k++] = S1[p4++];

    free(S1);
    free(S2);
    free(S3);
    free(S4);
}

// Merge Sort recursivo
void mergeSort(Pair* arr, int l, int r) {
    if (l < r) {
        int m1 = l + (r - l) / 2;
        int m2 = l + (r - l) / 2;
        int m3 = l + (r - l) / 2;
        mergeSort(arr, l, m1);
        mergeSort(arr, m1 + 1, m2);
        mergeSort(arr, m2+1, m3);
        mergeSort(arr, m3 + 1, r);
        merge(arr, l, m, r);
    }
}

// Función que crea la permutacion inversa de pi usando MergeSort
int* inversa(int* pi, int n) {
    // Creamos el arreglo de pares valor-posicion
    Pair *pairs = malloc(n * sizeof(Pair));
    for (int i = 0; i < n; i++) {
        pairs[i].value = pi[i];
        pairs[i].pos = i + 1;
    }

    // Ordenamos el arreglo de pares por la primera componente
    mergeSort(pairs, 0, n - 1);

    // Proyectamos solo la segunda componente en un nuevo arreglo
    int *proyectado = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        proyectado[i] = pairs[i].pos;
    }

    free(pairs);

    // Retornamos el nuevo arreglo
    return proyectado;
}