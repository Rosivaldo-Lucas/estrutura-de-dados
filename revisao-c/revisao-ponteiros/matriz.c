#include <stdio.h>
#include <stdlib.h>

// m -> numero de linhas
// n -> numero de colunas
float *transposta_vetor_simples(int m, int n, float *mat);
float **transposta_vetor_ponteiro(int m, int n, float **mat);

int main() {


    return 0;
}

float **transposta_vetor_ponteiro(int m, int n, float **mat) {
    float **trp = (float **) malloc(sizeof(float *) * n);

    int i, j;
    for (i = 0; i < n; i++) {
        trp[i] = (float *) malloc(sizeof(float) * m);
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            trp[j][i] = mat[i][j];
        }
    }

    return trp;
}


float *transposta_vetor_simples(int m, int n, float *mat) {
    float *trp = (float *) malloc(sizeof(float) * n * m);

    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            trp[j * m + i] = mat[i * n + j];
        }
    }

    return trp;
}
