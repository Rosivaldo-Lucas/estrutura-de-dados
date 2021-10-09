#ifndef LISTA_CIRCULAR
#define LISTA_CIRCULAR

typedef struct lc ListaCircular;

ListaCircular *lc_criar();
int lc_liberar(ListaCircular *lc);

int lc_inserir_inicio(ListaCircular *lc, int elem);
int lc_inserir_fim(ListaCircular *lc, int elem);
int lc_tamanho(ListaCircular *lc);

int lc_imprimir(ListaCircular *lc);

#endif
