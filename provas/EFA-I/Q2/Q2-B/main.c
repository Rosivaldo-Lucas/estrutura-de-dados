#include <stdio.h>
#include "lista.h"

int main(int argc, char *argv[]) {

    // cria a lista e insere no fim e mostra a lista
    printf("cria a lista e insere no fim e mostra a lista\n");
    Lista *l = ll_criar(5.0f);
    ll_inserir_fim(l, 8.0);
    ll_inserir_fim(l, 7.0);
    ll_inserir_fim(l, 1.0);
    ll_imprimir(l);
    printf("TAM = %d\n", ll_tamanho(l));

    printf("\n\n");

    // insere ordenado e mostra a nova lista
    printf("insere ordenado e mostra a nova lista\n");
    ll_inserir_ordenado(l, 6.0f);
    ll_imprimir(l);
    printf("TAM = %d\n", ll_tamanho(l));

    printf("\n\n");

    // insere no inicio e mostra a nova lista
    printf("insere no inicio e mostra a nova lista\n");
    ll_inserir_inicio(l, -50.0f);
    ll_imprimir(l);
    printf("TAM = %d\n", ll_tamanho(l));

    printf("\n\n");

    printf("remove o elemento -50.0 da lista e imprime a lista\n");
    ll_remover(l, -50.0f);
    ll_imprimir(l);

    printf("\n\n");

    if (ll_eh_vazia(l)) {
        printf("nao vazia\n");
    } else {
        printf("nao eh vazia\n");
    }

    printf("verifica se o elemento -50.0 pertence a lista\n");
    if (ll_pertence(l, -50.0f)) {
        printf("pertence\n");
    } else {
        printf("nao pertence\n");
    }

    printf("\n\n");

    printf("ordena a lista de forma asc\n");
    ll_ordenar(l, ll_asc);

    ll_imprimir(l);

    ll_liberar(l);

    return 0;
}
