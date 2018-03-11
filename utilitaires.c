#include "header.h"

///Fonction tir�e d'un utilisateur d'un forum pour vider le buffer de la saisie.
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}


///Fonction tir�e d'un cours OpenOffice sur la saisie de texte s�curis��, elle permet la suppression du "\n" capt� par la fonction fgets R(0 si bon, 1 si erreur) P(la chaine dans laquelle on �crit, la longueur max).
int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;

    // On lit le texte saisi au clavier
    if (fgets(chaine, longueur, stdin) != NULL)  // Pas d'erreur de saisie ?
    {
        positionEntree = strchr(chaine, '\n'); // On recherche l'"Entr�e"
        if (positionEntree != NULL) // Si on a trouv� le retour � la ligne
        {
            *positionEntree = '\0'; // On remplace ce caract�re par \0
        }
        return 1; // On renvoie 1 si la fonction s'est d�roul�e sans erreur
    }
    else
    {
        return 0; // On renvoie 0 s'il y a eu une erreur
    }
}


///Fonction qui affiche un trait sur l'�cran.
void trait(void)
{
    int i;

    for(i=0; i<100; i++) ///On tire un trait
    {
        printf("%c",196);
    }
    printf("\n");
}

