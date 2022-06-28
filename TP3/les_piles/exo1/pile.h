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