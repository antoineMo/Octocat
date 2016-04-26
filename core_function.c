/*
** core_function.c for core_function.c in /home/antoine/Desktop/pataugoire/octo
**
** Made by MORISSET Antoine
** Login   <moriss_a@etna-alternance.net>
**
** Started on  Wed Jan  20 11:16:32 2016 MORISSET Antoine
** Last update Fri jan  21 16:45:59 2016 MORISSET Antoine
*/

#include "struct.h"


////////// Fonction affichage perdu/gagné et play again //////////
void   do_my_message(char mode, char **tab, int v, int r)
{
  char entry;
  int x;
  int y;

  x = 1;
  y = 1;
  if (v == 1) {
    my_putstr("Perdu ! (╯°□ °）╯︵ ┻━┻)\n");
    if (r == 2)
    while ('\n' != getchar()); //dans le mode difficile un \n subsiste c'est pour vider getchar
  }
  else if (v == 2)
    my_putstr("bravo ! vous avez reussi (•_•) / ( •_•)>⌐■ -■ / (⌐■ _■ )\n");
  else
    my_putstr("Vous n'etes pas arriver au bout dommage ! (ノಠ益ಠ)ノ彡┻━┻ ).\n");
  my_putstr("voulez vous rejouer ? (y/any keys)");
  entry = getchar();
  while ('\n' != getchar());
  if (entry == 'y' && r == 1) //redirection pour le try again
    do_it_easy(tab, x, y);
  else if (entry == 'y' && r == 2)
    do_it_hard(tab, x, y);
  else if (entry == 'y' && r == 3)
    do_it_blind(mode, tab, x, y);
}

////////// Fonction Mode de jeu facile //////////
int     do_it_easy (char **tab, int x, int y)
{
  int   v;
  char  entry;

  v = 0;
  do_my_tab(tab, x, y); // premier affichage du tableau
  while (v == 0)
  {
    my_putstr("-> ");
    entry = getchar();
    while ('\n' != getchar()); //prise en compte des input
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
    v = do_my_tab(tab, x, y);
  }
  do_my_message('1', tab, v, 1);
  return (0);
}

////////// Fonction Mode de jeu difficile //////////
int     do_it_hard (char **tab, int x, int y)
{
  int   v;
  char  entry;

  v = 0;
  entry = '\0';
  do_my_tab(tab, x, y);
  while (entry != '\n' && v == 0) {
    my_putstr("-> ");
    entry = getchar();
    if (entry != '\n') {
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
      v = do_my_tab(tab, x, y);
      usleep(100000);
    }
  }
  do_my_message('1', tab, v, 2);
  return (0);
}

////////// Fonction affichage character pour pouvoir rejouer //////////
void    re_my_map(char **tab, int x, int y, int v)
{
  if (v == 2)
    tab[y][x] = 'O';
  else if (v == 1)
    tab[y][x] = 'T';
  else
    tab[y][x] = ' ';
}

////////// Fonction affichage du tableaux //////////
int     do_my_tab (char **tab, int x, int y)
{
  int   i;
  int   j;
  int   v;

  v = 0;
  if (tab[y][x] == 'O') //on verifie si le nouvel enplacement et un mur ou autre
    v = 2;
  else if (tab[y][x] != ' ')
    v = 1;
  tab[y][x] = 'X';
  my_putstr("\033c");
  i = 0;
  while (i < 20)
  {
    j = 0;
    while (j < 21) //affichage du tableau
    {
      my_putchar(tab[i][j]);
      j++;
    }
    i++;
  }
  re_my_map(tab, x, y, v);
  return (v);
}
