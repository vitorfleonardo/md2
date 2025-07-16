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
}

int calcular_phi(int n) {
    int r = n;
    int original_n = n;

    printf("phi(%d):\n", original_n);
    printf("%d = ", original_n);

    int primeiro_fator = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int expoente = 0;
            while (n % i == 0) {
                n /= i;
                expoente++;
            }

            if (!primeiro_fator) printf(" * ");
            printf("%d^%d", i, expoente);
            primeiro_fator = 0;

            printf("\n(1 - 1/%d): r = %d - %d = %d\n", i, r, r / i, r - r / i);
            r -= r / i;
        }
    }

    if (n > 1) {
        if (!primeiro_fator) printf(" * ");
        printf("%d^1", n);
        printf("\n (1 - 1/%d): r = %d - %d = %d\n", n, r, r / n, r - r / n);
        r -= r / n;
    }

    printf("phi(%d) = %d\n\n", original_n, r);
    return r;
}

void aplicar_teorema_euler(int a, int x, int n) {
    printf("%d e %d sao coprimos\n", a, n);
    int phi = calcular_phi(n);
    printf("%d^%d ≡ 1 mod %d\n", a, phi, n);

    int q = x / phi;
    int r = x % phi;

    printf("%d = %d * %d + %d\n", x, q, phi, r);
    printf("%d^%d ≡ (%d^%d)^%d * %d^%d mod %d\n", a, x, a, phi, q, a, r, n);
    printf("%d^%d ≡ 1^%d * %d^%d mod %d\n", a, x, q, a, r, n);

    int resultado = mod_pow(a, r, n);
    printf("%d^%d ≡ %d mod %d\n", a, x, resultado, n);
}

void decompor_teorema_divisao(int x, int divisor, int *q, int *r) {
    *q = x / divisor;
    *r = x % divisor;
    printf("%d = %d * %d + %d\n", x, *q, divisor, *r);
}

void calcular_valores_intermediarios_final(int a, int divisor, int q, int r, int n1) {
    // a^divisor mod n1 = x2
    int x2 = mod_pow(a, divisor, n1);
    printf("1) %d^%d mod %d = %d\n", a, divisor, n1, x2);

    // Cx2^q mod n1
    int parte1 = mod_pow(x2, q, n1);
    printf("2) %d^%d mod %d = %d\n", x2, q, n1, parte1);

    // a^r mod n1
    int parte2 = mod_pow(a, r, n1);
    printf("3) %d^%d mod %d = %d\n", a, r, n1, parte2);

    // ((x2^q) * (a^r)) mod n1
    int resultado_final = (parte1 * parte2) % n1;
    printf("4) Valor final: ((%d * %d) mod %d) = %d\n", parte1, parte2, n1, resultado_final);
}

int main() {
    int H, G, n, x, n1;
    printf("Digite cinco inteiros positivos (H G n x n1): ");
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
    int d = euclides_estendido(G, n, &aux1, &aux2);
    printf("\nEquacao final: 1 = %d * (%d) + %d * (%d)\n", G, aux1, n, aux2);

    int inverso = reduzir_modulo(aux1, n);
    printf("Inverso de %d em Z%d = %d\n", G, n, inverso);
    
    printf("\n=======ETAPA 3=======\n");
    printf("Divisão modular H por G:\n\n");

    int a = (H * inverso) % n;
    printf("a = (%d * %d) mod %d\n", H, inverso, n);
    printf("a = %d\n", a);

    printf("\n=======ETAPA 4=======\n");
    printf("Verifica se a e n1 são coprimos:\n\n");
    
    int aux3 = mdc_recursivo(a, n1);
    if (aux3 == 1) printf("%d e %d sao coprimos\n", a, n1);
    else printf("%d e %d nao sao coprimos\n", a, n1);

    printf("\n=======ETAPA 5=======\n");
    printf("Verifica se n1 eh primo:\n\n");

    int divisor, quociente, resto;
    if (verifica_primo(n1) == 1){
        printf("%d eh primo\n", n1);

        printf("\n=======ETAPA 6=======\n");
        printf("aplicar o Pequeno Teorema de Fermat:\n\n");

        aplicar_teorema_fermat(a, x, n1);

        printf("\n=======ETAPA 8=======\n");
        printf("Utilizar teorema da divisão para decompor x:\n\n");

        divisor = n1 - 1;
        decompor_teorema_divisao(x, divisor, &quociente, &resto);
    } 
    else 
    {
        printf("%d nao eh primo\n", n1);

        printf("\n=======ETAPA 7=======\n");
        printf("aplicar o Teorema de Euler:\n\n");

        if (aux3 == 1) aplicar_teorema_euler(a, x, n1);
        else printf("a e n1 nao sao coprimos, logo o Teorema de Euler nao pode ser aplicado\n");

        printf("\n=======ETAPA 8=======\n");
        printf("Utilizar teorema da divisão para decompor x:\n\n");

        divisor = calcular_phi(n1);
        decompor_teorema_divisao(x, divisor, &quociente, &resto);
    }

    printf("\n=======ETAPA 9=======\n");
    printf("Reescrever a expressão a^x mod n1:\n\n");
    printf("%d^%d ≡ ((%d^%d)^%d mod %d) * (%d^%d mod %d) mod %d\n", a, x, a, divisor, quociente, n1, a, resto, n1, n1);

    printf("\n=======ETAPA 10 e 11=======\n");
    printf("Calcular os seguintes valores intermediários e o valor final da congruência:\n\n");

    calcular_valores_intermediarios_final(a, divisor, quociente, resto, n1);

    return 0;
}