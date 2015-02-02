/*
** light_func.c for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/utils
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Mon May 27 16:52:34 2013 maxime guedj
** Last update Fri Jun  7 20:27:00 2013 maxime guedj
*/

#include <stdlib.h>
#include "raytracer.h"
#include "utils.h"

t_light		*creat_light()
{
  t_light	*elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (NULL);
  elem->pos = NULL;
  elem->is_set = 0;
  elem->color = 0;
  elem->next = NULL;
  return (elem);
}

char		set_light_pos(t_light *light, int x, int y, int z)
{
  light->pos = creat_point(x, y, z);
  if (light->pos == NULL)
    return (FAIL);
  return (SUCCESS);
}

void		set_light_color(t_light *light, int color)
{
  light->color = color;
}

void		free_light(t_light *light)
{
  if (light->pos)
    free_point(light->pos);
  free(light);
}
