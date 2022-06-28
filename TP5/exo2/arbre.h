typedef struct ARB ARB;

struct ARB {
    int val;
    ARB *fd;
    ARB *fg;
};

ARB *creer_arbre(int nv_val);
void afficher_croissant(ARB *arbre);
void afficher_arbre(ARB *arbre);
ARB *inserer(ARB *arbre, int nv_val);
ARB *trouver_noeud(ARB *arbre, int val);
