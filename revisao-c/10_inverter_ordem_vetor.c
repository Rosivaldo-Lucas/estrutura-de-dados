#include <stdio.h>

int* inverter_vetor(const int vetor[], int tamanho) {
    int i, j, aux, *vetor_invertido[tamanho];

    for (i = 0; i < tamanho; i++) {
        *vetor_invertido[i] = vetor[i];
    }

    for(i = 0; i < (tamanho - 1); i++) {
        for (j = (i + 1); j < tamanho; j++) {
            aux = *vetor_invertido[i];
            *vetor_invertido[i] = *vetor_invertido[j];
            *vetor_invertido[j] = aux;
        }
    }

    return vetor_invertido[tamanho];
}

int main(void) {

    int vetor[] = {1, 5, 3, 4, 6}; // vetor inverso - {6, 4, 3, 5, 1}

    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    inverter_vetor(vetor, tamanho);

    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    return 0;
}
