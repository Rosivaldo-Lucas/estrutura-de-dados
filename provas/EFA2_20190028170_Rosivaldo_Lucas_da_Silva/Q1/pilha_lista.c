#include <stdlib.h>
#include <string.h>
#include "pilha_lista.h"

typedef struct no No;
struct no {
    char elem;
    No *prox;
};

struct pilha {
    No *topo;
    int tam;
};

pilha_t *p_cria() {
    pilha_t *p = (pilha_t *) malloc(sizeof(pilha_t));

    if (p == NULL) return NULL;

    p->topo = NULL;
    p->tam = 0;

    return p;
}

int p_libera(pilha_t *p) {
    if (p == NULL) return 0;

    No *aux = p->topo;
    while (aux != NULL) {
        No *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }

    free(p);

    return 1;
}

int p_empilha(pilha_t *p, char elem) {
    if (p == NULL) return 0;

    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL) return 0;

    novo->elem = elem;
    novo->prox = p->topo;

    p->topo = novo;
    p->tam += 1;

    return 1;
}

int p_desempilha(pilha_t *p, char *elem) {
    if (p == NULL || p_vazia(p)) return 0;

    No *t = p->topo;
    *elem = t->elem;

    p->topo = t->prox;
    p->tam -= 1;
    free(t);

    return 1;
}

int p_tamanho(pilha_t *p) {
    if (p == NULL) return -1;

    return p->tam;
}

int p_vazia(pilha_t *p) {
    if (p == NULL) return 0;

    if (p->tam == 0) return 1;

    return 0;
}
