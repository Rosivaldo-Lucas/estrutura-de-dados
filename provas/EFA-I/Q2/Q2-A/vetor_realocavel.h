#ifndef VETOR_REALOCALVEL
#define VETOR_REALOCAVEL

typedef int Elemento;
typedef struct vetor VetorDinamico;

/** Funcao responsavel pela criacao do vetor dinamico. Na criacao eh alocado um tamanho maximo de
 *  10 elementos iniciais, mas a medida que se fizer necessario o uso de um tamanho maior sera
 *  alocado mais espaco automaticamente.
 *  
 *  @return caso tudo ocorra bem eh retornado o ponteiro para o primeiro indice do vetor,
 *          caso a alocacao tenha dado algum erro eh retornado o ponteiro NULL.
 * **/
VetorDinamico *vd_criar();

/** Funcao responsavel pela insercao de um novo elemento no vetor.
 *  
 *  @param (*vetorDinamico) - ponteiro para o vetor que ira receber o elemento passado como parametro
 *  @param (elemento) - elemento a ser inserido no vetor
 *  @return caso tudo ocorra bem eh retornado o inteiro 1,
 *          caso tenha ocorrido algum erro eh retornado o inteiro 0.
 * **/
int vd_inserir(VetorDinamico *vetorDinamico, Elemento elemento);

/** Funcao responsavel por acessar um determinado elemento no vetor.
 *  
 *  @param (*vetorDinamico) - ponteiro para o vetor que ira ter seu elemento acessado
 *  @param (i) - indice do elemento a ser acessado
 *  @param (*elemento) - contem o elemento acessado no indice informado
 *  @return caso tudo ocorra bem eh retornado o inteiro 1,
 *          caso tenha ocorrido algum erro eh retornado o inteiro 0.
 * **/
int vd_acessar_elemento(VetorDinamico *vetorDinamico, int i, Elemento *elemento);

/** Funcao responsavel por retornar o tamanho atual do vetor.
 *  
 *  @param (*vetorDinamico) - ponteiro para o vetor que ira ter seu tamanho retornado
 *  @return caso tudo ocorra bem eh retornado o inteiro com o tamanho do vetor,
 *          caso tenha ocorrido algum erro eh retornado um inteiro menor do que zero (exemplo -1).
 * **/
int vd_tamanho(VetorDinamico *vetorDinamico);

/** Funcao responsavel por liberar toda a memoria alocada pelo vetor.
 *  
 *  @param (*vetorDinamico) - ponteiro para o vetor que ira ter seu tamanho retornado
 *  @return caso tudo ocorra bem eh retornado o inteiro 1,
 *          caso tenha ocorrido algum erro eh retornado um inteiro menor do que zero (exemplo -1).
 * **/
int vd_liberar(VetorDinamico *vetorDinamico);

/** Funcao responsavel por imprimir na tela todos os dados armazenados pelo vetor.
 *  
 *  @param (*vetorDinamico) - ponteiro para o vetor que ira ser impresso na tela
 * **/
void vd_imprimir(VetorDinamico *vetorDinamico);

#endif
