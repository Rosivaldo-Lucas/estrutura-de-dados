#ifndef _FILA_VET_ESTATICO_
#define _FILA_VET_ESTATICO_

typedef struct fila fila_t;

fila_t *f_cria(void);
void f_destruir(fila_t *f);

int f_inserir(fila_t *f, int elem);
int f_remover(fila_t *f, int *elem);

int f_is_empty(fila_t *f);
int f_is_full(fila_t *f);

#endif
