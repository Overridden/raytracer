/*
** get_nbr_base.c for lib in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/parser
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Fri Jun  7 08:52:57 2013 maxime guedj
** Last update Fri Jun  7 09:43:00 2013 maxime guedj
*/

#include <string.h>
#include <math.h>
#include "lib.h"

int		getnbr_base(char *str, char *base)
{
  int		i;
  int		nbr;
  int		index;
  int		base_len;
  int		str_len;

  i = 0;
  nbr = 0;
  base_len = strlen(base);
  str_len = strlen(str);
  while (str[i])
    {
      if ((index = str_contain(base, str[i])) == -1)
	return (nbr);
      nbr += (index * (int)(pow(base_len, str_len - i - 1)));
      i++;
    }
  return (nbr);
}
