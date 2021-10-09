#include <stdio.h>

void trocar_valor(int *a, int *b);
int soma_e_dobra_valor(int *a, int *b);

int main(void) {

    int a = 10, b = 20;

    int soma = soma_e_dobra_valor(&a, &b);
    printf("soma = %d\na = %d\nb = %d\n", soma, a, b);


    // trocar_valor(&a, &b);
    // printf("a = %d\nb = %d\n", a, b);

    return 0;
}

int soma_e_dobra_valor(int *a, int *b) {
    int soma = *a + *b;

    *a = *a * 2;
    *b = *b * 2;

    return soma;
}


void trocar_valor(int *a, int *b) {

    int aux = *a;
    *a = *b;
    *b = aux;

}
