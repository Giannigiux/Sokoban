#include        <stdlib.h>
#include        "SDL/SDL.h"
#include        "SDL/SDL_image.h"
#include        "includes/prototypes.h"
#include        "includes/constantes.h"

int       **create_grid()
{
  // MUR = 0, VIDE = 1, CAISSE = 2, CIBLE = 3, MARIO = 4, CAISSE_OK = 5
  int     **grid;
  int     i = 0;

  grid = malloc(sizeof(int *) * NB_BLOCS_LARGEUR);
  while (i < NB_BLOCS_HAUTEUR)
  {
    grid[i] = malloc(sizeof(int) * NB_BLOCS_HAUTEUR);
    i++;
  }

  grid[0][0] = 0;
  grid[0][1] = 0;
  grid[0][2] = 0;
  grid[0][3] = 0;
  grid[0][4] = 0;
  grid[0][5] = 1;
  grid[0][6] = 1;
  grid[0][7] = 0;
  grid[0][8] = 0;
  grid[0][9] = 0;
  grid[0][10] = 0;
  grid[0][11] = 0;

  grid[1][0] = 0;
  grid[1][1] = 0;
  grid[1][2] = 0;
  grid[1][3] = 0;
  grid[1][4] = 0;
  grid[1][5] = 1;
  grid[1][6] = 1;
  grid[1][7] = 1;
  grid[1][8] = 1;
  grid[1][9] = 1;
  grid[1][10] = 1;
  grid[1][11] = 0;

  grid[2][0] = 0;
  grid[2][1] = 0;
  grid[2][2] = 0;
  grid[2][3] = 0;
  grid[2][4] = 1;
  grid[2][5] = 1;
  grid[2][6] = 1;
  grid[2][7] = 0;
  grid[2][8] = 0;
  grid[2][9] = 1;
  grid[2][10] = 1;
  grid[2][11] = 0;

  grid[3][0] = 1;
  grid[3][1] = 3;
  grid[3][2] = 3;
  grid[3][3] = 0;
  grid[3][4] = 1;
  grid[3][5] = 0;
  grid[3][6] = 1;
  grid[3][7] = 0;
  grid[3][8] = 0;
  grid[3][9] = 1;
  grid[3][10] = 0;
  grid[3][11] = 0;

  grid[4][0] = 1;
  grid[4][1] = 1;
  grid[4][2] = 1;
  grid[4][3] = 1;
  grid[4][4] = 1;
  grid[4][5] = 2;
  grid[4][6] = 1;
  grid[4][7] = 1;
  grid[4][8] = 0;
  grid[4][9] = 2;
  grid[4][10] = 0;
  grid[4][11] = 0;

  grid[5][0] = 0;
  grid[5][1] = 1;
  grid[5][2] = 1;
  grid[5][3] = 0;
  grid[5][4] = 1;
  grid[5][5] = 0;
  grid[5][6] = 1;
  grid[5][7] = 1;
  grid[5][8] = 1;
  grid[5][9] = 1;
  grid[5][10] = 0;
  grid[5][11] = 0;

  grid[6][0] = 0;
  grid[6][1] = 0;
  grid[6][2] = 0;
  grid[6][3] = 0;
  grid[6][4] = 1;
  grid[6][5] = 1;
  grid[6][6] = 1;
  grid[6][7] = 0;
  grid[6][8] = 0;
  grid[6][9] = 2;
  grid[6][10] = 0;
  grid[6][11] = 0;

  grid[7][0] = 0;
  grid[7][1] = 0;
  grid[7][2] = 0;
  grid[7][3] = 0;
  grid[7][4] = 0;
  grid[7][5] = 0;
  grid[7][6] = 0;
  grid[7][7] = 0;
  grid[7][8] = 0;
  grid[7][9] = 1;
  grid[7][10] = 1;
  grid[7][11] = 0;

  grid[8][0] = 0;
  grid[8][1] = 0;
  grid[8][2] = 0;
  grid[8][3] = 0;
  grid[8][4] = 3;
  grid[8][5] = 1;
  grid[8][6] = 1;
  grid[8][7] = 1;
  grid[8][8] = 1;
  grid[8][9] = 1;
  grid[8][10] = 1;
  grid[8][11] = 0;

  grid[9][0] = 0;
  grid[9][1] = 0;
  grid[9][2] = 0;
  grid[9][3] = 0;
  grid[9][4] = 0;
  grid[9][5] = 0;
  grid[9][6] = 0;
  grid[9][7] = 0;
  grid[9][8] = 0;
  grid[9][9] = 0;
  grid[9][10] = 0;
  grid[9][11] = 0;

  grid[10][0] = 0;
  grid[10][1] = 0;
  grid[10][2] = 0;
  grid[10][3] = 0;
  grid[10][4] = 0;
  grid[10][5] = 0;
  grid[10][6] = 0;
  grid[10][7] = 0;
  grid[10][8] = 0;
  grid[10][9] = 0;
  grid[10][10] = 0;
  grid[10][11] = 0;

  grid[11][0] = 0;
  grid[11][1] = 0;
  grid[11][2] = 0;
  grid[11][3] = 0;
  grid[11][4] = 0;
  grid[11][5] = 0;
  grid[11][6] = 0;
  grid[11][7] = 0;
  grid[11][8] = 0;
  grid[11][9] = 0;
  grid[11][10] = 0;
  grid[11][11] = 0;

  return grid;
}

void    display_grid(int **grid, SDL_Surface *ecran, sImages images, int t)
{
  int         i = 0, c;
  SDL_Rect    pos;

  pos.y = 0;
  while (i < NB_BLOCS_LARGEUR)
  {
    c = 0;
    pos.x = 0;
    while (c < NB_BLOCS_HAUTEUR)
    {
      if (grid[i][c] == 0)
        SDL_BlitSurface(images.mur, NULL, ecran, &pos);
      if (grid[i][c] == 2)
        SDL_BlitSurface(images.caisse, NULL, ecran, &pos);
      if (grid[i][c] == 3)
        SDL_BlitSurface(images.cible, NULL, ecran, &pos);
      c++;
      pos.x += 34;
    }
    pos.y += 34;
    i++;
  }
}

void    free_grid(int **grid)
{
  int   i = 0;

  while (i < NB_BLOCS_LARGEUR)
  {
    free(grid[i]);
    i++;
  }
}
