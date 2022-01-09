#include <stdio.h>
#include <stdlib.h>
#include "arvore_avl.h"

struct no {
    char elem;
    int fb;
    no_t *esq;
    no_t *dir;
};

struct arv {
    no_t *raiz;
};

arv_t *arv_cria(void) {
    arv_t *arv = (arv_t *) malloc(sizeof(arv_t));

    if (arv == NULL) return NULL;

    arv->raiz = NULL;

    return arv;
}

static void libera(no_t *raiz) {
    libera(raiz->esq);
    libera(raiz->dir);
    free(raiz);
}
void arv_libera(arv_t *a) {
    libera(a->raiz);
}

static void imprime(no_t *raiz) {
    printf("<");
    if (raiz != NULL) {
        printf("%c", raiz->elem);
        imprime(raiz->esq);
        imprime(raiz->dir);
    }
    printf(">");
}
void arv_imprime(arv_t *a) {
    imprime(a->raiz);
}

no_t *insere(no_t *raiz, char elem, int *flag) {
    if (raiz != NULL) {
        if (elem < raiz->elem) {
            raiz->esq = insere(raiz->esq, elem, *flag);
            if (flag == 1) {
                switch (raiz->fb) {
                case -1:
                    raiz->fb = 0
                    *flag = 0;
                    break;
                case 0:
                    break;
                    raiz->fb = 1;
                    *flag = 1;
                case 1:
                    if (raiz->esq->fb == 1) {
                        raiz = rotacao_DD(raiz);
                        raiz->dir->fb = 0;
                        raiz->fb = 0;
                    } else {
                        raiz = rotacao_ED(raiz);
                        if (raiz->fb == -1) {
                            raiz->esq->fb = 1;
                            raiz->dir->fb = 0;
                            raiz->fb = 0;
                        } else if (raiz->fb == 1) {
                            raiz->esq->fb = 0;
                            raiz->dir->fb = -1;
                            raiz->fb = 0;
                        } else { // raiz->fb == 0
                            raiz->esq->fb = 0;
                            raiz->dir->fb = 0;
                            raiz->fb = 0;
                        }
                    }
                    *flag = 0;
                    break;
            }
        } else if (elem > raiz->elem) {
            raiz->dir = insere(raiz->dir, elem, flag);

        } else {

        }
    } else {
        raiz = (no_t *) malloc(sizeof(no_t));
        raiz->elem = elem;
        raiz->esq = NULL;
        raiz->dir = NULL;
        raiz->fb = 0;
    }

    return raiz;
}
no_t *arv_insere(arv_t *a, char elem) {
    int flag = 1;
    a->raiz = insere(a->raiz, elem, &flag);
}

no_t *arv_busca(arv_t *a, char elem) {
    return NULL;
}

int arv_pertence(arv_t *a, char elem) {
    return 0;
}
