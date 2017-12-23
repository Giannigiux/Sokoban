#include        "SDL/SDL.h"
#include        "SDL/SDL_image.h"
#include        "includes/prototypes.h"
#include        "includes/constantes.h"

int             check_next_case(char operateur, char abscisse, SDL_Rect pos, int **grid)
{
  int           x, y;

  x = pos.x / 34;
  y = pos.y / 34;
  if (operateur == '+' && abscisse == 'x')
  {
    if (grid[y][x + 1] == 0)
    { // Si on a un mur
      return 0;
    }
    else if (grid[y][x + 1] == 2)
    { // Si on a une caisse
      if ((x + 1) < NB_BLOCS_HAUTEUR - 1 && grid[y][x + 2] != 0 && grid[y][x + 2] != 2) // Si l'espace après la caisse est libre
        return 2;
      else
        return 0;
    }
  }
  else if (operateur == '+' && abscisse == 'y')
  {
    if (grid[y - 1][x] == 0)
    { // Si on a un mur
      return 0;
    }
    else if (grid[y - 1][x] == 2)
    { // Si on a une caisse
      if ((y - 1) > 0 && grid[y - 2][x] != 0 && grid[y - 2][x] != 2)
        return 2;
      else
        return 0;
    }
  }
  else if (operateur == '-' && abscisse == 'x')
  {
    if (grid[y][x - 1] == 0)
    { // Si on a un mur
      return 0;
    }
    else if (grid[y][x - 1] == 2)
    { // Si on a une caisse
      if ((x - 1) > 0 && grid[y][x - 2] != 0 && grid[y][x - 2] != 2)
        return 2;
      else
        return 0;
    }
  }
  else if (operateur == '-' && abscisse == 'y')
  {
    if (grid[y + 1][x] == 0)
    { // Si on a un mur
      return 0;
    }
    else if (grid[y + 1][x] == 2)
    { // Si on a une caisse
      if ((y + 1) < NB_BLOCS_HAUTEUR - 1 && grid[y + 2][x] != 0 && grid[y + 2][x] != 2)
        return 2;
      else
        return 0;
    }
  }
  return 1;
}

int             check_cibles(int **grid, sCibles *cibles)
{
  int           i = 0, c = 0, d = 0, count = 0;

  while (i < NB_CIBLES)
  {
    if (grid[cibles->tab[i].y][cibles->tab[i].x] == 2)
      count++;
    i++;
  }
  if (count == NB_CIBLES)
    return 1;
  return 0;
}
