/*
** obj_list_func.c for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/utils
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Mon May 27 15:56:48 2013 maxime guedj
** Last update Thu May 30 13:31:51 2013 maxime guedj
*/

#include <stdio.h>
#include <stdlib.h>
#include "raytracer.h"
#include "utils.h"

t_obj		*add_obj(t_obj *first, t_obj *elem)
{
  t_obj		*tmp;

  tmp = first;
  if (tmp == NULL)
    return (elem);
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = elem;
  return (first);
}

void		free_obj(t_obj *obj)
{
  if (obj->pos != NULL)
    free_point(obj->pos);
  if (obj->inter != NULL)
    free_point(obj->inter);
  free(obj);
}

void		free_all_obj(t_obj *list)
{
  t_obj		*tmp;
  t_obj		*next;

  tmp = list;
  while (tmp)
    {
      next = tmp->next;
      free_obj(tmp);
      tmp = next;
    }
}
