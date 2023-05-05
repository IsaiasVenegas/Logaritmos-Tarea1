#include "permutation.c"
#include "mergeSort.c"
#include "createPi.c"

int main() {
    double clocks_spent_permutations, clocks_spent_merge_sort, avg_time_spent_permutations, avg_time_spent_merge_sort;
    clock_t begin, end;

    int *pi, *pi_inversa;

    for (int n = pow(2, 20); n <= pow(2, 30); n *= pow(2, 2)) {
        clocks_spent_permutations = 0.0;
        clocks_spent_merge_sort = 0.0;

        for (int i_test = 1; i_test <= 10; i_test++) {
            pi = createNIntegers(n); // TODO

            // First algorithm
            begin = clock();
            pi_inversa = permutation(pi, n);
            end = clock();
            clocks_spent_permutations += (double)(end - begin);
            printf("(%d) The elapsed time for %d permutations - permutations is %f seconds\n", i_test, n, (end - begin) / CLOCKS_PER_SEC);

            // Second algorithm
            begin = clock();
            pi_inversa = inversa(pi, n);
            end = clock();
            clocks_spent_merge_sort += (double)(end - begin);
            printf("(%d) The elapsed time for %d permutations - merge sort is %f seconds\n", i_test, n, (end - begin) / CLOCKS_PER_SEC);
        }
        avg_time_spent_permutations = clocks_spent_permutations / (CLOCKS_PER_SEC * 10);
        avg_time_spent_merge_sort = clocks_spent_merge_sort / (CLOCKS_PER_SEC * 10);

        printf("The avg for %d permutations - permutations is %f seconds\n", n, avg_time_spent_permutations);
        printf("The avg for %d permutations - merge sort is %f seconds\n", n, avg_time_spent_merge_sort);
    }

    return 0;
}
