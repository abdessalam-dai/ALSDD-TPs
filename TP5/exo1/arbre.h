typedef struct Node Node;
typedef struct Arbre Arbre;

struct Node {
    int val;
    Node *fd;
    Node *fg;
};

struct Arbre {
    Node *racine;
};

Arbre *init_arbre();
Node *creer_element(int nv_val);
int arbre_vide(Arbre *A);
void afficher_pre_ordre(Node *racine);
void afficher_in_ordre(Node *racine);
void afficher_post_ordre(Node *racine);
int nb_elements(Node *racine);
int est_feuille(Node *racine);
void afficher_feuilles(Node *racine);
int hauteur(Node *racine);
