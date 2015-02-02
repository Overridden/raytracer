/*
** my_put.c for my_put in /home/dovan_n//svn/raytracer-2017-nguye_1/lib
**
** Made by noel dovan
** Login   <dovan_n@epitech.net>
**
** Started on  Wed May 29 13:56:02 2013 noel dovan
** Last update Fri Jun  7 09:39:29 2013 maxime guedj
*/

#include <unistd.h>
#include "lib.h"

int		my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (-1);
  return (0);
}

int		my_putstr(char *str)
{
  if (write(1, str, my_strlen(str)) == -1)
    return (-1);
  return (0);
}

int		my_putnbr(int nb)
{
  if (nb < 0)
    {
      nb = nb * -1;
      if (my_putchar('-') == -1)
	return (-1);
    }
  if (nb >= 10)
    {
      if (my_putnbr(nb / 10) == -1)
	return (-1);
      if (my_putnbr(nb % 10) == -1)
	return (-1);
    }
  else
    if (my_putchar(nb + '0') == -1)
      return (-1);
  return (0);
}
