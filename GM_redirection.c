/*
** GM_redirection.c for GM_redirection.c in /home/antoine/Desktop/pataugoire/octo
**
** Made by MORISSET Antoine
** Login   <moriss_a@etna-alternance.net>
**
** Started on  Mon Jan  18 14:16:51 2016 MORISSET Antoine
** Last update Fri jan  21 16:45:59 2016 MORISSET Antoine
*/

#include "struct.h"

////////// Fonction chargement map depuis un fichier .map //////////
char		**map_loader(char *name)
{
	int 	j;
	int 	i;
	int 	lect;
 	char 	buffer[512];
 	int 	u;
	int 	pop;
	char  	**tab;

	tab = malloc(sizeof(char*)*20);
	for (i = 0; i < 20; i++)
    	tab[i] = malloc(sizeof(char)*22);
    if (tab == NULL)
		return (0);
     j = 0;
     u = 0;
     lect = open(name, O_RDONLY);
	 pop = read(lect, buffer, 512);
	 close(lect);
	 for (i = 0; i <= 21 && j < 20; i++){
	 	if (u < (pop))
	 		tab[j][i] = buffer[u];
	 	if (i == 20){
			tab[j][21] = '\0';
	 		i = -1;
	 		j++;
	 	}
	 	u++;
	 }
    return (tab);
}

////////// Fonction pour free le tableaux loader 100% free //////////
void 		my_free(char **tab)
{
	int 	i;

	for (i = 0; i < 20; ++i)
			free(tab[i]);
	free(tab);
}

////////// Fonction permetant apres chargement de la map de lancer le bon mode de jeu //////////
int 		redirection_map(char mode, char lvl, int x, int y)
{
  char 		**tab;
  char 		name[20] = "lvl";

  mini_strcat(name, lvl);
  my_strcat(name, ".map");
  tab = map_loader(name); //creation tableaux
  if (mode == '1') //redirection avec la map sur le mode choisi
    do_it_easy(tab, x, y);
  else if (mode == '2')
    do_it_hard(tab, x, y);
	else if (mode == '3' || mode == '4')
		do_it_blind(mode, tab, x, y);
  my_free(tab);
	main();
  return (0);
}