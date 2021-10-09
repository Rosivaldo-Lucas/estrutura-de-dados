#ifndef _PILHA_
#define _PILHA_

typedef struct pilha Pilha;

Pilha *p_criar(void);
void p_push(Pilha *p, float elem);
float p_pop(Pilha *p);
int p_vazia(Pilha *p);
void p_liberar(Pilha *p);

#endif
