#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_vetor_dinamico.h"

struct fila {
    int *v;  // vetor com os elementos da fila
    int ini; // indice do inicio da fila
    int tam; // numero de elem da fila
    int dim; // dimensao corrente do vetor
};

fila_t *f_cria(void) {
    fila_t *f = (fila_t *) malloc(sizeof(fila_t));

    if (f == NULL) return NULL;

    f->ini = 0;
    f->dim = 10;
    f->tam = 0;
    f->v = (int *) malloc(sizeof(int) * f->dim);

    if (f->v == NULL) {
        free(f);
        return NULL;
    }

    return f;
}

int f_libera(fila_t *f) {
    if (f == NULL || f->v == NULL) {
        return 0;
    }

    free(f->v);
    free(f);

    return 1;
}

int f_insere(fila_t *f, int elem) {
    if (f == NULL || f->v == NULL) return 0;

    int fim;
    if (f->tam == f->dim) { // fila cheia, dobra a capacidade da fila
        f->dim = f->dim * 2;
        f->v = (int *) realloc(f->v, sizeof(int) * f->dim);

        if (f->ini != 0) {
            memmove(&f->v[f->dim - f->ini], &f->v[f->ini], sizeof(float) * (f->tam - f->ini));
        }

    }

    fim = (f->ini + f->tam) % f->dim;
    f->v[fim] = elem;
    f->tam += 1;

    return 1;
}

int f_remove(fila_t *f, int *elem) {
    if (f == NULL || f->v == NULL) return 0;

    *elem = f->v[f->ini];
    f->ini = (f->ini + 1) % f->dim;
    f->tam -= 1;

    return 1;
}

int f_is_empty(fila_t *f) {
    if (f == NULL) return -1;

    return f->tam == 0;
}

int f_size(fila_t *f) {
    if (f == NULL) return -1;

    return f->tam;
}
