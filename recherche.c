#include "header.h"

///Fonction de recherche d'une fiche par son nom R(pointeur sur la carte trouvée) P(la collection).
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


///Fonction de recherche de l'existance d'une fiche par son nom R(pointeur sur la carte trouvée) P(la collection, le nom).
t_carte* checkNom(t_collec* collec, char nom[100])
{
    t_carte* current;
    t_carte* carte = NULL;
    int found = 0;

    current = collec->first;

    while(found == 0 && current != NULL)
    {

        if(strcmp(current->nom, nom) == 0)
        {
            carte = current;
            found = 1;
        }
        else
        {
            current = current->next;
        }
    }

    return carte;
}


///Fonction de recherche de fiches par leur note générale P(la collection).
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
        printf("Aucune carte n'ayant cette note g%cn%crale n'a %ct%c trouv%ce\n.", 130, 130, 130, 130, 130);
        rechercheNote(collec);
    }
    if(found != 0 && current == NULL)
    {
        printf("\n %d cartes ayant cette note g%cn%crale ont %ct%c trouv%ces.\n", found, 130, 130, 130, 130, 130);
    }
}


///Fonction de recherche de fiches par leur poste P(la collection).
void recherchePoste(t_collec* collec)
{
    char target[100];
    t_carte* current;
    int found = 0;

    printf("\nEntrez le poste %c rechercher : ", 133);

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


///Fonction de recherche de fiches par leur club P(la collection).
void rechercheClub(t_collec* collec)
{
    char target[100];
    t_carte* current;
    int found = 0;

    printf("\nEntrez le club %c rechercher : ", 133);
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
        rechercheClub(collec);
    }
    if(found != 0 && current == NULL)
    {
        printf("\n %d cartes ayant ce club ont %ct%c trouv%ces.\n", found, 130, 130, 130);
    }
}


///Fonction de recherche de fiches par leur pays P(la collection).
void recherchePays(t_collec* collec)
{
    char target[100];
    t_carte* current;
    int found = 0;

    printf("\nEntrez le pays %c rechercher : ", 133);
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
        recherchePays(collec);
    }
    if(found != 0 && current == NULL)
    {
        printf("\n %d cartes ayant ce pays ont %ct%c trouv%ces.\n", found, 130, 130, 130);
    }
}


///Fonction de recherche de fiches par leur note de VIT P(la collection).
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


///Fonction de recherche de fiches par leur note de DRI P(la collection).
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


///Fonction de recherche de fiches par leur note de TIR P(la collection).
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


///Fonction de recherche de fiches par leur note de DEF P(la collection).
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


///Fonction de recherche de fiches par leur note de PAS P(la collection).
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


///Fonction de recherche de fiches par leur note de PHY P(la collection)
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

