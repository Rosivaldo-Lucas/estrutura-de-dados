#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"
#include "../pilha.h"

struct calc {
    char f[21];
    Pilha *p;
};

Calc *calc_cria(char *f) {
    Calc *c = (Calc *) malloc(sizeof(Calc));

    if (c == NULL) return NULL;

    strcpy(c->f, f);
    c->p = p_criar();

    if (c->p == NULL) return NULL;

    return c;
}

void calc_operando(Calc *c, float v) {
    p_push(c->p, v);
    printf(c->f, v);
}

void calc_operador(Calc *c, char op) {
    float v2 = p_vazia(c->p) ? 0.0f : p_pop(c->p);
    float v1 = p_vazia(c->p) ? 0.0f : p_pop(c->p);

    float v;

    switch (op) {
        case '+':
            v = v1 + v2; break;
        case '-':
            v = v1 - v2; break;
        case '*':
            v = v1 * v2; break;
        case '/':
            v = v1 / v2; break;
        default:
            break;
    }

    p_push(c->p, v);
    printf(c->f, v);
}

void calc_liberar(Calc *c) {
    p_liberar(c->p);
    free(c);
}
