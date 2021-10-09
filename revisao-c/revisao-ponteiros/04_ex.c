#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear(void) {
    while (getchar() != '\n');
}

int main() {
    char aux[100];
    char **str = NULL;
    int n;

    scanf("%d", &n);
    clear();

    str = (char **) malloc(sizeof(char *) * n);

    int i, qtd = 0;
    for (i = 0; i < n; i++) {
        scanf("%s", aux);

        qtd = strlen(aux);
        
        str[i] = (char *) malloc(sizeof(char) * qtd + 1);

    }

    for (i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }

    for (i = 0; i < n; i++) {
        free(str[i]);
    }

    free(str);

    return 0;
}
