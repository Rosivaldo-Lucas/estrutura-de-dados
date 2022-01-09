#ifndef _ARVORE_BINARIA_BUSCA_H
#define _ARVORE_BINARIA_BUSCA_H

typedef struct no {
    char elem;
    struct no *esq, *dir;
} no_t;

typedef struct {
    no_t *raiz;
} abb_t;

abb_t *abb_cria(void);
int abb_vazia(abb_t *a);
void abb_libera(no_t *r);
void abb_imprime(no_t *r);
int abb_altura(no_t *r);
no_t *abb_busca(no_t *r, char elem);

#endif
