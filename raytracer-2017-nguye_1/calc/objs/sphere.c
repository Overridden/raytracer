/*
** sphere.c for sphere in /home/dovan_n//svn/raytracer-2017-nguye_1/objs
**
** Made by noel dovan
** Login   <dovan_n@epitech.net>
**
** Started on  Mon May 27 17:34:57 2013 noel dovan
** Last update Sat Jun  8 18:01:34 2013 maxime guedj
*/

#include <stdio.h>
#include "raytracer.h"
#include "object.h"
#include "utils.h"
#include "calc.h"
#include "lib.h"

void		sphere_norm(t_obj *obj, t_point *vector)
{
  vector->x = obj->inter->x;
  vector->y = obj->inter->y;
  vector->z = obj->inter->z;
}

double		sphere_c(t_point *eye, double par)
{
  double	c;

  c = square(eye->x) + square(eye->y) + square(eye->z) - square(par);
  return (c);
}

double		sphere_b(t_point *eye, t_point *vector)
{
  double	b;

  b = 2 * (eye->x * vector->x
	   + eye->y * vector->y
	   + eye->z * vector->z);
  return (b);
}

double		sphere_a(t_point *vector)
{
  double	a;

  a = square(vector->x) + square(vector->y) + square(vector->z);
  return (a);
}

void		obj_sphere(t_point *eye, t_point *vector, t_obj *obj)
{
  double	a;
  double	b;
  double	c;

  a = sphere_a(vector);
  b = sphere_b(eye, vector);
  c = sphere_c(eye, obj->param);
  solve2(a, b, c, obj);
}
