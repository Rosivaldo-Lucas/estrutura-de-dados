#ifndef _PILHA_LISTA_H
#define _PILHA_LISTA_H

typedef struct pilha pilha_t;

/**
 * Funcao responsavel pela criacao da estrutura pilha.
 * 
 * @return retorna um ponteiro para a pilha se tudo ocorreu com sucesso,
 *         retorna NULL se nao foi possivel realizar a criacao da pilha.
 * */
pilha_t *p_cria();

/**
 * Funcao responsavel pela liberacao da memoria alocada pela pilha.
 * 
 * @return retorna 0 se a pilha for NULL,
 *         retorna 1 se a liberacao dos elementos da pilha e a pilha foram liberados com sucesso.
 * */
int p_libera(pilha_t *p);

/**
 * Funcao responsavel pela insercao de um novo elemento no topo da pilha.
 * 
 * @param *p (pilha_t) - pilha que ira receber o novo elemento
 * @param elem (char) - elemento a ser inserido no topo da pilha
 * 
 * @return retorna 0 se ocorreu algum erro na insercao do elemento,
 *         retorna 1 se a insercao do elemento ocorreu com sucesso.
 * */
int p_empilha(pilha_t *p, char elem);

/**
 * Funcao responsavel pela remocao do elemento que esteja no topo da pilha.
 * 
 * @param p (pilha_t *) - pilha com os elementos
 * @param elem (char *) - elemento a ser removido do topo da pilha
 * 
 * @return retorna 0 se ocorreu algum erro na remocao do elemento,
 *         retorna 1 se a remocao do elemento ocorreu com sucesso,
 *         o elemento removido eh retornado pelo ponteiro *elem passado como parametro.
 * */
int p_desempilha(pilha_t *p, char *elem);

/**
 * Funcao responsavel por retornar o tamanho atual da pilha.
 * 
 * @param *p (pilha_t) - pilha que ira ter seu tamanho calculado
 * 
 * @return retorna -1 se ocorreu algum erro,
 *         retorna um int com o tamanho da pilha se tudo ocorreu com sucesso.
 * */
int p_tamanho(pilha_t *p);

/**
 * Funcao responsavel por verificar se a pilha esta vazia.
 * 
 * @param *p (pilha_t) - pilha que ira ser verificada
 * 
 * @return retorna -1 se ocorreu algum erro na verificacao da pilha,
 *         retorna 0 se a pilha nao esta vazia
 *         retorna 1 se a pilha esta vazia.
 * */
int p_vazia(pilha_t *p);

#endif
