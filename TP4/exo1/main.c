#include <stdio.h>

int somme(int n) {
    if (n <= 1) {
        return n;
    } else {
        return n + somme(n-1);
    }
}

int main() {
    int n;
    printf("Entrez un entier : ");
    scanf("%d", &n);
    printf("La somme des entiers de 1 a %d est : %d\n", n, somme(n));

    return 0;
}
