/*
** light.c for light in /home/dovan_n//svn/raytracer-2017-nguye_1/calc
**
** Made by noel dovan
** Login   <dovan_n@epitech.net>
**
** Started on  Mon Jun  3 17:23:09 2013 noel dovan
** Last update Sun Jun  9 16:52:21 2013 maxime guedj
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"
#include "calc.h"
#include "utils.h"
#include "object.h"

int		light_the_color(t_scene *scene, t_obj *n_obj, int color)
{
  int		i;
  t_light	*tmp;
  int		o_rgb[3];
  int		l_rgb[3];
  int		r_rgb[3];
  double	coef;

  i = 0;
  tmp = scene->light;
  init_color(color, o_rgb, r_rgb);
  while (tmp)
    {
      coef = get_coef(scene, n_obj, tmp);
      if (coef > 0 && coef != COEF_SHADOW)
	{
	  fill_l_rgb(l_rgb, tmp, n_obj, o_rgb);
	  add_color(r_rgb, l_rgb, coef);
	}
      else
	add_color(r_rgb, o_rgb, coef);
      tmp = tmp->next;
      i++;
    }
  div_color(r_rgb, i);
  return (c_color(r_rgb));
}

void		init_color(int color, int *o_rgb, int *r_rgb)
{
   get_rgb(color, o_rgb);
   memset(r_rgb, 0, sizeof(int) * 3);
}

void		fill_l_rgb(int *l_rgb, t_light *tmp, t_obj *n_obj, int *o_rgb)
{
  get_rgb(tmp->color, l_rgb);
  mult_color(l_rgb, n_obj->bright);
  add_color(l_rgb, o_rgb, 1 - n_obj->bright);
}

t_point		*get_vlight(t_obj *obj, t_light *light)
{
  t_point	*vlight;

  vlight = creat_point(0, 0, 0);
  if (vlight == NULL)
    return (NULL);
  vlight->x = (light->pos->x - obj->pos->x);
  vlight->y = (light->pos->y - obj->pos->y);
  vlight->z = (light->pos->z - obj->pos->z);
  m_i_rot_mult(vlight, obj);
  vlight->x = vlight->x - obj->inter->x;
  vlight->y = vlight->y - obj->inter->y;
  vlight->z = vlight->z - obj->inter->z;
  return (vlight);
}

double		get_coef(t_scene *scene, t_obj *obj, t_light *light)
{
  double	coef;
  t_point	*vlight;
  t_obj		*tmp;

  tmp = NULL;
  vlight = get_vlight(obj, light);
  if (check_shadow(scene, obj, vlight, tmp))
    coef = COEF_SHADOW;
  else
    coef = calc_cos(obj, vlight);
  scene = scene;
  free_point(vlight);
  coef = (coef == -1) ? 0 : coef;
  return (coef);
}
