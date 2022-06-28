#include <stdlib.h>
#include "file.h"

File *initialiser() {
    Element *premier = malloc(sizeof(Element)),
            *dernier = malloc(sizeof(Element));
    premier = NULL;
    dernier = NULL;

    File *file = malloc(sizeof(file));
    file->premier = premier;
    file->dernier = dernier;

    return file;
}

bool fileVide(File *file) {
    return file->premier == NULL;
}

void enfiler(File *file, int nvNombre) {
    Element *nvElement = malloc(sizeof(Element));
    nvElement->nombre = nvNombre;
    nvElement->suivant = NULL;

    if (fileVide(file)) {
        file->premier = nvElement;
    } else {
        file->dernier->suivant = nvElement;
    }

    file->dernier = nvElement;
}

int defiler(File *file) {
    if (fileVide(file)) {
        printf("Vous pouvez pas defiler, la file est vide!");
    } else {
        Element *premier = file->premier;
        int x = file->premier->nombre;
        file->premier = file->premier->suivant;
        free(premier);

        return x;
    }
}

void afficherFile(File *file) {
    if (fileVide(file)) {
        printf("La file est vide!");
    } else {
        Element *elem = file->premier;
        printf("\n(Tete):");
        while (elem != NULL) {
            printf(" [%d] %s", elem->nombre, elem->suivant!=NULL?"-":"");
            elem = elem->suivant;
        }
        printf(":(Queue)");
    }
    printf("\n\n");
}

int nombreElementsFile(File *file) {
    if (fileVide(file)) {
        return 0;
    } else {
        File *nv_file = initialiser();
        int nbElements = 0;

        while (!fileVide(file)) {
            enfiler(nv_file, defiler(file));

            nbElements++;
        }

        while (!fileVide(nv_file)) {
            enfiler(file, defiler(nv_file));
        }

        return nbElements;
    }
}

// void afficherPileInverser(Pile *pile) {
//     Pile *nv_pile = initialiser();
//     int sommet;

//     printf("\nAffichage inverser: \n");
//     if (pileVide(pile)) {

//     } else {
//         while (!pileVide(pile)) {
//             sommet = depiler(pile);
//             empiler(nv_pile, sommet);
//         }

//         while (!pileVide(nv_pile)) {
//             sommet = depiler(nv_pile);
//             printf("\n| %d |\n-----", sommet);
//             empiler(pile, sommet);
//         }
//         printf("\n");
//     }
// }
