/*
** plane_color.c for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/calc/objs
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Fri Jun  7 17:49:53 2013 maxime guedj
** Last update Sun Jun  9 16:32:18 2013 noel dovan
*/

#include <stdio.h>
#include <stdlib.h>
#include "raytracer.h"
#include "object.h"

int		plane_color(t_obj *obj)
{
  if (obj->color.color_type == COLOR_STD)
    return (obj->color.prim_color);
  if (obj->color.color_type == COLOR_CHECK_BOARD)
    return (dam_plane(obj));
  else if (obj->color.color_type == COLOR_RAYE_H
	   || obj->color.color_type == COLOR_RAYE_V)
    return (ray_plane(obj));
  else
    return (text_plane(obj));
}

int		dam_plane(t_obj *obj)
{
  int		color;
  int           damier_x;
  int           damier_y;

  ((obj->inter->y < 0) ? (damier_y = 100) : (damier_y = 0));
  ((obj->inter->x < 0) ? (damier_x = 100) : (damier_x = 0));
  if (((((int)obj->inter->x % 100) + damier_x > 50 &&
        ((int)obj->inter->y % 100) + damier_y > 50) ||
       (((int)obj->inter->x % 100) + damier_x < 50 &&
        ((int)obj->inter->y % 100) + damier_y < 50)))
    color = obj->color.sec_color;
  else
    color = obj->color.prim_color;
  return (color);
}

int		ray_plane(t_obj *obj)
{
  int		color;
  int           damier_x;
  int           damier_y;

  ((obj->inter->y < 0) ? (damier_y = 100) : (damier_y = 0));
  ((obj->inter->x < 0) ? (damier_x = 100) : (damier_x = 0));
  if (obj->color.color_type == 2)
    color = (((int)obj->inter->y % 100) + damier_y > 50) ?
      obj->color.sec_color : obj->color.prim_color;
  else
    color = (((int)obj->inter->x % 100) + damier_x > 50) ?
      obj->color.sec_color : obj->color.prim_color;
  return (color);
}

int		text_plane(t_obj *obj)
{
  int		color;

  color = 0;
  color = get_color_from_img((((int)(obj->inter->y * 4)
			       + (obj->texture.width / 2)) %
			      obj->texture.width),
			     (obj->texture.height / 2 -
			      (((int)(obj->inter->x * 4) %
				obj->texture.height) -
			       obj->texture.height / 2)),
			     obj->texture.data, obj->texture.sizeline_bpp);
  return (color);
}
