#include <stdio.h>
#include "ponto.h"

int main(int argc, char *argv[]) {
    Ponto *p = NULL, *q = NULL;

    float p_x, p_y, q_x, q_y;

    p = pto_criar(2.0f, 1.0f);
    q = pto_criar(3.4f, 2.1f);

    pto_obter(p, &p_x, &p_y);
    pto_obter(q, &q_x, &q_y);

    printf("p(%.2f, %.2f)\n", p_x, p_y);
    printf("q(%.2f, %.2f)\n", q_x, q_y);

    float distancia = pto_calcular_distancia(p, q);

    printf("distancia entre p(%.2f, %.2f) e q(%.2f, %.2f) = %.2f\n", p_x, p_y, q_x, q_y, distancia);

    pto_liberar(p);
    pto_liberar(q);

    return 0;
}
