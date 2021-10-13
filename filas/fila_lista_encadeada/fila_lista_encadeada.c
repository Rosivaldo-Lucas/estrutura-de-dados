#include <stdio.h>
#include <stdlib.h>
#include "fila_lista_encadeada.h"

typedef struct no No;
struct no {
    int elem;
    No *prox;
};

struct fila {
    No *ini, *fim;
    int tam;
};

fila_t *f_cria(void) {
    fila_t *f = (fila_t *) malloc(sizeof(fila_t));

    if (f == NULL) return NULL;

    f->ini = NULL;
    f->fim = NULL;
    f->tam = 0;

    return f;
}

int f_libera(fila_t *f) {
    if (f == NULL) return 0;

    No *p = f->ini;

    while (p != NULL) {
        No *n = p->prox;
        free(p);
        p = n;
    }

    free(f);

    return 1;
}

int f_insere(fila_t *f, int elem) {
    if (f == NULL) return 0;

    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL) return 0;

    novo->elem = elem;
    novo->prox = NULL;

    if (f_is_empty(f) == 1) {
        f->ini = novo;
        f->fim = novo;
    }

    f->fim->prox = novo;
    f->fim = novo;
    f->tam += 1;

    return 1;
}

int f_remove(fila_t *f, int *elem) {
    if (f == NULL) return 0;

    No *p = f->ini;
    *elem = p->elem;
    f->ini = p->prox;

    if (f_is_empty(f) == 1) {
        f->fim = NULL;
    }

    free(p);
    f->tam -= 1;

    return 1;
}

int f_is_empty(fila_t *f) {
    if (f == NULL) return -1;
 
    if (f->tam != 0) {
        return 0;
    }

    return 1;
}

int f_size(fila_t *f) {
    if (f == NULL) return -1;

    return f->tam;
}
