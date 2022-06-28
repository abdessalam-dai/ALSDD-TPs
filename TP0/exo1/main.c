#include <stdio.h>

int main() {
    int t[100], occ[100];
    int i, n;
    printf("Donnez la taille du tableau:\n");
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &t[i]);
    }
    for (i=0; i<100; i++) {
        occ[i] = 0;
    }
    for (i=0; i<n; i++) {
        occ[t[i]]++;
    }
    for (i=0; i<100; i++) {
        if (occ[i] != 0) {
            printf("%d est repeter %d fois.\n", i, occ[i]);
        }
    }

    return 0;
}

