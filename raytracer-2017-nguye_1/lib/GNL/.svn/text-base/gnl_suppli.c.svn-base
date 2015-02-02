/*
** gnl_suppli.c for gnl in /home/cerini_j//current_project/42/GNL
**
** Made by jeremy cerini
** Login   <cerini_j@epitech.net>
**
** Started on  Tue Apr 16 14:05:05 2013 jeremy cerini
** Last update Fri Jun  7 09:54:53 2013 maxime guedj
*/

#include <stdlib.h>
#include "raytracer.h"
#include "lib.h"

char	*my_clear(char *str, int size)
{
  int	j;

  j = -1;
  while (++j < size)
    str[j] = 0;
  return (str);
}

char	*my_realloc(char *str, int size)
{
  int	j;
  char	*new_str;

  j = 0;
  new_str = malloc(sizeof(*new_str) * size);
  if (new_str == NULL)
    {
      free(str);
      return (NULL);
    }
  my_clear(new_str, size);
  while (str[j] != 0)
    {
      new_str[j] = str[j];
      ++j;
    }
  new_str[j] = 0;
  free(str);
  return (new_str);
}

int	check_to_ret(t_gnl all, char *buff, int *i)
{
  if (((all.str[all.pos] = buff[(*i)++]) == 10
       || all.str[all.pos] == 0)
      && (all.str[all.pos] = 0) == 0)
    return (1);
  return (0);
}
