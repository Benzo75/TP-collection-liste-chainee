#include "header.h"

///Fonction tirée d'un utilisateur d'un forum pour vider le buffer de la saisie.
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}


///Fonction tirée d'un cours OpenOffice sur la saisie de texte sécuriséé, elle permet la suppression du "\n" capté par la fonction fgets R(0 si bon, 1 si erreur) P(la chaine dans laquelle on écrit, la longueur max).
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


///Fonction qui affiche un trait sur l'écran.
void trait(void)
{
    int i;

    for(i=0; i<100; i++) ///On tire un trait
    {
        printf("%c",196);
    }
    printf("\n");
}

