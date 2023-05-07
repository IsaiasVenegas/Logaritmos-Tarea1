#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int value;
    int pos;
} Pair;

// Funcion para obtener el sub arreglo al que pertenece el minimo entre los 4
int findMin(int arr1, int arr2, int arr3, int arr4) {
    int min = INT_MAX;
    int minIndex = -1;
    
    if (arr1 < min) {
        min = arr1;
        minIndex = 1;
    }
    if (arr2 < min) {
        min = arr2;
        minIndex = 2;
    }
    if (arr3 < min) {
        min = arr3;
        minIndex = 3;
    }
    if (arr4 < min) {
        min = arr4;
        minIndex = 4;
    }
    
    return minIndex;
}

// Función para fusionar dos subarreglos ya ordenados
void merge(Pair* arr, int l, int m1, int m2, int m3, int r) {
    int n1 = m1 - l + 1; //updated
    int n2 = m2 - m1; //updated
    int n3 = m3 - m2; //updated
    int n4 = r - m3 ; //updated
    Pair* S1 = malloc(n1 * sizeof(Pair));
    Pair* S2 = malloc(n2 * sizeof(Pair));
    Pair* S3 = malloc(n3 * sizeof(Pair));
    Pair* S4 = malloc(n4 * sizeof(Pair));

    // Recuperamos el primer arreglo
    for (int i = 0; i < n1; i++) {
        S1[i] = arr[l + i]; //updated
    }
    // Recuperamos el segundo arreglo
    for (int i = 0; i < n2; i++) {
        S2[i] = arr[m1 + 1 + i]; //updated
    }
    // Recuperamos el tercer arreglo
    for (int i = 0; i < n3; i++) {
        S3[i] = arr[m2 + 1 + i]; //updated
    }
    // Recuperamos el cuarto arreglo
    for (int i = 0; i < n4; i++) {
        S4[i] = arr[m3 + 1 + i]; //updated
    }

    // Ordenamos por comparacion de los cuatro subarreglos
    int v1 = INT_MAX, v2 = INT_MAX, v3 = INT_MAX, v4 = INT_MAX, k = l;
   
    int p1 = 0, p2=0, p3=0, p4=0;

    // Si el puntero no ha llegado al final
    if(p1<n1){
        v1 =  S1[p1].value;
    }
    if(p2<n2){
        v2 =  S2[p2].value;
    }
    if(p3<n3){
        v3 =  S3[p3].value;
    }
    if(p4<n4){
        v4 =  S4[p4].value;
    }

    int minBelongsTo = findMin(v1, v2, v3, v4);

    while(minBelongsTo != -1){
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
        // Actualizamos los valores v1 v2 v3 y v4
        if(p1<n1){
            v1 =  S1[p1].value;
        } else {
            v1 = INT_MAX;
        }
        if(p2<n2){
            v2 =  S2[p2].value;
        } else {
            v2 = INT_MAX;
        }
        if(p3<n3){
            v3 =  S3[p3].value;
        } else {
            v3 = INT_MAX;
        }
        if(p4<n4){
            v4 =  S4[p4].value;
        } else {
            v4 = INT_MAX;
        }
        minBelongsTo = findMin(v1, v2, v3, v4);
    }
        
    free(S1);
    free(S2);
    free(S3);
    free(S4);
}

// Merge Sort recursivo
void mergeSort(Pair* arr, int l, int r) {
    
    if (l < r) {
        int m1 = l + (r - l) / 4; //updated
        int m2 = l + (r - l) / 2; //updated
        int m3 = l + 3 * (r - l) / 4; //updated
        mergeSort(arr, l, m1);
        mergeSort(arr, m1 + 1, m2);
        mergeSort(arr, m2 + 1, m3);
        mergeSort(arr, m3 + 1, r);
        merge(arr, l, m1, m2, m3, r);
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