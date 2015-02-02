/*
** pars_objs.c for ls in /home/cerini_j//current_project/raytracer-2017-nguye_1
**
** Made by jeremy cerini
** Login   <cerini_j@epitech.net>
**
** Started on  Tue May 28 16:48:25 2013 jeremy cerini
** Last update Fri Jun  7 20:29:41 2013 jeremy cerini
*/

#include <stdlib.h>
#include <stdio.h>
#include "raytracer.h"
#include "init.h"
#include "utils.h"
#include "lib.h"

char		get_pos_l(t_light *objet, char *buff)
{
  t_point	*point;
  int		i;

  if ((objet->is_set & POS) == POS)
    return (CONTINUE);
  if ((point = malloc(sizeof(*point))) == NULL)
    return (EXIT_ERR);
  i = 0;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0'))
    ++i;
  point->x = (double)atoi(buff + i - IS_MINUS(*(buff + i - 1)));
  while (buff[i] != '\0' && buff[i] <= '9' && buff[i] >= '0')
    ++i;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0'))
    ++i;
  point->y = (double)atoi(buff + i - IS_MINUS(*(buff + i - 1)));
  while (buff[i] != '\0' && buff[i] <= '9' && buff[i] >= '0')
    ++i;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0'))
    ++i;
  point->z = (double)atoi(buff + i - IS_MINUS(*(buff + i - 1)));
  objet->is_set |= POS;
  objet->pos = point;
  return (CONTINUE);
}

char		get_color_l(t_light *objet, char *buff)
{
  int		i;

  if ((objet->is_set & COLOR) == COLOR)
    return (CONTINUE);
  i = 0;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0')
	 && (buff[i] > 'Z' || buff[i] < 'A'))
    ++i;
  if (buff[i] == 0 || buff[i] != '0' || buff[i + 1] != 'x')
    return (CONTINUE);
  i += 2;
  objet->color = getnbr_base(buff + i, "0123456789ABCDEF");
  objet->is_set |= COLOR;
  return (CONTINUE);
}
