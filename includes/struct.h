/*

  STRUCT.H contient les structures du projet

  GIUDICE Gianni - 23 Décembre 2017

*/

#ifndef     STRUCT_H
#define     STRUCT_H

  #include        "constantes.h"

  typedef struct  sGeneral
  {
    SDL_Surface   *ecran;
    Mix_Music     *musique;
    int           **grid;
  } sGeneral;

  typedef struct  sImages
  {
    SDL_Surface   *accueil;
    SDL_Surface   *mur;
    SDL_Surface   *caisse;
    SDL_Surface   *cible;
    SDL_Surface   *fin;
  } sImages;

  typedef struct  sMario
  {
    SDL_Surface   **tab;
    SDL_Rect      position;
  } sMario;

  typedef struct  sCibles
  {
    SDL_Rect      tab[NB_CIBLES];
  } sCibles;

#endif
