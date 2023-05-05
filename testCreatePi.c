#include "createPi.c"

int main(){
    for(int i=0; i<10; i++) {
        int n = pow(2, 20+i);
        int *pi = createNIntegers(n);

        printf("Caso n = 2 ^ %d : \n", 20+i);
        printf("El primer elemento de pi es: %d \n", pi[0]);
        printf("El último elemento de pi es: %d \n \n", pi[n-1]);
        free(pi);
    }
    return 0;
}