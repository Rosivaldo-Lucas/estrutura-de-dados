#include <stdio.h>

int main(void) {

    void *p = NULL;
    int x = 10;

    p = &x;

    // printf("conteudo: %d\n", *p); // erro: eh necessario realizar o cast

    printf("conteudo: %d\n", *((int *) p)); // realiza o cast e depois acessa o conteudo do endereco com o operador *

    // void *q = NULL;
    // int *p = NULL, x = 10, *a = NULL;

    // p = &x;
    // q = &x;

    // printf("endereco em q: %p\n", q);

    // q = &p;

    // printf("endereco em q: %p\n", q);

    // q = p;
    // // a = &p; // erro: a recebe um endereco de inteiro (int) nao um endereco de ponteiro que aponta pra inteiro (*int)
    // printf("endereco em q: %p\n", q);

    return 0;
}
