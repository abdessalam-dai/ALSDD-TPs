#include <stdio.h>
#include "file.c"

int main() {
    File *maFile = initialiser();

    enfiler(maFile, 4);
    enfiler(maFile, 8);
    enfiler(maFile, 15);
    enfiler(maFile, 16);
    enfiler(maFile, 23);
    enfiler(maFile, 42);

    printf("\nEtat de la file: \n");
    afficherFile(maFile);

    printf("Je defile %d\n", defiler(maFile));
    printf("Je defile %d\n", defiler(maFile));

    printf("\nEtat de la file: \n");
    afficherFile(maFile);

    printf("\nLe nombre d'elements de la file: %d\n\n", nombreElementsFile(maFile));
    return 0;
}