#include <stdio.h>
#include <stdlib.h>

typedef struct personne {
    char nom[50], prenom[50];
    int age;
}personne;

int main() {
    personne *pa=malloc(sizeof(personne)), *pb=malloc(sizeof(personne));

    scanf("%s %s", pa->nom, pa->prenom);
    scanf("%d", &(pa->age));
    scanf("%s %s", pb->nom, pb->prenom);
    scanf("%d", &(pb->age));

    printf("%s %s\n", pa->age < pb->age ? pa->nom : pb->nom, pa->age < pb->age ? pa->prenom : pb->prenom);

    return 0;
}