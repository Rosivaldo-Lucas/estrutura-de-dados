#ifndef _ARVORE_AVL_H
#define _ARVORE_AVL_H

typedef struct no no_t;
typedef struct arv arv_t;

arv_t *arv_cria(void);
void arv_libera(arv_t *a);
void arv_imprime(arv_t *a);

no_t *arv_insere(arv_t *a, char elem);
no_t *arv_busca(arv_t *a, char elem);
int arv_pertence(arv_t *a, char elem);

#endif
