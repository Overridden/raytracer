/*
** cylinder_color.c for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/calc/objs
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Fri Jun  7 19:52:55 2013 maxime guedj
** Last update Sun Jun  9 16:31:46 2013 noel dovan
*/

#include <math.h>
#include "raytracer.h"
#include "object.h"

int		cylinder_color(t_obj *obj)
{
  int		damier_x;
  int		damier_y;
  double	theta;

  if (obj->color.color_type == COLOR_STD)
    return (obj->color.prim_color);
  theta = acos((obj->inter->x) / obj->param);
  if ((obj->inter->y) > 0.0000001)
    theta = theta * -1 + M_PI;
  (((obj->inter->z) < 0.0000001) ? (damier_y = 10) : (damier_y = 0));
  (((obj->texture.width * (theta + M_PI / 2) / (M_PI)) < 0) ?
   (damier_x = 5) : (damier_x = 0));
  if (obj->color.color_type == COLOR_CHECK_BOARD)
    return (dam_cylinder(obj, theta, damier_y));
  else if (obj->color.color_type == COLOR_RAYE_H
	   || obj->color.color_type == COLOR_RAYE_V)
    return (ray_cylinder(obj, theta, damier_y));
  else
    return (text_cylinder(obj, theta));
}

int		dam_cylinder(t_obj *obj, double theta, int damier_y)
{
  int		color;

  if (((((int)(WINDOW_WIDTH * (theta + M_PI / 2) / (M_PI)) / 5) % 100) >= 50 &&
       ((int)(obj->inter->z)) % 10 + damier_y >= 5)
      ||
      ((((int)(WINDOW_WIDTH * (theta + M_PI / 2) / (M_PI)) / 5) % 100) < 50 &&
       ((int)(obj->inter->z)) % 10 + damier_y < 5))
    color = obj->color.sec_color;
  else
    color = obj->color.prim_color;
  return (color);
}

int		ray_cylinder(t_obj *obj, double theta, int damier_y)
{
  int		color;

  color = 0;
  if (obj->color.color_type == COLOR_RAYE_V)
    color = ((int)(WINDOW_WIDTH *
		   ((theta + M_PI / 2) / M_PI / 5)) % 100 >= 50) ?
      obj->color.sec_color : obj->color.prim_color;
  else if (obj->color.color_type == COLOR_RAYE_H)
    color = (((int)(obj->inter->z) % 10) + damier_y < 5) ?
      obj->color.sec_color : obj->color.prim_color;
  return (color);
}

int		text_cylinder(t_obj *obj, double theta)
{
  int		color;

  if ((obj->inter->z) < 0.0000001)
    color = get_color_from_img((obj->texture.width / (M_PI) *
				(theta + M_PI / 2)),
			       ((int)((obj->inter->z) *
				      obj->texture.height / 24) %
				obj->texture.height),
			       obj->texture.data, obj->texture.sizeline_bpp);
  else
    color = get_color_from_img((obj->texture.width *
				(theta + M_PI / 2) / (M_PI)),
			       ((int)((obj->inter->z) *
				      obj->texture.height / 24) %
				obj->texture.height) * -1
			       + obj->texture.height,
			       obj->texture.data, obj->texture.sizeline_bpp);
  return (color);
}
