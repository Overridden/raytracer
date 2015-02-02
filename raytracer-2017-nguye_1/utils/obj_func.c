/*
** obj_func.c for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/utils
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Mon May 27 15:31:12 2013 maxime guedj
** Last update Sun Jun  9 14:11:45 2013 jeremy cerini
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "raytracer.h"
#include "utils.h"
#include "lib.h"

t_obj		*creat_obj(char type)
{
  t_obj		*elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (NULL);
  elem->type = (enum obj_type)(type);
  elem->pos = NULL;
  elem->limit = NULL;
  elem->inter = NULL;
  elem->k[0] = 0;
  elem->k[1] = 0;
  elem->color.prim_color = 0;
  elem->color.color_type = 0;
  elem->color.sec_color = -1;
  elem->is_set = 0;
  elem->next = NULL;
  elem->texture.texture_ptr = NULL;
  elem->texture.texture_name = NULL;
  elem->bright = 0;
  set_obj_rot(elem, 0, 0, 0);
  return (elem);
}

char		set_obj_pos(t_obj *obj, int x, int y, int z)
{
  obj->pos = creat_point(x, y, z);
  if (obj->pos == NULL)
    return (FAIL);
  return (SUCCESS);
}

void		set_obj_rot(t_obj *obj , int x, int y, int z)
{
  double	r_x;
  double	r_y;
  double	r_z;

  set_obj_n_rot(obj, x, y, z);
  r_x = convert_to_rad(x) * (-1);
  r_y = convert_to_rad(y) * (-1);
  r_z = convert_to_rad(z) * (-1);
  obj->i_rot[0][0] = (obj->type == sphere) ? 1 : cos(r_z) * cos(r_y);
  obj->i_rot[1][0] = (obj->type == sphere) ? 0 : cos(r_y) * -sin(r_z);
  obj->i_rot[2][0] = (obj->type == sphere) ? 0 : sin(r_y);
  obj->i_rot[0][1] = (obj->type == sphere) ? 0 :
    cos(r_z) * sin(r_x) * sin(r_y) + cos(r_x) * sin(r_z);
  obj->i_rot[1][1] = (obj->type == sphere) ? 1 :
    -sin(r_z) * sin(r_x) * sin(r_y) + cos(r_x) * cos(r_z);
  obj->i_rot[2][1] = (obj->type == sphere) ? 0 : -sin(r_x) * cos(r_y);
  obj->i_rot[0][2] = (obj->type == sphere) ? 0 :
    cos(r_x) * -sin(r_y) * cos(r_z) + sin(r_x) * sin(r_z);
  obj->i_rot[1][2] = (obj->type == sphere) ? 0 :
    cos(r_x) * -sin(r_y) * -sin(r_z) + sin(r_x) * cos(r_z);
  obj->i_rot[2][2] = (obj->type == sphere) ? 1 : cos(r_x) * cos(r_y);
}

void		set_obj_n_rot(t_obj *obj, int x, int y, int z)
{
   double	r_x;
  double	r_y;
  double	r_z;

  r_x = convert_to_rad(x);
  r_y = convert_to_rad(y);
  r_z = convert_to_rad(z);
  obj->n_rot[0][0] = (obj->type == sphere) ? 1 : cos(r_z) * cos(r_y);
  obj->n_rot[1][0] = (obj->type == sphere) ? 0 : cos(r_y) * -sin(r_z);
  obj->n_rot[2][0] = (obj->type == sphere) ? 0 : sin(r_y);
  obj->n_rot[0][1] = (obj->type == sphere) ? 0 :
    cos(r_z) * sin(r_x) * sin(r_y) + cos(r_x) * sin(r_z);
  obj->n_rot[1][1] = (obj->type == sphere) ? 1 :
    -sin(r_z) * sin(r_x) * sin(r_y) + cos(r_x) * cos(r_z);
  obj->n_rot[2][1] = (obj->type == sphere) ? 0 : -sin(r_x) * cos(r_y);
  obj->n_rot[0][2] = (obj->type == sphere) ? 0 :
    cos(r_x) * -sin(r_y) * cos(r_z) + sin(r_x) * sin(r_z);
  obj->n_rot[1][2] = (obj->type == sphere) ? 0 :
    cos(r_x) * -sin(r_y) * -sin(r_z) + sin(r_x) * cos(r_z);
  obj->n_rot[2][2] = (obj->type == sphere) ? 1 : cos(r_x) * cos(r_y);
}

void		set_obj_param(t_obj *obj, int param)
{
  if (obj->type == cone)
    obj->param = convert_to_rad((double)param);
  else
    obj->param = param;
}
