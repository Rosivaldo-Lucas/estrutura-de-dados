#include <stdio.h>
#include "lista.h"

int main() {

    Lista *l = criar();

    inserir(l, 5);
    inserir(l, 2);
    inserir(l, 3);
    inserir(l, 7);
    inserir(l, 8);

    imprimir(l);

    remover(l, 8);

    imprimir(l);

    liberar(l);

    return 0;
}
