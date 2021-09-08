#ifndef PONTO_H
#define PONTO_H

typedef struct ponto Ponto;

Ponto *pto_criar(float x, float y);
int pto_liberar(Ponto *ponto);
int pto_obter(Ponto *ponto, float *x, float *y);
int pto_setar(Ponto *ponto, float x, float y);
float pto_calcular_distancia(Ponto *p, Ponto *q);

#endif
