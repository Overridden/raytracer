/*
** epure_str.c for  in /home/lastru_g//svn/raytracer-2017-nguye_1/parser
**
** Made by gael lastrucci
** Login   <lastru_g@epitech.net>
**
** Started on  Mon Jun  3 12:31:38 2013 gael lastrucci
** Last update Fri Jun  7 09:41:36 2013 maxime guedj
*/

#include <stdio.h>
#include <stdlib.h>

void		all_space(char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == '\t')
	str[i] = ' ';
      i++;
    }
}

void		sup_char(char *str, int i)
{
  int		x;

  x = i;
  while (str[x] != 0)
    {
      str[x] = str[x + 1];
      x++;
    }
}

char		*my_epure_str(char *str)
{
  int		i;

  i = 0;
  if (str != NULL)
    {
      all_space(str);
      while (str[0] == ' ' && str[0] != 0)
	sup_char(str, 0);
      while (str[i] != 0)
	{
	  if (str[i] == ' ' && str[i + 1] == ' ')
	    {
	      sup_char(str, i);
	      --i;
	    }
	  i++;
	}
      if (i > 0 && str[i - 1] == ' ')
	str[i - 1] = 0;
    }
  return (str);
}
