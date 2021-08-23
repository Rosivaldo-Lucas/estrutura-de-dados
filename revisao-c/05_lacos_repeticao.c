/**
    programa que recebe um valor de inicio e fim e realiza a impressao dos valores entre o intervalo.

    @version v0.0.1 Agosto/2021
    @author LUCAS, Rosivaldo
**/
#include <stdio.h>

/**
    funcao que imprime o intervalo dos valores utilizando a estrutura de repeticao while.

    @param inicio - (int) inicio do intervalo
    @param fim - (int) fim do intervalo
**/
void laco_while(int inicio, int fim) {
    printf("laco while\n");

    while (inicio <= fim) {
        printf("%d ", inicio);
        inicio++;
    }

    printf("\n\n");
}

/**
    funcao que imprime o intervalo dos valores utilizando a estrutura de repeticao do while.

    @param inicio - (int) inicio do intervalo
    @param fim - (int) fim do intervalo
**/
void laco_do_while(int inicio, int fim) {
    printf("laco do while\n");

    do {
        printf("%d ", inicio);
        inicio++;
    } while(inicio <= fim);

    printf("\n\n");
}

/**
    funcao que imprime o intervalo dos valores utilizando a estrutura de repeticao for.

    @param inicio - (int) inicio do intervalo
    @param fim - (int) fim do intervalo
**/
void laco_for(int inicio, int fim) {
    printf("laco for\n");

    int i;
    for (i = inicio; i <= fim; i++) {
        printf("%d ", i);
    }

    printf("\n\n");
}

int main(void) {
    
    int inicio, fim;

    printf("inicio: ");
    scanf("%d", &inicio);

    printf("fim: ");
    scanf("%d", &fim);

    laco_while(inicio, fim);

    laco_do_while(inicio, fim);

    laco_for(inicio, fim);

    return 0;
}
