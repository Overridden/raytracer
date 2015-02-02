/*
** setscene.c for set obj n light in /home/cerini_j//current_project/raytracer-2017-nguye_1
**
** Made by jeremy cerini
** Login   <cerini_j@epitech.net>
**
** Started on  Wed May 29 09:38:14 2013 jeremy cerini
** Last update Sun Jun  9 14:11:22 2013 jeremy cerini
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "raytracer.h"
#include "init.h"
#include "utils.h"
#include "lib.h"

char		set_object(int fd, char **current, t_obj *objet, t_tabs *tabs)
{
  int		i;
  char		ret;

  set_tab_obj(tabs);
  ret = CONTINUE;
  while (ret == CONTINUE)
    {
      free(*current);
      if ((*current = my_epure_str(get_next_line(fd))) == NULL)
	return (EXIT);
      i = 0;
      if ((*current)[0] != 0 && (*current)[0] != '#'
	  && (*current)[0] != ';')
	{
	  while (tabs->lineo[i] != NULL &&
		 strncmp(tabs->lineo[i], *current, strlen(tabs->lineo[i])) != 0)
	    ++i;
	  if (tabs->lineo[i] == NULL)
	    return (CONTINUE);
	  ret = tabs->tabo[i](objet, *current);
	}
    }
  return (CONTINUE);
}

char		set_light(int fd, char **current, t_light *lumiere, t_tabs *tabs)
{
  int		i;
  char		ret;

  set_tab_light(tabs);
  ret = CONTINUE;
  while (ret == CONTINUE)
    {
      free(*current);
      if ((*current = my_epure_str(get_next_line(fd))) == NULL)
	return (EXIT);
      i = 0;
      if ((*current)[0] != 0 && (*current)[0] != '#'
	  && (*current)[0] != ';')
	{
	  while (tabs->linel[i] != NULL &&
		 strncmp(tabs->linel[i], *current, strlen(tabs->linel[i])) != 0)
	    ++i;
	  if (tabs->linel[i] == NULL)
	    return (CONTINUE);
	  ret = tabs->tabl[i](lumiere, *current);
	}
    }
  return (CONTINUE);
}

void		set_tab_light(t_tabs *tabs)
{
  if (tabs->linel[0] != NULL && strcmp(tabs->linel[0], STR_POS) == 0)
    return ;
  tabs->linel[0] = STR_POS;
  tabs->linel[1] = STR_COLOR;
  tabs->linel[2] = NULL;
  tabs->tabl[0] = &get_pos_l;
  tabs->tabl[1] = &get_color_l;
}

void		set_tab_obj(t_tabs *tabs)
{
  if (tabs->lineo[0] != NULL && strcmp(tabs->lineo[0], STR_POS) == 0)
    return ;
  tabs->lineo[0] = STR_POS;
  tabs->lineo[1] = STR_ROT;
  tabs->lineo[2] = STR_COLOR;
  tabs->lineo[3] = STR_PARAM;
  tabs->lineo[4] = STR_TEX;
  tabs->lineo[5] = STR_BRI;
  tabs->lineo[6] = STR_C_T;
  tabs->lineo[7] = STR_C_N;
  tabs->lineo[8] = STR_LIM;
  tabs->lineo[9] = NULL;
  tabs->tabo[0] = &get_pos;
  tabs->tabo[1] = &get_rot;
  tabs->tabo[2] = &get_color;
  tabs->tabo[3] = &get_param;
  tabs->tabo[4] = &get_texture;
  tabs->tabo[5] = &get_brightness;
  tabs->tabo[6] = &get_color_type;
  tabs->tabo[7] = &get_sec_color;
  tabs->tabo[8] = &get_limit;
}

char			add_to_current(int fd, t_scene *scene,
				       char **line, t_tabs *tabs)
{
  t_obj			*obj;

  if (scene->obj == NULL)
    {
      free(*line);
      *line = my_epure_str(get_next_line(fd));
      return (CONTINUE);
    }
  obj = scene->obj;
  while (obj->next)
    obj = obj->next;
  return (set_object(fd, line, obj, tabs));
}
