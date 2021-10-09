#include <stdio.h>

int main(void) {
    int vet[5];

    for (int i = 0; i < 5; i++) {
        scanf("%d", (vet + i));
    }

    for (int i = 0; i < 5; i++) {
        printf("vet[%d] = %d\n", i, *(vet + i) * 2);
    }

    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            printf("vet[%d] = %p\n", i, (vet + i));
        }
    }

    return 0;
}
