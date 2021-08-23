/**
    programa que calcula a area do circulo com raio informado pelo usuario.

    @version v0.0.1 Agosto/2021
    @author LUCAS, Rosivaldo
**/
#include <stdio.h>
#include <math.h>

/**
    constante que define o numero PI
**/
#define PI 3.14

/**
    metodo responsavel por receber o raio do circulo e realizar o calculo da sua area.

    @param raio_circulo - (float)
    @return (float) - com o calculo da area do circulo
**/
float calcular_area_circulo(float raio_circulo) {
    float area_circulo = pow(raio_circulo, 2) * PI;
    
    return area_circulo;
}

int main(void) {

    float raio_circulo;

    printf("informe o raio do circulo: ");
    scanf("%f", &raio_circulo);

    float area_circulo = calcular_area_circulo(raio_circulo);

    printf("area do circulo = %.2f\n\a", area_circulo);

    return 0;

}
