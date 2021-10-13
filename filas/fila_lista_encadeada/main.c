#include <stdio.h>
#include <stdlib.h>
#include "fila_lista_encadeada.h"

int main(void) {
    int i, x;

    fila_t *f = f_cria();

    for (i = 0; i < 10; i++) {
        f_insere(f, i);
    }

    printf("tam = %d\n", f_size(f));

    f_remove(f, &x);
    f_remove(f, &x);

    f_insere(f, 11);
    f_insere(f, 50);

    while (!f_is_empty(f)) {
        f_remove(f, &x);
        printf("%d ", x);
    }

    printf("\ntam = %d\n", f_size(f));

    if (f_is_empty(f))
        printf("vazia\n");
    else
        printf("nao vazia\n");

    f_libera(f);

    return 0;
}
