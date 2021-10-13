#ifndef _FILA_LISTA_ENCADEADA_H
#define _FILA_LISTA_ENCADEADA_H

typedef struct fila fila_t;

fila_t *f_cria(void);
int f_libera(fila_t *f);

int f_insere(fila_t *f, int elem);
int f_remove(fila_t *f, int *elem);

int f_is_empty(fila_t *f);
int f_size(fila_t *f);

#endif
