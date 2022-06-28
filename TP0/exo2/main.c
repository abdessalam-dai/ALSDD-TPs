// #include <stdio.h>

// #define nb_max 2

// struct ville {
//         char nom[100];
//         int nb_habitants;
//     };

// void tri(struct ville villes[nb_max]) {
//     for (int i=0; i<nb_max; i++) {
//         for (int j=0; j<nb_max; j++) {
//             if (villes[i].nb_habitants < villes[j].nb_habitants) {
//                 struct ville temp;
//                 temp = villes[i];
//                 villes[i] = villes[j];
//                 villes[j] = temp;
//             }
//         }
//     }
// }

// int main() {
//     struct ville villes[nb_max];

//     /* Lire les villes et les nombres d'habitants */
//     for (int i=0; i<nb_max; i++) {
//         scanf("%s %d", villes[i].nom, &villes[i].nb_habitants);
//     }

//     /* Tri le tableau des villes en ordre croissant de nombre d'habitants */
//     tri(villes);

//     printf("\n%s\n\n", "LES VILLES PAR ORDRE CROISSANT DE NOMBRE D'HABITANTS:");
//     for (int i=0; i<nb_max; i++) {
//         printf("%s %s\n%s %d\n\n", "Ville:", villes[i].nom, "Nombre d'habitants:", villes[i].nb_habitants);
//     }
// }



#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nom[20];
    int nbr;
}ville;

typedef struct node {
    ville data;
    struct node * next;
}node;

node * create_list(int n) {
    node * head = NULL;
    node * p = NULL;
    node * temp = NULL;

    for (int i=0; i<n; i++) {
        temp = (node*)malloc(sizeof(node));

        printf("\nDonnez le nom de la ville %d: ", i+1);
        scanf("%s", temp->data.nom);

        printf("\nDonnez le nombre d'habitants de la ville %d: ", i+1);
        scanf("%d", &(temp->data.nbr));

        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            p = head;

            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp;
        }
    }

    return head;
}

node * sort(node * head) {
    node * p;
    node * p1;
    ville temp;

    p = head;

    while (p != NULL) {
        p1 = p->next;
        while (p1 != NULL) {
            if (p->data.nbr > p1->data.nbr) {
                temp = p->data;
                p->data = p1->data;
                p1->data = temp;
            }
            p1 = p1->next;
        }
        p = p->next;
    }

    return head;
}

void display_list(node * head) {
    node * p = head;
    int i = 1;
    printf("   Ville \t Nombre d'habintants\n");
    while (p != NULL) {
        printf("%d. %s \t %d\n", i, p->data.nom, p->data.nbr);
        p = p->next;
        i++;
    }
}

int main() {
    int n;
    node * head = NULL;

    printf("Donnez le nombre des villes: ");
    scanf("%d", &n);

    head = create_list(n);

    head = sort(head);

    display_list(head);

    return 0;
}