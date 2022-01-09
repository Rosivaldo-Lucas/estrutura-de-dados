#include <stdio.h>
#include <string.h>
#include "fila_lista_dupla.h"
#include "../Q1/pilha_lista.h"

int eh_palindromo(char *palavra) {
    int i = 0, palindromo = 1;
    char pal_p[21], pal_f[21];

    pilha_t *p = p_cria();
    fila_t *f = f_cria();
    
    while (palavra[i] != '\0') {
        p_empilha(p, palavra[i]);
        f_insere(f, palavra[i]);
        i++;
    }

    i = 0;
    while (!p_vazia(p) && !f_vazia(f)) {
        p_desempilha(p, &pal_p[i]);
        f_remove(f, &pal_f[i]);

        if (pal_p[i] != pal_f[i]) {
            palindromo = 0;
        }

        i++;
    }

    if (strcmp(palavra, pal_p) != 0 || strcmp(palavra, pal_f) != 0) {
        palindromo = 0;
    }

    return palindromo;
}

int main(void) {
    char p[21];

    printf("palavra: ");
    scanf("%s", p);

    if (eh_palindromo(p) == 1) {
        printf("eh palindromo\n");
    } else {
        printf("nao eh palindromo\n");
    }

    return 0;
}
