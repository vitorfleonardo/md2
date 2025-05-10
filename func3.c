#include <stdio.h>

int MdcRecursivo(int n, int G){
    printf("mdc(%d, %d) = ", n, G);
    if (G==0){
        printf("%d\n", n);
        return n;
    } 
    return MdcRecursivo(G, n % G);    
}

int main() {
    int a = 252;
    int b = 105;
    
    MdcRecursivo(a, b);
    
    return 0;
}