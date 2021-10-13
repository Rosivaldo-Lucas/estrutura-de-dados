#ifndef _FILA_
#define _FILA_

typedef struct fila Fila;

Fila *f_cria(void);
void f_libera(Fila *f);

int f_insere(Fila *f, float elem);
float f_retira(Fila *f);
int f_vazia(Fila *f);

#endif
