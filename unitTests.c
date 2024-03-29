#include "createPi.c"
#include "permutation.c"
#include "mergeSortArity.c"

int checkPi(int *arr1, int *arr2, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] != arr2[i])
        {
            printf("arr1[%d] = %d \n", i, arr1[i]);
            printf("arr2[%d] = %d \n", i, arr2[i]);
            return 0;
        }
    }
    return 1;
}

int main()
{
    printf("Tests básicos para el algoritmo de permutación: \n");
    int pi_1[] = {1};
    int pi_inversa_1[] = {1};
    if (!checkPi(permutation(pi_1, 1), pi_inversa_1, 1))
    {
        printf("Error, pi_inversa está malo para el caso 1 \n");
        exit(1);
    }
    int pi_2[] = {2, 1};
    int pi_inversa_2[] = {2, 1};
    if (!checkPi(permutation(pi_2, 2), pi_inversa_2, 2))
    {
        printf("Error, pi_inversa está malo para el caso 2 \n");
        exit(1);
    }
    int pi_3[] = {2, 1, 3};
    int pi_inversa_3[] = {2, 1, 3};
    if (!checkPi(permutation(pi_3, 3), pi_inversa_3, 3))
    {
        printf("Error, pi_inversa está malo para el caso 3 \n");
        exit(1);
    }
    int pi_4[] = {3, 1, 4, 2};
    int pi_inversa_4[] = {2, 4, 1, 3};
    if (!checkPi(permutation(pi_4, 4), pi_inversa_4, 4))
    {
        printf("Error, pi_inversa está malo para el caso 4 \n");
        exit(1);
    }
    int pi_5[] = {3, 5, 4, 1, 2};
    int pi_inversa_5[] =  {4, 5, 1, 3, 2};
    if (!checkPi(permutation(pi_5, 5), pi_inversa_5, 5))
    {
        printf("Error, pi_inversa está malo para el caso 5 \n");
        exit(1);
    }
    int pi_6[] = {5, 6, 1, 3, 2, 4};
    int pi_inversa_6[] = {3, 5, 4, 6, 1, 2};
    if (!checkPi(permutation(pi_6, 6), pi_inversa_6, 6))
    {
        printf("Error, pi_inversa está malo para el caso 6 \n");
        exit(1);
    }
    int pi_7[] = {7, 2, 6, 3, 1, 4, 5};
    int pi_inversa_7[] = {5, 2, 4, 6, 7, 3, 1};
    if (!checkPi(permutation(pi_7, 7), pi_inversa_7, 7))
    {
        printf("Error, pi_inversa está malo para el caso 7 \n");
        exit(1);
    }
    int pi_8[] = {3, 5, 6, 8, 1, 2, 4, 7};
    int pi_inversa_8[] = {5, 6, 1, 7, 2, 3, 8, 4};
    if (!checkPi(permutation(pi_8, 8), pi_inversa_8, 8))
    {
        printf("Error, pi_inversa está malo para el caso 8 \n");
        exit(1);
    }
    int pi_9[] = {1, 7, 4, 2, 8, 9, 5, 3, 6};
    int pi_inversa_9[] = {1, 4, 8, 3, 7, 9, 2, 5, 6};
    if (!checkPi(permutation(pi_9, 9), pi_inversa_9, 9))
    {
        printf("Error, pi_inversa está malo para el caso 9 \n");
        exit(1);
    }
    int pi_10[] = {2, 6, 5, 3, 1, 9, 7, 10, 8, 4};
    int pi_inversa_10[] = {5, 1, 4, 10, 3, 2, 7, 9, 6, 8};
    if (!checkPi(permutation(pi_10, 10), pi_inversa_10, 10))
    {
        printf("Error, pi_inversa está malo para el caso 10 \n");
        exit(1);
    }
    printf("Tests básicos listos! \n \n");
    printf("Comparamos si el algoritmo de merge sort responde igual que el algoritmo de permutación: \n");

    for (int i = 1; i < 100; i++)
    {
        int *pi = createNIntegers(i);
        int *pi_permutation;
        pi_permutation = permutation(pi, i);
        int *pi_merge_sort;
        pi_merge_sort = inversa(pi, i, 8);
        if (!checkPi(pi_merge_sort, pi_permutation, i))
        {
            printf("pi   -> ");
            for(int j=0; j<i; j++){
                printf("%d ", pi[j]);
            }
            printf("\npi_m -> ");
            for(int j=0; j<i; j++){
                printf("%d ", pi_merge_sort[j]);
            }
            printf("\npi_p -> ");
            for(int j=0; j<i; j++){
                printf("%d ", pi_permutation[j]);
            }
            printf("\n");
            printf("Error, pi_merge_sort es distinto a pi_permutation para el caso %d \n", i);
            exit(1);
        }
        free(pi);
        free(pi_permutation);
        free(pi_merge_sort);
    }
    printf("Permutación y Merge Sort listos! \n \n");

    printf("Comparamos si el algoritmo de merge sort responde igual que el algoritmo de permutación para un n muy grande: \n");

    // No se analizan casos más grandes porque no hay espacio en RAM para almacenar 3 de estos arreglos
    for (int i = 0; i < 9; i++)
    {
        int n = pow(2, 20 + i);
        printf("Probando para el caso n = 2^%d \n", 20+i);
        int *pi = createNIntegers(n);
        int *pi_permutation;
        pi_permutation = permutation(pi, n);
        int *pi_merge_sort;
        pi_merge_sort = inversa(pi, n, 8);
        if (!checkPi(pi_merge_sort, pi_permutation, n))
        {
            printf("Error, pi_merge_sort es distinto a pi_permutation para el caso n = 2^%d \n", 20+i);
            exit(1);
        }
        free(pi);
        free(pi_permutation);
        free(pi_merge_sort);
        printf("Caso %d listo! \n", n);
    }
    printf("Permutación y Merge Sort para n grande listos! \n \n");

    return 0;
}