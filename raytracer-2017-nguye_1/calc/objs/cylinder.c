/*
** cylinder.c for RT in /home/nguye_1//projects/igraph/raytracer-2017-nguye_1/objs
**
** Made by alexandre1 nguyen
** Login   <nguye_1@epitech.net>
**
** Started on  Mon May 27 17:34:59 2013 alexandre1 nguyen
** Last update Sat Jun  8 18:01:57 2013 maxime guedj
*/

#include "raytracer.h"
#include "object.h"
#include "utils.h"
#include "calc.h"
#include "lib.h"

void		cylinder_norm(t_obj *obj, t_point *vector)
{
  vector->x = obj->inter->x;
  vector->y = obj->inter->y;
  vector->z = 0;
}

double		cylinder_c(t_point *eye, double par)
{
  double	c;

  c = square(eye->x) + square(eye->y) - square(par);
  return (c);
}

double		cylinder_b(t_point *eye, t_point *vector)
{
  double	b;

  b = 2 * (eye->x * vector->x + eye->y * vector->y);
  return (b);
}

double		cylinder_a(t_point *vector)
{
  double	a;

  a = square(vector->x) + square(vector->y);
  return (a);
}

void		obj_cylinder(t_point *eye, t_point *vector, t_obj *obj)
{
  double	a;
  double	b;
  double	c;

  a = cylinder_a(vector);
  b = cylinder_b(eye, vector);
  c = cylinder_c(eye, obj->param);
  solve2(a, b, c, obj);
}
