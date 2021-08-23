#include <stdio.h>

int eh_primo(int numero) {
    int i, primo = 1;

    if (numero <= 1 && numero % 2 == 0) {
        primo = 1;
    } else {
        primo = 0;
    }

    while (primo && d <= numero / 2) {
        if (numero % d == 0) {
            primo = 0;
        }

        d = d + 2;
    }

    return primo;

}

int main(void) {
    int numero;

    printf("numero: ");
    scanf("%d", &numero);

    int isPrimo = eh_primo(numero);

    if (isPrimo == 0) {
        printf("EH PRIMO\n");
    } else {
        printf("NAO EH PRIMO\n");
    }

    return 0;
}
