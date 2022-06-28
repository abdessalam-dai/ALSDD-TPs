#include <stdio.h>
#include "arbre.c"

int main() {
    Arbre *A = init_arbre();

    A->racine = creer_element(3);

        A->racine->fd = creer_element(4);
        A->racine->fd->fd = creer_element(33);

            A->racine->fd->fd->fg = creer_element(5);

        A->racine->fd->fg = creer_element(3);

        A->racine->fg = creer_element(12);
        A->racine->fg->fd = creer_element(7);
        A->racine->fg->fg = creer_element(0);

            A->racine->fg->fg->fg = creer_element(9);

                A->racine->fg->fg->fg->fg = creer_element(-2);

    printf("\n\nParcours Pre-Ordre:\n");
    afficher_pre_ordre(A->racine);

    printf("\n\nParcours In-Ordre:\n");
    afficher_in_ordre(A->racine);

    printf("\n\nParcours Post-Ordre:\n");
    afficher_post_ordre(A->racine);

    printf("\n\nAffichage de tous les feuilles:\n");
    afficher_feuilles(A->racine);

    printf("\n\nLe nombre d'elements de l'arbre: %d\n", nb_elements(A->racine));

    printf("\n\nL'hauteur de l'arbre: %d\n", hauteur(A->racine));

    return 0;
}
