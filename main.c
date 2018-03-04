#include "header.h"

int main()
{
    int choix=0;

    while(choix != 6)
    {
        choix=menu();

        switch(choix)
        {
        //case 1 : affichage();
        //case 2 : recherche();
        //case 3 : tri();
        //case 4 : ajout();
        //case 5 : supprimer();
        default : break;
        }

    }

    return 0;
}

///Fonction d'affichage du menu (retourne le choix) :
int menu()
{
    int choix=0;  ///Variable choix utilisateur pour le switch.
    int i=0;  ///Variable pour les boucles.

    ///Interface graphique (limitée car le CDC interdit l'utilisation de la fonction gotoligcol) :

    ///Ligne du haut :
    printf("%c",201);
    for(i=0; i<27; i++)
    {
        printf("%c",205);
    }
    printf("%c\n",187);

    ///Titre :
    printf("%c Collection de cartes FIFA %c\n", 186, 186);

    ///Ligne du bas :
    printf("%c",200);
    for(i=0; i<27; i++)
    {
        printf("%c",205);
    }
    printf("%c\n\n",188);

    ///Choix :
    printf(" 1 - Voir la collection\n");
    printf(" 2 - Rechercher une carte\n");
    printf(" 3 - Trier la collection\n\n");

    printf(" 4 - Ajouter une carte\n");
    printf(" 5 - Supprimer une carte\n\n");

    printf(" 6 - Quitter l'application\n\n");

    printf(" Que voulez-vous faire ?\n");
    scanf("%d",&choix);

    for(i=0; i<50; i++)
    {
        printf("%c",196);
    }
    printf("\n");

    return choix;
}
