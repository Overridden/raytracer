/*
** all_func.c for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/utils
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Mon May 27 19:50:49 2013 maxime guedj
** Last update Tue May 28 14:30:37 2013 maxime guedj
*/

#include <stdlib.h>
#include "raytracer.h"
#include "utils.h"

t_scene		*creat_scene()
{
  t_scene	*elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (NULL);
  elem->eye = NULL;
  elem->obj = NULL;
  elem->light = NULL;
  elem->mlx = NULL;
  return (elem);
}

void		free_all(t_scene *all)
{
  if (all->obj != NULL)
    free_all_obj(all->obj);
  if (all->light != NULL)
    free_all_light(all->light);
  if (all->mlx)
    free(all->mlx);
  free(all);
}
