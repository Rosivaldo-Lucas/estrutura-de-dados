#ifndef _ARV_HEAP_H
#define _ARV_HEAP_H

#define MAX 100

typedef struct no no_t;
typedef struct arv arv_heap_t;

arv_heap_t *arv_cria(void);
int arv_insere(arv_heap_t *a, int elem, int prio);
int arv_remove(arv_heap_t *a, int *elem);
int arv_vazia(arv_heap_t *a);
int arv_cheia(arv_heap_t *a);
void arv_libera(arv_heap_t *a);

#endif
