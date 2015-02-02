/*
** math_calcul.c for math_calcul in /home/dovan_n//svn/raytracer-2017-nguye_1/objs
**
** Made by noel dovan
** Login   <dovan_n@epitech.net>
**
** Started on  Mon May 27 17:59:18 2013 noel dovan
** Last update Sat Jun  8 18:00:44 2013 maxime guedj
*/

#include <math.h>
#include "raytracer.h"
#include "object.h"
#include "utils.h"
#include "lib.h"

void		solve2(double a, double b, double c, t_obj *obj)
{
  double	delta;
  double	k1;
  double	k2;

  if ((delta = square(b) - 4 * a * c) >= 0.00001)
    {
      k1 = (-b + sqrt(delta)) / (2 * a);
      k2 = (-b - sqrt(delta)) / (2 * a);
      if (k1 < k2)
	{
	  obj->k[0] = k1;
	  obj->k[1] = k2;
	}
      else
	{
	  obj->k[0] = k2;
	  obj->k[1] = k1;
	}
    }
  else
    {
      obj->k[0] = -1;
      obj->k[1] = -1;
    }
}
