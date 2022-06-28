#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *p, *pi;

    printf("Entrez la taille du tableau: ");
    scanf("%d", &n); // Lecture de la tallie du tableau

    p = malloc(sizeof(*p)*n); // Reservation de l'espace memoire

    printf("\nLecture du %d elements:\n", n);
    for (pi=p; pi<p+n; pi++) { // Lecture
        scanf("%d", &(*pi));
    }

    printf("\nAffichage:\n");
    for (pi=p ; pi<p+n; pi++) { // Affichage
        printf("%d\n", *pi);
    }

    return 0;
}