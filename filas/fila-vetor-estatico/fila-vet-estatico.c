#include <stdio.h>
#include <stdlib.h>
#include "fila-vet-estatico.h"

#define TAM_FILA 10

struct fila {
    int inicio, fim, total;
    int itens[TAM_FILA];
};

fila_t *f_cria(void) {
    fila_t *f = (fila_t *) malloc(sizeof(fila_t));

    if (f == NULL) return NULL;

    f->total = 0;
    f->inicio = 0;
    f->fim = 0;

    return f;
}

void f_destruir(fila_t *f) {
    if (f != NULL) free(f);
}

int f_inserir(fila_t *f, int elem) {
    if (f_is_full(f) == 1) return 0; // fila cheia

    f->itens[f->fim] = elem;
    f->fim = (f->fim + 1) % TAM_FILA;
    f->total = f->total + 1;

    return 1;
}

int f_remover(fila_t *f, int *elem) {
    if (f_is_empty(f) == 1) return 0; // fila vazia

    *elem = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % TAM_FILA;
    f->total = f->total - 1;

    return 1;
}

int f_is_empty(fila_t *f) {
    if (f == NULL) return -1;

    return f->total == 0;
}

int f_is_full(fila_t *f) {
    if (f == NULL) return -1;

    return f->total == TAM_FILA;
}

int f_size(fila_t *f) {
    if (f == NULL) return -1;

    return f->total;
}
