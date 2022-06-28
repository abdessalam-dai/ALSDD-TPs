#include <stdio.h>

#define MAX_SIZE 2

int main() {
    int tab[MAX_SIZE], sum, *p;

    // Lecture des elements
    for (p=tab; p<tab+MAX_SIZE; p++) {
        scanf("%d", &(*p));
    }

    // Calcule la somme de ces elements
    for (p=tab; p<tab+MAX_SIZE; p++) {
        sum += *p;
    }

    printf("La somme des elements du tabluea est %d\n", sum);

    return 0;
}