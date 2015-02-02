/*
** delete_elem_list.c for  in /home/lastru_g//svn/raytracer-2017-nguye_1/parser
**
** Made by gael lastrucci
** Login   <lastru_g@epitech.net>
**
** Started on  Wed May 29 11:52:26 2013 gael lastrucci
** Last update Fri Jun  7 10:18:59 2013 maxime guedj
*/

#include <stdlib.h>
#include "raytracer.h"
#include "init.h"
#include "utils.h"

void		del_elem_light(t_scene *scene, t_light *del)
{
  t_light	*tmp;

  tmp = scene->light;
  if (del == tmp)
    {
      if (del->pos != NULL)
	free(del->pos);
      scene->light = scene->light->next;
      free(del);
    }
  else
    {
      while (tmp->next != del)
	tmp = tmp->next;
      if (del->pos != NULL)
	free(del->pos);
      tmp->next = del->next;
      free(del);
    }
}

void		del_elem_obj(t_scene *scene, t_obj *del)
{
  t_obj		*tmp;

  tmp = scene->obj;
  if (del == tmp)
    {
      if (del->pos != NULL)
	free(del->pos);
      scene->obj = scene->obj->next;
      free(del);
    }
  else
    {
      while (tmp->next != del)
	tmp = tmp->next;
      if (del->pos != NULL)
	free(del->pos);
      tmp->next = del->next;
      free(del);
    }
}

t_scene		*free_all_elem(t_scene *all)
{
  free_all(all);
  return (NULL);
}
