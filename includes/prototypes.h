/*

  PROTOTYPES.H contient les prototypes des fonctions

  GIUDICE Gianni - 30 Novembre 2017

*/

#ifndef     CONSTANTES_H
#define     CONSTANTES_H

  #include    "SDL/SDL_mixer.h"
  #include    "constantes.h"
  #include    "struct.h"


  void        pause(sGeneral, sImages, sCibles *, sMario *);
  void        initialisation(sGeneral *);
  void        initialisation_images(sImages *);
  void        initialisation_mario(sMario *);
  void        initialisation_cibles(sCibles *, sGeneral);
  int         check_next_case(char, char, SDL_Rect, int **);
  int         check_cibles(int **, sCibles *);
  int         **create_grid();
  void        display_grid(int **, SDL_Surface *, sImages, int);
  void        free_grid();
  void        free_and_close(sMario *, sGeneral *);

#endif
