#include <stdio.h>
#include <stdlib.h>
#include "lista-circular.h"

typedef struct no No;

struct no {
    int elem;
    No *prox;
};

struct lc {
    No *ini;
};

ListaCircular *lc_criar() {
    ListaCircular *lc = (ListaCircular *) malloc(sizeof(ListaCircular));

    if (lc == NULL) {
        return NULL;
    }

    lc->ini = NULL;

    return lc;
}

int lc_liberar(ListaCircular *lc) {

    if (lc == NULL || lc->ini == NULL) {
        return 0;
    }

    No *p = lc->ini;
    No *aux;

    while (p->prox != lc->ini) {
        aux = p;
        p = p->prox;
        free(aux);
    }

    free(lc);

    return 1;
}

int lc_inserir_inicio(ListaCircular *lc, int elem) {
    if (lc == NULL) {
        return 0;
    }

    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->elem = elem;

    if (lc->ini == NULL) {
        novo->prox = novo;

        lc->ini = novo;

        return 1;
    }

    No *p = lc->ini;

    while (p->prox != lc->ini) {
        p = p->prox;
    }

    novo->prox = lc->ini;
    lc->ini = novo;
    p->prox = novo;

    return 1;
}

int lc_inserir_fim(ListaCircular *lc, int elem) {
    if (lc == NULL) {
        return 0;
    }

    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->elem = elem;

    if (lc->ini == NULL) {
        novo->prox = novo;

        lc->ini = novo;

        return 1;
    }

    novo->prox = lc->ini;

    No *p = lc->ini;

    while (p->prox != lc->ini) {
        p = p->prox;
    }

    p->prox = novo;

    return 1;
}

int lc_imprimir(ListaCircular *lc) {
    if (lc == NULL) {
        return 0;
    }

    if (lc->ini == NULL) {
        return 0;
    }

    No *p = lc->ini;

    do {
        printf("%d ", p->elem);
        p = p->prox;
    } while (p != lc->ini);

    // if (lc->ini == lc->ini->prox) {
    //     printf("%d\n", lc->ini->elem);
    // }

    // No *p = lc->ini;

    // while (p->prox != lc->ini) {
    //     printf("%d ", p->elem);
    //     p = p->prox;
    // }

    // printf("%d\n", p->elem);

    return 0;
}

int lc_tamanho(ListaCircular *lc) {
    if (lc == NULL) {
        return -1;
    }

    if (lc->ini == lc->ini->prox) {
        return 1;
    } else {
        No *p = lc->ini;
        int cont = 0;

        while (p->prox != lc->ini) {
            cont++;
            p = p->prox;
        }

        cont++;

        return cont;
    }

    return 0;
}
