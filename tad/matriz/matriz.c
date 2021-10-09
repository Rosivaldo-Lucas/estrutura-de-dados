#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

struct matriz {
    int linha;
    int coluna;
    float **vet;
};

Matriz *mat_criar(int linha, int coluna) {
    Matriz *mat = (Matriz *) malloc(sizeof(Matriz));

    mat->linha = linha;
    mat->coluna = coluna;
    mat->vet = (float **) malloc(sizeof(float *) * linha);

    int i;
    for (i = 0; i < linha; i++) {
        mat->vet[i] = (float *) malloc(sizeof(float) * coluna);
    }

    return mat;
}

int mat_liberar(Matriz *mat) {
    if (mat == NULL) {
        return 0;
    }

    int i;
    for (i = 0; i < mat->linha; i++) {
        free(mat->vet[i]);
    }

    free(mat->vet);
    free(mat);

    return 1;
}

int mat_acessar(Matriz *mat, int i, int j, float *item) {
    if (mat == NULL || mat->vet == NULL) {
        return 0;
    }

    *item = mat->vet[i][j];

    return 1;
}

int mat_atribuir(Matriz *mat, int i, int j, float item) {
    if (mat == NULL || mat->vet == NULL) {
        return 0;
    }

    mat->vet[i][j] = item;

    return 1;
}

int mat_inicializar(Matriz *mat) {
    if (mat == NULL || mat->vet == NULL) {
        return 0;
    }

    int i, j;
    for (i = 0; i < mat->linha; i++) {
        for (j = 0; j < mat->coluna; j++) {
            mat->vet[i][j] = 1;
        }
    }

    return 1;

}

int mat_nlinhas(Matriz *mat) {
    if (mat == NULL || mat->vet == NULL) {
        return 0;
    }

    return mat->linha;
}

int mat_ncolunas(Matriz *mat) {
    if (mat == NULL || mat->vet == NULL) {
        return 0;
    }

    return mat->coluna;
}

int mat_print(Matriz *mat) {
    if (mat == NULL || mat->vet == NULL) {
        return 0;
    }

    int i, j;
    for (i = 0; i < mat->linha; i++) {
        for (j= 0; j < mat->coluna; j++) {
            printf("%.2f ", mat->vet[i][j]);
        }
        printf("\n");
    }

}

