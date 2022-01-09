#ifndef _ARVB_VETOR_H
#define _ARVB_VETOR_H

#define MAX 100

typedef struct no no_t;
typedef struct arv arv_t;

arv_t arv_cria(void);
int arv_insere(arv_t *a, int elem);
void arv_libera();
void arv_imprime(arv_t *a);

#endif
