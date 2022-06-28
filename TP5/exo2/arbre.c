#include <stdlib.h>
#include <string.h>
#include "arbre.h"

ARB *creer_arbre(int nv_val) {
    ARB *arbre = malloc(sizeof(ARB));

    arbre->val = nv_val;
    arbre->fd = NULL;
    arbre->fg = NULL;

    return arbre;
}

void afficher_croissant(ARB *arbre) {
    if (arbre != NULL) {
        afficher_croissant(arbre->fg);
        printf("%d, ", arbre->val);
        afficher_croissant(arbre->fd);
    }
}

void afficher_arbre(ARB *arbre) {
    if (arbre == NULL) {
        printf("%s", "_");
    } else {
        printf("(");
        afficher_arbre(arbre->fg);

        printf(",");
        printf("%d", arbre->val);
        printf(",");

        afficher_arbre(arbre->fd);
        printf(")");
    }
}

ARB *inserer(ARB *arbre, int nv_val) {
    if (arbre == NULL)
        return creer_arbre(nv_val);

    if (nv_val > arbre->val) {
        arbre->fd = inserer(arbre->fd, nv_val);
    } else {
        arbre->fg = inserer(arbre->fg, nv_val);
    }
    return arbre;
}

ARB *trouver_noeud(ARB *arbre, int val) {
    if (arbre == NULL || arbre->val == val)
        return arbre;

    if (val > arbre->val) {
        return trouver_noeud(arbre->fd, val);
    } else {
        return trouver_noeud(arbre->fg, val);
    }
}
