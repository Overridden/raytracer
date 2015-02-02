/*
** get_pixel_color.c for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/calc
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Tue May 28 13:40:42 2013 maxime guedj
** Last update Sun Jun  9 14:30:39 2013 jeremy cerini
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "raytracer.h"
#include "object.h"
#include "calc.h"
#include "utils.h"
#include "lib.h"

static t_color_func	get_color[4] = {&sphere_color, &cylinder_color,
					&plane_color, &cone_color};

int		get_clean_pixel(t_scene *scene, double x, double y)
{
  int		pixel[5];
  int		ret;

  pixel[0] = get_pixel_color(scene, x, y);
  pixel[1] = get_pixel_color(scene, x - COEF_ECART, y);
  pixel[2] = get_pixel_color(scene, x + COEF_ECART, y);
  pixel[3] = get_pixel_color(scene, x, y + COEF_ECART);
  pixel[4] = get_pixel_color(scene, x, y - COEF_ECART);
  ret = (pixel[0] % 256 + pixel[1] / my_pow_it(256, 0)
	 % 256 + pixel[2] % 256 + pixel[3]
	 % 256 + pixel[4] % 256) / 5;
  ret += (pixel[0] / 256 % 256 + pixel[1] / 256
	  % 256 + pixel[2] / 256 % 256 + pixel[3] /
	  256 % 256 + pixel[4] / 256 % 256) / 5 * 256;
  ret += (pixel[0] / my_pow_it(256, 2) % 256 + pixel[1] / my_pow_it(256, 2)
	  % 256 + pixel[2] / my_pow_it(256, 2) % 256 + pixel[3]
	  / my_pow_it(256, 2) % 256 + pixel[4] / my_pow_it(256, 2) % 256)
    / 5 * my_pow_it(256, 2);
  return (ret);
}

int		get_pixel_color(t_scene *scene, double x, double y)
{
  t_obj		*n_obj;
  int		color;

  n_obj = find_the_object(scene, x, y);
  if (n_obj == NULL)
    return (0);
  color = get_color[n_obj->type](n_obj);
  color = light_the_color(scene, n_obj, color);
  free_point(n_obj->inter);
  n_obj->inter = NULL;
  return (color);
}
