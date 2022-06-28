#include <stdio.h>
#include "arbre.c"

int main() {
    ARB *A = NULL;

    int i, size, n;

    printf("Entrez le nombre de valeurs vous voulez inserer a l'arbre A: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        printf("Entrez la valeur de %deme noeud: ", i+1);
        scanf("%d", &n);
        if (i == 0) {
            A = creer_arbre(n);
        } else {
            A = inserer(A, n);
        }
    }

    printf("Affichage de l'arbre:\n");
    afficher_arbre(A);

    printf("\n\nAffichage croissant de l'arbre:\n");
    afficher_croissant(A);

    printf("\n\nEntrez une valeur a rechercher: ");
    scanf("%d", &n);
    ARB *node = trouver_noeud(A, n);
    if (node != NULL) {
        printf("\nLe noeud avec la valeur %d existe!\nAffichage de sous-arbre:\n", n);
        afficher_arbre(node);
        printf("\n\n");
    } else {
        printf("\nLe noeud avec la valeur %d n'existe pas!\n");
    }

    return 0;
}
