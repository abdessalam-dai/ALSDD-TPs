#include <stdbool.h>

typedef struct Element Element;
struct Element {
    int nombre;
    Element *suivant;
};

typedef struct Pile Pile;
struct Pile {
    Element *premier;
};

Pile *initialiser(); // initialisation de la pile
void empiler(Pile *pile, int nvNombre); // ajout d'un element a la pile
int depiler(Pile *pile);    // suppression d'un element de la pile
void afficherPile(Pile *pile);  // Afficher la pile

bool pileVide(Pile *pile);  // Tester si une pile est vide
int sommetPile(Pile *pile); // Recuperer la valeur du sommet de la pile
int nombreElementsPile(Pile *pile);  // Nombre d'elements d'une pile
void afficherPileInverser(Pile *pile);  // Afficher les elements d'une pile en ordre inverse