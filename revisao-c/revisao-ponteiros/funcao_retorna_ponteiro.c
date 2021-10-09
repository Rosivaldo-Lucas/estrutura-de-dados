#include <stdio.h>

int *vet(int *v);
char *match(char c, char *s);

int main(void) {

    int i;

    // char s[80], *p, ch;
    int v[] = {1, 2, 3, 4, 5};
    int *vetor = NULL;

    printf("vetor atual\n\n");

    for (i = 0; i < 4; i++) {
        printf("v[%d] = %d\n", i, v[i]);
    }

    printf("\n\n");

    vetor = vet(v);

    printf("vetor retornado\n\n");

    for (i = 0; i < 4; i++) {
        printf("v[%d] = %d\n", i, vetor[i]);
    }

    // gets(s);

    // ch = getchar();

    // p = match(ch, s);

    // if (*p) {
    //     printf("%s\n", p);
    // } else {
    //     printf("Não encontrou\n");
    // }

    return 0;
}

int *vet(int *v) {
    int i;

    int vetor[4];
    int *ptret;

    for (i = 0; i < 4; i++) {
        vetor[i] = v[i] * 2;
        printf("AAA%d\n", vetor[i]);
    }

    ptret = &vetor[0];

    return ptret;
}

char *match(char c, char *s) {
    
    while (c != *s && *s) {
        s++;
    }

    return s;

}
