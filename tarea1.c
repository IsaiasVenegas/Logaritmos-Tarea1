#include "permutation.c"
#include "mergeSort.c"
#include "createPi.c"

typedef struct {
    double permutations;
    double merge_sort;
} Clocks_spent;

int main() {
    Clocks_spent* times = malloc(10 * sizeof(Clocks_spent));
    int avg_permutations, avg_merge_sort, sd_permutations, sd_merge_sort;
    clock_t begin, end;

    int *pi, *pi_inversa;

    for (int i = 0; i <= 8; i++) {
        int n = pow(2, 20 + i);
        avg_permutations = 0.0;
        avg_merge_sort = 0.0;
        sd_permutations = 0.0;
        sd_merge_sort = 0.0;
        

        for (int i_test = 1; i_test <= 10; i_test++) {
            pi = createNIntegers(n); // TODO

            // First algorithm
            begin = clock();
            pi_inversa = permutation(pi, n);
            end = clock();
            times[i_test-1].permutations = ((double)(end - begin) / CLOCKS_PER_SEC) *1000.0;
            printf("(%d) The elapsed time for 2^%d permutations - permutations is %d milliseconds\n", i_test, 20+i, (int)times[i_test-1].permutations);
            free(pi_inversa);
            // Second algorithm
            begin = clock();
            pi_inversa = inversa(pi, n);
            end = clock();
            times[i_test-1].merge_sort = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000.0;
            printf("(%d) The elapsed time for 2^%d permutations - merge sort is %d milliseconds\n", i_test, 20+i, (int)times[i_test-1].merge_sort);
            free(pi);
            free(pi_inversa);
        }
        // Acá se calculan los promedios
        for(int j=0; j<10; j++){
            avg_permutations += times[j].permutations;
            avg_merge_sort += times[j].merge_sort;
        }
        avg_permutations = avg_permutations / 10;
        avg_merge_sort = avg_merge_sort / 10;
        // Acá se calculan las desviaciones estandar
        for(int j=0; j<10; j++){
            sd_permutations += pow(fabs(times[j].permutations - avg_permutations), 2);
            sd_merge_sort += pow(fabs(times[j].merge_sort - avg_merge_sort), 2);
        }
        sd_permutations = (int) sqrt(sd_permutations / 10.0);
        sd_merge_sort = (int) sqrt(sd_merge_sort / 10.0);

        printf("The avg for 2^%d permutations - permutations is %d milliseconds\n", 20+i, avg_permutations);
        printf("The sd for 2^%d permutations - permutations is %d milliseconds\n", 20+i, sd_permutations);
        printf("The avg for 2^%d permutations - merge sort is %d milliseconds\n", 20+i, avg_merge_sort);
        printf("The sd for 2^%d permutations - merge sort is %d milliseconds\n", 20+i, sd_merge_sort);
    }

    return 0;
}
