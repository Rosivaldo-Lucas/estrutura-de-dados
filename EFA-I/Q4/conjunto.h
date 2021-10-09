#ifndef CONJUNTO_REAIS
#define CONJUNTO_REAIS

typedef struct conjunto Conjunto;

/**
 * Funcao responsavel pela criacao de um novo conjunto.
 * 
 * @return caso a criacao do conjunto seja realizada com sucesso eh retornado um conjunto vazio,
 *         caso contrario eh retornado o ponteiro NULL
 * **/
Conjunto *cr_criar();

/**
 * Funcao responsavel pela liberacao do conjunto e seus elementos.
 * 
 * @param (*conjunto) conjunto a ser liberado da memoria
 * @return caso a liberacao seja realizada com sucesso eh retornado (1),
 *         caso contrario eh retornado (0).
 * **/
int cr_liberar(Conjunto *conjunto);

/**
 * Funcao responsavel pela insercao de um elemento no conjunto. Caso o elemento passado
 * como parametro ja pertenca ao conjunto o mesmo nao sera adicionado.
 * 
 * @param (conjunto) conjunto a receber o elemento
 * @param (elem) novo elemento do conjunto
 * @return caso o elemento seja adicionado com sucesso eh retornado (1),
 *         caso contrario eh retornado (0).
 * **/
int cr_inserir(Conjunto *conjunto, float elem);

/**
 * Funcao responsavel pela remocao de um determinado elemento do conjunto.
 * 
 * @param (*conjunto) conjunto a ter o elmento removido
 * @param (elem) elemento a ser removido do conjunto
 * @return caso o elemento seja removido com sucesso eh retornado (1),
 *         caso contrario eh retornado (0).
 * **/
int cr_remover(Conjunto *conjunto, float elem);

/**
 * Funcao responsavel pela impressao dos elementos do conjunto na tela.
 * 
 * @param (*conjunto) conjunto a ter os elementos impressos na tela
 * @return caso os elemento sejam impressos com sucesso eh retornado (1),
 *         caso contrario eh retornado (0).
 * **/
int cr_imprime(Conjunto *conjunto);

/**
 * Funcao responsavel por realizar a uniao de dois conjuntos e retornar o conjunto uniao.
 * 
 * @param (*A) conjunto A
 * @param (*B) conjunto B
 * @return (*uniao) conjunto uniao entre os dois conjuntos passados,
 *         caso ocorra algum problema na unicao eh retornado o ponteiro NULL.
 * **/
Conjunto *cr_uniao(Conjunto *A, Conjunto *B);

/**
 * Funcao responsavel por realizar a interseccao de dois conjuntos e retornar o conjunto uniao.
 * 
 * @param (*A) conjunto A
 * @param (*B) conjunto B
 * @return (*interseccao) conjunto interseccao entre os dois conjuntos passados,
 *         caso ocorra algum problema na interseccao eh retornado o ponteiro NULL.
 * **/
Conjunto *cr_interseccao(Conjunto *A, Conjunto *B);

/**
 * Funcao responsavel por verificar se um elemento pertence ao conjunto.
 * 
 * @param (*conjunto) conjunto a ter o elemento verificado
 * @param (elem) elemento a ser verificado no conjunto
 * @return caso o elemento pertenca ao conjunto eh retornado (1),
 *         caso contrario eh retornado (0).
 * **/
int cr_pertence(Conjunto *conjunto, float elem);

/**
 * Funcao responsavel por verificar se dois conjuntos sao iguais.
 * 
 * @param (*A) conjunto A
 * @param (*B) conjunto B
 * @return caso os conjuntos sejam iguais eh retornado (1),
 *         caso contrario eh retornado (0).
 * **/
int cr_iguais(Conjunto *A, Conjunto *B);

/**
 * Funcao responsavel por retornar o tamanho atual do conjunto.
 * 
 * @param (*conjunto) conjunto a ter o tamanho informado
 * @return caso o conjunto seja valido eh retornado o seu tamanho,
 *         caso contrario eh retornado (-1).
 * **/
int cr_tamanho(Conjunto *conjunto);

/**
 * Funcao responsavel por verificar se um conjunto eh vazio.
 * 
 * @param (*conjunto) conjunto a ser verificado
 * @return caso o conjunto seja vazio eh retornado (1),
 *         caso contrario eh retornado (0).
 * **/
int cr_is_vazio(Conjunto *conjunto);

#endif
