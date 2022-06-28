#include <stdio.h>

float puissance(float x, int n) {
    if (n == 0) return 1;

    return x * puissance(x, n-1);
}

int main() {
    float x;
    int n;
    printf("Entrez un reel X : ");
    scanf("%f", &x);
    printf("Entrez un entier n : ");
    scanf("%d", &n);
    printf("%.f pussiance %d = %f\n", x, n, puissance(x, n));

    return 0;
}
