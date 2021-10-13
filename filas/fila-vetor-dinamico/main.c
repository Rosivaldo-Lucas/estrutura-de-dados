#include <stdio.h>
#include <stdlib.h>
#include "fila_vetor_dinamico.h"

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

    f_libera(f);

    return 0;
}
