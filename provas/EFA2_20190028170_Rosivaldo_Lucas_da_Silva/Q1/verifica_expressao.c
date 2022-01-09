#include <stdio.h>
#include "pilha_lista.h"

int expressao_ta_balanceada(char *ex) {
    int i = 0;
    int balan = 1;

    char elem;

    pilha_t *p = p_cria();

    while (ex[i] != '\0' && balan != 0) {
        if (ex[i] == '[' || ex[i] == '(' || ex[i] == '{') {
            p_empilha(p, ex[i]);
        } else {
            if (p_vazia(p)) {
                balan = 0;
            } else {
                p_desempilha(p, &elem);
            }

            if (ex[i] == ']' && elem != '[') balan = 0;
            if (ex[i] == ')' && elem != '(') balan = 0;
            if (ex[i] == '}' && elem != '{') balan = 0;
        }

        i++;
    }

    if (!p_vazia(p)) {
        balan = 0;
    }

    p_libera(p);

    return balan;
}

void imprime_expressao(char *expressao) {
    int i = 0;

    while (expressao[i] != '\0') {
        printf("%c", expressao[i]);
        i++;
    }

    printf("\n");
}

int main(void) {
    int op;
    char expressao[21];

    char ex1[] = {'[', '{', '(', ')', '(', ')', '}', '{', '}', ']', '\0'};
    char ex2[] = {'{', '[', '(', '[', '{', '}', ']', ')', ']', '}', '\0'};
    char ex3[] = {'{', '[', '(', '}', ']', ')', '\0'};
    char ex4[] = {'{', '[', ')', '(', ')', '(', ']', '}', '\0'};

    printf("verificando expressoes\n");

    printf("1 - digitar expressao tamanho de 20\n");
    printf("2 - verificar expressoes disponiveis no sistema\n");

    scanf("%d", &op);

    printf("\n");

    if (op == 1) {
        printf("digite a expressao: ");
        scanf("%s", expressao);

        if (expressao_ta_balanceada(expressao)) {
            printf("balanceada\n");
        } else {
            printf("nao balanceada\n");
        }

    } else {
        imprime_expressao(ex1);
        if (expressao_ta_balanceada(ex1)) {
            printf("ex1 - balanceada\n\n");
        } else {
            printf("ex1 - nao balanceada\n\n");
        }

        imprime_expressao(ex2);
        if (expressao_ta_balanceada(ex2)) {
            printf("ex2 - balanceada\n\n");
        } else {
            printf("ex2 - nao balanceada\n\n");
        }

        imprime_expressao(ex3);
        if (expressao_ta_balanceada(ex3)) {
            printf("ex3 - balanceada\n\n");
        } else {
            printf("ex3 - nao balanceada\n\n");
        }

        imprime_expressao(ex4);
        if (expressao_ta_balanceada(ex4)) {
            printf("ex4 - balanceada\n\n");
        } else {
            printf("ex4 - nao balanceada\n\n");
        }
    }

    return 0;
}
