typedef struct Element Element;
struct Element {
    int nombre;
    struct Element *suivant;
    struct Element *prec;
};

typedef struct Liste Liste;
struct Liste {
    Element *premier;
};

Liste *initialisation();
void insertion(Liste *liste, int nvNombre);
void suppression(Liste *liste);
void afficherListe(Liste *liste);

void insertion_milieu(Liste *liste, int nvNombre, int pos);
int taille_liste(Liste *liste);
void suppr_milieu(Liste *liste, int pos);
void destruct_liste(Liste *liste);