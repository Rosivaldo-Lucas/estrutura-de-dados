/**
    programa que cria um vetor de forma dinamica, recebendo o tamanho pelo usuario.

    @version v0.0.1 Agosto/2021
    @author LUCAS, Rosivaldo
**/
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int tamanho, i;
    int *vetor = NULL;

    printf("tamanho vetor: ");
    scanf("%d", &tamanho);

    vetor = (int *) malloc(sizeof(int) * tamanho); // aloca um espaco dinamicamente para o vetor

    for (i = 0; i < tamanho; i++) {
        printf("%d posicao: ", (i + 1));
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor); // libera o espaco alocado para o vetor

    printf("\n");

    return 0;
}
