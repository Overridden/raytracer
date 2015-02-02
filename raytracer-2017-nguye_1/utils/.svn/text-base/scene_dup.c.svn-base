/*
** scene_dup.c for scene_dup in /home/dovan_n//svn/raytracer-2017-nguye_1/utils
**
** Made by noel dovan
** Login   <dovan_n@epitech.net>
**
** Started on  Fri Jun  7 12:54:37 2013 noel dovan
** Last update Sun Jun  9 16:32:54 2013 noel dovan
*/

#include <stdlib.h>
#include <strings.h>
#include "raytracer.h"
#include "utils.h"

t_scene		*scene_dup(t_scene *scene)
{
  t_scene	*ret;
  t_obj		*cur;
  t_obj		*prev;
  t_obj		*tmp;

  if ((ret = malloc(sizeof(*ret))) == NULL)
    return (NULL);
  ret->mlx = scene->mlx;
  ret->obj = scene->eye;
  prev = NULL;
  if ((ret->eye = dup_obj(scene->eye)) == NULL)
    return (NULL);
  cur = scene->obj;
  while (cur != NULL)
    {
      if ((tmp = dup_obj(cur)) == NULL)
	return (NULL);
      if (prev == NULL)
	ret->obj = tmp;
      else
	prev->next = tmp;
      prev = tmp;
      cur = cur->next;
    }
  return (scene_dup_light(scene, ret));
}

void		dup_pars(t_obj *cur, t_obj *ret)
{
  ret->texture.texture_name = cur->texture.texture_name;
  ret->texture.texture_ptr = cur->texture.texture_ptr;
  ret->texture.width = cur->texture.width;
  ret->texture.height = cur->texture.height;
  ret->texture.sizeline_bpp[0] = cur->texture.sizeline_bpp[0];
  ret->texture.sizeline_bpp[1] = cur->texture.sizeline_bpp[1];
  ret->texture.data = cur->texture.data;
}

t_obj		*dup_obj(t_obj *cur)
{
  t_obj		*ret;
  int		i;

  if ((ret = malloc(sizeof(*ret))) == NULL)
    return (NULL);
  ret->type = cur->type;
  ret->inter = NULL;
  ret->k[0] = 0;
  ret->k[1] = 1;
  dup_pars(cur, ret);
  ret->limit = cur->limit;
  ret->bright = cur->bright;
  ret->color.color_type = cur->color.color_type;
  ret->color.prim_color = cur->color.prim_color;
  ret->color.sec_color = cur->color.sec_color;
  ret->param = cur->param;
  ret->pos = cur->pos;
  i = -1;
  while (++i < 9)
    {
      ret->n_rot[i / 3][i % 3] = cur->n_rot[i / 3][i % 3];
      ret->i_rot[i / 3][i % 3] = cur->i_rot[i / 3][i % 3];
    }
  ret->next = NULL;
  return (ret);
}

t_scene		*scene_dup_light(t_scene *scene, t_scene *ret)
{
  t_light	*tmpl;
  t_light	*curl;
  t_light	*prevl;

  prevl = NULL;
  curl = scene->light;
  while (curl != NULL)
    {
      if ((tmpl = dup_light(curl)) == NULL)
	return (NULL);
      if (prevl == NULL)
	ret->light = tmpl;
      else
	prevl->next = tmpl;
      prevl = tmpl;
      curl = curl->next;
    }
  return (ret);
}

t_light		*dup_light(t_light *cur)
{
  t_light	*ret;

  if ((ret = malloc(sizeof(*ret))) == NULL)
    return (NULL);
  ret->color = cur->color;
  ret->pos = cur->pos;
  ret->next = NULL;
  return (ret);
}
