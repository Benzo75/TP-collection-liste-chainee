#include "header.h"

///Fonction d'initialisation de la collection (retourne un pointeur sur l'ancre).
t_collec* initCollec()
{
    t_collec* collec;
    collec = (t_collec*) malloc(sizeof(t_collec));   ///On alloue dynamiquement l'ancre.

    if(collec == NULL) ///Si une des deux allocs dynamiques s'est mal passé :
    {
        exit(EXIT_FAILURE); ///On quitte le programme.
    }

    collec->first = NULL;
    collec->last = NULL;

    return collec;
}


///Fonction d'initialisation d'une carte (retourne un pointeur sur la carte).
t_carte* initCarte()
{
    t_carte* carte;
    carte = (t_carte*) malloc(sizeof(t_carte));   ///On alloue dynamiquement l'ancre.

    if(carte == NULL) ///Si l'alloc dynamique s'est mal passé :
    {
        exit(EXIT_FAILURE); ///On quitte le programme.
    }

    carte->next = NULL;

    return carte;
}


///Fonction pour ajouter une carte (au début de la liste).
void ajoutCarte(t_collec* collec)
{
    char transition[100];

    t_carte* newCarte=NULL;
    newCarte = (t_carte*) malloc(sizeof(t_carte));  ///Alloc dynamique d'une nouvelle carte.

    if(newCarte == NULL)    ///Si l'alloc ne marche pas :
    {
        exit(EXIT_FAILURE); ///On quitte.
    }

    ///On va maintenant demander à l'utilisateur de rentrer les champs de la nouvelle carte :

    printf(" Nom : ");
    viderBuffer();
    lire(transition, 100);
    newCarte->nom = malloc((strlen(transition)+1)*sizeof(char));
    strcpy(newCarte->nom, transition);

    printf("\n Note g%cn%crale : ", 130, 130);
    scanf("%d", &newCarte->note);

    printf(" Poste : ");
    viderBuffer();
    lire(transition, 100);
    newCarte->poste = (char*) malloc((strlen(transition)+1)*sizeof(char));
    strcpy(newCarte->poste, transition);

    printf(" Club : ");
    lire(transition, 100);
    newCarte->club = malloc((strlen(transition)+1)*sizeof(char));
    strcpy(newCarte->club, transition);

    printf(" Pays : ");
    lire(transition, 100);
    newCarte->pays = malloc((strlen(transition)+1)*sizeof(char));
    strcpy(newCarte->pays, transition);

    printf("Stats : \n VIT : ");
    scanf("%d", &newCarte->stats.vit);
    printf(" DRI : ");
    scanf("%d", &newCarte->stats.dri);
    printf(" TIR : ");
    scanf("%d", &newCarte->stats.tir);
    printf(" DEF : ");
    scanf("%d", &newCarte->stats.def);
    printf(" PAS : ");
    scanf("%d", &newCarte->stats.pas);
    printf(" PHY : ");
    scanf("%d", &newCarte->stats.phy);

    insertionDebut(collec, newCarte);

}


///Fonction d'insertion d'une carte en début de liste.
void insertionDebut(t_collec* collec, t_carte* newCarte)
{
    if(collec->first == NULL)
    {
        newCarte->next = NULL;
        collec->first = newCarte;
        collec->last = newCarte;
    }
    else if(collec->first != NULL)
    {
        newCarte->next = collec->first;
        collec->first = newCarte;
    }
}


