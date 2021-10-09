#include <stdio.h>

int main(int argc, char* argv[]) {

    // int *vet[5]; // vetor de 5 ponteiros

    int *pvet[2];
    int x = 10, y[2] = {20, 30};

    pvet[0] = &x; // receber o end de x
    pvet[1] = y; // receber o end do vetor y

    printf("pvet[0]: %p\n", pvet[0]); // &x
    printf("pvet[1]: %p\n", pvet[1]); // &y[0]

    printf("*pvet[0]: %d\n", *pvet[0]); // x
    printf("*pvet[1][1]: %d\n", *pvet[1][1]); // y[1]

    return 0;
}
