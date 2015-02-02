/*
** cosinus.c for cosinus in /home/dovan_n//svn/raytracer-2017-nguye_1/calc
**
** Made by noel dovan
** Login   <dovan_n@epitech.net>
**
** Started on  Wed May 29 14:09:24 2013 noel dovan
** Last update Sun Jun  9 16:37:13 2013 noel dovan
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "raytracer.h"
#include "calc.h"
#include "utils.h"
#include "lib.h"
#include "object.h"

static t_vec_func	n_func[4] = {&sphere_norm, &cylinder_norm,
			     &plane_norm, &cone_norm};

t_point		*get_norm(t_obj *obj)
{
  t_point	*norm;

  norm = creat_point(0, 0, 0);
  if (norm == NULL)
    return (NULL);
  n_func[obj->type](obj, norm);
  return (norm);
}

double		calc_cos(t_obj *obj, t_point *vlight)
{
  t_point	*normal;
  double	normal_n;
  double	normal_l;
  double	normal_res;
  double	scalaire;
  double	cos_param;

  normal = get_norm(obj);
  if (obj->k[1] == -1 && obj->type != plane)
    {
      normal->x *= -1;
      normal->y *= -1;
      normal->z *= -1;
    }
  if (normal == NULL || vlight == NULL)
    return (2);
  normal_n = sqrt(square(normal->x) + square(normal->y) + square(normal->z));
  normal_l = sqrt(square(vlight->x) + square(vlight->y) + square(vlight->z));
  normal_res = normal_n * normal_l;
  scalaire = normal->x * vlight->x + normal->y * vlight->y
    + normal->z * vlight->z;
  if ((cos_param = (scalaire / normal_res)) < 0)
    cos_param = -1;
  free_point(normal);
  return (cos_param);
}
