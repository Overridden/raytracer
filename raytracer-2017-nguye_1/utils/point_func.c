/*
** point_func.c for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/utils
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Mon May 27 16:55:56 2013 maxime guedj
** Last update Wed May 29 09:38:11 2013 maxime guedj
*/

#include <stdlib.h>
#include "raytracer.h"
#include "utils.h"

t_point		*creat_point(double x, double y, double z)
{
  t_point	*p;

  p = malloc(sizeof(*p));
  if (p == NULL)
    return (NULL);
  p->x = x;
  p->y = y;
  p->z = z;
  return (p);
}

t_point		*dup_point(t_point *p)
{
  return (creat_point(p->x, p->y, p->z));
}

void		cpy_point(t_point *src, t_point *dest)
{
  dest->x = src->x;
  dest->y = src->y;
  dest->z = src->z;
}

void		free_point(t_point *p)
{
  free(p);
}
