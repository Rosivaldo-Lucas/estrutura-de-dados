#ifndef LISTA_SIMPLESMENTE_ENCADEADA
#define LISTA_SIMPLESMENTE_ENCADEADA

typedef float Elem;
typedef struct lista Lista;

/**
 * Struct que contem o tipo de ordenacao que a lista suporta.
 * **/
typedef enum tipoOrdenacao {
    ll_asc = 0,
    ll_desc = 1
} TipoOrdenacao;

/** 
 *  Funcao responsavel pela criacao de uma lista e inserir na lista o elemento passado como parametro.
 *  
 *  @param (elem) - elemento inicial da lista
 *  @return caso tudo ocorra bem eh retornado a lista com o elemento inserido,
 *          caso a alocacao tenha dado algum erro eh retornado o ponteiro NULL.
 * **/
Lista *ll_criar(Elem elem);

/** 
 *  Funcao responsavel pela liberacao da lista e seus elementos alocados dinamicamente.
 * 
 *  @param (*lista) - lista com os elementos
 *  @return caso tudo ocorra bem eh retornado (1),
 *          caso tenha dado algum erro eh retornado (0).
 * **/
int ll_liberar(Lista *lista);

/** 
 *  Funcao responsavel por imprimir os elementos da lista.
 *  
 *  @param (*lista) - lista com os elementos
 * **/
void ll_imprimir(Lista *lista);

/** 
 *  Funcao responsavel por retornar o tamanho da lista.
 *  
 *  @param (*lista) - lista com os elementos 
 *  @return caso tudo ocorra bem eh retornado o tamanho da lista,
 *          caso tenha dado algum erro eh retornado (-1).
 * **/
int ll_tamanho(Lista *lista);

/** 
 *  Funcao responsavel por inserir um elemento no fim da lista.
 * 
 *  @param (*lista) - lista com os elementos
 *  @param (elem) - elemento a ser inserido na lista
 *  @return caso tudo ocorra bem eh retornado (1),
 *          caso tenha dado algum erro eh retornado (0).
 * **/
int ll_inserir_fim(Lista *lista, Elem elem);

/** 
 *  Funcao responsavel por inserir um elemento no inicio da lista.
 *  
 *  @param (*lista) - lista com os elementos
 *  @param (elem) - elemento a ser inserido na lista
 *  @return caso tudo ocorra bem eh retornado (1),
 *          caso tenha dado algum erro eh retornado (0).
 * **/
int ll_inserir_inicio(Lista *lista, Elem elem);

/** 
 *  Funcao responsavel por ordenar os elementos da lista.
 *  
 *  @param (*lista) - lista com os elemetos
 *  @param (tipo) - tipo de ordenacao (asc ou desc)
 *  @return caso tudo ocorra bem eh retornado (1),
 *          caso tenha dado algum erro eh retornado (0).
 * **/
int ll_ordenar(Lista *lista, TipoOrdenacao tipo);

/** 
 *  Funcao responsavel pela remocao de um elemento na lista.
 *  
 *  @param (*lista) - lista com os elemetos
 *  @param (elem) - elemento a ser removido da lista
 *  @return caso tudo ocorra bem eh retornado (1),
 *          caso tenha dado algum erro eh retornado (0).
 * **/
int ll_remover(Lista *lista, Elem elem);

/** 
 *  Funcao responsavel por verificar se a lista esta vazia.
 *  
 *  @param (*lista) - lista com os elemetos
 *  @return caso tudo ocorra bem eh retornado (1) indicando que a lista esta vazia,
 *          caso contrario eh retornado (0) indicando que a lista nao esta vazia.
 * **/
int ll_eh_vazia(Lista *lista);

/** 
 *  Funcao responsavel pela verificacao se um dado elemeto pertence a lista.
 *  
 *  @param (*lista) - lista com os elemetos
 *  @param (elem) - elemento a ser pesquisado na lista
 *  @return caso tudo ocorra bem eh retornado (1) indicando que o elemento pertence a lista,
 *          caso contrario eh retornado (0) indicando que o elemento nao pertence a lista.
 * **/
int ll_pertence(Lista *lista, Elem elem);

/** 
 *  Funcao responsavel por inserir um elemento de forma ordenada na lista.
 *  
 *  @param (*lista) - lista a receber o novo elemento
 *  @param (elem) - elemento a ser inserido na lista
 *  @return caso tudo ocorra bem eh retornado (1) indicando que o elemento foi inserido,
 *          caso contrario eh retornado (0) indicando que o elemento nao foi inserido.
 * **/
int ll_inserir_ordenado(Lista *lista, Elem elem);

#endif
