#include <stdbool.h>

typedef struct Element Element;
struct Element {
    int nombre;
    Element *suivant;
};

typedef struct File File;
struct File {
    Element *premier, *dernier;
};

File *initialiser(); // initialisation de la file

bool fileVide(File *file);  // Tester si une file est vide
void enfiler(File *file, int nvNombre); // ajout d'un element a la file
int defiler(File *file);    // suppression d'un element de la file
void afficherFile(File *file);  // Afficher la file
int nombreElementsFile(File *file);  // Nombre d'elements d'une file
