/*
** check_eye.c for  in /home/lastru_g//svn/raytracer-2017-nguye_1/parser
**
** Made by gael lastrucci
** Login   <lastru_g@epitech.net>
**
** Started on  Wed May 29 14:09:17 2013 gael lastrucci
** Last update Fri Jun  7 10:18:46 2013 maxime guedj
*/

#include <stdlib.h>
#include "raytracer.h"
#include "init.h"

void		eye_other_place(t_scene *scene, t_obj *eye)
{
  t_obj		*tmp;

  tmp = scene->obj;
  while (tmp->next != eye)
    tmp = tmp->next;
  if (tmp->next != NULL && tmp->next->next != NULL)
  tmp->next = tmp->next->next;
  eye->next = NULL;
  scene->eye = eye;
}

void		eye_first_place(t_scene *scene)
{
  scene->eye = scene->obj;
  scene->obj = scene->obj->next;
  scene->eye->next = NULL;
}

int		check_eye(t_scene *scene)
{
  t_obj		*tmp;
  t_obj		*eye;
  int		nb_eyes;

  tmp = scene->obj;
  nb_eyes = 0;
  while (tmp != NULL)
    {
      if (tmp->type == eyes)
	{
	  ++nb_eyes;
	  eye = tmp;
	}
      tmp = tmp->next;
    }
  if (nb_eyes == 0 || nb_eyes > 1)
    return (error_eyes(nb_eyes));
  if (scene->obj->type == eyes)
    eye_first_place(scene);
  else
    eye_other_place(scene, eye);
  return (1);
}
