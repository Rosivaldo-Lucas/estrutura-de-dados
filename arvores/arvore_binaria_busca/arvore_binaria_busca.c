#include <stdlib.h>
#include <stdio.h>
#include "arvore_binaria.h"

typedef struct no {
    char elem;
    struct no *esq, *dir;
} no_t;

typedef struct {
    no_t *raiz;
} abb_t;

abb_t *abb_cria(void) {

    abb_t *novo = (abb_t *) malloc(sizeof(abb_t));

    if (novo == NULL) return 0;

    novo->raiz = NULL;

    return novo;
}

int abb_vazia(abb_t *a) {
    if (a->raiz == NULL) {
        return 1;
    }

    return 0;
}

void abb_libera(no_t *r) {
    if (r != NULL) {
        abb_libera(r->esq);
        abb_libera(r->dir);
        free(r);
    }
}

void abb_imprime(no_t *r);
int abb_altura(no_t *r);

no_t *abb_busca(no_t *r, char elem) {
    if (r != NULL) {
        
    }
}
