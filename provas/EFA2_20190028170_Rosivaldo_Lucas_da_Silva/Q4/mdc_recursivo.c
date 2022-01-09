#include <stdio.h>

int mdc_recursivo(int a, int b) {
    if (b == 0) {
        return a;
    } else if (b > 0) {
        int mod = a % b;
        return mdc_recursivo(b, mod);
    } else {
        return mdc_recursivo(a, -b);
    }
}

int main(void) {

    int mdc = mdc_recursivo(726, -275);

    printf("mdc = %d\n", mdc);

    return 0;
}
