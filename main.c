#include <stdio.h>
#include <stdlib.h>

int mdc_recursivo(int n, int G){
    printf("mdc(%d, %d) = ", n, G);
    if (G==0){
        printf("%d\n", n);
        return n;
    } 
    return mdc_recursivo(G, n % G);    
}

int reduzir_modulo(int x, int n) {
    int r = x % n;
    if (r < 0)
        r += n;
    return r;
}

int euclides_estendido(int G, int n, int *x, int *y) {
    if (n == 0) {
        *x = 1;
        *y = 0;
        return G;
    }

    int x1, y1;
    int q = G / n;
    int r = G % n;

    // Print da forma isolada
    printf("%d = %d * %d + %d  =>  %d = %d - %d * %d\n", G, q, n, r, r, G, q, n);

    int d = euclides_estendido(n, r, &x1, &y1);

    *x = y1;
    *y = x1 - q * y1;

    return d;
}

int verifica_primo(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

int mod_pow(int a, int b, int n) {
    int result = 1;
    a = a % n;
    for (int i = 0; i < b; i++) {
        result = (result * a) % n;
    }
    return result;
}

void aplicar_teorema_fermat(int a, int x, int n) {
    printf("%d eh primo => %d^(%d - 1) = %d^%d ≡ 1 mod %d\n", n, a, n, a, n - 1, n);

    int q = x / (n - 1);
    int r = x % (n - 1);

    printf("%d = %d * %d + %d\n", x, q, n - 1, r);
    printf("%d^%d ≡ (%d^%d)^%d * %d^%d mod %d\n", a, x, a, n - 1, q, a, r, n);
    printf("%d^%d ≡ 1^%d * %d^%d ≡ %d^%d mod %d\n", a, x, q, a, r, a, r, n);

    int resultado = mod_pow(a, r, n);
    printf("%d^%d ≡ %d mod %d\n", a, x, resultado, n);
    printf("Q.E.D.\n");
}

int main() {
    int H, G, n, x, n1;
    printf("Digite três inteiros positivos (H G n): ");
    scanf("%d %d %d %d %d", &H, &G, &n, &x, &n1);

    printf("\n=======ETAPA 1=======\n");
    printf("Verificar se G e n são primos:\n\n");

    if (mdc_recursivo(n, G) != 1) {
        printf("A divisão modular não é possível.\n");
        return 0;
    }

    printf("\n=======ETAPA 2=======\n");
    printf("Realizar divisoes sucessivas e encontrar inverso:\n\n");

    int aux1, aux2;
    int d = euclides_estendido(n, G, &aux1, &aux2);
    printf("\nEquacao final: 1 = %d * (%d) + %d * (%d)\n", G, aux1, n, aux2);

    int inverso = reduzir_modulo(aux2, n);
    printf("Inverso de %d em Z%d eh %d\n", n, G, inverso);
    
    printf("\n=======ETAPA 3=======\n");
    printf("Divisão modular H por G:\n\n");

    int a = (H * inverso) % n;
    printf("a = (%d * %d) mod %d\n", H, inverso, n);
    printf("a = %d\n", a);

    printf("\n=======ETAPA 4=======\n");
    printf("Verifica se a e n1 são coprimos:\n\n");
    
    if (mdc_recursivo(a, n1) == 1) printf("%d e %d sao coprimos\n", a, n1);
    else printf("%d e %d nao sao coprimos\n", a, n1);

    printf("\n=======ETAPA 5=======\n");
    printf("Verifica se n1 eh primo:\n\n");

    if (verifica_primo(n1) == 1){
        printf("%d eh primo\n", n1);

        printf("\n=======ETAPA 6=======\n");
        printf("aplicar o Pequeno Teorema de Fermat:\n\n");

        aplicar_teorema_fermat(a, x, n1);
    } 
    else 
    {
        printf("%d nao eh primo\n", n1);

        printf("\n=======ETAPA 7=======\n");
        printf("aplicar o Teorema de Euler:\n\n");

        //aplicar_teorema_euler(a, x, n1);
    }


    return 0;
}