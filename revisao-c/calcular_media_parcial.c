/**
    programa que realiza o calcula da media de 3 nota do usuario e verifica se foi APROVADO ou
    ficou em RECUPERACAO e mostra quanto eh necessario o aluno tirar na 4 prova para ser APROVADO
    com media 7.

    @version v0.0.1 Agosto/2021
    @author LUCAS, Rosivaldo
**/
#include <stdio.h>

#define TAMANHO_VETOR_NOTAS 3

/**
    funcao responsavel pela realizacao do calcula da media das notas passadas.

    @param notas[] - (float) vetor contendo as notas
    @param tamanho - (int) parametro com o tamanho do vetor
    @return (float) - retorna a media das notas
**/
float calcular_media(float notas[], int tamanho) {
    int i;
    
    float soma_notas = 0;

    if (tamanho == 0) {
        return 0;
    }

    for (i = 0; i < tamanho; i++) {
        soma_notas = soma_notas + notas[i];
    }

    float media_notas = soma_notas / tamanho;

    return media_notas;
}

/**
    funcao que calcula quanto o aluno precisa para na 4 prova para ficar com 7 na media.

    @param media_notas - (float) media das notas calculas
    @return (float) - nota necessaria para ficar com 7 na media
**/
float verificar_quando_deve_tirar_quarta_nota(float media_notas) {

    return 14 - media_notas;

}

int main(void) {
    int i;
    float notas[TAMANHO_VETOR_NOTAS];

    for (i = 0; i < TAMANHO_VETOR_NOTAS; i++) {
        printf("%d nota: ", (i + 1));
        scanf("%f", &notas[i]);
    }

    float media_notas = calcular_media(notas, TAMANHO_VETOR_NOTAS);

    if (media_notas == 0) {
        printf("ocorreu algum erro no calculo da media das notas\n");
    }

    if (media_notas >= 7) {
        printf("APROVADO\n");
    } else if (media_notas >= 5 && media_notas < 7) {
        printf("RECUPERACAO\n");

        float quarta_nota = verificar_quando_deve_tirar_quarta_nota(media_notas);

        printf("4 nota deve tirar %.2f para ficar com 7 na media\n", quarta_nota);
    }

    return 0;
}
