#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

struct no {
    int elem;
    no *esq, *dir;
};

arvore_t *ab_cria() {
    arvore_t *a = (arvore_t *) malloc(sizeof(arvore_t));

    if (a == NULL) return NULL;

    a->raiz = NULL;

    return a;
}

int ab_vazia(arvore_t *a) {
    if (a == NULL) return -1;

    if (a->raiz == NULL) return 1;

    return 0;
}

void ab_libera(no *raiz) {
    if (raiz != NULL) {
        ab_libera(raiz->esq);
        ab_libera(raiz->dir);
        free(raiz);
    }
}

void ab_imprime(no *raiz) {
    if (raiz != NULL) {
        printf("%d(", raiz->elem);
        ab_imprime(raiz->esq);
        printf(",");
        ab_imprime(raiz->dir);
        printf(")");
    } else {
        printf("null");
    }
}

int ab_altura(no *raiz) {
    if (raiz == NULL) return 0;

    int alt_esq = 1 + ab_altura(raiz->esq);
    int alt_dir = 1 + ab_altura(raiz->dir);

    if (alt_esq > alt_dir) {
        return alt_esq;
    } else {
        return alt_dir;
    }
}

no *ab_buscar(no *raiz, int elem) {
    if (raiz == NULL) return NULL;

    if (raiz->elem == elem) return raiz;

    no *p = ab_buscar(raiz->esq, elem);
    if (p == NULL)
        p = ab_buscar(raiz->dir, elem);

    return p;
}

no *ab_busca_pai(no *raiz, int pai) {
    if (raiz == NULL) return NULL;

    if (raiz->esq != NULL && raiz->esq->elem == pai)
        return raiz;

    if (raiz->dir != NULL && raiz->dir->elem == pai)
        return raiz;

    no *p = ab_busca_pai(raiz->esq, pai);
    if (p == NULL)
        p = ab_busca_pai(raiz->dir, pai);

    return p;
}

// se pai == -1 - inserir na raiz
// caso contrario, insere do esquerdo de pai
int ab_insere_esq(arvore_t *a, int elem, int pai) {
    no *p = (no *) malloc(sizeof(no));
    if (p == NULL) return 0;
    p->esq = NULL;
    p->dir = NULL;
    p->elem = elem;

    if (pai == -1) {
        if (a->raiz == NULL) {
            a->raiz = p;
        } else {
            free(p);
            return 0;
        }
    } else {
        no *aux = ab_buscar(a->raiz, pai);
        if (aux != NULL && aux->esq == NULL) {
            aux->esq = p;
        } else {
            free(p);
            return 0;
        }
    }

    return 1;
}

int ab_insere_dir(arvore_t *a, int elem, int pai) {
    no *p = (no *) malloc(sizeof(no));
    if (p == NULL) return 0;
    p->esq = NULL;
    p->dir = NULL;
    p->elem = elem;

    if (pai == -1) {
        if (a->raiz == NULL) {
            a->raiz = p;
        } else {
            free(p);
            return 0;
        }
    } else {
        no *aux = ab_buscar(a->raiz, pai);
        if (aux != NULL && aux->dir == NULL) {
            aux->dir = p;
        } else {
            free(p);
            return 0;
        }
    }

    return 1;
}

// 1 etapa - encontrar o elemento a ser removido
// 2 etapa - remover o elemento
int ab_remove(arvore_t *a, int elem) {
    no *p, *pai;
    int eh_esq;

    // 1 etapa
    if (a->raiz != NULL && a->raiz->elem == elem) {
        p = a->raiz;
        pai = NULL;
    } else {
        pai = ab_busca_pai(a->raiz, elem);

        if (pai != NULL) {
            if (pai->esq != NULL && pai->esq->elem == elem) {
                p = pai->esq;
                eh_esq = 1;
            } else if (pai->dir != NULL && pai->dir->elem == elem) {
                p = pai->dir;
                eh_esq = 0;
            }
        } else { // pai eh NULL
            p = NULL; // elemento nao existe na arvore
        }
    }

    // 2 etapa
    if (p == NULL) {
        return 0;
    } else {
        if (p->esq == NULL && p->dir == NULL) { // remocao do p como folha
            if (pai == NULL) {
                a->raiz = NULL;
                free(p);
            } else {
                if (eh_esq) {
                    pai->esq = NULL;
                    free(p);
                } else {
                    pai->dir = NULL;
                    free(p);
                }
            }
            return 1;
        } else { // ou esq existe ou dir existe
            if (p->esq != NULL) {
                p->elem = p->esq->elem;
                p->esq->elem = elem;
            } else {
                p->elem = p->dir->elem;
                p->dir->elem = elem;
            }
            return ab_remove(a, elem);
        }
    }
}

void pre_ordem(no *raiz) {
    if (raiz != NULL) {
        printf("<%d<", raiz->elem);
        pre_ordem(raiz->esq);
        printf(",");
        pre_ordem(raiz->dir);
        printf(">");
    } else {
        printf("null");
    }
}

void em_ordem(no *raiz) {

}

void pos_ordem(no *raiz) {

}
