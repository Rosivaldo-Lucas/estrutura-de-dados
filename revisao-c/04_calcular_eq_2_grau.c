/**
    programa que realiza o calculo de uma equacao do segundo grau.

    @version v0.0.1 Agosto/2021
    @author LUCAS, Rosivaldo
**/
#include <stdio.h>
#include <math.h>

/**
    metodo responsavel pela realizacao do calculo do delta para o calculo da eq do segundo grau.

    @param a - (float)
    @param b - (float)
    @param c - (float)
    @return (float) - retorna o delta calculado
**/
float delta(float a, float b, float c) {
    return pow(b, 2) - (4 * a * c);
}

/**
    metodo responsavel por realizar o calculo da 1 raiz.

    @param a - (float)
    @param b - (float)
    @param c - (float)
    @return (float) - retorna o calcula da 1 reaiz
**/
float raiz1(float a, float b, float c) {
    if (a == 0) {
        return -1;
    }

    float d = delta(a, b, c);
    return (-b + sqrt(d)) / (2 * a);
}

/**
    metodo responsavel por realizar o calculo da 2 raiz.

    @param a - (float)
    @param b - (float)
    @param c - (float)
    @return (float) - retorna o calcula da 2 reaiz
**/
float raiz2(float a, float b, float c) {
    if (a == 0) {
        return -1;
    }
    
    float d = delta(a, b, c);
    return (-b - sqrt(d)) / (2 * a);
}

/**
    metodo responsavel por realizar o calculo da eq e mostrar na tela os resultados.

    @param a - (float)
    @param b - (float)
    @param c - (float)
**/
void calcular_eq(float a, float b, float c) {
    if (a == 0) {
        return -1;
    }

    float d = delta(a, b, c);

    if (d < 0) {
        printf("nao existe raizes reais\n");
    } else if (d == 0) {
        float raiz = raiz1(a, b, c);
        printf("x1 = x2 = %.2f\n", raiz);
    } else {
        float x1 = raiz1(a, b, c);
        float x2 = raiz2(a, b, c);
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    }

}

int main(void) {
    float a, b, c;

    printf("formato equacao 2 grau: aX^2 + bX + c\n");
    
    printf("a: ");
    scanf("%f", &a);

    printf("b: ");
    scanf("%f", &b);

    printf("c: ");
    scanf("%f", &c);

    calcular_eq(a, b, c);

    return 0;
}