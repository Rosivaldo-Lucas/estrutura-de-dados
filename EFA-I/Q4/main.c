#include <stdio.h>
#include "conjunto.h"

int main() {
    Conjunto *A = NULL, *B = NULL, *C = NULL, *D = NULL;

    // cria os conjuntos A e B
    A = cr_criar(A);
    B = cr_criar(B);

    // insere e impreme o conjunto A
    printf("imprime conjunto A\n");
    cr_inserir(A, 1.0f);
    cr_inserir(A, 8.0f);
    cr_inserir(A, 3.0f);
    cr_inserir(A, 5.0f);
    cr_imprime(A);
    printf("TAM A = %d\n", cr_tamanho(A));
    
    // verifica se conjunto eh vazio
    if (cr_is_vazio(A)) {
        printf("eh vazio\n");

    } else {
        printf("nao eh vazio\n");
    }

    // verifica se o elemento pertence ao conjunto
    if (cr_pertence(A, 1.0f)) {
        printf("pertence\n");
    } else {
        printf("nao pertence\n");
    }

    // insere e impreme o conjunto B
    printf("imprime conjunto B\n");
    cr_inserir(B, 1.0f);
    cr_inserir(B, 8.0f);
    cr_inserir(B, 5.0f);
    cr_inserir(B, 4.0f);
    cr_inserir(B, 11.0f);
    cr_inserir(B, 25.0f);
    cr_imprime(B);
    printf("TAM B = %d\n", cr_tamanho(B));

    // verifica se conjunto eh vazio
    if (cr_is_vazio(B)) {
        printf("eh vazio\n");

    } else {
        printf("nao eh vazio\n");
    }

    // verifica se o elemento pertence ao conjunto
    if (cr_pertence(A, 1.0f)) {
        printf("pertence\n");
    } else {
        printf("nao pertence\n");
    }

    // remove o elemento 25.0 do conjunto B
    cr_remover(B, 25.0f);

    printf("conjunto B com elemento 25 removido\n");
    cr_imprime(B);

    // imprime conjunto C (UNIAO)
    printf("conjunto uniao A e B = C\n");
    C = cr_uniao(A, B);
    cr_imprime(C);

    // imprime conjunto D (INTERSECCAO)
    printf("conjunto interseccao A e B = D\n");
    D = cr_interseccao(A, B);
    cr_imprime(D);

    cr_liberar(A);
    cr_liberar(B);
    cr_liberar(C);
    cr_liberar(D);

    return 0;
}
