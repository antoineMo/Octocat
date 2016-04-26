/*
** struct.h for  in /Users/vanhem_n/Documents/Octo
**
** Made by VAN HEMELRYCK Nathan
** Login   <Vanhem_n@etna-alternance.net>
**
** Started on  Mon Jan 09 09:13:47 2016 VAN HEMELRYCK Nathan
** Last update Mon Jan 17 16:39:00 2016 VAN HEMELRYCK Nathan
*/

#ifndef __STRUCT_H__
#define	__STRUCT_H__

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h> // include open read


////////// Prototype fonction //////////
void      my_putchar(char c);
void	  my_putstr(char *str);
int	      my_strlen(char *str);
void      mini_strcat(char* s, char c);
char	  *my_strcat(char *str1, char *str2);
int    	  main (void);
void      do_my_message(char mode, char **tab, int v, int r);
int       do_it_easy (char **tab, int x, int y);
int       do_it_hard (char **tab, int x, int y);
int       do_my_tab (char **tab, int x, int y);
char  	  **map_loader(char *name);
int       redirection_map(char mode, char lvl, int x, int y);
int       do_it_blind (char mode, char **tab, int x, int y);
int       do_my_blind_tab (char mode, char **tab, int x, int y);
void      aff_my_blind_tab (char **tab, int x, int y);
void      re_my_map(char **tab, int x, int y, int v);

#endif