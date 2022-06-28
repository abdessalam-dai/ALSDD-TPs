#include <stdio.h>

#define MAX_LEN 5

int sommeTab(int tab[MAX_LEN], int i) {
    if (i == MAX_LEN-1) return tab[i];

    return tab[i] + sommeTab(tab, i+1);
}

int main() {
    int tab[MAX_LEN];
    for (int i=0; i<MAX_LEN; i++) {
        printf("Entrez la valeur de %deme element : ", i+1);
        scanf("%d", &tab[i]);
    }
    printf("La somme des elements de tableau est : %d\n", sommeTab(tab, 0));

    return 0;
}
