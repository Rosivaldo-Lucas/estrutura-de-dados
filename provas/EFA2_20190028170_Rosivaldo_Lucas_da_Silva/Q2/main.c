#include <stdio.h>
#include "fila_lista_dupla.h"

int main(void) {
    char x;

    fila_t *f = f_cria();
    
    f_remove(f, &x);

    f_insere(f, 'a');
    f_insere(f, 'b');
    f_insere(f, 'c');
    f_insere(f, 'd');

    while (!f_vazia(f)) {
        f_remove(f, &x);
        printf("%c\n", x);
    }

    if (f_vazia(f)) {
        printf("vazia\n");
    } else {
        printf("nao vazia\n");
    }

    f_libera(f);

    return 0;
}
