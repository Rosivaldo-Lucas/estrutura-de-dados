#ifndef _FILA_LISTA_DUPLA_H
#define _FILA_LISTA_DUPLA_H

typedef struct fila fila_t;

fila_t *f_cria(void);
int f_libera(fila_t *f);

int f_insere(fila_t *f, char elem);
int f_remove(fila_t *f, char *elem);

int f_vazia(fila_t *f);
int f_tamanho(fila_t *f);

#endif
