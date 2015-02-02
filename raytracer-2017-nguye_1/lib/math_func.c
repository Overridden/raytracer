/*
** math_func.c for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/lib
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Fri Jun  7 09:34:22 2013 maxime guedj
** Last update Fri Jun  7 10:42:40 2013 maxime guedj
*/

#include <math.h>

int		my_pow_it(int nb, int i)
{
  int		ret;

  ret = 1;
  while (--i >= 0)
    ret *= nb;
  return (ret);
}

double		square(double value)
{
  double	result;

  result = value * value;
  return (result);
}

double		convert_to_rad(int value)
{
  double	result;

  result = value * M_PI / 180;
  return (result);
}
