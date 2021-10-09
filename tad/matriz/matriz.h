#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct matriz Matriz;

Matriz *mat_criar(int linha, int coluna);
int mat_liberar(Matriz *mat);
int mat_acessar(Matriz *mat, int i, int j, float *item);
int mat_atribuir(Matriz *mat, int i, int j, float item);
int mat_inicializar(Matriz *mat);
int mat_nlinhas(Matriz *mat);
int mat_ncolunas(Matriz *mat);
int mat_print(Matriz *mat);

#endif
