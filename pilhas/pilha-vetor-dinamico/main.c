#include <stdio.h>
#include "../pilha.h"

int main(void) {
    Pilha *p = p_criar();

    p_push(p, 5);
    p_push(p, 10);
    p_push(p, 50);

    float elem = p_pop(p);

    printf("elem = %.2f\n", elem);
    printf("elem = %.2f\n", p_pop(p));

    p_liberar(p);

    return 0;
}
