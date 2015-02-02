/*
** plane.c for RT in /home/nguye_1//projects/igraph/raytracer-2017-nguye_1/objs
**
** Made by alexandre1 nguyen
** Login   <nguye_1@epitech.net>
**
** Started on  Tue May 28 11:09:47 2013 alexandre1 nguyen
** Last update Sat Jun  8 17:45:28 2013 maxime guedj
*/

#include <stdio.h>
#include <math.h>
#include "raytracer.h"
#include "object.h"
#include "utils.h"
#include "calc.h"

void		plane_norm(t_obj *obj, t_point *vector)
{
  vector->x = 0;
  vector->y = 0;
  vector->z = (obj->pos->z < 0) ? D : -D;
}

double		calcul_plane(double eyez, double vectorz)
{
  double	k;

  k = -(eyez / vectorz);
  if ((k) > 0.00000001)
    return (k);
  else
    return (-1);

}

void		obj_plane(t_point *eye, t_point *vector, t_obj *obj)
{
  if (ABS(vector->z) < 0.0000001)
    {
      obj->k[0] = -1;
      obj->k[1] = -1;
    }
  else
    {
      obj->k[0] = calcul_plane(eye->z, vector->z);
      obj->k[1] = -1;
    }
}
