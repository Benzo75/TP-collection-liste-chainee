#include "header.h"

int main()
{
    int choix=0;    ///Variable pour le choix du menu.
    int retour=0;   ///Variable "verrou" pour revenir au menu.
    int i=0;    ///Variable compteur.

    t_collec* collec=NULL;  ///Déclaration d'un pointeur sur collection.

    collec = initCollec();  ///On initialise la collection et on donne son adresse à collec.


    lectureSauvegarde(collec);


    while(choix != 6)   ///Tant que l'utilisateur ne veut pas quitter :
    {
        choix=menu();   ///On lance le menu et on récupère le choix.

        switch(choix)
        {
        case 1 :    ///L'utilisateur veut afficher la collection :
        {
            affichageCollec(collec);    ///On affiche.

            while(retour != 1)  ///Tant que l'utilisateur ne tape pas 1 :
            {
                printf("\n Retour : Tapez 1.\n");   ///On lui demande de taper 1.
                scanf("%d", &retour);
            }
            for(i=0; i<100; i++) ///On tire un trait
            {
                printf("%c",196);
            }
            printf("\n");
            retour=0;
            choix=0;
            break;
        }
        //case 2 : recherche();
        //case 3 : tri();

        case 4 :
        {
            ajoutCarte(collec);
            break;
        }

        //case 5 : supprimer();

        case 6 :
            sauvegarde(collec);
            break;
        default :
            break;
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

    printf(" 6 - Sauvegarder et quitter\n\n");

    printf(" Que voulez-vous faire ?\n");
    scanf("%d",&choix);

    for(i=0; i<100; i++)
    {
        printf("%c",196);
    }
    printf("\n");

    return choix;
}


///Fonction d'affichage de la collection :
void affichageCollec(t_collec* collec)
{


    t_carte* carteActuelle = collec->first;

    if(collec == NULL)
    {
        exit(EXIT_FAILURE);
    }



    while(carteActuelle->next != NULL)
    {

        printf("\t\t%s\n\n", carteActuelle->nom);

        printf(" Note g%cn%crale : %d\n", 130, 130, carteActuelle->note);
        printf(" Poste : %s\n", carteActuelle->poste);
        printf("  Club : %s\n", carteActuelle->club);
        printf("  Pays : %s\n", carteActuelle->pays);

        printf(" Stats : %d VIT, %d DRI, %d TIR, %d DEF, %d PAS, %d PHY.\n\n\n", carteActuelle->stats.vit, carteActuelle->stats.dri, carteActuelle->stats.tir, carteActuelle->stats.def, carteActuelle->stats.pas, carteActuelle->stats.phy);


        carteActuelle = carteActuelle->next;

    }
}


