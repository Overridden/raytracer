/*
** set_new_eye.c for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/calc
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Tue May 28 16:58:25 2013 maxime guedj
** Last update Fri Jun  7 11:49:08 2013 maxime guedj
*/

#include "raytracer.h"
#include "calc.h"

void		set_new_eye(t_point *dest, t_obj *obj, t_point *pos)
{
  double	x;
  double	y;
  double	z;

  x = obj->i_rot[0][0] * (dest->x - pos->x);
  x += obj->i_rot[1][0] * (dest->y - pos->y);
  x += obj->i_rot[2][0] * (dest->z - pos->z);
  y = obj->i_rot[0][1] * (dest->x - pos->x);
  y += (obj->i_rot[1][1] * (dest->y - pos->y));
  y += (obj->i_rot[2][1] * (dest->z - pos->z));
  z = obj->i_rot[0][2] * (dest->x - pos->x);
  z += obj->i_rot[1][2] * (dest->y - pos->y);
  z += obj->i_rot[2][2] * (dest->z - pos->z);
  dest->x = x;
  dest->y = y;
  dest->z = z;
}

void		set_new_eye_n(t_point *dest, t_obj *obj, t_obj *tmp,
			      t_point *pos)
{
  double	x;
  double	y;
  double	z;

  x = tmp->i_rot[0][0] * (dest->x - pos->x);
  x += tmp->i_rot[1][0] * (dest->y - pos->y);
  x += tmp->i_rot[2][0] * (dest->z - pos->z);
  y = tmp->i_rot[0][1] * (dest->x - pos->x);
  y += (tmp->i_rot[1][1] * (dest->y - pos->y));
  y += (tmp->i_rot[2][1] * (dest->z - pos->z));
  z = tmp->i_rot[0][2] * (dest->x - pos->x);
  z += tmp->i_rot[1][2] * (dest->y - pos->y);
  z += tmp->i_rot[2][2] * (dest->z - pos->z);
  dest->x = x;
  dest->y = y;
  dest->z = z;
  m_n_rot_mult(dest, obj);
}
