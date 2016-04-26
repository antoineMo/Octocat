/*
** other_function.c for other_function.c in /home/antoine/Desktop/pataugoire/octo
**
** Made by MORISSET Antoine
** Login   <moriss_a@etna-alternance.net>
**
** Started on  Wed Jan  20 15:16:32 2016 MORISSET Antoine
** Last update Fri jan  21 16:45:59 2016 MORISSET Antoine
*/

#include "struct.h"

////////// Fonction Mode de jeu aveugle ou octowiew //////////
int     do_it_blind (char mode, char **tab, int x, int y)
{
  int   v;
  char  entry;

  v = 0;
  do_my_blind_tab(mode, tab, x, y);
  while (v == 0)
  {
    my_putstr("-> ");
    entry = getchar();
    while ('\n' != getchar());
    if (entry == 'd')
      x++;
    else if (entry == 'a' && x > 0)
      x--;
    else if (entry == 'w')
      y--;
    else if (entry == 's')
      y++;
    else
    my_putstr("valeur nul\n");
    v = do_my_blind_tab(mode, tab, x, y);
  }
  do_my_message(mode, tab, v, 3);
  return (0);
}

////////// Fonction mode aveugle/ redirection sur affichage si octowiew/////////
int     do_my_blind_tab (char mode, char **tab, int x, int y)
{
  int   v;

  v = 0;
  if (tab[y][x] == 'O')
    v = 2;
  else if (tab[y][x] != ' ')
    v = 1;
  tab[y][x] = 'X';
  my_putstr("\033c");
  if (mode == '3') { //si c'est octowiew
    my_putchar('\n');
    aff_my_blind_tab(tab, x, y);
  }
  if (mode == '4' && v == 0 && (x != 1 || y != 1)) {
    my_putstr("toujours en vie !? bien jouer ... pour l\'instant ;) \n");
  }
  re_my_map(tab, x, y, v);
  return (v);
}

////////// Fonction affichage du tableaux octoview //////////
void    aff_my_blind_tab (char **tab, int x, int y)
{
  int   i;
  int   j;

  i = 0;
  while (i < 21)
  {
    j = 0;
    while (j < 22) //affichage autour de l'emplacement du joueur
    {
      if (i < (y+2) && i > (y-2) && j < (x+2) && j > (x-2))
        my_putchar(tab[i][j]);
      j++;
    }
    if (i < (y+2) && i > (y-2))
      my_putchar('\n');
    i++;
  }
}