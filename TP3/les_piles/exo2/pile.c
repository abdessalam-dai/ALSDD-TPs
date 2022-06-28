#include <stdlib.h>
#include "pile.h"

Pile *initialiser() {
    Element *premier = malloc(sizeof(Element));
    premier = NULL;

    Pile *pile = malloc(sizeof(Pile));
    pile->premier = premier;

    return pile;
}

void empiler(Pile *pile, int nvNombre) {
    Element *nvElement = malloc(sizeof(Element));
    nvElement->nombre = nvNombre;
    nvElement->suivant = pile->premier;

    pile->premier = nvElement;
}

int depiler(Pile *pile) {
    if (pileVide(pile)) {
        printf("Vous pouvez pas depiler, la pile est vide!");
    } else {
        Element *sommet = pile->premier;
        int x = pile->premier->nombre;
        pile->premier = pile->premier->suivant;
        free(sommet);

        return x;
    }
}

void afficherPile(Pile *pile) {
    if (pileVide(pile)) {
        printf("La pile est vide!");
    } else {
        Element *sommet = pile->premier;
        printf("\n(Sommet)\n  ↓\n------");
        while (sommet != NULL) {
            printf("\n| %d |\n------", sommet->nombre);
            sommet = sommet->suivant;
        }
    }
    printf("\n\n");
}


bool pileVide(Pile *pile) {
    return pile->premier == NULL;
}

int sommetPile(Pile *pile) {
    if (pileVide(pile)) {
        printf("La pile est vide!");
    } else {
        int sommet = depiler(pile);
        empiler(pile, sommet);

        return sommet;
    }
}

int nombreElementsPile(Pile *pile) {
    if (pileVide(pile)) {
        return 0;
    } else {
        Pile *nv_pile = initialiser();
        int nbElements = 0;

        while (!pileVide(pile)) {
            empiler(nv_pile, depiler(pile));

            nbElements++;
        }

        while (!pileVide(nv_pile)) {
            empiler(pile, depiler(nv_pile));
        }

        return nbElements;
    }
}

void afficherPileInverser(Pile *pile) {
    printf("\nAffichage inverser: \n");
    if (pileVide(pile)) {

    } else {
        Pile *nv_pile = initialiser();
        int sommet;

        while (!pileVide(pile)) {
            empiler(nv_pile, depiler(pile));
        }
        printf("\n------");
        while (!pileVide(nv_pile)) {
            sommet = depiler(nv_pile);
            printf("\n| %d |\n------", sommet);
            empiler(pile, sommet);
        }
        printf("\n");
    }
}
