#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no No;

struct no {
    Elem elem;
    No *prox;
};

struct lista {
    No *ini, *fim;
};

Lista *ll_criar(Elem elem) {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    No *no = (No *) malloc(sizeof(No));

    if (lista == NULL || no == NULL) {
        return NULL;
    }

    no->elem = elem;
    no->prox = NULL;

    lista->ini = no;
    lista->fim = no;
    lista->fim->prox = NULL;

    return lista;
}

int ll_liberar(Lista *lista) {
    if (lista == NULL || lista->ini == NULL) {
        return 0;
    }

    No *p = lista->ini;
    while (p != NULL) {
        lista->ini = lista->ini->prox;
        free(p);
        p = lista->ini;
    }

    free(lista);

    return 1;
}

void ll_imprimir(Lista *lista) {
    No *p = lista->ini;

    while(p != NULL) {
        printf("%.2f ", p->elem);
        p = p->prox;
    }

    printf("\n");
}

int ll_tamanho(Lista *lista) {
    if (lista == NULL) {
        return -1;
    }

    No *p = lista->ini;
    int cont = 0;
    
    while (p != NULL) {
        cont++;
        p = p->prox;
    }

    return cont;
}

int ll_inserir_fim(Lista *lista, Elem elem) {
    if (lista == NULL) {
        return 0;
    }

    No *novoNo = (No *) malloc(sizeof(No));
    
    if (novoNo == NULL) {
        return 0;
    }

    novoNo->elem = elem;
    novoNo->prox = NULL;

    lista->fim->prox = novoNo;
    lista->fim = novoNo;

    return 1;
}

int ll_inserir_inicio(Lista *lista, Elem elem) {
    No *novoNo = (No *) malloc(sizeof(No));

    if (lista == NULL || novoNo == NULL) {
        return 0;
    }

    novoNo->elem = elem;
    novoNo->prox = lista->ini;
    lista->ini = novoNo;
    
    return 1;
}

int ll_ordenar(Lista *lista, TipoOrdenacao tipo) {
    if (lista == NULL) {
        return 0;
    }

    int aux;
    if (tipo == ll_asc) {
        for (No *i = lista->ini; i->prox != NULL; i = i->prox) {
            for (No *j = i->prox; j != NULL; j = j->prox) {
                if (i->elem > j->elem) {
                    aux = j->elem;
                    j->elem = i->elem;
                    i->elem = aux;
                }
            }
        }
    } else if (tipo == ll_desc) {
        for (No *i = lista->ini; i->prox != NULL; i = i->prox) {
            for (No *j = i->prox; j != NULL; j = j->prox) {
                if (i->elem < j->elem) {
                    aux = j->elem;
                    j->elem = i->elem;
                    i->elem = aux;
                }
            }
        }
    }
}

int ll_remover(Lista *lista, Elem elem) {
    if (lista == NULL) {
        return 0;
    }

    No *p = lista->ini;
    No *ant = NULL;
    
    while(p != NULL) {
        if (p->elem == elem) { // verifica se o elemento passado eh igual ao elemento da lista
            if (p == lista->ini) { // verifica se o elemento encontrado esta no inicio da lista
                lista->ini = lista->ini->prox; // o inicio da lista eh atualizado com o proximo elemento
                free(p); // o elemento eh liberado da memoria
            } else if (p == lista->fim) { // verifica se o elemento encontrado esta no fim da lista
                lista->fim = ant; // atualiza o fim da lista para o elemento ant
                lista->fim->prox = NULL; // atualiza o fim da lista prox para NULL
                free(p); // libera o elemento que esta no fim da memoria
            } else { // caso o elemento nao esteja nem no fim e nem no inicio o mesmo se encontra em alguma posicao no meio da lista
                ant->prox = p->prox; // atualiza o ant proximo para receber o proximo elemento da lista, nao quebrando a continuidade da lista
                free(p); // libera o elemento no meio da lista
            }
            return 1; // retorna 1 indicando sucesso na remocao do elemento
        } else { // caso o elemento nao seja igual sao atualizados os ponteiros auxiliares ant e p
            ant = p;
            p = p->prox;
        }
    }

    return 0; // retorna 0 indicando falha na remocao do elemento
}

int ll_eh_vazia(Lista *lista) {
    if (lista == NULL) {
        return 0;
    }

    if (ll_tamanho(lista) != 0) {
        return 0;
    }

    return 1;
}

int ll_pertence(Lista *lista, Elem elem) {
    if (lista == NULL) {
        return 0;
    }

    No *p = lista->ini;

    while (p != NULL) {
        if (p->elem == elem) {
            return 1;
        }
        
        p = p->prox;
    }

    return 0;
}

int ll_inserir_ordenado(Lista *lista, Elem elem) {
    if (lista == NULL) {
        return 0;
    }

    if (ll_eh_vazia(lista)) {
        ll_inserir_inicio(lista, elem);
        
        return 1;
    }

    No *novo = (No *) malloc(sizeof(No));
    
    if (novo == NULL) {
        return 0;
    }
    
    novo->elem = elem;
    No *ant = NULL;
    No *p = lista->ini;
    
    while (p != NULL && p->elem < elem) {
        ant = p;
        p = p->prox;
    }
    
    if (p == lista->ini) {
        novo->prox = lista->ini;
        lista->ini = novo;
    
        return 1;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    
    return 1;
}
