#include <stdio.h>
#include <stdlib.h>
#include "vetor_realocavel.h"

struct vetor {
    Elemento *vetor;
    int tam;
    int qtd_max;
};

VetorDinamico *vd_criar() {
    VetorDinamico *vetorDinamico = (VetorDinamico *) malloc(sizeof(VetorDinamico));

    if (vetorDinamico == NULL) {
        return NULL;
    }

    vetorDinamico->vetor = (Elemento *) malloc(sizeof(Elemento) * 10);

    if (vetorDinamico->vetor == NULL) {
        return NULL;
    }

    vetorDinamico->qtd_max = 10;
    vetorDinamico->tam = 0;

    return vetorDinamico;
}

int vd_inserir(VetorDinamico *vetorDinamico, Elemento elemento) {
    if (vetorDinamico == NULL || vetorDinamico->vetor == NULL) {
        return 0;
    }

    if (vetorDinamico->tam == vetorDinamico->qtd_max) {
        vetorDinamico->vetor = (Elemento *) realloc(vetorDinamico->vetor, sizeof(Elemento) * 2);

        if (vetorDinamico->vetor == NULL) {
            return 0;
        }

        vetorDinamico->qtd_max *= 2;
    }

    vetorDinamico->vetor[vetorDinamico->tam++] = elemento;

    return 1;
}

int vd_acessar_elemento(VetorDinamico *vetorDinamico, int i, Elemento *elemento) {
    if (vetorDinamico == NULL || vetorDinamico->vetor == NULL || i < 0 || i >= vetorDinamico->tam) {
        return 0;
    }

    (*elemento) = vetorDinamico->vetor[i];

    return 1;
}

int vd_tamanho(VetorDinamico *vetorDinamico) {
    if (vetorDinamico == NULL || vetorDinamico->vetor == NULL) {
        return -1;
    }

    return vetorDinamico->tam;
}

int vd_liberar(VetorDinamico *vetorDinamico) {
    if (vetorDinamico == NULL || vetorDinamico->vetor == NULL) {
        return 0;
    }

    free(vetorDinamico->vetor);
    free(vetorDinamico);

    return 1;
}

void vd_imprimir(VetorDinamico *vetorDinamico) {
    if (vetorDinamico == NULL || vetorDinamico->vetor == NULL) {
        return;
    }

    int i;
    for (i = 0; i < vetorDinamico->tam; i++) {
        printf("[%d] = %d ", i, vetorDinamico->vetor[i]);
    }
    printf("\n");
}
