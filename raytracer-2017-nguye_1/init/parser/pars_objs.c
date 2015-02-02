/*
** pars_objs.c for ls in /home/cerini_j//current_project/raytracer-2017-nguye_1
**
** Made by jeremy cerini
** Login   <cerini_j@epitech.net>
**
** Started on  Tue May 28 16:48:25 2013 jeremy cerini
** Last update Sat Jun  8 11:34:24 2013 jeremy cerini
*/

#include <string.h>
#include <stdlib.h>
#include "raytracer.h"
#include "init.h"
#include "utils.h"
#include "lib.h"

char		get_pos(t_obj *objet, char *buff)
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

char		get_param(t_obj *objet, char *buff)
{
  int		i;

  if ((objet->is_set & PARAM) == PARAM)
    return (CONTINUE);
  i = 0;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0'))
    ++i;
  objet->param = (double)atoi(buff + i);
  if (objet->type == cone)
    objet->param = convert_to_rad((double)(objet->param));
  objet->is_set |= PARAM;
  return (CONTINUE);
}

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

char		get_texture(t_obj *objet, char *buff)
{
  int		i;

  if ((objet->is_set & TEXTURE) == TEXTURE)
    return (CONTINUE);
  i = strlen(STR_TEX);
  while (buff[i] != 0 && buff[i] == ' '
	 && buff[i] == ' ')
    ++i;
  if ((objet->texture.texture_name = strdup(buff + i)) == NULL)
    return (EXIT_ERR);
  objet->is_set |= TEXTURE;
  return (CONTINUE);
}

char		get_rot(t_obj *objet, char *buff)
{
  int		rot[3];
  int		i;

  if ((objet->is_set & ROT) == ROT)
    return (CONTINUE);
  i = 0;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0'))
    ++i;
  rot[0] = atoi(buff + i - IS_MINUS(*(buff + i - 1)));
  while (buff[i] != '\0' && buff[i] <= '9' && buff[i] >= '0')
    ++i;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0'))
    ++i;
  rot[1] = atoi(buff + i - IS_MINUS(*(buff + i - 1)));
  while (buff[i] != '\0' && buff[i] <= '9' && buff[i] >= '0')
    ++i;
  while (buff[i] != '\0' && (buff[i] > '9' || buff[i] < '0'))
    ++i;
  rot[2] = atoi(buff + i - IS_MINUS(*(buff + i - 1)));
  objet->is_set |= ROT;
  set_obj_rot(objet, rot[0], rot[1], rot[2]);
  return (CONTINUE);
}

