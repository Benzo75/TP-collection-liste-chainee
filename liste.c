#include "header.h"

///Fonction d'initialisation de la collection R(pointeur sur la collection).
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


///Fonction d'initialisation d'une carte R(pointeur sur la carte).
t_carte* initCarte()
{
    t_carte* carte;
    carte = (t_carte*) malloc(sizeof(t_carte));   ///On alloue dynamiquement la carte.

    if(carte == NULL) ///Si l'alloc dynamique s'est mal passé :
    {
        exit(EXIT_FAILURE); ///On quitte le programme.
    }

    carte->next = NULL;

    return carte;
}


///Fonction pour ajouter une carte en début de liste P(la collection).
void ajoutCarte(t_collec* collec)
{
    char transition[100];
    int nomUnique = 0;
    t_carte* current = collec->first;   ///On déclare un pointeur sur carte et on l'initialise sur la première carte.
    int i = 0;  ///Compteur du nombre de cartes.

    ///Test pour savoir si la limite de cartes n'est pas atteinte (limite = 100) :
    while(current != NULL)
    {
     i++;   ///On incrémente le compteur de carte.
     current = current->next;   ///on passe à la carte suivante.
    }
    if(i >= 100)
    {
        printf("La limite de carte (100) est atteinte !\n");
        trait();
    }

    else    ///Si la limite n'est pas atteinte :
    {
    t_carte* newCarte=NULL;
    newCarte = (t_carte*) malloc(sizeof(t_carte));  ///Alloc dynamique d'une nouvelle carte.

    if(newCarte == NULL)    ///Si l'alloc ne marche pas :
    {
        exit(EXIT_FAILURE); ///On quitte.
    }

    ///On va maintenant demander à l'utilisateur de rentrer les champs de la nouvelle carte :

    viderBuffer();

    while(nomUnique == 0)
    {
        printf(" Nom : ");

    lire(transition, 100);
    if(checkNom(collec, transition) != NULL)
        {
            printf("Une carte ayant ce nom existe d%cj%c !\n", 130, 133);

            nomUnique = 0;
        }
        else
        {
            nomUnique = 1;
        }
    }

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

}


///Fonction d'insertion d'une carte en début de liste P(la collection).
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


///Fonction d'insertion d'une carte en fin de liste P(la collection).
void insertionFin(t_collec* collec, t_carte* newCarte)
{
    t_carte* current = collec->last;    ///On déclare un pointeur sur une carte courant et on l'initialise  sur la dernière carte.

    if(collec->first == NULL)   ///Si la liste est vide :
    {
        newCarte->next = NULL;
        collec->first = newCarte;
        collec->last = newCarte;
    }
    else if(collec->first != NULL)  ///Sinon :
    {
        current->next = newCarte;
        collec->last = newCarte;
    }
}


///Fonction de suppression d'une carte P(la collection, la carte à supprimer).
void supprimer(t_collec* collec, t_carte* carte)
{
    int done = 0;
    t_carte* current = collec->first;   ///On déclare un pointeur de parcours sur une carte, et on l'initialise sur la première carte.

    if(collec->first == carte)    ///Si la carte à supprimer est la première :
    {
        collec->first = current->next;  ///On fait pointer l'ancre sur la deuxième carte.
        free(carte);    ///Et on supprime la première carte.
    }
    else if(carte->next != NULL)   ///Si la carte à supprimer n'est pas la première carte ni la dernière :
    {
        while(done == 0)
        {
            if(current->next == carte)  ///Si la carte suivante est celle à supprimer :
            {
                current->next = carte->next;    ///On fait pointer la carte précédant celle à supprimer sur la carte suivant celle à supprimer.
                free(carte->nom);
                free(carte->poste);
                free(carte->club);
                free(carte->pays);
                free(carte);    ///On supprime la carte.
                done = 1;   ///On indique que c'est bon pour sortir de la boucle.
            }
            else    ///Si la carte à supprimer n'est pas la suivante.
            {
                current = current->next;    ///on passe à la carte suivante.
            }
        }
    }
    else    ///Si la carte à supprimer est la dernière :
    {
        while(done == 0)
        {
            if(current->next == carte)  ///Si la carte suivante est celle à supprimer :
            {
                current->next = carte->next;    ///On fait pointer la carte précédant celle à supprimer sur la carte suivant celle à supprimer. (ici NULL)
                free(carte->nom);
                free(carte->poste);
                free(carte->club);
                free(carte->pays);
                free(carte);    ///On supprime la carte.
                collec->last = current; ///On indique que current est la dernière carte.
                done = 1;   ///On indique que c'est bon pour sortir de la boucle.
            }
            else    ///Si la carte à supprimer n'est pas la suivante.
            {
                current = current->next;    ///on passe à la carte suivante.
            }
        }
    }
}

