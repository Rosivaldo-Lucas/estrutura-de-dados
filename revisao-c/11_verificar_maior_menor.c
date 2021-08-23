#include <stdio.h>

// verificar o maior e o menor valor utilizando passagem por referencia
void maior_menor(int v[], int t, int *maior, int *menor) {
    int i;
    
    *(maior) = v[0];
    *(menor) = v[0];

    for (i = 1; i < t; i++) {
        if (v[i] > *maior) {
            *maior = v[i];
        }

        if (v[i] < *menor) {
            *menor = v[i];
        }

    }

}

int main(void) {

    int v[] = {1, 10, 4, 6, 8, 9, 4, 7, 50, 66};

    int tamanho = sizeof(v)/sizeof(v[0]);

    int maior, menor;

    maior_menor(v, tamanho, &maior, &menor);

    // int i, maior = v[0], menor = v[0];
    // for (i = 1; i < tamanho; i++) {
    //     if (v[i] > maior) {
    //         maior = v[i];
    //     }

    //     if (v[i] < menor) {
    //         menor = v[i];
    //     }

    // }

    printf("maior: %d\n", maior);
    printf("menor: %d\n", menor);

    return 0;
}
