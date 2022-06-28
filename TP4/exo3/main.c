#include <stdio.h>

int pgcd(int a, int b) {
    if (b == 0) return a;

    return pgcd(b, a % b);
}

int main() {
    int a, b;
    printf("Entrez deux nombres a et b : ");
    scanf("%d %d", &a, &b);
    printf("PGCD(%d, %d) = %d\n", a, b, pgcd(a, b));

    return 0;
}
