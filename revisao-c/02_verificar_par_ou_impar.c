/**
    programa que recebe um numero inteiro e verifica se eh par ou impar.

    @version v0.0.1 Agosto/2021
    @author LUCAS, Rosivaldo
**/
#include <stdio.h>

int main(void) {
    int numero;

    printf("numero: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("%d eh par\n", numero);
    } else {
        printf("%d eh impar\n", numero);
    }

    return 0;
}
