#include        <stdlib.h>
#include        <stdio.h>
#include        "SDL/SDL.h"
#include        "SDL/SDL_image.h"
#include        "includes/prototypes.h"
#include        "includes/constantes.h"
#include        "includes/struct.h"
#include        "SDL/SDL_mixer.h"

int             main(int argc, char *argv[])
{
    sMario      mario;
    sCibles     cibles;
    sGeneral    general;
    sImages     images;

    initialisation(&general); // Initialise la SDL et la musique
    initialisation_images(&images); // Charge les images
    initialisation_mario(&mario); // Initialise la structure mario
    initialisation_cibles(&cibles, general); // Initialise le tableau de cibles

    pause(general, images, &cibles, &mario);

    // On libère la mémoire allouée
    free_and_close(&mario, &general);

    return EXIT_SUCCESS;
}

void            pause(sGeneral general, sImages images, sCibles *cibles, sMario *mario)
{
  int           continuer = 1;
  int           t = 0, c = 0;
  int           accueil = 1;
  SDL_Event     event;
  SDL_Rect      pos;

  pos.x = 0;
  pos.y = 0;

  while (continuer)
  {
    c = 0;
    SDL_WaitEvent(&event);
    if (event.type == SDL_QUIT)
    {
      continuer = 0;
    }
    else if (event.type == SDL_KEYDOWN)
    {
      if (accueil == 1)
      {
        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
          continuer = 0;
        }
        else if (event.key.keysym.sym == SDLK_RETURN)
        {
          accueil = 0;
        }
      }
      else
      {
        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
          continuer = 0;
        }
        else if (event.key.keysym.sym == SDLK_RIGHT && mario->position.x < (LARGEUR_FENETRE - 34))
        {
          if (check_next_case('+', 'x', mario->position, general.grid) != 0)
          {
            if (check_next_case('+', 'x', mario->position, general.grid) == 2)
            {
              general.grid[mario->position.y / 34][(mario->position.x / 34) + 1] = 1;
              general.grid[mario->position.y / 34][(mario->position.x / 34) + 2] = 2;
            }
            mario->position.x += 34;
          }
          t = 2;
        }
        else if (event.key.keysym.sym == SDLK_LEFT && mario->position.x > 0)
        {
          if (check_next_case('-', 'x', mario->position, general.grid) != 0)
          {
            if (check_next_case('-', 'x', mario->position, general.grid) == 2)
            {
              general.grid[mario->position.y / 34][(mario->position.x / 34) - 1] = 1;
              general.grid[mario->position.y / 34][(mario->position.x / 34) - 2] = 2;
            }
            mario->position.x -= 34;
          }
          t = 3;
        }
        else if (event.key.keysym.sym == SDLK_UP && mario->position.y > 0)
        {
          if (check_next_case('+', 'y', mario->position, general.grid) != 0)
          {
            if (check_next_case('+', 'y', mario->position, general.grid) == 2)
            {
              general.grid[(mario->position.y / 34) - 1][mario->position.x / 34] = 1;
              general.grid[(mario->position.y / 34) - 2][mario->position.x / 34] = 2;
            }
            mario->position.y -= 34;
          }
          t = 1;
        }
        else if (event.key.keysym.sym == SDLK_DOWN && mario->position.y < (HAUTEUR_FENETRE - 34))
        {
          if (check_next_case('-', 'y', mario->position, general.grid) != 0)
          {
            if (check_next_case('-', 'y', mario->position, general.grid) == 2)
            {
              general.grid[(mario->position.y / 34) + 1][mario->position.x / 34] = 1;
              general.grid[(mario->position.y / 34) + 2][mario->position.x / 34] = 2;
            }
            mario->position.y += 34;
          }
          t = 0;
        }
      }
    }

    if (accueil == 0)
    {
      // On remplie notre écran d'une couleur unie
      SDL_FillRect(general.ecran, NULL, SDL_MapRGB(general.ecran->format, 255, 255, 255));
      if (check_cibles(general.grid, cibles) == 0) // Si il y a encore des cibles
      {
        // On affiche notre surface
        while (c < NB_CIBLES)
        {
          if (general.grid[cibles->tab[c].y][cibles->tab[c].x] != 2)
            general.grid[cibles->tab[c].y][cibles->tab[c].x] = 3;
          c++;
        }
        display_grid(general.grid, general.ecran, images, t);
        SDL_BlitSurface(mario->tab[t], NULL, general.ecran, &mario->position);
      }
      else // Si le joueur a fini la carte
      {
        SDL_BlitSurface(images.fin, NULL, general.ecran, NULL);
      }
    }
    else
      SDL_BlitSurface(images.accueil, NULL, general.ecran, &pos);
    SDL_Flip(general.ecran); // Met à jour l'écran
  }
}
