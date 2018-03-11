#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

///Structure de la carte (cellule de la liste chainée).
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

///Structure de la collection (ancre de la liste chainée).
typedef struct collec
{
t_carte* first;
t_carte* last;

}t_collec;


///Dans "main.c" :

///Fonction d'affichage du menu R(le choix).
int menu(void);
///Fonction d'affichage de la collection P(la collection)
void afficherCollec(t_collec* collec);
///Fonction d'affichage d'une carte P(la carte).
void afficherCarte(t_carte* carte);
///Fonction pour le choix du type de recherche P(la collection).
void recherche(t_collec* collec);


///Dans "liste.c" :

///Fonction d'initialisation de la collection R(pointeur sur la collection).
t_collec* initCollec(void);
///Fonction d'initialisation d'une carte R(pointeur sur la carte).
t_carte* initCarte(void);
///Fonction pour ajouter une carte en début de liste P(la collection).
void ajoutCarte(t_collec* collec);
///Fonction d'insertion d'une carte en début de liste P(la collection).
void insertionDebut(t_collec* collec, t_carte* newCarte);
///Fonction d'insertion d'une carte en fin de liste P(la collection).
void insertionFin(t_collec* collec, t_carte* newCarte);
///Fonction de suppression d'une carte P(la collection, la carte à supprimer).
void supprimer(t_collec* collec, t_carte* carte);


///Dans "recherche.c" :

///Fonction de recherche d'une fiche par son nom R(pointeur sur la carte trouvée) P(la collection).
t_carte* rechercheNom(t_collec* collec);
///Fonction de recherche de l'existance d'une fiche par son nom R(pointeur sur la carte trouvée) P(la collection, le nom).
t_carte* checkNom(t_collec* collec, char nom[100]);
///Fonction de recherche de fiches par leur note générale P(la collection).
void rechercheNote(t_collec* collec);
///Fonction de recherche de fiches par leur poste P(la collection).
void recherchePoste(t_collec* collec);
///Fonction de recherche de fiches par leur club P(la collection).
void rechercheClub(t_collec* collec);
///Fonction de recherche de fiches par leur pays P(la collection).
void recherchePays(t_collec* collec);
///Fonction de recherche de fiches par leur note de VIT P(la collection).
void rechercheVIT(t_collec* collec);
///Fonction de recherche de fiches par leur note de DRI P(la collection).
void rechercheDRI(t_collec* collec);
///Fonction de recherche de fiches par leur note de TIR P(la collection).
void rechercheTIR(t_collec* collec);
///Fonction de recherche de fiches par leur note de DEF P(la collection).
void rechercheDEF(t_collec* collec);
///Fonction de recherche de fiches par leur note de PAS P(la collection).
void recherchePAS(t_collec* collec);
///Fonction de recherche de fiches par leur note de PHY P(la collection).
void recherchePHY(t_collec* collec);


///Dans "fichier.c" :

///Fonction de sauvegarde de la collection dans un fichier P(la collection).
void sauvegarde(t_collec* collec);
///Fonction de lecture du fichier de sauvegarde P(la collection).
void lectureSauvegarde(t_collec* collec);


///Dans "utilitaires.c" :

///Fonction tirée d'un utilisateur d'un forum pour vider le buffer de la saisie.
void viderBuffer(void);
///Fonction tirée d'un cours OpenOffice sur la saisie de texte sécuriséé, elle permet la suppression du "\n" capté par la fonction fgets R(0 si bon, 1 si erreur) P(la chaine dans laquelle on écrit, la longueur max).
int lire(char *chaine, int longueur);
///Fonction qui affiche un trait sur l'écran.
void trait(void);

#endif // HEADER_H_INCLUDED
