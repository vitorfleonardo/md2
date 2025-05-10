#include <stdio.h>

int MdcRecursivo(int n, int G){
    printf("mdc(%d, %d) = ", n, G);
    if (G==0){
        printf("%d\n", n);
        return n;
    } 
    return MdcRecursivo(G, n % G);    
}

int mod_pow(int a, int b, int n) {
    int result = 1;
    a = a % n;
    for (int i = 0; i < b; i++) {
        result = (result * a) % n;
    }
    return result;
}

void aplicar_teorema_de_fermat(int a, int x, int n) {
    printf("Aplicando o Pequeno Teorema de Fermat:\n");
    printf("%d eh primo, entao %d^(%d - 1) = %d^%d eh congruente a 1 mod %d\n", n, a, n, a, n - 1, n);

    int q = x / (n - 1);
    int r = x % (n - 1);

    printf("Decompondo %d como %d * %d + %d\n", x, q, n - 1, r);
    printf("Portanto, %d^%d ≡ (%d^%d)^%d * %d^%d mod %d\n", a, x, a, n - 1, q, a, r, n);
    printf("Como %d^%d ≡ 1 mod %d, temos:\n", a, n - 1, n);
    printf("%d^%d ≡ 1^%d * %d^%d ≡ %d^%d mod %d\n", a, x, q, a, r, a, r, n);

    int resultado = mod_pow(a, r, n);
    printf("Calculando %d^%d mod %d = %d\n", a, r, n, resultado);
    printf("Resultado final: %d^%d ≡ %d mod %d\n", a, x, resultado, n);
}

int main() {
    int a = 21;
    int x = 45;
    int n = 11;
    
    aplicar_teorema_de_fermat(a, x, n);
    
    return 0;
}