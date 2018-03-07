#include "header.h"

///Fonction de sauvegarde de la collection dans un fichier.
void sauvegarde(t_collec* collec)
{
    FILE* sauvegarde;   ///Déclaration d'un pointeur sur fichier.
    t_carte* courant;   ///Déclaration d'un pointeur sur la carte à sauvegarder.

    sauvegarde = fopen("sauvegarde.txt", "w");  ///On ouvre le fichier de sauvegarde (on le crée s'il n'existe pas et on le remplace s'il existait déjà).

    if(sauvegarde == NULL) ///Si le fichier s'est mal ouvert :
    {
        exit(EXIT_FAILURE); ///On quitte le programme.
    }
printf("test1");
    ///Sauvegarde de la première carte :

    courant = collec->first;    ///On pointe sur la première cellule.
printf("test2");
    fprintf(sauvegarde, "%s\n%d\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", courant->nom, courant->note, courant->poste, courant->club, courant->pays, courant->stats.vit, courant->stats.dri, courant->stats.tir, courant->stats.def, courant->stats.pas, courant->stats.phy);
printf("test3");
///Sauvegarde des autres
    while(courant->next != NULL)
    {
printf("test4");
        courant = courant->next;
        printf("test a");
        fprintf(sauvegarde, "%s\n%d\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", courant->nom, courant->note, courant->poste, courant->club, courant->pays, courant->stats.vit, courant->stats.dri, courant->stats.tir, courant->stats.def, courant->stats.pas, courant->stats.phy);
printf("test5");
    }

    fclose(sauvegarde);
    printf("test6");
}


///Fonction de lecture du fichier de sauvegarde.
void lectureSauvegarde(t_collec* collec)
{
    int i=0;    ///Variable compteur qui va permettre de savoir quoi faire en fonction du numéro de la ligne lue.
    char transition[100];
    t_carte* carte;



    FILE* sauvegarde;   ///Déclaration d'un pointeur sur fichier.
    //t_carte* courant;   ///Déclaration d'un pointeur sur la carte à sauvegarder.

    sauvegarde = fopen("sauvegarde.txt", "r");  ///On ouvre le fichier de sauvegarde (en lecture seule).

    if(sauvegarde == NULL) ///Si le fichier s'est mal ouvert :
    {
        exit(EXIT_FAILURE); ///On quitte le programme.
    }




    while(fgets(transition, 100, sauvegarde) != NULL)   ///Tant qu'on a pas atteint la fin du fichier, on copie une ligne dans transition et :
    {
        i++;

        if(i%11 == 1)    ///Si c'est la ligne 1, 12, 23, 34 ...
        {
            carte = initCarte();  ///On initialise une carte.
            carte->nom = malloc((strlen(transition)+1)*sizeof(char));
            strcpy(carte->nom, transition);

        }
        if(i%11 == 2)   ///Si c'est la ligne 2, 13, 24, 35...
        {
            carte->note = atoi(transition);

        }
        if(i%11 == 3)   ///Si c'est la ligne 3, 14, 25, 36...
        {
            carte->poste = malloc((strlen(transition)+1)*sizeof(char));
            strcpy(carte->poste, transition);

        }
        if(i%11 == 4)   ///Si c'est la ligne 4, 15, 26, 37...
        {
            carte->club = malloc((strlen(transition)+1)*sizeof(char));
            strcpy(carte->club, transition);

        }
        if(i%11 == 5)   ///Si c'est la ligne 5, 16, 27, 38...
        {
            carte->pays = malloc((strlen(transition)+1)*sizeof(char));
            strcpy(carte->pays, transition);

        }
        if(i%11 == 6)   ///Si c'est la ligne 6, 17, 28, 39...
        {
            carte->stats.vit = atoi(transition);

        }
        if(i%11 == 7)   ///Si c'est la ligne 7, 18, 29, 40...
        {
            carte->stats.dri = atoi(transition);

        }
        if(i%11 == 8)   ///Si c'est la ligne 8, 19, 30, 41...
        {
            carte->stats.tir = atoi(transition);

        }
        if(i%11 == 9)   ///Si c'est la ligne 9, 20, 31, 42...
        {
            carte->stats.def = atoi(transition);

        }
        if(i%11 == 10)   ///Si c'est la ligne 10, 21, 32, 43...
        {
            carte->stats.pas = atoi(transition);

        }
        if(i%11 == 0)   ///Si c'est la ligne 11, 22, 33, 44...
        {
            carte->stats.phy = atoi(transition);

            insertionDebut(collec, carte);

        }

    }
    fclose(sauvegarde);
}



