/**
    programa que cria uma matriz de forma dinamica, recebendo o tamanho pelo usuario.

    @version v0.0.1 Agosto/2021
    @author LUCAS, Rosivaldo
**/
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int linhas, colunas, i, j;
    int **matriz = NULL;

    printf("linhas: ");
    scanf("%d", &linhas);

    printf("colunas: ");
    scanf("%d", &colunas);

    matriz = (int **) malloc(sizeof(int*) * linhas);

    for (i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(sizeof(int) * colunas);
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            matriz[i][j] = 0;
        }
    }

    printf("\n\n\t");

    for (j = 0; j < colunas; j++) {
        printf("%d ", j + 1);
    }

    printf("\n\n");

    for (i = 0; i < linhas; i++) {

        printf("%d\t", i + 1);
        
        for (j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }

    printf("\n");

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            free(matriz[i]);
        }
    }

    free(matriz);

    return 0;
}
