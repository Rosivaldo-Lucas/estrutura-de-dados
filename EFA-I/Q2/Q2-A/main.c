#include <stdio.h>
#include "vetor_realocavel.h"

int main(int argc, char *argv[]) {
    // cria um vetor dinamico com capacidade inicial de 10 elementos
    VetorDinamico *vetor = vd_criar();

    // insere 10 elementos no vetor
    vd_inserir(vetor, 10);
    vd_inserir(vetor, 20);
    vd_inserir(vetor, 30);
    vd_inserir(vetor, 40);
    vd_inserir(vetor, 50);
    vd_inserir(vetor, 60);
    vd_inserir(vetor, 70);
    vd_inserir(vetor, 80);
    vd_inserir(vetor, 90);
    vd_inserir(vetor, 100);

    // imprime os elementos do vetor e imprime seu tamanho e acessa o determinado elemento
    printf("Imprime elementos\n");
    vd_imprimir(vetor);
    printf("TAM = %d\n", vd_tamanho(vetor));

    // elemento esperado é o 100
    int elem;
    printf("elemento %d\n", vd_acessar_elemento(vetor, 9, &elem));

    // adiciona mais um elemento ao vetor (sera alocado mais 10 posicoes para o vetor)
    vd_inserir(vetor, 120);

    // imprime os elementos do vetor e imprime seu tamanho e acessa o determinado elemento
    printf("Imprime elementos\n");
    vd_imprimir(vetor);
    printf("TAM = %d\n", vd_tamanho(vetor));

    // elemento esperado é o 120
    vd_acessar_elemento(vetor, 10, &elem);
    printf("elemento %d\n", elem);

    vd_liberar(vetor);

    return 0;
}

