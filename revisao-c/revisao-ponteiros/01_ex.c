#include <stdio.h>

int main(void) {
    int x = 10, *p_int = NULL;
    float y = 10.0, *p_float = NULL;
    char z = 'a', *p_char = NULL;

    p_int = &x;
    p_float = &y;
    p_char = &z;

    printf("antes\n");

    printf("x = %d\n", x);
    printf("y = %f\n", y);
    printf("z = %c\n", z);

    *p_int = 20;
    *p_float = 30.5;
    *p_char = 'b';

    printf("depois\n");

    printf("x = %d\n", x);
    printf("y = %f\n", y);
    printf("z = %c\n", z);

    return 0;
}
