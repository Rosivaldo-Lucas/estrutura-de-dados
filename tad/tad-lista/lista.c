#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

typedef struct no No;

struct no {
    elem info;
    No *prox;
};

struct lista {
    No *ini, *fim;
    int tam;
};

Lista *criar() {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    if (lista == NULL) {
        return NULL;
    }

    lista->ini = NULL;
    lista->fim = NULL;
    lista->tam = 0;

    return lista;
}

void liberar(Lista *lista) {
    No *p = lista->ini;

    while(p != NULL) {
        lista->ini = p->prox;
        free(p);
        p = lista->ini;
    }

    free(lista);
}

void inserir(Lista *lista, elem e) {

    No *novoNo = (No *) malloc(sizeof(No));
    novoNo->info = e;
    novoNo->prox = NULL;

    // 1o. caso: lista vazia
    if (lista->ini == NULL) {
        lista->ini = novoNo;
        // lista->fim = novoNo;
    } else { // 2o. caso: lista com pelomenos um elemento
        lista->fim->prox = novoNo;
        // lista->fim = novoNo;
    }

    lista->fim = novoNo;
    lista->tam++;
}

int tamanho(Lista *lista) {
    if (lista == NULL) {
        return 0;
    }

    return lista->tam;
}

void imprimir(Lista *lista) {

    No *p = lista->ini;

    while(p != NULL) {
        printf("%d ", p->info);
        p = p->prox;
    }

    printf("\n");

}

int esta_na_lista(Lista *lista, elem e) {

    No *p = NULL;

    for (p = lista->ini; p->prox != NULL; p = p->prox) {
        if (p->info == e) {
            return 1;
        }
    }

    return 0;
}

int remover(Lista *lista, elem e) {
    No *ant = NULL;
    No *p = lista->ini;

    while(p != NULL) {
        if (p->info == e) {
            if (p == lista->ini) { // ou ant == NULL
                lista->ini = lista->ini->prox;
                free(p);
            } else if (p == lista->fim) {
                lista->fim = ant;
                lista->fim->prox = NULL;
                free(p);
            } else {
                ant->prox = p->prox;
                free(p);
            }

            lista->tam--;
            
            return 1;
        } else {
            ant = p;
            p = p->prox;
        }
    }

    return 0;
}
