#include <stdio.h>
#include "matriz.h"

int main() {
    Matriz *matriz = mat_criar(2, 3);

    mat_inicializar(matriz);

    mat_print(matriz);

    printf("\n\n\n");

    mat_atribuir(matriz, 1, 2, 55.5f);

    mat_print(matriz);

    printf("\n\n\n");


    printf("linha: %d\n", mat_nlinhas(matriz));
    printf("coluna: %d\n", mat_ncolunas(matriz));

    printf("\n\n\n");

    float item;
    mat_acessar(matriz, 0, 0, &item);
    printf("acessar: %.2f\n", item);

    mat_liberar(matriz);

    return 0;
}
