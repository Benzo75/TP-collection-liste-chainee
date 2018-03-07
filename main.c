#include "header.h"

int main()
{
    int choix=0;    ///Variable pour le choix du menu.
    int retour=0;   ///Variable "verrou" pour revenir au menu.
    int i=0;    ///Variable compteur.

    t_collec* collec=NULL;  ///Déclaration d'un pointeur sur collection.

    collec = initCollec();  ///On initialise la collection et on donne son adresse à collec.


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

///Fonction d'initialisation de la collection (retourne un pointeur sur l'ancre) :
t_collec* initCollec()
{
    //t_stats* stats;
    //stats = (t_stats*) malloc(sizeof(t_stats));  ///On alloue dynamiquement les stats de la première carte.

    t_carte* carte;
    carte = (t_carte*) malloc(sizeof(t_carte));  ///On alloue dynamiquement la première carte.

    t_collec* collec;
    collec = (t_collec*) malloc(sizeof(t_collec));   ///On alloue dynamiquement l'ancre.


    if(collec == NULL || carte == NULL /*|| stats == NULL*/) ///Si une des trois allocs dynamiques s'est mal passé :
    {
        exit(EXIT_FAILURE); ///On quitte le programme.
    }

    ///On initialise l'ancre :
    collec->first = carte;
    collec->last = carte;

    ///On initialise la première carte :
    char transition1[] = "Cristiano Ronaldo";
    carte->nom = malloc((strlen(transition1)+1)*sizeof(char));
    strcpy(carte->nom, transition1);

    carte->note = 99;

    char transition2[] = "AG";
    carte->poste = malloc((strlen(transition2)+1)*sizeof(char));
    strcpy(carte->poste, transition2);

    char transition3[] = "Real Madrid CF";
    carte->club = malloc((strlen(transition3)+1)*sizeof(char));
    strcpy(carte->club, transition3);

    char transition4[] = "Portugal";
    carte->pays = malloc((strlen(transition4)+1)*sizeof(char));
    strcpy(carte->pays, transition4);

    ///On initialise les stats de la première carte.
    carte->stats.vit = 98;
    carte->stats.dri = 98;
    carte->stats.tir = 99;
    carte->stats.def = 50;
    carte->stats.pas = 94;
    carte->stats.phy = 95;

    carte->next = NULL;

    return collec;
}

///Fonction d'affichage de la collection :
void affichageCollec(t_collec* collec)
{
    t_carte* carteActuelle = collec->first;

    if(collec == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while(carteActuelle != NULL)
    {
        printf("\t\t%s\n\n", carteActuelle->nom);

        printf(" Note g%cn%crale : %d\n", 130, 130, carteActuelle->note);
        printf(" Poste : %s\n", carteActuelle->poste);
        printf("  Club : %s\n", carteActuelle->club);
        printf("  Pays : %s\n", carteActuelle->pays);

        printf(" Stats : %d VIT, %d DRI, %d TIR, %d DEF, %d PAS, %d PHY.\n\n", carteActuelle->stats.vit, carteActuelle->stats.dri, carteActuelle->stats.tir, carteActuelle->stats.def, carteActuelle->stats.pas, carteActuelle->stats.phy);


        carteActuelle = carteActuelle->next;
    }
}

///Fonction tirée d'un utilisateur d'un forum pour vider le buffer de la saisie.
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

///Fonction tirée d'un cours OpenOffice sur la saisie de texte sécuriséé, elle permet la suppression du "\n" capté par la fonction fgets.
int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;

    // On lit le texte saisi au clavier
    if (fgets(chaine, longueur, stdin) != NULL)  // Pas d'erreur de saisie ?
    {
        positionEntree = strchr(chaine, '\n'); // On recherche l'"Entrée"
        if (positionEntree != NULL) // Si on a trouvé le retour à la ligne
        {
            *positionEntree = '\0'; // On remplace ce caractère par \0
        }
        return 1; // On renvoie 1 si la fonction s'est déroulée sans erreur
    }
    else
    {
        return 0; // On renvoie 0 s'il y a eu une erreur
    }
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

     ///Modification des pointeurs :
     newCarte->next = collec->first;
     collec->first = newCarte;

}

///Fonction de sauvegarde de la collection dans un fichier.
void sauvegarde(t_collec* collec)
{
    FILE* sauvegarde;   ///Déclaration d'un pointeur sur fichier.
    t_carte* courant;   ///Déclaration d'un pointeur sur la carte à sauvegarder.

    sauvegarde = fopen("sauvegarde.txt", "w");  ///On ouvre le fichier de sauvegarde (on le crée s'il n'existe pas et on le remplace s'il existait déjà).

    ///Sauvegarde de la première carte :

    courant = collec->first;    ///On pointe sur la première cellule.

    fprintf(sauvegarde, "%s\n%d\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d", courant->nom, courant->note, courant->poste, courant->club, courant->pays, courant->stats.vit, courant->stats.dri, courant->stats.tir, courant->stats.def, courant->stats.pas, courant->stats.phy);

fclose(sauvegarde);






}
