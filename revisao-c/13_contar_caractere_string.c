#include <stdio.h>

int contar(char c[], char caractere) {

    int i = 0, cont = 0;
    while (c[i] != '\0') {

        if (c[i] == caractere) {
            cont = cont + 1;
        }

        i++;
    }

    return cont;

}

int main(void) {

    char c[50];
    char caractere;
    
    printf("digite a frase: ");
    gets(c);

    printf("digite o caractere para ser contato: ");
    scanf("%c", &caractere);

    int cont = contar(c, caractere);

    printf("cont = %d\n", cont);

    return 0;
}
