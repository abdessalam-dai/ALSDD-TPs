#include <stdlib.h>
#include "pile.h"

Pile *initialiser() {
    Element *premier = malloc(sizeof(Element));
    premier = NULL;

    Pile *pile = malloc(sizeof(Pile));
    pile->premier = premier;

    return pile;
}

int pileVide(Pile *pile) {
    return pile->premier == NULL;
}

void empiler(Pile *pile, int nvNombre) {
    Element *nvElement = malloc(sizeof(Element));
    nvElement->nombre = nvNombre;
    nvElement->suivant = pile->premier;

    pile->premier = nvElement;
}

int depiler(Pile *pile) {
    if (pileVide(pile)) {
        printf("Vous ne pouvez pas depiler, la pile est vide!");
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