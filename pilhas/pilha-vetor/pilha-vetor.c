#include <stdio.h>
#include <stdlib.h>
#include "../pilha.h"

struct pilha {
    int tam;
    int dim;
    float *vet;
};

Pilha *p_criar(void) {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));

    if (p == NULL) {
        return NULL;
    }
    
    p->dim = 2;
    p->vet = (float *) malloc(sizeof(float) * p->dim);
    p->tam = 0;

    return p;
}

void p_push(Pilha *p, float elem) {
    if (p == NULL) {
        return;
    }

    if (p->tam == p->dim) {
        p->dim *= 2;
        p->vet = (float *) realloc(p->vet, sizeof(float) * p->dim);
    }

    p->vet[p->tam++] = elem;
}

float p_pop(Pilha *p) {
    if (p == NULL || p->vet == NULL) {
        return -1;
    }

    float elem = p->vet[--p->tam];

    return elem;
}

int p_vazia(Pilha *p) {
    if (p == NULL || p->vet == NULL) {
        return 0;
    }

    return p->tam == 0;

}

void p_liberar(Pilha *p) {
    free(p->vet);
    free(p);
}
