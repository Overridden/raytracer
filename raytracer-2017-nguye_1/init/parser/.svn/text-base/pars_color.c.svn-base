/*
** pars_color.h for color in /home/cerini_j//current_project/raytracer-2017-nguye_1
**
** Made by jeremy cerini
** Login   <cerini_j@epitech.net>
**
** Started on  Fri Jun  7 15:20:03 2013 jeremy cerini
** Last update Fri Jun  7 17:00:51 2013 maxime guedj
*/

#include <stdlib.h>
#include "raytracer.h"
#include "init.h"
#include "utils.h"
#include "lib.h"

char		get_color(t_obj *objet, char *buff)
{
  int		i;

  if ((objet->is_set & COLOR) == COLOR)
    return (CONTINUE);
  i = 0;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0')
	 && (buff[i] > 'Z' || buff[i] < 'A'))
    ++i;
  if (buff[i] != '0' || buff[i + 1] != 'x')
    return (CONTINUE);
  i += 2;
  objet->color.prim_color = getnbr_base(buff + i, "0123456789ABCDEF");
  objet->is_set |= COLOR;
  return (CONTINUE);
}

char		get_color_n(t_obj *objet, char *buff)
{
  int		i;

  if ((objet->is_set & COLOR_N) == COLOR_N)
    return (CONTINUE);
  i = 0;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0')
	 && (buff[i] > 'Z' || buff[i] < 'A'))
    ++i;
  if (buff[i] != '0' || buff[i + 1] != 'x')
    return (CONTINUE);
  i += 2;
  objet->color.sec_color = getnbr_base(buff + i, "0123456789ABCDEF");
  objet->is_set |= COLOR_N;
  return (CONTINUE);
}

char		get_t_color(t_obj *objet, char *buff)
{
  int		i;

  if ((objet->is_set & COLOR_T) == COLOR_T)
    return (CONTINUE);
  i = 0;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0'))
    ++i;
  objet->color.color_type = atoi(buff + i) / 1000 % 256;
  objet->is_set |= COLOR_T;
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
  objet->color = getnbr_base(buff + i, "0123456789ABCDEF");
  objet->is_set |= COLOR;
  return (CONTINUE);
}
