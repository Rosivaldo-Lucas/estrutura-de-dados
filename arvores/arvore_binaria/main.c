#include <stdio.h>
#include "arvore_binaria.h"

int main(void) {
    arvore_t *a = ab_cria();

    ab_insere_esq(a, 1, -1);
    ab_insere_esq(a, 2, 1);
    ab_insere_dir(a, 3, 1);
    ab_insere_esq(a, 4, 3);
    ab_insere_dir(a, 5, 3);
    ab_insere_esq(a, 6, 4);

    ab_remove(a, 1);
    pre_ordem(a->raiz);
    printf("\n");

    ab_libera(a->raiz);

    return 0;
}
