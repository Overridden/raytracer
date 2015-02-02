/*
** pars_other.c for pars_other.c in /home/cerini_j//current_project/raytracer-2017-nguye_1
** 
** Made by jeremy cerini
** Login   <cerini_j@epitech.net>
** 
** Started on  Fri Jun  7 17:38:02 2013 jeremy cerini
** Last update Sun Jun  9 14:09:57 2013 jeremy cerini
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "raytracer.h"
#include "init.h"
#include "utils.h"
#include "lib.h"

char		get_sec_color(t_obj *objet, char *buff)
{
  int		i;

  if ((objet->is_set & COLOR_SEC) == COLOR_SEC)
    return (CONTINUE);
  i = 0;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0')
	 && (buff[i] > 'Z' || buff[i] < 'A'))
    ++i;
  if (buff[i] != '0' || buff[i + 1] != 'x')
    return (CONTINUE);
  i += 2;
  objet->color.sec_color = getnbr_base(buff + i, "0123456789ABCDEF");
  objet->is_set |= COLOR_SEC;
  return (CONTINUE);
}

char		get_brightness(t_obj *objet, char *buff)
{
  int		i;

  if ((objet->is_set & BRIGHT) == BRIGHT)
    return (CONTINUE);
  i = 0;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0'))
    ++i;
  objet->bright = (double)atoi(buff + i) / 1000;
  if (objet->bright > 1)
    objet->bright = 1;
  objet->is_set |= BRIGHT;
  return (CONTINUE);
}

char		get_color_type(t_obj *objet, char *buff)
{
  int		i;

  if ((objet->is_set & TYPE_COLOR) == TYPE_COLOR)
    return (CONTINUE);
  i = 0;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0'))
    ++i;
  objet->color.color_type = (char)atoi(buff + i);
  objet->is_set |= TYPE_COLOR;
  return (CONTINUE);
}

char		get_limit(t_obj *objet, char *buff)
{
  t_point	*point;
  int		i;

  if ((objet->is_set & LIMIT) == LIMIT)
    return (CONTINUE);
  if ((point = malloc(sizeof(*point))) == NULL)
    return (EXIT_ERR);
  i = 0;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0'))
    ++i;
  point->x = (double)atoi(buff + i);
  while (buff[i] != '\0' && buff[i] <= '9' && buff[i] >= '0')
    ++i;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0'))
    ++i;
  point->y = (double)atoi(buff + i);
  while (buff[i] != '\0' && buff[i] <= '9' && buff[i] >= '0')
    ++i;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0'))
    ++i;
  point->z = (double)atoi(buff + i);
  objet->is_set |= LIMIT;
  objet->limit = point;
  return (CONTINUE);
}

