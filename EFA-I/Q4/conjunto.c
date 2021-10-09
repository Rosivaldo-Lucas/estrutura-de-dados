#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

typedef struct no No;
struct no {
    float elemento;
    No *prox;
};

struct conjunto {
    No *ini, *fim;
};

Conjunto *cr_criar() {
    Conjunto *conjunto = (Conjunto *) malloc(sizeof(Conjunto));

    if (conjunto == NULL) {
        return NULL;
    }

    conjunto->ini = NULL;
    conjunto->fim = NULL;

    return conjunto;
}

int cr_liberar(Conjunto *conjunto) {
    if (conjunto == NULL) {
        return 0;
    }

    No *p = conjunto->ini;
    while (p != NULL) {
        conjunto->ini = p->prox;
        free(p);
        p = conjunto->ini;
    }

    free(conjunto);
    return 1;
}

int cr_inserir(Conjunto *conjunto, float elem) {
    if (conjunto == NULL) {
        return 0;
    }

    if (cr_pertence(conjunto, elem)) {
        return 0;
    }

    No *novoNo = (No *) malloc(sizeof(No));
    
    if (novoNo == NULL) {
        return 0;
    }
    
    novoNo->elemento = elem;
    novoNo->prox = NULL;

    if (conjunto->ini == NULL) {
        conjunto->ini = novoNo;
    } else {
        conjunto->fim->prox = novoNo;
    }

    conjunto->fim = novoNo;

    return 1;
}

int cr_remover(Conjunto *conjunto, float elem) {
    if (conjunto == NULL) {
        return 0;
    }

    No *p = conjunto->ini;
    No *ant = NULL;
    while(p != NULL) {
        if (p->elemento == elem) {
            if (p == conjunto->ini) {
                conjunto->ini = conjunto->ini->prox;
                free(p);
            } else if (p == conjunto->fim) {
                conjunto->fim = ant;
                conjunto->fim->prox = NULL;
                free(p);
            } else {
                ant->prox = p->prox;
                free(p);
            }

            return 0;
        } else {
            ant = p;
            p = p->prox;
        }
    }

    return 0;
}

int cr_imprime(Conjunto *conjunto) {
    if (conjunto == NULL) {
        return 0;
    }

    No *p = conjunto->ini;
    while (p != NULL) {
        printf("%.2f ", p->elemento);
        p = p->prox;
    }

    printf("\n");

    return 1;
}

Conjunto *cr_uniao(Conjunto *A, Conjunto *B) {
    if (A == NULL || B == NULL) {
        return NULL;
    }

    Conjunto *uniao = cr_criar();

    if (uniao == NULL) {
        return NULL;
    }

    No *p = NULL;

    p = A->ini;
    while (p != NULL) {
        cr_inserir(uniao, p->elemento);
        p = p->prox;
    }

    p = B->ini;
    while (p != NULL) {
        cr_inserir(uniao, p->elemento);
        p = p->prox;
    }

    return uniao;
}

Conjunto *cr_interseccao(Conjunto *A, Conjunto *B) {
    if (A == NULL || B == NULL) {
        return NULL;
    }

    Conjunto *interceccao = cr_criar();

    if (interceccao == NULL) {
        return NULL;
    }

    for (No *i = A->ini; i != NULL; i = i->prox) {
        for (No *j = B->ini; j != NULL; j = j->prox) {
            if (i->elemento == j->elemento) {
                cr_inserir(interceccao, i->elemento);
            }
        }
    }

    return interceccao;
}

int cr_pertence(Conjunto *conjunto, float elem) {
    if (conjunto == NULL) {
        return 0;
    }

    No *p = conjunto->ini;
    while (p != NULL) {
        if (p->elemento == elem) {
            return 1;
        }

        p = p->prox;
    }

    return 0;
}

int cr_iguais(Conjunto *A, Conjunto *B) {
    if (A == NULL || B == NULL) {
        return -1;
    }

    for (No *i = A->ini; i != NULL; i = i->prox) {
        for (No *j = B->ini; j != NULL; j = j->prox) {
            if (i->elemento != j->elemento) {
                return 0;
            }
        }
    }

    return 1;
}

int cr_tamanho(Conjunto *conjunto) {
    if (conjunto == NULL) {
        return -1;
    }

    int cont = 0;
    No *p = conjunto->ini;
    while (p != NULL) {
        cont++;
        p = p->prox;
    }

    return cont;
}

int cr_is_vazio(Conjunto *conjunto) {
    if (conjunto == NULL) {
        return 1;
    }

    if (cr_tamanho(conjunto) != 0) {
        return 0;
    }

    return 1;
}
     