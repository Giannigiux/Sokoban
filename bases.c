#include        <stdlib.h>
#include        <stdio.h>
#include        "SDL/SDL.h"
#include        "SDL/SDL_image.h"
#include        "includes/prototypes.h"
#include        "includes/constantes.h"
#include        "includes/struct.h"
#include        "SDL/SDL_mixer.h"

void            initialisation(sGeneral *general)
{
  general->ecran = NULL;
  general->ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  if (general->ecran == NULL)
  {
    fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  // On change le nom de notre fenêtre
  SDL_WM_SetCaption("Mario Sokoban", NULL);

  SDL_EnableKeyRepeat(100, 500);
  general->musique = Mix_LoadMUS("sound/musique.mp3"); // Chargement de la musique
  Mix_PlayMusic(general->musique, -1); // Joue infiniment la musique

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1) // Initialisation de la SDL
  {
    fprintf(stderr, "Erreur d'initialisation de la SDL");
    exit(EXIT_FAILURE);
  }

  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) // Initialisation de l'API Mixer
  {
    printf("%s", Mix_GetError());
  }

  general->grid = create_grid();;
}

void            initialisation_images(sImages *images)
{
  images->accueil = NULL;
  images->mur = NULL;
  images->caisse = NULL;
  images->cible = NULL;

  images->accueil = IMG_Load("pictures/ecran_accueil.png");
  images->mur = IMG_Load("pictures/mur.jpg");
  images->caisse = IMG_Load("pictures/caisse.jpg");
  images->cible = IMG_Load("pictures/cible.png");
  images->fin = IMG_Load("pictures/ecran_fin.png");
}

void            initialisation_mario(sMario *mario)
{
  int           i = 0;

  mario->tab = malloc(sizeof(SDL_Surface *) * 4);

  while (i < 4)
  {
    mario->tab[i] = NULL;
    i++;
  }

  mario->position.x = 5 * 34;
  mario->position.y = 0;

  mario->tab[0] = IMG_Load("pictures/mario_bas.gif");
  mario->tab[1] = IMG_Load("pictures/mario_haut.gif");
  mario->tab[2] = IMG_Load("pictures/mario_droite.gif");
  mario->tab[3] = IMG_Load("pictures/mario_gauche.gif");
}

void            initialisation_cibles(sCibles *cibles, sGeneral general)
{
  int           i = 0, c = 0, d = 0;

  // on cherche les cibles
  while (c < NB_BLOCS_LARGEUR)
  {
    d = 0;
    while (d < NB_BLOCS_HAUTEUR)
    {
      if (general.grid[c][d] == 3)
      {
        cibles->tab[i].x = d;
        cibles->tab[i].y = c;
        i++;
      }
      d++;
    }
    c++;
  }
}

void            free_and_close(sMario *mario, sGeneral *general)
{
  SDL_FreeSurface(mario->tab[0]);
  SDL_FreeSurface(mario->tab[1]);
  SDL_FreeSurface(mario->tab[2]);
  SDL_FreeSurface(mario->tab[3]);
  free_grid(general->grid);
  Mix_FreeMusic(general->musique);
  Mix_CloseAudio();
  SDL_Quit();
}
