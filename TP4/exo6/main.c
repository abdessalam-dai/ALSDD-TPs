#include <stdio.h>

#define MAX_LEN 5

void afficherTab(int tab[MAX_LEN], int len) {
    if (len != 0) {
        afficherTab(tab, len-1);
        printf("%d\n", tab[len-1]);
    }
}

int main() {
    int tab[MAX_LEN];
    for (int i=0; i<MAX_LEN; i++) {
        printf("Entrez la valeur de %deme element : ", i+1);
        scanf("%d", &tab[i]);
    }
    printf("Affichage des elements de tableau:\n");
    afficherTab(tab, MAX_LEN);

    return 0;
}
