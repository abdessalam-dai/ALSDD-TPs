#include <stdio.h>
#include "pile.c"

int main() {
    Pile *maPile = initialiser();

    empiler(maPile, 4);
    empiler(maPile, 8);
    empiler(maPile, 15);
    empiler(maPile, 16);
    empiler(maPile, 23);
    empiler(maPile, 42);

    printf("\nEtat de la pile: \n");
    afficherPile(maPile);

    printf("Je depile %d\n", depiler(maPile));
    printf("Je depile %d\n", depiler(maPile));

    printf("\nEtat de la pile: \n");
    afficherPile(maPile);

    printf("\nSommet de la pile: %d\n", sommetPile(maPile));

    printf("\nLe nombre d'elements de la pile: %d\n", nombreElementsPile(maPile));
    afficherPileInverser(maPile);
    return 0;
}