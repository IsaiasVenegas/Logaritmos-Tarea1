#include "permutation.c"
#include "mergeSortArity.c"
#include "createPi.c"

typedef struct
{
    double permutations;
    double merge_sort;
} Clocks_spent;

int main()
{
    Clocks_spent *times = malloc(10 * sizeof(Clocks_spent));
    int avg_merge_sort, sd_merge_sort;
    clock_t begin, end;

    int *pi, *pi_inversa;
    for (int arity = 2; arity <= 1024; arity *= 2)
    {
        int n = pow(2, 24);
        avg_merge_sort = 0.0;
        sd_merge_sort = 0.0;

        for (int i_test = 1; i_test <= 10; i_test++)
        {
            pi = createNIntegers(n);
            // Second algorithm
            begin = clock();
            pi_inversa = inversa(pi, n, arity);
            end = clock();
            times[i_test - 1].merge_sort = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000.0;
            printf("(%d) The elapsed time for 2^24 permutations - merge sort Arity is %d is %d milliseconds\n", i_test, arity, (int)times[i_test - 1].merge_sort);
            free(pi);
            free(pi_inversa);
        }
        // Acá se calculan los promedios
        for (int j = 0; j < 10; j++)
        {
            avg_merge_sort += times[j].merge_sort;
        }
        avg_merge_sort = avg_merge_sort / 10;
        // Acá se calculan las desviaciones estandar
        for (int j = 0; j < 10; j++)
        {
            sd_merge_sort += pow(fabs(times[j].merge_sort - avg_merge_sort), 2);
        }
        sd_merge_sort = (int)sqrt(sd_merge_sort / 10.0);

        printf("The avg for 2^24 permutations - merge sort Arity is %d is %d milliseconds\n", arity, avg_merge_sort);
        printf("The sd for 2^24 permutations - merge sort Arity is %d is %d milliseconds\n", arity, sd_merge_sort);
    }

    return 0;
}
