/**
    ponteiros podem ser comparados usando:
    ==, !=, >, <, >= e <=
**/

#include <stdio.h>

int main(void) {
    int *p, **q, x = 10;

    p = &x;

    printf("endereco x: %p\n", &x);
    printf("endereco p: %p\n", p);
    
    printf("*p: %d\n", *p);

    q = &p;

    printf("endereco real p: %p\n", &p);
    printf("endereco q: %p\n", q);
    printf("**q: %d\n", **q);

    return 0;
}
