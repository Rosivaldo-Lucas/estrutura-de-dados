#ifndef _CALC_
#define _CALC_

typedef struct calc Calc;

Calc *calc_cria(char *f);
void calc_operando(Calc *c, float v);
void calc_operador(Calc *c, char op);
void calc_liberar(Calc *c);

#endif
