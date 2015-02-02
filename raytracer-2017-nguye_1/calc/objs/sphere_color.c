/*
** sphere_color.c for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/calc/objs
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Fri Jun  7 17:06:08 2013 maxime guedj
** Last update Sun Jun  9 15:26:52 2013 alexandre1 nguyen
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "raytracer.h"
#include "object.h"

int		sphere_color(t_obj *obj)
{
  double	phi;
  double	theta;

  if (obj->color.color_type == COLOR_STD)
    return (obj->color.prim_color);
  phi = acos(obj->inter->z / obj->param);
  if (obj->inter->y > 0.0000001)
    theta = acos(((obj->inter->x / obj->param)
		  / sin(phi)) * -1) + M_PI;
  else
    theta = acos((obj->inter->x /
		  obj->param) / sin(phi));
  if (obj->color.color_type == COLOR_CHECK_BOARD)
    return (dam_sphere(obj, phi, theta));
  else if (obj->color.color_type ==  COLOR_RAYE_V
	   || obj->color.color_type == COLOR_RAYE_H)
    return (ray_sphere(obj, phi, theta));
  else
    return (text_sphere(obj, phi, theta));
}

int		dam_sphere(t_obj *obj, double phi, double theta)
{
  if ((((int)(WINDOW_WIDTH * theta / (2 * M_PI)) % 100 > 50 &&
	(int)(WINDOW_HEIGHT * phi / M_PI) % 100 > 50) ||
       ((int)(WINDOW_WIDTH * theta / (2 * M_PI)) % 100 < 50 &&
	(int)(WINDOW_HEIGHT * phi / M_PI) % 100 < 50)))
    return (obj->color.sec_color);
  else
    return (obj->color.prim_color);
}

int		ray_sphere(t_obj *obj, double phi, double theta)
{
  int		color;

  if (obj->color.color_type == COLOR_RAYE_H)
    {
      color = ((int)(WINDOW_WIDTH * phi / M_PI) % 100 > 50) ?
	obj->color.sec_color : obj->color.prim_color;
    }
  else
    {
      color = (((int)(WINDOW_WIDTH * theta / (2 * M_PI)) % 100) > 50) ?
	obj->color.sec_color : obj->color.prim_color;
    }
  return (color);
}

int		text_sphere(t_obj *obj, double phi, double theta)
{
  int		x;
  int		y;
  int		color;

  color = 0;
  x = obj->texture.width * theta / (2 * M_PI);
  y = obj->texture.height * phi / M_PI;
  color = get_color_from_img(x, y, obj->texture.data,
			     obj->texture.sizeline_bpp);
  return (color);
}
