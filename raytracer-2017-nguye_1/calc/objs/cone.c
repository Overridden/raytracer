/*
** cone.c for cone in /home/dovan_n//svn/raytracer-2017-nguye_1/objs
**
** Made by noel dovan
** Login   <dovan_n@epitech.net>
**
** Started on  Tue May 28 14:31:09 2013 noel dovan
** Last update Sat Jun  8 18:01:20 2013 maxime guedj
*/

#include <math.h>
#include "raytracer.h"
#include "object.h"
#include "utils.h"
#include "calc.h"
#include "lib.h"

void		cone_norm(t_obj *obj, t_point *vector)
{
  vector->x = obj->inter->x;
  vector->y = obj->inter->y;
  vector->z = -square(tan(obj->param)) * obj->inter->z;
}

double		cone_c(t_point *eye, double par)
{
  double	c;
  double	ta;

  ta = tan(par);
  c = square(eye->x) + square(eye->y) - square(eye->z) * square(ta);
  return (c);
}

double		cone_b(t_point *eye, t_point *vector, double par)
{
  double	b;
  double	ta;

  ta = tan(par);
  b = 2 * (vector->x * eye->x
	   + vector->y * eye->y
	   - vector->z * eye->z
	   *square(ta));
  return (b);
}

double		cone_a(t_point *vector, double par)
{
  double	a;
  double	ta;

  ta = tan(par);
  a = square(vector->x)
    + square(vector->y)
    - square(vector->z)
    * square(ta);
  return (a);
}

void		obj_cone(t_point *eye, t_point *vector, t_obj *obj)
{
  double	a;
  double	b;
  double	c;

  a = cone_a(vector, obj->param);
  b = cone_b(eye, vector, obj->param);
  c = cone_c(eye, obj->param);
  solve2(a, b, c, obj);
}
