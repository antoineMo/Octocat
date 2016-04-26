/*
** octocat.c for octocat.c in /home/antoine/Desktop/pataugoire/octo
**
** Made by MORISSET Antoine
** Login   <moriss_a@etna-alternance.net>
**
** Started on  Mon Jan  18 09:36:51 2016 MORISSET Antoine
** Last update Fri jan  21 16:46:59 2016 MORISSET Antoine
*/

#include "struct.h"

////////// Affichage menu 1 //////////
void	 menutxt()
{
  my_putstr("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  my_putstr("| Bienvenue sur le project octocat !                   |\n");
  my_putstr("| 1 : Lancer le jeu en mode facile                     |\n");
  my_putstr("| 2 : Lancer le jeu en mode difficile                  |\n");
  my_putstr("| 3 : Lancer le jeu en mode Octoview                   |\n");
  my_putstr("| 4 : Lancer le jeu en mode blind                      |\n");
  my_putstr("|                                                      |\n");
  my_putstr("| q : quitter le programme                             |\n");
  my_putstr(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
}

////////// Affichage menu 2 (selection de maps) //////////
void	 sous_menutxt()
{
  my_putstr("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  my_putstr("| choisissez un niveau avec son numero !               |\n");
  my_putstr("|     _     _     _     _     _     _                  |\n");
  my_putstr("|    |1|   |2|   |3|   |4|   |5|   |6|                 |\n");
  my_putstr("|     ^     ^     ^     ^     ^     ^                  |\n");
  my_putstr("|                                                      |\n");
  my_putstr("| -Deplacer votre personnage (X) avec les touches wasd |\n");
  my_putstr("|   afin d'atteindre la sortie -> O !                  |\n");
  my_putstr("| r : retour a l'ecran titre                           |\n");
  my_putstr(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
}

////////// Menu selection de maps //////////
int 	  sous_menu (char mode, int x, int y)
{
  char 	entry;

  sous_menutxt();
  my_putstr("-> ");
  entry = getchar();
  while ('\n' != getchar());
  if (entry >= '1' && entry <= '6') //verification niveau
    redirection_map(mode, entry, x, y);
  else if (entry == 'r')
    return (1);
  else
    my_putstr("no such map\n");
  return (0);
}

////////// Menu Principale //////////
int 	  main (void)
{
  int 	x;
  int 	y;
  int 	v;
  char 	entry;

  x = 1;
  y = 1;
  v = 0;
  my_putstr("\033c");
  menutxt(); //affigage du menu
  my_putstr("-> ");
  entry = getchar();
  while ('\n' != getchar());
  if (entry >= '1' && entry <= '4') //verification de l'input
    v = sous_menu(entry, x, y);
  else if (entry == 'q')
  {
    my_putstr("bye\n");
    return (0);
  }
  else
  my_putstr("no such option\n");
  if (v == 1)
  main();
  return (0);
}