/**
    programa que calcula o somatorio entre um intervalo de dois numeros informados pelo usuario.

    @version v0.0.1 Agosto/2021
    @author LUCAS, Rosivaldo
**/
#include <stdio.h>

/**
    funcao para calcular o somatorio entre dois numeros inteiros.

    @param inicio - (int)
    @param fim - (int)
    @return (int) - com o samatorio calculado
**/
int somatorio_intervalo(int inicio, int fim) {
    int i, soma = 0;

    for (i = inicio; i <= fim; i++) {
        soma = soma + i;
    }

    return soma;
}

int main(void) {

    int inicio, fim;

    printf("inicio: ");
    scanf("%d", &inicio);

    printf("fim: ");
    scanf("%d", &fim);

    int somatorio = somatorio_intervalo(inicio, fim);

    printf("somatorio de %d ate %d eh = %d\n", inicio, fim, somatorio);

    return 0;
}
