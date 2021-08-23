#include <stdio.h>

int main(void) {

    int v[] = {1, 10, 4, 6, 8, 9, 4, 7, 50, 66};

    int t = sizeof(v)/sizeof(v[0]);

    int i, aux;
    for (i = t - 1; i > 0; i--) {
        aux = v[i];
        v[i] = v[i - 1];
        v[i - 1] = aux;
    }

    for (i = 0; i < t; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");

    return 0;
}
