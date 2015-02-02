/*
** verif_final.c for  in /home/lastru_g//svn/raytracer-2017-nguye_1/parser
**
** Made by gael lastrucci
** Login   <lastru_g@epitech.net>
**
** Started on  Tue May 28 14:10:05 2013 gael lastrucci
** Last update Fri Jun  7 19:35:19 2013 jeremy cerini
*/

#include <unistd.h>
#include <stdlib.h>
#include "raytracer.h"
#include "init.h"

unsigned int	*creat_tab_verif()
{
  unsigned int	*tab;

  if ((tab = malloc(6 * sizeof(*tab))) == NULL)
    return (NULL);
  tab[0] = POS | COLOR | PARAM;
  tab[1] = POS | COLOR | PARAM;
  tab[2] = POS | COLOR;
  tab[3] = POS | COLOR | PARAM;
  tab[4] = POS;
  tab[5] = POS | COLOR;
  return (tab);
}

void		verif_light(t_scene *scene, unsigned int *tab)
{
  t_light	*tmp;
  t_light	*prev;

  tmp = scene->light;
  while (tmp != NULL)
    {
      prev = tmp;
      tmp = tmp->next;
      if ((prev->is_set & tab[5]) != tab[5])
	del_elem_light(scene, prev);
    }
}

void		verif_obj(t_scene *scene, unsigned int *tab)
{
  t_obj		*tmp;
  t_obj		*prev;

  tmp = scene->obj;
  while (tmp != NULL)
    {
      prev = tmp;
      tmp = tmp->next;
      if ((prev->is_set & tab[prev->type]) != tab[prev->type]
	  || verif_ext(prev) != CONTINUE)
	del_elem_obj(scene, prev);
   }
}

t_scene		*verif_final(t_scene *scene)
{
  unsigned int	*tab;

  tab = NULL;
  if ((tab = creat_tab_verif()) == NULL)
    {
      free_all_elem(scene);
      scene = NULL;
      write(2, "Error during parsing.\n", 22);
      return (NULL);
    }
  verif_obj(scene, tab);
  if (check_eye(scene) == 0 || scene->eye == NULL)
    {
      free_all_elem(scene);
      scene = NULL;
      write(2, "Error during parsing.\n", 22);
      return (NULL);
    }
  verif_light(scene, tab);
  free(tab);
  return (scene);
}
