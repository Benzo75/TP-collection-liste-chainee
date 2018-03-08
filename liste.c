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
    carte = (t_carte*) malloc(sizeof(t_carte));   ///On alloue dynamiquement la carte.

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


///Fonction de recherche d'une fiche par son nom.
t_carte* rechercheNom(t_collec* collec)
{
    char target[100];
    t_carte* current;
    t_carte* carte;
    int found = 0;

    printf("\nEntrez le nom %c rechercher : ", 133);
    fgets(target, 100, stdin);
    target[strlen(target)-1]='\0';     ///Retire le "\n" à la fin de la chaîne saisie.

    current = collec->first;

    while(found == 0 && current != NULL)
    {

        if(strcmp(current->nom, target) == 0)
        {
            carte = current;
            found = 1;
        }
        else
        {
            current = current->next;
        }
    }
    if(found == 0 && current == NULL)
    {
        printf("Aucune carte n'ayant ce nom n'a %ct%c trouv%ce.", 130, 130, 130);
        carte = rechercheNom(collec);
    }

    return carte;
}


///Fonction de recherche de fiches par leur note générale.
void rechercheNote(t_collec* collec)
{
    int target;
    t_carte* current;
    int found = 0;

    printf("Entrez la note %c rechercher : ", 133);
    scanf("%d", &target);

    current = collec->first;

    while(current != NULL)
    {

        if(current->note == target)
        {
            found++;
            afficherCarte(current);
        }

        current = current->next;

    }

    if(found == 0 && current == NULL)
    {
        printf("Aucune carte n'ayant cette note g%cn%crale n'a %ct%c trouv%ce.", 130, 130, 130, 130, 130);
        rechercheNote(collec);
    }
    if(found != 0 && current == NULL)
    {
        printf("\n %d cartes ayant cette note g%cn%crale ont %ct%c trouv%ces.\n", found, 130, 130, 130, 130, 130);
    }
}


///Fonction de recherche de fiches par leur poste.
void recherchePoste(t_collec* collec)
{
    char target[100];
    t_carte* current;
    int found = 0;

    printf("\nEntrez le poste %c rechercher : ", 133);
    viderBuffer();
    fgets(target, 100, stdin);
    target[strlen(target)-1]='\0';     ///Retire le "\n" à la fin de la chaîne saisie.

    current = collec->first;

    while(current != NULL)
    {
        if(strcmp(current->poste, target) == 0)
        {
            found++;
            afficherCarte(current);
        }
        current = current->next;
    }

    if(found == 0 && current == NULL)
    {
        printf("Aucune carte n'ayant ce poste n'a %ct%c trouv%ce.", 130, 130, 130);
        recherchePoste(collec);
    }
    if(found != 0 && current == NULL)
    {
        printf("\n %d cartes ayant ce poste ont %ct%c trouv%ces.\n", found, 130, 130, 130);
    }
}


///Fonction de recherche de fiches par leur club.
void rechercheClub(t_collec* collec)
{
    char target[100];
    t_carte* current;
    int found = 0;

    printf("\nEntrez le club %c rechercher : ", 133);
    viderBuffer();
    fgets(target, 100, stdin);
    target[strlen(target)-1]='\0';     ///Retire le "\n" à la fin de la chaîne saisie.

    current = collec->first;

    while(current != NULL)
    {
        if(strcmp(current->club, target) == 0)
        {
            found++;
            afficherCarte(current);
        }
        current = current->next;
    }

    if(found == 0 && current == NULL)
    {
        printf("Aucune carte n'ayant ce club n'a %ct%c trouv%ce.", 130, 130, 130);
        recherchePoste(collec);
    }
    if(found != 0 && current == NULL)
    {
        printf("\n %d cartes ayant ce club ont %ct%c trouv%ces.\n", found, 130, 130, 130);
    }
}


///Fonction de recherche de fiches par leur pays.
void recherchePays(t_collec* collec)
{
    char target[100];
    t_carte* current;
    int found = 0;

    printf("\nEntrez le pays %c rechercher : ", 133);
    viderBuffer();
    fgets(target, 100, stdin);
    target[strlen(target)-1]='\0';     ///Retire le "\n" à la fin de la chaîne saisie.

    current = collec->first;

    while(current != NULL)
    {
        if(strcmp(current->pays, target) == 0)
        {
            found++;
            afficherCarte(current);
        }
        current = current->next;
    }

    if(found == 0 && current == NULL)
    {
        printf("Aucune carte n'ayant ce pays n'a %ct%c trouv%ce.", 130, 130, 130);
        recherchePoste(collec);
    }
    if(found != 0 && current == NULL)
    {
        printf("\n %d cartes ayant ce pays ont %ct%c trouv%ces.\n", found, 130, 130, 130);
    }
}


///Fonction de recherche de fiches par leur note de VIT.
void rechercheVIT(t_collec* collec)
{
    int target;
    t_carte* current;
    int found = 0;

    printf("Entrez la note de VIT %c rechercher : ", 133);
    scanf("%d", &target);

    current = collec->first;

    while(current != NULL)
    {

        if(current->stats.vit == target)
        {
            found++;
            afficherCarte(current);
        }

        current = current->next;

    }

    if(found == 0 && current == NULL)
    {
        printf("Aucune carte n'ayant cette note de VIT n'a %ct%c trouv%ce.\n", 130, 130, 130);
        rechercheVIT(collec);
    }
    if(found != 0 && current == NULL)
    {
        printf("\n %d cartes ayant cette note de VIT ont %ct%c trouv%ces.\n", found, 130, 130, 130);
    }
}


///Fonction de recherche de fiches par leur note de VIT.
void rechercheDRI(t_collec* collec)
{
    int target;
    t_carte* current;
    int found = 0;

    printf("Entrez la note de DRI %c rechercher : ", 133);
    scanf("%d", &target);

    current = collec->first;

    while(current != NULL)
    {

        if(current->stats.dri == target)
        {
            found++;
            afficherCarte(current);
        }

        current = current->next;

    }

    if(found == 0 && current == NULL)
    {
        printf("Aucune carte n'ayant cette note de DRI n'a %ct%c trouv%ce.\n", 130, 130, 130);
        rechercheDRI(collec);
    }
    if(found != 0 && current == NULL)
    {
        printf("\n %d cartes ayant cette note de DRI ont %ct%c trouv%ces.\n", found, 130, 130, 130);
    }
}


///Fonction de recherche de fiches par leur note de VIT.
void rechercheTIR(t_collec* collec)
{
    int target;
    t_carte* current;
    int found = 0;

    printf("Entrez la note de TIR %c rechercher : ", 133);
    scanf("%d", &target);

    current = collec->first;

    while(current != NULL)
    {

        if(current->stats.tir == target)
        {
            found++;
            afficherCarte(current);
        }

        current = current->next;

    }

    if(found == 0 && current == NULL)
    {
        printf("Aucune carte n'ayant cette note de TIR n'a %ct%c trouv%ce.\n", 130, 130, 130);
        rechercheTIR(collec);
    }
    if(found != 0 && current == NULL)
    {
        printf("\n %d cartes ayant cette note de TIR ont %ct%c trouv%ces.\n", found, 130, 130, 130);
    }
}


///Fonction de recherche de fiches par leur note de VIT.
void rechercheDEF(t_collec* collec)
{
    int target;
    t_carte* current;
    int found = 0;

    printf("Entrez la note de DEF %c rechercher : ", 133);
    scanf("%d", &target);

    current = collec->first;

    while(current != NULL)
    {

        if(current->stats.def == target)
        {
            found++;
            afficherCarte(current);
        }

        current = current->next;

    }

    if(found == 0 && current == NULL)
    {
        printf("Aucune carte n'ayant cette note de DEF n'a %ct%c trouv%ce.\n", 130, 130, 130);
        rechercheDEF(collec);
    }
    if(found != 0 && current == NULL)
    {
        printf("\n %d cartes ayant cette note de DEF ont %ct%c trouv%ces.\n", found, 130, 130, 130);
    }
}

///Fonction de recherche de fiches par leur note de VIT.
void recherchePAS(t_collec* collec)
{
    int target;
    t_carte* current;
    int found = 0;

    printf("Entrez la note de PAS %c rechercher : ", 133);
    scanf("%d", &target);

    current = collec->first;

    while(current != NULL)
    {

        if(current->stats.pas == target)
        {
            found++;
            afficherCarte(current);
        }

        current = current->next;

    }

    if(found == 0 && current == NULL)
    {
        printf("Aucune carte n'ayant cette note de PAS n'a %ct%c trouv%ce.\n", 130, 130, 130);
        recherchePAS(collec);
    }
    if(found != 0 && current == NULL)
    {
        printf("\n %d cartes ayant cette note de PAS ont %ct%c trouv%ces.\n", found, 130, 130, 130);
    }
}

///Fonction de recherche de fiches par leur note de VIT.
void recherchePHY(t_collec* collec)
{
    int target;
    t_carte* current;
    int found = 0;

    printf("Entrez la note de PHY %c rechercher : ", 133);
    scanf("%d", &target);

    current = collec->first;

    while(current != NULL)
    {

        if(current->stats.phy == target)
        {
            found++;
            afficherCarte(current);
        }

        current = current->next;

    }

    if(found == 0 && current == NULL)
    {
        printf("Aucune carte n'ayant cette note de PHY n'a %ct%c trouv%ce.\n", 130, 130, 130);
        recherchePHY(collec);
    }
    if(found != 0 && current == NULL)
    {
        printf("\n %d cartes ayant cette note de PHY ont %ct%c trouv%ces.\n", found, 130, 130, 130);
    }
}





