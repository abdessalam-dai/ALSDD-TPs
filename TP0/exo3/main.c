#include <stdio.h>

#define NB_MAX 100

typedef struct {
    char nom[30];
    float moyenne;
}etudiant;

void actualise_moyennes(etudiant etudiants[NB_MAX], int nb_etudiants) {
    for (int i=0; i<nb_etudiants; i++) {
        if (etudiants[i].moyenne < 10) {
            etudiants[i].moyenne += 1;
        } else if (etudiants[i].moyenne <= 15) {
            etudiants[i].moyenne += 0.5;
        }
    }
}

int main() {
    etudiant etudiants[NB_MAX];

    int nb_etudiants;
    printf("%s", "Entrez le nombre d'etudiants: ");
    scanf("%d", &nb_etudiants);

    for (int i=0; i<nb_etudiants; i++) {
        printf("\nEntre le nom de l'etudiant %d: ", i+1);
        scanf("%s", etudiants[i].nom);

        printf("Entre la moyenne de l'etudiant %d: ", i+1);
        scanf("%f", &etudiants[i].moyenne);
    }

    actualise_moyennes(etudiants, nb_etudiants);

    printf("\n%s\n", "Les moyennes des etudiants: ");
    for (int i=0; i<nb_etudiants; i++) {
        printf("%s : %.2f\n", etudiants[i].nom, etudiants[i].moyenne);
    }
}