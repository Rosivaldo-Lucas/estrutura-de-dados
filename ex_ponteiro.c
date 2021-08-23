#include <stdio.h>

void alterar_vetor(int *vetor, int elementos);

int main(void) {

    int v[] = {5, 10, 15, 3, 10, 76, 5, 13, 33, 45};
    int *pt;
    int i;

    pt = v; // atribui o endereco do vetor

    printf("antes\n");
    for (i = 0; i < 10; i++) {
        printf("V[%d] = %d ", i, *(pt + i)); // *(pt + i) -> pt[i]
    }

    printf("\n");

    alterar_vetor(v, 10);

    for (i = 0; i < 10; i++) {
        printf("V[%d] = %d\r\n", i, *(pt + i)); // *(pt + 1) -> pt[i]
    }

    return 0;
}

void alterar_vetor(int *vetor, int elementos) {

    int i;

    if (vetor != NULL) {
        for (i = 0; i < elementos; i++) {
            *(vetor) = *(vetor) * 2; // ex: v[i] = v[i] * 2

            vetor++; // desloca o ponteiro para o proximo elemento
        }
    }

}
