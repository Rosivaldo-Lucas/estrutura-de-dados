#include <stdio.h>
#include "lista-circular.h"

int main() {

    ListaCircular *lc = lc_criar();

    lc_inserir_inicio(lc, 10);
    lc_inserir_inicio(lc, 8);
    lc_inserir_inicio(lc, 5);
    lc_inserir_inicio(lc, 550);
    lc_inserir_inicio(lc, 1);

    lc_imprimir(lc);

    int tam = lc_tamanho(lc);

    printf("\ntam = %d\n", tam);

    lc_liberar(lc);

    return 0;
}
