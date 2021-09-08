#include <stdlib.h>
#include <math.h>
#include "ponto.h"

// outra forma de implementar as operacoes do TAD Ponto
// struct ponto {
//     float x;
//     float y;
// };

struct ponto {
    float coordenadas[1];
};

Ponto *pto_criar(float x, float y) {
    Ponto *ponto = (Ponto *) malloc(sizeof(Ponto));

    if (ponto) {
        ponto->coordenadas[0] = x;
        ponto->coordenadas[1] = y;
    }

    return ponto;
}

int pto_liberar(Ponto *ponto) {
    if (ponto == NULL) {
        return 0;
    }

    free(ponto);
}

int pto_obter(Ponto *ponto, float *x, float *y) {
    if (ponto == NULL || x == NULL || y == NULL) {
        return 0;
    }

    *x = ponto->coordenadas[0];
    *y = ponto->coordenadas[1];

    return 1;
}

int pto_setar(Ponto *ponto, float x, float y) {
    if (ponto == NULL) {
        return 0;
    }

    ponto->coordenadas[0] = x;
    ponto->coordenadas[1] = y;
}

float pto_calcular_distancia(Ponto *p, Ponto *q) {
    if (p == NULL || q == NULL) {
        return -1.0f;
    }
    
    float diferenca_x = p->coordenadas[0] - q->coordenadas[0];
    float diferenca_y = p->coordenadas[1] - q->coordenadas[1];

    float distancia = sqrt(pow(diferenca_x, 2) + pow(diferenca_y, 2));

    return distancia;
}
