#ifndef LISTA_H
#define LISTA_H

typedef int elem;
typedef struct lista Lista;

Lista *criar();
void liberar(Lista *lista);
void inserir(Lista *lista, elem e);
int tamanho(Lista *lista);
void imprimir(Lista *lista);
int esta_na_lista(Lista *lista, elem e);
int remover(Lista *lista, elem e);

#endif
