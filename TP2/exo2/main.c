#include <stdio.h>
#include "liste_chainee.c"

int main() {
    Liste *maListe = initialisation();
    int option, val, pos;

    insertion(maListe, 2);
    insertion(maListe, 9);
    afficherListe(maListe);
    insertion_milieu(maListe, 66, 3);
    afficherListe(maListe);
    suppr_milieu(maListe, 4);
    afficherListe(maListe);
    destruct_liste(maListe);
    afficherListe(maListe);
    // inverse_liste(maListe);
    // afficherListe(maListe);

    return 0;
}