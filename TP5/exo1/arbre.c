#include <stdlib.h>
#include "arbre.h"

Arbre *init_arbre() {
    Arbre *A = malloc(sizeof(Arbre));

    A->racine = NULL;

    return A;
}

Node *creer_element(int nv_val) {
    Node *node = malloc(sizeof(Node));

    node->val = nv_val;
    node->fd = NULL;
    node->fg = NULL;

    return node;
}

int arbre_vide(Arbre *A) {
    return A->racine == NULL;
}

void afficher_pre_ordre(Node *racine) {
    if (racine != NULL) {
        printf("%d, ", racine->val);
        afficher_pre_ordre(racine->fg);
        afficher_pre_ordre(racine->fd);
    }
}

void afficher_in_ordre(Node *racine) {
    if (racine != NULL) {
        afficher_pre_ordre(racine->fg);
        printf("%d, ", racine->val);
        afficher_pre_ordre(racine->fd);
    }
}

void afficher_post_ordre(Node *racine) {
    if (racine != NULL) {
        afficher_pre_ordre(racine->fg);
        afficher_pre_ordre(racine->fd);
        printf("%d, ", racine->val);
    }
}

int nb_elements(Node *racine) {
    if (racine == NULL) {
        return 0;
    } else {
        return 1 + nb_elements(racine->fd) + nb_elements(racine->fg);
    }
}

int est_feuille(Node *racine) {
    return racine->fd == NULL && racine->fg == NULL;
}

void afficher_feuilles(Node *racine) {
    if (racine != NULL) {
        if (est_feuille(racine)) {
            printf("%d, ", racine->val);
        } else {
            afficher_feuilles(racine->fd);
            afficher_feuilles(racine->fg);
        }
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

int hauteur(Node *racine) {
    if (racine == NULL || est_feuille(racine)) {
        return 0;
    } else {
        return 1 + max(hauteur(racine->fd), hauteur(racine->fg));
    }
}
