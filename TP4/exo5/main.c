#include <stdio.h>
#include <math.h>

int convert_dec_bin(int n) {
    if (n == 0) return 0;

    return (n % 2) + 10 * convert_dec_bin(n / 2);
}

int main() {
    int n;
    printf("Entrez un nombre en decimal : ");
    scanf("%d", &n);
    printf("%d en binaire est : %d", n, convert_dec_bin(n));

    return 0;
}
