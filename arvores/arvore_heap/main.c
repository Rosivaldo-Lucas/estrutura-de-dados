#include <stdio.h>
#include "arv_heap.h"

int main(void) {
    int elem;
    
    arv_heap_t *a = arv_cria();

    arv_insere(a, 4, 5);
    arv_insere(a, 7, 1);
    arv_insere(a, 2, 3);
    arv_insere(a, 8, 9);
    arv_insere(a, 22, 10);
    arv_insere(a, 22, 11);

    while (!arv_vazia(a)) {
        arv_remove(a, &elem);
        printf("%d ", elem);
    }

    arv_libera(a);

    return 0;
}
