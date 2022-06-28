#include "Liste_chainee.h"
#include <stdlib.h>

// initialisation ed la liste
Liste *initialisation() {
    Liste* new_list;
    Element *head;

    // Creer le premier element
    head = malloc(sizeof(Element));
    head->nombre = 0;
    head->suivant = NULL;
    head->prec = NULL;

    // Creer la liste
    new_list = malloc(sizeof(Liste));
    new_list->premier = head;

    return new_list;
}

// insertion au debut de la liste
void insertion(Liste *liste, int nvNombre) {
    Element *new_element;

    // Creer le nouveau element
    new_element = malloc(sizeof(Element));
    new_element->nombre = nvNombre;

    // Pointer son suivant vers le premier de la liste
    new_element->suivant = liste->premier;
    // Pointer son precedant vers NULL
    new_element->prec = NULL;

    // Pointer le precedant de le premier vers le nouveau
    liste->premier->prec = new_element;

    // Pointer le premier element vers le nouveau
    liste->premier = new_element;
}

// suppression au debut de la liste
void suppression(Liste *liste) {
    if (liste->premier != NULL) {
        Element *elem_a_suppr = liste->premier;

        // Avancer le premier element vers le suivant
        liste->premier = liste->premier->suivant;

        // Liberer le premier element a supprimer
        free(elem_a_suppr);
    } else {
        printf("La liste est vide!\n");
    }

}

// afficher la liste
void afficherListe(Liste *liste) {
    printf("\n");
    if (liste->premier != NULL) {
        Element *p;

        printf("Affichage de la liste:\n NULL <= ");
        p = liste->premier;
        while (p != NULL) {
            printf("(%d)", p->nombre);
            printf(p->suivant == NULL ? " => " : " <=> ");
            p = p->suivant;
        }
        printf("NULL\n");
    } else {
        printf("La liste est vide!\n");
    }
}

// calculer la taille de la liste
int taille_liste(Liste *liste) {
    int taille = 0;

    Element *p = liste->premier;
    while (p != NULL) {
        taille++;
        p = p->suivant;
    }

    return taille;
}

// insertion d'un element en milieu de la liste
void insertion_milieu(Liste *liste, int nvNombre, int pos) {
    Element *p, *q, *nvP;

    if (pos <= 0 || pos > taille_liste(liste)) {
        printf("Invalid position!\n");
    } else if (pos == 1) {  // Si (pos = 1) Inserer au debut du liste
        insertion(liste, nvNombre);
    } else {
        int i = 1;
        p = NULL;           // Element precedant
        q = liste->premier; // Element courant
        while (q != NULL && i < pos) {
            p = q;
            q = q->suivant;
            i++;
        }
        nvP = malloc(sizeof(Element));  // Creer le nouveau element
        nvP->nombre = nvNombre;
        nvP->suivant = q;
        nvP->prec = p;
        p->suivant = nvP;
    }
}

// suppression d'un element en milieu de la liste
void suppr_milieu(Liste *liste, int pos) {
    Element *p;
    Element *q;

    if (pos <= 0 || pos > taille_liste(liste)) {
        printf("Invalid position!\n");
    } else if (pos == 1) {
        suppression(liste); // Si (pos = 1) Supprimer au debut de la liste
    } else {
        int i = 1;
        p = NULL;           // Element precedant
        q = liste->premier; // Element courant
        while (q != NULL && i < pos) {
            p = q;
            q = q->suivant;
            i++;
        }
        p->suivant = q->suivant; // suivant de  p Pointe vers: q->suivant
        q->suivant->prec = p;    // prec de  q->suivant pointe vers: p
        free(q);
    }
}

// destruction de la liste
void destruct_liste(Liste *liste) {
    while (liste->premier != NULL) {
        suppression(liste);
    }
}