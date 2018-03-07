#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

///Sous-structure des stats du joueur.
typedef struct stats
{
int vit;
int dri;
int tir;
int def;
int pas;
int phy;

}t_stats;

///Structure de la carte.
typedef struct carte
{
char* nom;
int note;
char* poste;
char* club;
char* pays;
t_stats stats;

struct carte* next; ///Pointeur vers la carte suivante.

}t_carte;

///Structure de la liste.
typedef struct collec
{
t_carte* first;
t_carte* last;

}t_collec;

///Fonction d'affichage du menu (retourne le choix) :
int menu();

///Fonction d'initialisation de la collection (retourne un pointeur sur l'ancre) :
t_collec* initCollec();

///Fonction d'affichage de la collection :
void affichageCollec(t_collec* collec);

///Fonction tirée d'un utilisateur d'un forum pour vider le buffer de la saisie.
void viderBuffer();

///Fonction tirée d'un cours OpenOffice sur la saisie de texte sécuriséé, elle permet la suppression du "\n" capté par la fonction fgets.
int lire(char *chaine, int longueur);

///Fonction pour ajouter une carte (au début de la liste).
void ajoutCarte(t_collec* collec);

#endif // HEADER_H_INCLUDED
