#include <stdio.h>
#include <stdlib.h>
#include "fila_lista_dupla.h"

typedef struct no No;
struct no {
    char elem;
    No *ant, *prox;
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
        f->ini = p->prox;
        free(p);
        p = f->ini;
    }

    free(f);

    return 1;
}

int f_insere(fila_t *f, char elem) {
    if (f == NULL) return 0;

    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL) return 0;

    novo->elem = elem;
    novo->ant = NULL;
    novo->prox = NULL;

    if (f_vazia(f) == 1) {
        f->ini = novo;
        f->fim = novo;
    } else {
        novo->ant = f->fim;
        f->fim->prox = novo;
        f->fim = novo;
    }

    f->tam += 1;

    return 1;
}

int f_remove(fila_t *f, char *elem) {
    if (f == NULL || f_vazia(f)) return 0;

    No *aux = f->ini;
    *elem = aux->elem;

    if (f->ini == f->fim) {
        f->ini = NULL;
        f->fim = NULL;
        
        free(aux);
    } else {
        f->ini = aux->prox;        
        f->ini->ant = NULL;

        free(aux);
    }

    f->tam -= 1;    

    return 1;
}

int f_vazia(fila_t *f) {
    if (f == NULL) return -1;

    if (f->tam != 0) {
        return 0;
    }

    return 1;
}

int f_tamanho(fila_t *f) {
    if (f == NULL) return -1;

    return f->tam;
}
