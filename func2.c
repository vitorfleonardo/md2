#include <stdio.h>
#include <stdlib.h>

int reduzir_modulo(int x, int n) {
    int r = x % n;
    if (r < 0)
        r += n;
    return r;
}

int euclides_estendido_com_print(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int q = a / b;
    int r = a % b;

    // Print da forma isolada
    printf("%d = %d * %d + %d  =>  %d = %d - %d * %d\n", a, q, b, r, r, a, q, b);

    int d = euclides_estendido_com_print(b, r, &x1, &y1);

    *x = y1;
    *y = x1 - q * y1;

    return d;
}

int main() {
    int a, b;
    printf("Digite dois inteiros positivos (a b): ");
    scanf("%d %d", &a, &b);

    int x, y;
    printf("\nEtapas das divisoes sucessivas:\n");
    int d = euclides_estendido_com_print(a, b, &x, &y);

    if (d != 1) {
        printf("\nNao existe combinacao linear que de 1, pois o MDC eh %d.\n", d);
    } else {
        printf("\nEquacao final: 1 = %d * (%d) + %d * (%d)\n", a, x, b, y);
        int inverso = reduzir_modulo(y, a);
        printf("Inverso de %d em Z%d eh %d\n", b, a, inverso);
    }

    return 0;
}