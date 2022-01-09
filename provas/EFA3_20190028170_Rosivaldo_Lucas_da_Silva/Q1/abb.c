#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

struct no {
    chave c;
    no_t *esq, *dir;
};

struct abb {
    no_t *raiz;
};

abb_t *abb_cria() {
    abb_t *abb = (abb_t *) malloc(sizeof(abb_t));

    if (abb == NULL) return NULL;

    abb->raiz = NULL;

    return abb;
}

void libera(no_t *raiz) {
    if (raiz != NULL) {
        libera(raiz->esq);
        libera(raiz->dir);
        free(raiz);
    }
}
void abb_libera(abb_t *abb) {
    if (abb != NULL) libera(abb->raiz);
}

no_t *insere(no_t *raiz, chave c) {
    if (raiz == NULL) {
        raiz = (no_t *) malloc(sizeof(no_t));
        raiz->c = c;
        raiz->esq = NULL;
        raiz->dir = NULL;
    } else if (raiz->c == c) {
        return raiz;
    } else if (raiz->c > c) {
        raiz->esq = insere(raiz->esq, c);
    } else {
        raiz->dir = insere(raiz->dir, c);
    }
    return raiz;
}
int abb_insere(abb_t *abb, chave c) {
    if (abb == NULL) return 0;
    abb->raiz = insere(abb->raiz, c);
    return 1;
}

no_t *remover(no_t *raiz, chave c) {
    if (raiz == NULL) {
        return NULL;
    } else if (raiz->c > c) {
        raiz->esq = remover(raiz->esq, c);
    } else if (raiz->c < c) {
        raiz->dir = remover(raiz->dir, c);
    } else {
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            raiz = NULL;
        } else if (raiz->esq == NULL) {
            no_t *aux = raiz;
            raiz = raiz->dir;
            free(aux);
        } else if (raiz->dir == NULL) {
            no_t *aux = raiz;
            raiz = raiz->esq;
            free(aux);
        } else {
            no_t *aux = raiz->esq;
            
            while (aux->dir != NULL) {
                aux = aux->dir;
            }

            raiz->c = aux->c;

            raiz->esq = remover(raiz->esq, aux->c);
        }
    }

    return raiz;
}
int abb_remove(abb_t *abb, chave c) {
    if (abb == NULL) return 0;

    abb->raiz = remover(abb->raiz, c);
}

no_t *busca(no_t *raiz, chave c) {
    if (raiz == NULL) {
        return NULL;
    } else if (raiz->c == c) {
        return raiz;
    } else if (raiz->c > c) {
        return busca(raiz->esq, c);
    } else {
        return busca(raiz->dir, c);
    }
}
no_t *abb_busca(abb_t *abb, chave c) {
    if (abb == NULL) return NULL;

    return busca(abb->raiz, c);
}

int qtd_folha(no_t *raiz) {
    int qtd_e = 0;
    int qtd_d = 0;

    if (raiz == NULL) {
        return 0;
    } else if (raiz->esq == NULL || raiz->dir == NULL) {
        return 1;
    }

    qtd_e = qtd_folha(raiz->esq);
    qtd_d = qtd_folha(raiz->dir);

    return (qtd_e + qtd_d);
}
int abb_qtd_folha(abb_t *abb) {
    if (abb == NULL) return -1;

    return qtd_folha(abb->raiz);
}

void mostra(no_t *raiz) {
    if (raiz != NULL) {
        printf("<%d", raiz->c);
        mostra(raiz->esq);
        mostra(raiz->dir);
        printf(">");
    } else {
        printf("<>");
    }
}
void abb_mostra(abb_t *abb) {
    if (abb != NULL) mostra(abb->raiz);
}
