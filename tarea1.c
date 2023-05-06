#include "permutation.c"
#include "mergeSort.c"
#include "createPi.c"

int main() {
    double clocks_spent_permutations, clocks_spent_merge_sort, avg_time_spent_permutations, avg_time_spent_merge_sort;
    clock_t begin, end;

    int *pi, *pi_inversa;

    for (int i = 0; i <= 7; i++) {
        int n = pow(2, 20 + i);
        clocks_spent_permutations = 0.0;
        clocks_spent_merge_sort = 0.0;

        for (int i_test = 1; i_test <= 10; i_test++) {
            pi = createNIntegers(n); // TODO

            // First algorithm
            begin = clock();
            pi_inversa = permutation(pi, n);
            end = clock();
            clocks_spent_permutations += (double)(end - begin);
            printf("(%d) The elapsed time for 2^%d permutations - permutations is %f seconds\n", i_test, 20+i, (double)(end - begin) / CLOCKS_PER_SEC);
            free(pi_inversa);
            // Second algorithm
            begin = clock();
            pi_inversa = inversa(pi, n);
            end = clock();
            clocks_spent_merge_sort += (double)(end - begin);
            printf("(%d) The elapsed time for 2^%d permutations - merge sort is %f seconds\n", i_test, 20+i, (double)(end - begin) / CLOCKS_PER_SEC);
            free(pi);
            free(pi_inversa);
        }
        avg_time_spent_permutations = clocks_spent_permutations / (CLOCKS_PER_SEC * 10);
        avg_time_spent_merge_sort = clocks_spent_merge_sort / (CLOCKS_PER_SEC * 10);

        printf("The avg for 2^%d permutations - permutations is %f seconds\n", 20+i, avg_time_spent_permutations);
        printf("The avg for 2^%d permutations - merge sort is %f seconds\n", 20+i, avg_time_spent_merge_sort);
    }

    return 0;
}
