#include <stdio.h>

int retorna_maior_valor(int array[], int tam) {
    int i;
    int maior = array[0];

    for (i = 1; i < tam; i++) {
        if (maior < array[i]) {
            maior = array[i];
        }
    }

    return maior;
}

int main(void) {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int tam = sizeof(array) / sizeof(array[0]);

    int maior = retorna_maior_valor(array, tam);

    printf("maior valor = %d\n", maior);

    return 0;
}
