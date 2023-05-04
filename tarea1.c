#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void mergeSort(Pair* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
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

int main() {
    double clocks_spent_permutations, clocks_spent_merge_sort, avg_time_spent_permutations, avg_time_spent_merge_sort;
    clock_t begin, end;

    int *pi, *pi_inversa;

    while (int n = 2 ^ 20; n <= 2 ^ 30; n *= 2 ^ 2) {
        clocks_spent_permutations = 0.0;
        clocks_spent_merge_sort = 0.0;

        for (int i_test = 1; i_test <= 10; i_test++) {
            pi = createNIntegers(n); // TODO

            // First algorithm
            begin = clock();
            pi_inversa = permutation(pi, n);
            end = clock();
            clock_spent_permutations += (double)(end - begin);
            printf("(%d) The elapsed time for %d permutations - permutations is %f seconds", i_test, n, (end - begin) / CLOCKS_PER_SEC);

            // Second algorithm
            begin = clock();
            pi_inversa = inversa(pi, n);
            end = clock();
            clocks_spent_merge_sort += (double)(end - begin);
            printf("(%d) The elapsed time for %d permutations - merge sort is %f seconds", i_test, n, (end - begin) / CLOCKS_PER_SEC);
        }
        avg_time_spent_permutations = clocks_spent_permutations / (CLOCKS_PER_SEC * 10);
        avg_time_spent_merge_sort = clocks_spent_merge_sort / (CLOCKS_PER_SEC * 10);

        printf("The avg for %d permutations - permutations is %f seconds", n, avg_time_spent_permutations);
        printf("The avg for %d permutations - merge sort is %f seconds", n, avg_time_spent_merge_sort);
    }

    return 0;
}
