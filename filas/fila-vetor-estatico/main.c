#include <stdio.h>
#include <stdlib.h>
#include "fila-vet-estatico.h"

int main(void) {
    int i, x;
    
    fila_t *f = f_cria();

    for (i = 0; i < 10; i++) {
        f_inserir(f, i);
    }

    printf("tam = %d\n", f_size(f));

    f_remover(f, &x);
    f_remover(f, &x);

    f_inserir(f, 11);
    f_inserir(f, 50);

    if (f_inserir(f, 10) == 0) {
        printf("fila cheia\n");
        exit(1);
    }

    while (!f_is_empty(f)) {
        f_remover(f, &x);
        printf("%d ", x);
    }

    f_destruir(f);

    return 0;
}
