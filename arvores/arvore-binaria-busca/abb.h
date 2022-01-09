#ifndef _ABB_H
#define _ABB_H

typedef int chave;
typedef struct no no_t;
typedef struct abb abb_t;

abb_t *abb_cria();
void abb_libera(abb_t *abb);
int abb_insere(abb_t *abb, chave c);
int abb_remove(abb_t *abb, chave c);
no_t *abb_busca(abb_t *abb, chave c);
int abb_qtd_folha(abb_t *abb);
void abb_mostra(abb_t *abb);

#endif
