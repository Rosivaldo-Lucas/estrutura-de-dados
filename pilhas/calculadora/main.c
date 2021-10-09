#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main(void) {

    Calc *calc = calc_cria("%.2f\n");

    while (1) {
        char c;

        scanf("%c", &c);

        if (c == '+' || c == '-' || c == '*' || c == '/')
            calc_operador(calc, c);

        else if (c == 'q')
            break;

        else {
            float v;

            ungetc(c, stdin);

            if (scanf("%f", &v) == 1)
                calc_operando(calc, v);

            else {
                printf("Erro na leitura\n");

                exit(1);
            }
        }
    }

    calc_liberar(calc);

    return 0;
}
