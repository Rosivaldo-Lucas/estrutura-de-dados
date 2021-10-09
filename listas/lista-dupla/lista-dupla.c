#include <stdio.h>
#include <stdlib.h>
#include "lista-dupla.h"

typedef struct no No;

struct no {
    int elem;
    No *ant, *prox;
};

struct ld {
    No *ini, *fim;
};

ListaDupla *ld_criar() {
    ListaDupla *ld = (ListaDupla *) malloc(sizeof(ListaDupla));

    if (ld == NULL) {
        return NULL;
    }

    ld->ini = NULL;
    ld->fim = NULL;

    return ld;
}

No *ld_buscar(ListaDupla *ld, int elem) {
    if (ld == NULL || ld->ini == NULL) {
        return NULL;
    }

    No *p = NULL;

    for (p = ld->ini; p != NULL; p = p->prox) {
        if (p->elem == elem) {
            return p;
        }
    }

    return NULL;
}

int ld_liberar(ListaDupla *ld) {
    if (ld == NULL) {
        return 0;
    }

    if (ld->ini == NULL) {
        free(ld);
        return 1;
    }

    No *p = ld->ini;

    while (p != NULL) {
        ld->ini = p->prox;
        free(p);
        p = ld->ini;
    }

    free(ld);

    return 1;
}

int ld_inserir_ordenado(ListaDupla *ld, int elem) {
    if (ld == NULL) {
        return 0;
    }

    No *novo = (No *) malloc(sizeof(No));
    novo->elem = elem;
    novo->ant = NULL;
    novo->prox = NULL;

    No *p = ld->ini;
    No *ant = NULL;

    while (p != NULL && p->elem < elem) {
        ant = p;
        p = p->prox;
    }

    // caso onde elem ja existe
    if (p != NULL && elem == p->elem) {
        free(novo);
        return 0;
    }

    if (ant == NULL) { // lista vazia ou lista com elementos
        novo->prox = ld->ini;
        if (ld->ini != NULL) {
            ld->ini->ant = novo;
        }
        ld->ini = novo;
    } else { // no meio ou no fim da lista
        novo->prox = ant->prox;
        ant->prox = novo;
        if (novo->prox != NULL) {
            novo->prox->ant = novo;
        } else {
            ld->fim = novo;
        }
        novo->ant = ant;
    }

    return 1;
}

int ld_inserir_inicio(ListaDupla *ld, int elem) {
    if (ld == NULL) {
        return 0;
    }

    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->elem = elem;
    novo->ant = NULL;
    novo->prox = NULL;

    if (ld->ini == NULL && ld->fim == NULL) {
        ld->fim = novo;
    } else {
        ld->ini->ant = novo;
        novo->prox = ld->ini;
    }

    ld->ini = novo; // seta o inicio da lista para o novo primeiro elem

    return 1;
}

int ld_inserir_fim(ListaDupla *ld, int elem) {
    if (ld == NULL) {
        return 0;
    }

    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->elem = elem;
    novo->ant = NULL;
    novo->prox = NULL;

    if (ld->ini == NULL && ld->fim == NULL) {
        ld->ini = novo;
        ld->fim = novo;
    } else {
        ld->fim->prox = novo;
        novo->ant = ld->fim;
    }

    ld->fim = novo; // atualiza o novo ultimo elemento

    return 1;
}

int ld_imprimir(ListaDupla *ld) {
    if (ld == NULL || ld->ini == NULL) {
        return 0;
    }

    No *p = ld->ini;

    while (p != NULL) {
        printf("%d ", p->elem);
        p = p->prox;
    }

    printf("\n");

    return 1;
}

int ld_inserir_lista_vazia(ListaDupla *ld, int elem) {
    if (ld == NULL || ld->ini != NULL) {
        return 0;
    }

    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->elem = elem;
    novo->ant = NULL;
    novo->prox = NULL;

    ld->ini = novo;

    return 1;
}

int ld_remover(ListaDupla *ld, int elem) {
    if (ld == NULL || ld->ini == NULL) {
        return 0;
    }

    No *p = ld_buscar(ld, elem);

    if (p == ld->ini) { // primeiro elemento
        ld->ini = p->prox;
        ld->ini->ant = NULL;
        free(p);
    } else if (p == ld->fim) { // ultimo elemento
        ld->fim = p->ant;
        ld->fim->prox = NULL;
        free(p);
    } else { // elemento do meio
        No *aux_ant = NULL, *aux_prox = NULL;

        aux_ant = p->ant;
        aux_prox = p->prox;

        aux_ant->prox = aux_prox;
        aux_prox->ant = aux_ant;

        free(p);
    }

    // No *p = ld->ini;
    // No *ant = NULL;

    // while (p != NULL && elem > p->elem) {
    //     ant = p;
    //     p = p->prox;
    // }

    // if (p == NULL) {
    //     return 0;
    // }

    // if (ant == NULL) {
    //     ld->ini = ld->ini->prox;
    //     if (ld->ini != NULL) {
    //         ld->ini->ant == NULL;
    //     } else {
    //         ld->fim = NULL;
    //     }
    //     free(p);
    // } else { // remocao no meio ou fim
    //     if (p->prox == NULL) {
    //         ld->fim = p->ant;
    //         ant->prox = NULL;
    //         free(p);
    //     } else { // remover do meio
    //         ant->prox = p->prox;
    //         p->prox->ant = ant;
    //         free(p);
    //     }
    // }

    // return 1;
}

int ld_eh_vazia(ListaDupla *ld) {
    if (ld == NULL) {
        return -1;
    }

    if (ld->ini != NULL && ld->fim != NULL) {
        return 0;
    }

    return 1;
}

int ld_tamanho(ListaDupla *ld) {
    if (ld == NULL) {
        return -1;
    }

    No *p = ld->ini;
    int cont = 0;

    while (p != NULL) {
        cont += 1;
        p = p->prox;
    }

    return cont;
}

int ld_imprimir_inverso(ListaDupla *ld) {
    if (ld == NULL || ld->ini == NULL) {
        return 0;
    }

    No *p = ld->fim;

    do {
        printf("%d ", p->elem);
        p = p->ant;
    } while (p != NULL);

    printf("\n");
}
