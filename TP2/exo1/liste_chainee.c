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