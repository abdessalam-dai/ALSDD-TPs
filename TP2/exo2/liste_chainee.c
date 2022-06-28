#include "list_chainee.h"
#include <stdlib.h>

Liste *initialisation() {
    Liste* new_list;
    Element *head;

    head = (Element*)malloc(sizeof(Element));
    head->nombre = 0;
    head->suivant = NULL;


    new_list = (Liste*)malloc(sizeof(Liste));
    new_list->premier = head;

    return new_list;
}

void insertion(Liste *liste, int nvNombre) {
    Element *new_element;

    new_element = (Element*)malloc(sizeof(Element));
    new_element->nombre = nvNombre;
    new_element->suivant = liste->premier;
    
    liste->premier = new_element;
}

void suppression(Liste *liste) {
    if (liste->premier != NULL) {
        Element *elem_a_suppr;
        elem_a_suppr = liste->premier;
        liste->premier = liste->premier->suivant;
        free(elem_a_suppr);
    } else {
        printf("La liste est vide!\n");
    }

}

void afficherListe(Liste *liste) {
    printf("\n");
    if (liste->premier != NULL) {
        Element *p;

        printf("Affichage de la liste:\n ");
        p = liste->premier;
        while (p != NULL) {
            printf("%d => ", p->nombre);
            p = p->suivant;
        }
        printf("NULL\n");
    } else {
        printf("La liste est vide!\n");
    }
}

int taille_liste(Liste *liste) {
    int taille=0;

    Element *p;
    p = liste->premier;
    while (p != NULL) {
        taille++;
        p = p->suivant;
    }

    return taille;
}

void insertion_milieu(Liste *liste, int nvNombre, int pos) {
    Element *p;
    Element *q;
    Element *nvP;

    if (pos <= 0 || pos > taille_liste(liste)) {
        printf("Invalid position!\n");
    } else if (pos == 1) {
        insertion(liste, nvNombre);
    } else {
        int i = 1;
        p = NULL;
        q = liste->premier;
        while (q != NULL && i < pos) {
            p = q;
            q = q->suivant;
            i++;
        }
        nvP = (Element*)malloc(sizeof(Element));
        nvP->nombre = nvNombre;
        nvP->suivant = q;
        p->suivant = nvP;
    }
}

void suppr_milieu(Liste *liste, int pos) {
    Element *p;
    Element *q;

    if (pos <= 0 || pos > taille_liste(liste)) {
        printf("Invalid position!\n");
    } else if (pos == 1) {
        suppression(liste);
    } else {
        int i = 1;
        p = NULL;
        q = liste->premier;
        while (q != NULL && i < pos) {
            p = q;
            q = q->suivant;
            i++;
        }
        p->suivant = q->suivant;
        free(q);
    }
}

void destruct_liste(Liste *liste) {
    while (liste->premier != NULL) {
        suppression(liste);
    }
}

void inverse_liste(Liste *liste) {
    Element *P; Element *N;
    P = NULL;
    while (liste->premier != NULL) {
        N = liste->premier->suivant;
        liste->premier->suivant = P;
        P = liste->premier;
        liste->premier = N;
    }
    liste->premier = P;
}