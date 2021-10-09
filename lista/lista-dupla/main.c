#include <stdio.h>
#include "lista-dupla.h"

int main(void) {
    ListaDupla *ld = ld_criar();

    ld_inserir_fim(ld, 5);
    ld_inserir_fim(ld, 2);
    ld_inserir_fim(ld, 7);
    ld_inserir_fim(ld, 1);
    ld_inserir_fim(ld, -80);

    ld_imprimir(ld);

    ld_remover(ld, 5);
    ld_remover(ld, -80);
    ld_remover(ld, 7);

    ld_imprimir(ld);

    ld_liberar(ld);

    return 0;
}
