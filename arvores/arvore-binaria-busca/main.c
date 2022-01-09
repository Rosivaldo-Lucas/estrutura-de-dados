#include <stdio.h>
#include "abb.h"

int main(void) {
    abb_t *a = abb_cria();

    abb_insere(a, 5);
    abb_insere(a, 3);
    abb_insere(a, 7);
    abb_insere(a, 9);
    abb_insere(a, 8);
    abb_insere(a, 2);

    abb_mostra(a);
    printf("\n");

    printf("qtd = %d\n", abb_qtd_folha(a));

    abb_remove(a, 3);

    abb_mostra(a);
    printf("\n");

    printf("qtd = %d\n", abb_qtd_folha(a));

    //abb_libera(a);

    return 0;
}
