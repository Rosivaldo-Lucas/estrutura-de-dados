#ifndef _ARVORE_BINARIA_H
#define _ARVORE_BINARIA_H

typedef struct arvore arvore_t;
typedef struct no no_t;

arvore_t *arv_cria(void);
no_t *arv_insere_no(no_t *esq, no_t *dir, char elem);
void arv_libera(arvore_t *a);
void arv_imprime(arvore_t *a);
int arv_pertence(arvore_t *a, char elem);
no_t *arv_busca(arvore_t *a, char elem);

#endif
