/*
** my_putchar.c for my_putchar.c in /home/antoine/Desktop/pataugoire/octo
**
** Made by MORISSET Antoine
** Login   <moriss_a@etna-alternance.net>
**
** Started on  Mon Jan  18 09:36:51 2016 MORISSET Antoine
** Last update Fri jan  21 16:45:59 2016 MORISSET Antoine
*/

#include "struct.h"

////////// Fonction affichage carractere //////////
void	my_putchar(char c)
{
  write(1, &c, 1);
}

////////// Fonction affichage chaine de carractere //////////
void	my_putstr(char *str)
{
  int cp;
  cp = 0;
  while (*(str + cp) != '\0')
    {
      my_putchar(*(str + cp));
      ++cp;
    }
}

////////// Fonction longueur d'une chaine //////////
int	  my_strlen(char *str)
{
  int var;
  var = 0;
  while (*(str + var) != '\0')
    {
      var++;
    }
  return (var);
}

////////// Fonction pour le lvl{variable}.map //////////
void  mini_strcat(char* s, char c)
{
        int len = my_strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

////////// Fonction concatenation //////////
char	*my_strcat(char *str1, char *str2)
{
  int var;
  int var2;

  var = 0;
  var2 = 0;
  while (str1[var] != '\0')
    {
      var++;
    }
  while (str2[var2] != '\0')
    {
      str1[var] = str2[var2];
      var2++;
      var++;
    }
  str1[var] = '\0';
  return (str1);
}