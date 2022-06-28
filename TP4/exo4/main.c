#include <stdio.h>

void montee(int n) {
    if (n != 0) {
        montee(n-1);
        printf("%d\n", n);
    }
}

void descente(int n) {
    if (n != 0) {
        printf("%d\n", n);
        descente(n-1);
    }
}

int main() {
    int n;
    printf("Entrez un entier n : ");
    scanf("%d", &n);

    printf("Affichage des entiers de 1 à %d dans l’ordre croissant:\n", n);
    montee(n);

    printf("Affichage des entiers de 1 à %d dans l’ordre décroissant:\n", n);
    descente(n);

    return 0;
}
