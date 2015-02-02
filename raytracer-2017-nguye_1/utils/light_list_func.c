/*
** light_list_func.c for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/utils
** 
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
** 
** Started on  Mon May 27 17:03:07 2013 maxime guedj
** Last update Mon May 27 19:40:19 2013 maxime guedj
*/

#include <stdlib.h>
#include "raytracer.h"
#include "utils.h"

t_light		*add_light(t_light *first, t_light *elem)
{
  t_light	*tmp;

  tmp = first;
  if (tmp == NULL)
    return (elem);
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = elem;
  return (first);
}

void		free_all_light(t_light *list)
{
  t_light	*tmp;
  t_light	*next;

  tmp = list;
  while (tmp)
    {
      next = tmp->next;
      free_light(tmp);
      tmp = next;
    }
}
