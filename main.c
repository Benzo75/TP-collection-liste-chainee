#include "header.h"

int main()
{
    int choix=0;    ///Variable pour le choix du menu.
    int retour=0;   ///Variable "verrou" pour revenir au menu.

    t_collec* collec=NULL;  ///Déclaration d'un pointeur sur collection.
    collec = initCollec();  ///On initialise la collection et on donne son adresse à collec.

    lectureSauvegarde(collec);

    while(choix != 6)   ///Tant que l'utilisateur ne veut pas quitter :
    {
        choix=menu();   ///On lance le menu et on récupère le choix.

        switch(choix)
        {
        case 1 :    ///L'utilisateur veut afficher la collection :
            afficherCollec(collec);    ///On affiche.
            while(retour != 1)  ///Tant que l'utilisateur ne tape pas 1 :
            {
                printf("\n Retour : Tapez 1.\n");   ///On lui demande de taper 1.
                scanf("%d", &retour);
            }
            retour=0;
            choix=0;
            trait();
            break;
        case 2 :
            recherche(collec);
            break;
        //case 3 : tri();
        case 4 :
            ajoutCarte(collec);
            break;
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
void afficherCollec(t_collec* collec)
{
    t_carte* carteActuelle = collec->first;

    if(collec == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while(carteActuelle->next != NULL)  ///Tant qu'on est pas à la dernière carte :
    {
        printf("\t      [ %s ]\n\n", carteActuelle->nom);

        printf(" Note g%cn%crale : %d\n", 130, 130, carteActuelle->note);
        printf(" Poste : %s\n", carteActuelle->poste);
        printf("  Club : %s\n", carteActuelle->club);
        printf("  Pays : %s\n", carteActuelle->pays);

        printf(" Stats : %d VIT, %d DRI, %d TIR, %d DEF, %d PAS, %d PHY.\n\n\n", carteActuelle->stats.vit, carteActuelle->stats.dri, carteActuelle->stats.tir, carteActuelle->stats.def, carteActuelle->stats.pas, carteActuelle->stats.phy);


        carteActuelle = carteActuelle->next;
    }
    if(carteActuelle->next == NULL) ///Si on est à la dernière carte :
    {
        printf("\t      [ %s ]\n\n", carteActuelle->nom);

        printf(" Note g%cn%crale : %d\n", 130, 130, carteActuelle->note);
        printf(" Poste : %s\n", carteActuelle->poste);
        printf("  Club : %s\n", carteActuelle->club);
        printf("  Pays : %s\n", carteActuelle->pays);

        printf(" Stats : %d VIT, %d DRI, %d TIR, %d DEF, %d PAS, %d PHY.\n\n\n", carteActuelle->stats.vit, carteActuelle->stats.dri, carteActuelle->stats.tir, carteActuelle->stats.def, carteActuelle->stats.pas, carteActuelle->stats.phy);
    }
}


///Fonction d'affichage d'une carte :
void afficherCarte(t_carte* carte)
{
    printf("\n\t      [ %s ]\n\n", carte->nom);

    printf(" Note g%cn%crale : %d\n", 130, 130, carte->note);
    printf(" Poste : %s\n", carte->poste);
    printf("  Club : %s\n", carte->club);
    printf("  Pays : %s\n", carte->pays);

    printf(" Stats : %d VIT, %d DRI, %d TIR, %d DEF, %d PAS, %d PHY.\n", carte->stats.vit, carte->stats.dri, carte->stats.tir, carte->stats.def, carte->stats.pas, carte->stats.phy);
}


///Fonction pour le choix du type de recherche.
void recherche(t_collec* collec)
{
    int choixR=0;   ///Variable pour le choix du type de racherche.

    printf(" Quel champ voulez-vous rechercher ?\n\n");

    printf(" 1 - Recherche par nom\n\n");

    printf(" 2 - Recherche par note g%cn%crale\n", 130, 130);
    printf(" 3 - Recherche par poste\n");
    printf(" 4 - Recherche par club\n");
    printf(" 5 - Recherche par pays\n\n");

    printf(" 6 - Recherche par note de VIT\n");
    printf(" 7 - Recherche par note de DRI\n");
    printf(" 8 - Recherche par note de TIR\n");
    printf(" 9 - Recherche par note de DEF\n");
    printf(" 10 - Recherche par note de PAS\n");
    printf(" 11 - Recherche par note de PHY\n");
    scanf("%d", &choixR);

    switch(choixR)
    {
    case 1 :
        viderBuffer();
        afficherCarte(rechercheNom(collec));
        trait();
        break;
    case 2 :
        rechercheNote(collec);
        trait();
        break;
    case 3 :
        recherchePoste(collec);
        trait();
        break;
    case 4 :
        rechercheClub(collec);
        trait();
        break;
    case 5 :
        recherchePays(collec);
        trait();
        break;
    case 6 :
        rechercheVIT(collec);
        trait();
        break;
    case 7 :
        rechercheDRI(collec);
        trait();
        break;
    case 8 :
        rechercheTIR(collec);
        trait();
        break;
    case 9 :
        rechercheDEF(collec);
        trait();
        break;
    case 10 :
        recherchePAS(collec);
        trait();
        break;
    case 11 :
        recherchePHY(collec);
        trait();
        break;
    }
}
