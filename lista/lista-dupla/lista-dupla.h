#ifndef LISTA_DUPLA
#define LISTA_DUPLA

typedef struct ld ListaDupla;

ListaDupla *ld_criar();
int ld_liberar(ListaDupla *ld);

int ld_inserir_ordenado(ListaDupla *ld, int elem);
int ld_inserir_inicio(ListaDupla *ld, int elem);
int ld_inserir_fim(ListaDupla *ld, int elem);
int ld_remover(ListaDupla *ld, int elem);

int ld_eh_vazia(ListaDupla *ld);
int ld_tamanho(ListaDupla *ld);

int ld_imprimir(ListaDupla *ld);
int ld_imprimir_inverso(ListaDupla *ld);

#endif
