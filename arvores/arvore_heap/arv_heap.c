#include <stdio.h>
#include <stdlib.h>
#include "arv_heap.h"

struct no {
    int elem;
    int prio;
};

struct arv {
    int n;
    no_t *heap[MAX];
};

void sobe(arv_heap_t *arv, int i) {
    int j;
    no_t *temp;

    j = (int) ((i - 1) / 2);

    if (j >= 0 && arv->heap[i]->prio > arv->heap[j]->prio) {
        temp = arv->heap[i];
        arv->heap[i] = arv->heap[j];
        arv->heap[j] = temp;
        sobe(arv, j);
    }

}

void desce(arv_heap_t *arv, int i) {
    int j;
    no_t *temp;

    j = (2 * i) + 1;

    if (j < arv->n) {
        if (j < (arv->n - 1)) {
            if (arv->heap[j]->prio < arv->heap[j + 1]->prio) {
                j++;
            }
        }
    }

    if (arv->heap[j]->prio > arv->heap[i]->prio) {
        temp = arv->heap[i];
        arv->heap[i] = arv->heap[j];
        arv->heap[j] = temp;

        desce(arv, j);
    }

}

arv_heap_t *arv_cria(void) {
    arv_heap_t *a = (arv_heap_t *) malloc(sizeof(arv_heap_t));

    if (a == NULL) return NULL;

    a->n = 0;

    return a;
}

int arv_insere(arv_heap_t *a, int elem, int prio) {
    if (!arv_cheia(a)) {
        no_t *p = (no_t *) malloc(sizeof(no_t));
        p->elem = elem;
        p->prio = prio;
        a->heap[a->n] = p;
        sobe(a, a->n);
        a->n++;

        return 1;
    }
    
    return 0;
}

int arv_remove(arv_heap_t *a, int *elem) {    
    if (!arv_vazia(a)) {
        *elem = a->heap[0]->elem;
        free(a->heap[0]);
        a->n--;
        a->heap[0] = a->heap[a->n];
        desce(a, 0);


        return 1;
    }

    return 0;
}

int arv_vazia(arv_heap_t *a) {
    if (a == NULL) return -1;

    return a->n == 0;
}

int arv_cheia(arv_heap_t *a) {
    if (a == NULL) return -1;

    return a->n == MAX;
}

void arv_libera(arv_heap_t *a) {
    if (a != NULL) {
        for (int i = 0; i < a->n; i++) {
            free(a->heap[i]);
        }
    
        free(a);
    }
}
