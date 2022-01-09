#ifndef _ARVORE_BINARIA_H
#define _ARVORE_BINARIA_H

typedef struct no no;

typedef struct arvore {
    no *raiz;
} arvore_t;

arvore_t *ab_cria();
int ab_vazia(arvore_t *a);
void ab_libera(no *raiz);
void ab_imprime(no *raiz);
int ab_altura(no *raiz);
no *ab_buscar(no *raiz, int elem);
no *ab_busca_pai(no *raiz, int elem);
int ab_insere_esq(arvore_t *a, int elem, int pai);
int ab_insere_dir(arvore_t *a, int elem, int pai);
int ab_remove(arvore_t *a, int elem);

void pre_ordem(no *raiz);
void em_ordem(no *raiz);
void pos_ordem(no *raiz);

#endif
