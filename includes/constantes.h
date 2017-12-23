/*

  CONSTANTES.H contient les constantes du jeu, à savoir
  la taille d'un bloc, la largeur de la fenêtre, etc..


  GIUDICE Gianni - 29 Novembre 2017

*/

#ifndef     DEF_CONSTANTES
# define    DEF_CONSTANTES

  #define   TAILLE_BLOC       34
  #define   NB_BLOCS_LARGEUR  12
  #define   NB_BLOCS_HAUTEUR  12
  #define   LARGEUR_FENETRE   TAILLE_BLOC * NB_BLOCS_LARGEUR
  #define   HAUTEUR_FENETRE   TAILLE_BLOC * NB_BLOCS_HAUTEUR
  #define   NB_CIBLES         3

  enum      { MUR, VIDE, CAISSE, CIBLE, MARIO, CAISSE_OK };

#endif
